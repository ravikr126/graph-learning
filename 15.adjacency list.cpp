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
    g.addedge(0,1);
    g.addedge(0,1);
    g.addedge(0,1);
    g.addedge(0,1);
    g.addedge(0,1);
    g.addedge(0,1);
    g.addedge(0,1);
    g.print_adjlist();
    return 0;
}
