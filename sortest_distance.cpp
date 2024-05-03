#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll n,e;
    cin >> n >> e;
    ll adj[n][n];
    for(long long int i=0;i<n;i++)
    {
        for(long long int j=0;j<n;j++)
        {
            if(i==j)
            {
                adj[i][j]=0;
            }
            else
            {
                adj[i][j]=1e16;
            }
        }
    }
while(e--)
{
    long long a,b,c;
    cin >> a >> b >> c;

    adj[a-1][b-1]=min(adj[a-1][b-1],c);
}
for(long long int k=0;k<n;k++)
{
    for(long long int i=0;i<n;i++)
    {
        for(long long int j=0;j<n;j++)
        {
            if(adj[i][k]!=1e16 && adj[k][j]!=1e16 && adj[i][k] +adj[k][j] < adj[i][j])
            {
                adj[i][j]=adj[i][k]+adj[k][j];
            }
        }
    }
}
for(int i=0;i<n;i++)
{
    if(adj[i][i]<0)
    {
        cout << "Negative cycle detected" << endl;
        return 0;
    }
}
long long int q;
cin >> q;
while(q--)
{
    long long int s,d;
    cin >> s >> d;
    if(s<=0 || s>n || d<=0 || d>n)
    {
        cout << "Invalid nodes" << endl;
        continue;
    }
    if(adj[s-1][d-1]==1e16)
    {
        cout << "No connection" << endl;
    }
    else
    {
        cout << adj[s-1][d-1];
    }
}


    return 0;
}