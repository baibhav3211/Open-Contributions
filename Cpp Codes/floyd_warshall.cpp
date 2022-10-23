#include<bits/stdc++.h>
using namespace std;
#define INF 9999

int adj[100][100];
int parent[100][100];

int pathfind(int source,int des)
{
    if(source==des)
    {
        cout << "Path: " << source;
        return 0;
    }
    pathfind(source,parent[source][des]);
    cout << "->" << des;
}
int main()
{
    ifstream input("floyd_input.txt");
    if(!input.is_open())
    {
        cout << "File not open!\n";
    }

    int totalnode,node1,node2,weight;
    input>>totalnode;

    for(int i=1; i<=totalnode; i++)
    {
        for(int j=1; j<=totalnode; j++)
        {
            if(i==j)
            {
                adj[i][j]=0;
            }
            else
            {
                adj[i][j]=INF;
            }
            parent[i][j]=i;
        }
    }
    while(input>>node1>>node2>>weight)
    {
        adj[node1][node2]=weight;
    }

    /*cout << "Distance table:\n";
    for(int i=1;i<=totalnode;i++)
    {
        for(int j=1;j<=totalnode;j++)
        {
            cout << adj[i][j] << "   ";
        }
        cout << endl;
    }
    cout << "\nSequence table:\n";
    for(int i=1;i<=totalnode;i++)
    {
        for(int j=1;j<=totalnode;j++)
        {
            cout << parent[i][j] << "   ";
        }
        cout << endl;
    }*/

    for(int k=1; k<=totalnode; k++)
    {
        for(int i=1; i<=totalnode; i++)
        {
            for(int j=1; j<=totalnode; j++)
            {
                if(adj[i][k]+adj[k][j] < adj[i][j])
                {
                    adj[i][j]=adj[i][k]+adj[k][j];
                    parent[i][j]=parent[k][j];
                }
            }
        }
    }

    /*int source,des;
    cout << "Enter source & destination: ";
    cin >> source >> des;

    cout << "Cost: " << adj[source][des] << endl;
    */

    for(int i=1;i<=totalnode;i++)
    {
        for(int j=1;j<=totalnode;j++)
        {
            cout << "Cost from " << i << " to " << j << ": " << adj[i][j] << endl;
            pathfind(i,j);
            cout << endl << endl;
        }
        //cout << endl;
    }

    //pathfind(source,des);
    return 0;
}
