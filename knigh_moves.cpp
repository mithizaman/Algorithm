#include <bits/stdc++.h>
using namespace std;
const int N=1005;
const int P=1e9;
bool vis[N][N];
int dis[N][N];
vector<pair<int,int>> d= {{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1}};
bool valid(int i,int j,int n,int m)
{
    return(i>=0 && i<n && j>=0 && j<m);
}
void bfs(int si,int sj,int n,int m)
{
    queue<pair<int,int>> q;
    q.push({si,sj});
    dis[si][sj]=0;

    while(!q.empty())
    {
        pair<int,int> cur = q.front();
        q.pop();
        int a=cur.first;
        int b=cur.second;

        for(int k=0;k<d.size();k++)
        {
            int ci=a+d[k].first;
            int cj=b+d[k].second;
            if(valid(ci,cj,n,m) && dis[ci][cj]==P)
            {
                dis[ci][cj]=dis[a][b]+1;
                q.push({ci,cj});
            }
        }
    }
}
int main()
{
    int t;
    cin >>t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        int si,sj,des1,des2;

        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                dis[i][j]=P;
            }
        }
        cin >> si >> sj >> des1 >> des2;
        bfs(si,sj,n,m);
        if(dis[des1][des2]==P)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << dis[des1][des2] << endl;
        }
    }
    return 0;
}