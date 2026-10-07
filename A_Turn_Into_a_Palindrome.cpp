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
        char c;
        string s;
        cin >> n >> c;

        cin >> s;
        int ans = 0;
        for(int i = 0; i < n / 2; i++)
        {
            int j = n - i - 1;

            if(s[i] == s[j])
                continue;

            if(s[i] == c || s[j] == c)
                ans += 1;
            else
                ans += 2;            
        }
        cout << ans << '\n';
    }

    return 0;
}
