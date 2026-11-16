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
        ll n, m;
        cin >> n >> m;
        vector<ll> ar(n), br(n);
        for(int i = 0; i < n; i++)
            cin >> ar[i];
        for(int i = 0; i < n; i++)
            cin >> br[i];

        ll sum1 = 0, sum2 = 0, sum3 = 0;
        for(int i = 0; i < n; i++)
        {
            sum1 += ar[i];
            sum2 += br[i];
            sum3 += min(ar[i], br[i]);
        }

        ll ans = min({m + sum1, m + sum2, 2 * m + sum3});
        cout << ans << '\n';
    }

    return 0;
}
