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

    int n, t;
    cin >> n >> t;

    vector<int> ar(n);
    for(int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }
    
    auto ok = [&](ll sec)
    {
        ll cnt = 0;

        for(int i = 0; i < n; i++)
        {
            cnt += sec / ar[i];

            if(cnt >= t)
                return true;
        }

        return false;
    };

    ll l = 0, r = 1e18;
    ll ans = -1;

    while(l <= r)
    {
        ll mid = l + (r - l) / 2;

        if(ok(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << ans << '\n';

    return 0;
}
