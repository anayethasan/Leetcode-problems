#include <bits/stdc++.h>
using namespace std;

/************************************************************
*                                                          *
*  "If talent doesn't work, believe in yourself and        *
*   do hard work. Allah will give you the best gift."      *
*                                                          *
*************************************************************/

#define ll long long
#define hea cout << "YES\n";
#define na cout << "NO\n";
#define nl cout << '\n';

const int maxN = 2e5 + 10;
int n, h[maxN], dp[maxN];

int fun(int i)
{
    if(i == n)
        return 0;

    if(dp[i] != -1)
        return dp[i];
    
    int ans = INT_MAX;
    if(i + 1 <= n)
        ans = min(ans, abs(h[i] - h[i + 1]) + fun(i + 1));
    
    if(i + 2 <= n)
        ans = min(ans, abs(h[i] - h[i + 2]) + fun(i + 2));

    return dp[i] = ans;
}

int main() 
{
    ios::sync_with_stdio(0), cin.tie(0);

    // sieve(); 

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> h[i];
    
    memset(dp, -1, sizeof(dp));

    cout << fun(1) << '\n';

    return 0;
}
