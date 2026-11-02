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
        int n;
        cin >> n;
        vector<int> a(n+1);
        bool flag = true;
        ll s = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            s += a[i];
            if (a[i] > 1)
                flag = false;
        }

        if (flag)
        {
            cout << -1 << endl;
            continue;
        }

        for (int i = 2; i <= n - 1; i++)
        {
            if (a[i] > 1)
                flag = true;
        }

        if (flag)
        {
            cout << s - 1 << endl;
        }
        else
        {
            cout << a[1] + a[n] - 1 << endl;
        }
    }

    return 0;
}
