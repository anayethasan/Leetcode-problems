#include <bits/stdc++.h>
using namespace std;

/************************************************************
*                                                          *
*  "If talent doesn't work, believe in yourself and        *
*   do hard work. Allah will give you the best gift."      *
*                                                          *
*************************************************************/


int gcd(int a, int b) {
    if(a % b == 0)
        return b;
    return gcd(b, a % b);    
}

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

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
        
        int x = INT_MAX, y = INT_MAX;
        int ans = 0;

        for(int i = 0; i < n; i++)
        {
            int val;
            cin >> val;

            if(x > y)
                swap(x, y);

            if(val <= x)
            {
                x = val;
            }
            else if(val <= y)
            {
                y = val;
            }
            else
            {
                ans++;
                x = val;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
