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

const vector<int> T = {0, 3, 5, 6, 9, 10, 12, 15};

int work(int x)
{
    return (*lower_bound(T.begin(), T.end(), x)) == x;
}

int main() 
{
    ios::sync_with_stdio(0), cin.tie(0);

    // sieve(); 

    int t;
    cin >> t;
    while (t--) 
    {
        int n, q;
        cin >> n >> q;

        vector<int> ar(n);
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> ar[i];
            ar[i] = work(ar[i]);
            ans += ar[i];
        }

        cout << ans << ' ';
        while(q--)
        {
            int p, x;
            cin >> p >> x;

            p--;
            x = work(x);
            ans -= ar[p];
            ar[p] = x;
            ans += ar[p];

            cout << ans << " ";
        }
        nl;
    }

    return 0;
}
