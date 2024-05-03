
#include <bits/stdc++.h>
using namespace std;
const int N=1005;
vector<pair<int,long long int>> v[N];
long long int dis[N];

void dijkstra(int src)

{
    priority_queue<pair<long long int,int>> pq;
    pq.push({0,src});
    dis[src]=0;
    while(!pq.empty())
    {
        pair<long long int,int> par=pq.top();
        pq.pop();
        long long int cost=par.first;
        int node=par.second;

        if(cost>dis[node])
        {
            continue;
        }
        for(pair<long long int,int> child:v[node])
        {
            int childNode=child.first;
            long long int childCost=child.second;

            if(cost+childCost<dis[childNode])
            {
                dis[childNode]=cost+childCost;
                pq.push({dis[childNode],childNode});
            }
        }
        if(pq.empty() && dis[node==1e18])
        {
            break;
        }
    }
}
int main()
{
    int n,e;
    cin >>n >> e;
    while(e--)
    {
        int a,b;
        long long int c;
        cin >> a >>b >> c;
        v[a].push_back({b,c});
        //v[b].push_back({a,c});
    }
    int src;
    cin >> src;

    long long int t;
    cin >> t;
    while(t--)
    {
        int dest;
        long long int cost;
        cin >> dest,cost;
        for(int i=0;i<=n;i++)
        {
            dis[i]=1e18;
        }
        dijkstra(src);
        if(dis[dest]<=cost)
        {
            cout <<"YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}

