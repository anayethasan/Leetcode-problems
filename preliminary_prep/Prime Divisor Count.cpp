#include <bits/stdc++.h>
using namespace std;

/************************************************************
*                                                          *
*  "If talent doesn't work, believe in yourself and        *
*   do hard work. Allah will give you the best gift."      *
*                                                          *
*************************************************************/

const int maxN = 1e6 + 9;
int spf[maxN];

void sieve()
{
    for(int i = 2; i < maxN; i++)
    {
        spf[i] = i;
    }

    for(int i = 2; i * i < maxN; i++)
    {
        if(spf[i] == i)
        {
            for(int j = i * i; j < maxN; j += i)
            {
                if(spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}

int main() 
{
    ios::sync_with_stdio(0), cin.tie(0);

    sieve(); 
    int q;
    cin >> q;
    while(q--)
    {
        int x;
        cin >> x;

        int ans = 0;

        while(x > 1)
        {
            int p = spf[x];
            ans++;
            while(x % p == 0)
                x /= p;
        }
        cout << ans << '\n';
    }
    

    return 0;
}
