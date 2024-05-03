#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >>m;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin >> arr[i];
        }
        int s = 1000-m;

        bool dp[n+1][s+1];
        
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=s;j++)
            {
                dp[i][j] = false;
            }
        }
        dp[0][0] = true;

        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=s;j++)
            {
                dp[i][j] = dp[i-1][j];
                if(j>=arr[i-1])
                {
                    dp[i][j] = dp[i][j] ||dp[i-1][j-arr[i-1]];
                }
            }
        }
        if(s==0 || dp[n][s])
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}