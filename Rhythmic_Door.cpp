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
        string s;
        cin >> s;
        int ans = 0, consv_cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(i == 0 || s[i] != s[i-1])
                consv_cnt = 1;
            else 
                consv_cnt++;

            if(consv_cnt == 3)
            {
                ans++;
                consv_cnt = 0;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
