#include <bits/stdc++.h>
using namespace std;
const int N= 1005;
int vis[N][N];
pair<int,int> path[N][N];
vector<pair<int,int>> moves={{-1,0},{1,0},{0,-1},{0,1}};
int n,m;
int sx,sy,ex,ey;

bool isValid(int x,int y)
{
    return !vis[x][y] && (x>=0) and (x<n) and (y>=0) and (y<m);
}
void bfs()
{
    queue<pair<int,int>> q;
    q.push({sx,sy});
    vis[sx][sy]=true;
    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(auto mv:moves)
        {
            int new_x= x+mv.first;
            int new_y= y+mv.second;
            if(isValid(new_x,new_y))
            {
                vis[new_x][new_y] = true;
                path[new_x][new_y] = {mv.first,mv.second};
                q.push({new_x,new_y});
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            path[i][j]={-1,-1};
            char c;
            cin >> c;
            if(c=='#')
            {
                vis[i][j] = true;
            }
            if(c=='A')
            {
                sx=i;
                sy=j;
            }
            if(c=='B')
            {
                ex = i;
                ey = j;
            }
        }
    }
    bfs();
    if(!vis[ex][ey])
    {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    vector<pair<int,int>> ans;
    pair<int,int> dest = {ex,ey};

    while(dest.first!=sx or dest.second != sy)
    {
        ans.push_back({path[dest.first][dest.second]});
        dest.first -= ans.back().first;
        dest.second  -= ans.back().second;
    }
    reverse(ans.begin(),ans.end());
    /*for(auto i:ans)
    {
        cout << i.first << " " << i.second << endl;
    }*/
    for(auto i:ans)
    {
        if(i.first == 1 and i.second == 0)
        {
            cout << "D";
        }
        if(i.first == -1 and i.second == 0)
        {
            cout << "U";
        }
        if(i.first == 0 and i.second == -1)
        {
            cout << "R";
        }
        if(i.first == 0 and i.second == 1)
        {
            cout << "L";
        }
    }
    return 0;
}



//
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
    if(find(a) != find(b))
    {
        if(Size[a] < Size[b])
        {
            swap(a,b);
        }
        parent[b] = a;
        Size[a] += Size[b];
    }
}
int main()
{
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        make(i);
    }
    while(m--)
    {
        int u,v;
        cin >> u >>v;
        Union(u,v);
    }
    int cnt = 0;
    for(int i = 1;i<=n;i++)
    {
        if(i==find(i))
        {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}

//mst

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
        if(Size[a] < Size[b])
        {
            swap(a,b);
        }
        parent[b] = a;
        Size[a] += Size[b];
    }
}
    /*if(find(a) != find(b))
    {
        if(Size[a] < Size[b])
        {
            swap(a,b);
        }
        parent[b] = a;
        Size[a] += Size[b];
    }
}*/
int main()
{
    int n,m;
    cin >> n >> m;
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
    }
    cout << cost << endl;
    return 0;
}
