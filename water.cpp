#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> h(n);
        for(int i=0;i<n;i++)
        {
            cin >> h[i];
        }
        int ans = INT_MIN;
        int left=0;
        int right= n-1;
        int ai=-1;
        int aj=-1;

        while(left<right)
        {
            if(min(h[left],h[right]) > ans)
            {
                ans = min(h[left],h[right]);
                ai=left;
                aj=right;
            }
            if(h[left] < h[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        cout << ai << " " << aj << endl;
    }
    return 0;
}