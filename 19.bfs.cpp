#include <bits/stdc++.h>
#include<list>
using namespace std;
class graph{
    int V;
    list<int> *l;
    public:
    graph (int v){
        V=v;
        l=new list<int>[V];
    }
    void addedge(int i,int j,bool undir=true)
{
    l[i].push_back(j);
    if(undir)
    l[j].push_back(i);
}
void bfs(int source)
{
    queue<int>q;
    q.push(source);
    bool *visited =new bool [V]{0};
    visited[source]=true;
    while(!q.empty())
    {
        int f=q.front();
        cout<<f<<endl;
        q.pop();

        for(auto nbrs: l[f])
        {
            if(!visited[nbrs]){
                q.push(nbrs);
                visited[nbrs]==true;
            }
        }
    }
}

void print_adjlist(){
    for(int i=0;i<V;i++)
    {
        cout<<i<<"-->";
        for(auto node:l[i])
        cout<<node<<",";
        cout<<endl;
    }
}

};


int main()
{
    graph g(6);
    g.addedge(0,1);
    g.addedge(1,2);
    g.addedge(0,3);
    g.addedge(3,0);
    g.addedge(1,0);
    g.addedge(2,1);
    g.addedge(3,1);
    g.addedge(2,2);
    // g.print_adjlist();
    bfs(0);
    return 0;
}


//coding ninjas


#include <iostream>
#include <queue>
using namespace std;

void bfs(int **edges,int n,int start,bool *visited){

  queue<int> q;
  q.push(start);
  visited[start]=true;
  while(!q.empty()){
    int node=q.front();
    q.pop();
    cout<<node<<" ";
    

    for(int i=0;i<n;i++){
      if(edges[node][i] && !visited[i]){
        q.push(i);
        visited[i]=true;
      }
    }
  }
  // cout<<endl;
}

int main() {
    int V, E;
    cin >> V >> E;

    int **edges=new int*[V];
    //intialization
    for(int i=0;i<V;i++){
      edges[i]=new int[V];
      for(int j=0;j<V;j++)
        edges[i][j]=0;
    }

    for(int i=0;i<E;i++){
      int a,b;
      cin>>a>>b;
      edges[a][b]=1;
      edges[b][a]=1;
    }
    bool* visited=new bool[V];
    for(int i=0;i<V;i++)
      visited[i]=false;
    
    for(int i = 0;i<V;i++){
        if(visited[i] == false){
            bfs(edges,V,i,visited);
        }
    }

  return 0;
}

