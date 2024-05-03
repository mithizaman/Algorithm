#include <bits/stdc++.h>
using namespace std;
class Edge
{
    public:
        int u,v,c;
        Edge(int u,int v,int c)
        {
            this->u=u;
            this->v=v;
            this->c=c;
        }
};
const int N=1e5+5;
long long int dis[N];

int main()
{
    int n,e;
    cin >> n >> e;
    vector<Edge> EdgeList;
    while(e--)
    {
        int u,v,c;
        cin >> u >> v >> c;
        EdgeList.push_back(Edge(u,v,c));
    }
    for(int i=0;i<=n;i++)
    {
        dis[i]=1e18;
    }
    int src;
    cin >> src;

    int q;
    cin >> q;
    dis[src]=0;
    for(int i=1;i<=n-1;i++)
    {
        for(Edge ed : EdgeList)
        {
            int u,v,c;
            u=ed.u;
            v=ed.v;
            c=ed.c;
            if(dis[u] < 1e18 && dis[u] + c < dis[v])
            {
                dis[v]=dis[u]+c;
            }
        }
    }
    for(Edge ed : EdgeList)
        {
            int u,v,c;
            u=ed.u;
            v=ed.v;
            c=ed.c;
            if(dis[u] < 1e18 && dis[u] + c < dis[v])
            {
                cout << "Negative Cycle Detected" << endl;
                return 0;
            }
        }

        while(q--)
        {
            int d;
            cin >> d;
            if(dis[d]==1e18)
            {
                cout << "Not Possible" << endl;
            }
            else
            {
                cout << dis[d] << endl;
            }
        }
    return 0;
}