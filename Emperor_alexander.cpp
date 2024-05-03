#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int parent[N];
int Size[N];

void make(int v)
{
    parent[v] = v;
    Size[v]=1;
}
int find(int v)
{
    if(v==parent[v])
    {
        return v;
    }
    return parent[v] = find(parent[v]);
}
void Union(int a,int b)
{
    int par_a = find(a);
    int par_b = find(b);
    if(par_a != par_b)
    {
        if(Size[par_a] < Size[par_b])
        {
            swap(par_a,par_b);
        }
        parent[par_b] = par_a;
        Size[par_a] += Size[par_b];
    }
}
 
int main()
{
    int n,m;
    cin >> n >> m;
    make(n);
    vector<pair<int,pair<int,int>>> edges;
    for(int i=0;i<m;i++)
    {
        int u,v,wt;
        cin >> u >> v >> wt;
        edges.push_back({wt,{u,v}});
    }
    for(int i=1;i<=n;i++)
    {
        make(i);
    }
    sort(edges.begin(),edges.end());

    long long int cost=0;
    int e=0;
    for(auto edge:edges)
    {
        int c = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        if(find(u) == find(v))
        {
            continue;
        }
        Union(u,v);
        cost += c;
        e++;
    }
    if(e == n-1)
    {
        cout << m-(n-1) << " "<< cost << endl;
    }
    else
    {
        cout << "Not Possible" << endl;
    }
    return 0;
}
