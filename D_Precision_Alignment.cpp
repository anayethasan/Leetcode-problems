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

void solve() 
{
    ll n, k;
    cin >> n >> k;

    vector<tuple<ll, ll, ll>> ar(n);
    
    vector<ll> sum(n), del(n);
    for(int i = 0; i < n; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;

        ar[i] = {a, b, c};
        sum[i] = a + b + c;

        if(a > b || a > c || b > c)
            del[i] = 0;
        else if(a == b && b == c)
            del[i] =  k + 1;
        else 
            del[i] = min(c - b + 1, b - a + 1);
    }
    auto ok = [&](ll x)
    {
        ll res = 0;
        for(int i = 0; i < n; i++)
        {
            if(sum[i] < x)
                res += x - sum[i] + 2 * del[i];
            
            if(res > k)
                return false;
        }
        return true;
    };
    ll l = -3000000001LL;
    ll r = 2000000000000000000LL;

    while(l < r)
    {
        ll mid = l + (r - l + 1) / 2;
        if(ok(mid))
            l = mid;
        else
            r = mid - 1;
    }
    cout << l << '\n';
}

int main() 
{
    ios::sync_with_stdio(0), cin.tie(0);

    // sieve(); 

    int t;
    cin >> t;
    while (t--) 
    {
        solve();
    }

    return 0;
}
