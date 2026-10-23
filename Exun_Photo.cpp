#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;

template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

        vector<int> ar(n+1);
        for(int i = 1; i <= n; i++)
        {
            cin >> ar[i];
        }

        bool sorted = true;
        
        for (int i = 1; i <= n; i++)
        {
            if (ar[i] != n - i + 1)
            {
                sorted = false;
                break;
            }
        }

        if (sorted)
        {
            cout << 0 << '\n';
            continue;
        }

        if(k == 1)
        {
            cout << -1 << '\n';
            continue;
        }

        pbds<ll> pb;

        ll jmp = k - 1;
        ll ans = 0;

        for (ll i = 1; i <= n; i++)
        {
            ll curr = ar[i];

            ll sml = pb.order_of_key(curr);

            ans += (sml + jmp - 1) / jmp;

            pb.insert(curr);
        }

        cout << ans << '\n';

    }

    return 0;
}
