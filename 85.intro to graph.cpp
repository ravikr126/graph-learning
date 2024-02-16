//love babbar graph series video number 85 

// Online C++ coadjiler to run C++ program online
#include <iostream>
#include<unordered_map>
#include<list>
using namespace std;

class graph{
    public:
    unordered_map<int, list<int>>adj;
    void joint(int start,int end, bool direction)
    {
        
        adj[start].push_back(end);
        if(direction==0)
        {
            adj[end].push_back(start);
        }
        print(adj);
    }
    
    void print(unordered_map<int,list<int>>adj)
    {
        for(auto x:adj)
        {
            cout<<x.first<<"->"<<" ";
            for(auto y: x.second)
            cout<<y<<'\n';
            cout<<endl;
        }
        
    }
};


int main() {
    // Write C++ code here
    int edge,nodes;
    cout<<"Enter the no of nodes"<<'\n';
    cin>>nodes;
        cout<<"Enter the no of edges"<<'\n';
    cin>>edge;
    for(int i=0;i<edge;i++)
    {
       int start,end;
       graph g;
       cin>>start>>end;
       g.joint(start,end,0);
    }

    return 0;
}
