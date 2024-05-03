#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
bool vis[N];
vector<int> adj[N];
int cycleEdge = 0;
void dfs(int node1, int node2)
{
    vis[node1] = true;
    for(int child:adj[node1])
    {
        if(!vis[child])
        {
            dfs(child,node1);
        }
        else if(child!=node2)
        {
            cycleEdge++;
        }
    }
}
int main()
{
    int n,e;
    cin >> n >> e;
    while(e--)
    {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            dfs(i,-1);
        }
    }
    cout << cycleEdge/2 << endl;
    return 0;
}