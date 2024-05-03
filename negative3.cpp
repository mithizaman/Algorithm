#include <bits/stdc++.h>
using namespace std;
class Edge
{
    public:
    int u,v;
    long long int c;
    Edge(int u,int v,long long int c)
    {
        this->u=u;
        this->v=v;
        this->c=c;
    }
};
const int N=1005;
long long int dis[N];
int main()
{
    int n,e;
    cin >> n >> e;
    vector<Edge> EdgeList;
    while(e--)
    {
        int u,v;
        long long c;
        cin >> u >> v >> c;
        EdgeList.push_back(Edge(u,v,c));
    }

    int src;
    cin >> src;

    int t;
    cin >> t;
    while(t--)
    {
        int dest;
        long long int cost;
        cin >> dest >> cost;
        for(int i=0;i<n;i++)
        {
            dis[i]=1e18;
        }
        dis[0]=0;
    
    for(int i=1;i<=n-1;i++)
    {
        for(Edge ed : EdgeList)
        {
            int u,vc;
            u=ed.u;
            v=ed.v;
            c=ed.c;
            if(dis[u]<1e18 && dis[u] + c < dis[v])
            {
                dis[v]=dis[u] +c;
            }
        }
    }
    if(dis[dest]<=cost)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
