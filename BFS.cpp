#include <iostream>
#include <list>
#include <unordered_map>
#include <set>
#include <vector>
#include <queue>

using namespace std;

void prepAdjList(unordered_map<int, set<int>> &adjList, vector<pair<int, int>> &edges) {
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        adjList[u].insert(v);
        adjList[v].insert(u);
    }
}

void bfs(unordered_map<int, set<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node) {
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while (!q.empty()) {
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);

        for (auto i : adjList[frontNode]) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges) {
    unordered_map<int, set<int>> adjList;
    vector<int> ans;
    unordered_map<int, bool> visited;

    prepAdjList(adjList, edges);

    for (int i = 0; i < vertex; i++) {
        if (!visited[i]) {
            bfs(adjList, visited, ans, i);
        }
    }
    return ans;
}

int main() {
    // Example usage:
    
    int vertices = 5;
    vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {1, 3}, {2, 4}};

    vector<int> result = BFS(vertices, edges);

    cout << "BFS Traversal: ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
