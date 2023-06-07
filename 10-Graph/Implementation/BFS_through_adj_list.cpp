#include<bits/stdc++.h>
using namespace std;

vector <int> bfsOfGraph(int node, vector <int> adj[])
{
    vector <int> bfs;

    //vis vetor is used to record the status of node whether it is visited or not
    vector <int> vis(node+1,0);

    //traverse through all the nodes to find bfs of graph
    for(int i=1;i<=node;i++)
    {
        if(vis[i]==0)
        {
            queue <int> q;
            q.push(i);
            vis[i]=1;
            while(!q.empty())
            {
                int n = q.front();
                q.pop();
                bfs.push_back(n);
                for(auto it : adj[n])
                {
                    if(vis[it]==0)
                    {
                        q.push(it);
                        vis[it]=1;
                    }
                }
            }
        }
    }
    return bfs;
}

int main()
{
    int node,edge,i,j,count=0;
    cout<<"Enter number of node and edges for a graph\n";
    cin>>node>>edge;
    vector <int> adj[node+1];

    //below code is used to create adjancy list of a undirected graph
    for(i=0;i<edge;i++)
    {
        int u,v;
        cout<<"Enter vertex's of "<<++count<<" edge  = ";
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //function call to find bfs of graph
    vector <int> bfs = bfsOfGraph(node,adj);

    //Print bfs of a graph
    cout<<"\nBread first search \n";
    for(int i=0;i<node;i++)
        cout<<bfs[i]<<" ";
    return 0; 
}
