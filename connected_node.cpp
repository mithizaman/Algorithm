#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,e;
	cin >> n >> e;


	int mat[n][n];
	memset(mat,0,sizeof(mat));

	while(e--)
	{
        int a,b;
        cin >> a >> b;
        mat[a][b] = 1;
        mat[b][a] = 1;
	}
    int q;
    cin >> q;
	while(q--)
    {
        int x;
        cin >> x;
        
        vector<int> v;
        for(int i=0;i<n;i++)
        {
            if(mat[x][i]==1)
            {
                v.push_back(i);
            }
        }
        if(v.empty())
        {
            cout << -1 << endl;
        }
        else
        {
            sort(v.rbegin(),v.rend());
            for(int x:v)
            {
                cout << x << " ";
            }
            cout << endl;
        }
	}
	return 0;
}