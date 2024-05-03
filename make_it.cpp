#include <bits/stdc++.h>
using namespace std;

bool dp[100005];
bool canReach(int C,int A)
{
    if(C==A)
    {
        return true;
    }
    if(C>A || dp[C])
    {
        return false;
    }
    dp[C] = true;
    return canReach(C+3,A) || canReach(C*2,A);
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int A;
        cin >> A;
        memset(dp,false,sizeof(dp));
        if(canReach(1,A))
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