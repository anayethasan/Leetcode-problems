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
        string s;
        cin >> s;

        int one = 0, zero = 0;

        for(auto ch : s)
        {
            if(ch == '0')
                zero++;
            else
                one++;
        }

        cout << ( min(zero, one) % 2 == 0 ? "NET" : "DA") << '\n';
    }

    return 0;
}
