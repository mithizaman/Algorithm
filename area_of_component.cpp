#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
    int n,m;
    vector<vector<bool>> visited;
    bool valid(int i,int j)
    {
        return i>=0 && i< n && j>=0 && j<m;
    }
    int dfs(int i ,int j,vector<vector<char>>& grid)
    {
        visited[i][j]=true;
        int area=1;
        vector<pair<int,int>> d={{0,1},{0,-1},{-1,0},{1,0}};
        for(int k=0;k<4;k++)
        {
            int ci=i+d[k].first;
            int cj=j+d[k].second;
            if(valid(ci,cj) && !visited[ci][cj] && grid[ci][cj] == '.')
            {
                area += dfs(ci,cj,grid);
            }
        }
        return area;
    }
    int  min_component(vector<vector<char>> & grid)
    {
        n=grid.size();
        m=grid[0].size();
        visited.resize(n);
        for(int i=0;i<n;i++)
        {
            visited[i].resize(m,false);
        }
        int minArea=-1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='.' && !visited[i][j])
                {
                    int area=dfs(i,j,grid);
                    if(minArea==-1 || area < minArea)
                    {
                        minArea=area;
                    }
                }
            }
        }
        return minArea;
    }
};
int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<char>> grid(n);
    for(int i=0;i<n;i++)
    {
        grid[i].resize(m);
        for(int j=0;j<m;j++)
        {
            cin>> grid[i][j];
        }
    }
    Solution S;
    cout << S.min_component(grid) << endl;
    return 0;
}