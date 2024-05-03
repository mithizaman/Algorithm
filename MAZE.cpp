#include <bits/stdc++.h>
using namespace std;
const int N= 1005;
int vis[N][N];
pair<int,int> path[N][N];
vector<pair<int,int>> moves={{-1,0},{1,0},{0,-1},{0,1}};
vector<vector<char>> maze;
int n,m;
int sx,sy,ex,ey;

bool isValid(int x,int y)
{
    return (x>=0) and (x<n) and (y>=0) and (y<m) && maze[x][y]!='#';
}
void bfs()
{
    queue<pair<int,int>> q;
    q.push({ex,ey});
    vis[ex][ey]=true;
    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(auto mv:moves)
        {
            int new_x= x+mv.first;
            int new_y= y+mv.second;
            if(isValid(new_x,new_y) && !vis[new_x][new_y])
            {
                vis[new_x][new_y] = true;
                path[new_x][new_y] = {x,y};
                q.push({new_x,new_y});
            }
        }
    }
}
int main()
{
    cin >> n >> m;
    maze.resize(n,vector<char> (m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            char c;
            cin >> c;
            maze[i][j] = c;
            if(c=='R')
            {
                sx=i;
                sy=j;
            }
            if(c=='D')
            {
                ex = i;
                ey = j;
            }
        }
    }
    bfs();
    if(!vis[sx][sy]) 
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout << maze[i][j];
            }
            cout << endl;
        }
        return 0;
    }
    pair<int,int> dest = {sx,sy};

    while(dest.first != ex || dest.second != ey)
    {
        maze[dest.first][dest.second] = 'X';
        dest = path[dest.first][dest.second];
    }
    maze[ex][ey] = 'D';
    maze[sx][sy] = 'R';
    for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout << maze[i][j];
            }
            cout << endl;
        }
    return 0;
}
