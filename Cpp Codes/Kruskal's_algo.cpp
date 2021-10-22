#include<bits/stdc++.h>
using namespace std;
struct edge{
    int s;
    int d;
    int w;

};
int findparent(int parent[],int p)
{
    if(parent[p]==p)
    {
        return p;
    }
    return findparent(parent,parent[p]);
}
bool comp(edge a,edge b)
{
    return a.w<b.w;
}
void kruskal(vector<edge>graph,int n,int e)
{
   int parent[n];
   vector<edge>mst(n-1);
   for (int i = 0; i < n; i++)
   {
       parent[i]=i;
   }
   int i=0;
   int count=0;
   sort(graph.begin(),graph.end(),comp);
   while (count!=n-1)
   {
       edge curr=graph[i];
       int sourceparent=findparent(parent,curr.s);
       int destparent=findparent(parent,curr.d);
       if(sourceparent!=destparent)
       {
           parent[sourceparent]=destparent;
           mst[count]=curr;
           count++;
       }
      i++;
   }
      for(int i = 0; i <n-1; i++)
    {         
        
       cout<<mst[i].s<<" "<<mst[i].d<<" "<<mst[i].w<<endl;
    }
}
int main()
{
int v,e;
cin>>v>>e;
vector<edge>graph(e);
for (int i = 0; i < e; i++)
{
    int x,y,z;
    cin>>x>>y>>z;
    graph[i].s=x;
    graph[i].d=y;
    graph[i].w=z;
}
kruskal(graph,v,e);
return 0;
}
