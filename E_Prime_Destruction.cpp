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

int main() 
{
    ios::sync_with_stdio(0), cin.tie(0);

    // sieve(); 

    int t;
    cin >> t;
    while (t--) 
    {
        int n, k;
        cin >> n >> k;

        vector<int> dp(n + 1);
        vector<vector<int>> dv(n + 1);

        for (int i = 2; i <= n; ++i)
        {
            if (dv[i].size() == 0)
            {
                for (int j = i; j <= n; j += i)
                    dv[j].emplace_back(i);
            }
        }

    
        for (int i = k + 1; i <= n; ++i)
        {
            dp[i] = i;

            for (auto u : dv[i])
            {
                dp[i] = min(dp[i], dp[i / u] * u + 1);
            }
        }

        ll res = 0;

        for (int i = 0; i < n; ++i)
        {
            int u;
            cin >> u;

            res += dp[u];
        }

        cout << res << '\n';
    }

    return 0;
}
