#include <bits/stdc++.h>
using namespace std;

/************************************************************
*                                                          *
*  "If talent doesn't work, believe in yourself and        *
*   do hard work. Allah will give you the best gift."      *
*                                                          *
*************************************************************/

bool check_kth_bit_on_or_off(int n, int k) {
    return ((n >> k) & 1);
}

int turn_on_kth_bit(int n, int k) {
    return (n | (1 << k));
}

int turn_off_kth_bit(int n, int k) {
    return (n & (~(1 << k)));
}

int toggle_kth_bit(int n, int k) {
    return (n ^ (1 << k));
}

map<int, int> prime_factorization(int n) {
    map<int, int> mp;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            mp[i]++;
            n /= i;
        }
    }
    if (n > 1) {
        mp[n]++;
    }
    return mp;
}

bool is_prime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

const int MAXN = 1e5+5;
vector<int> allPrime;
vector<bool> prime(MAXN, true);

void sieve() {
    prime[0] = prime[1] = false;
    for (int i = 2; i * i < MAXN; i++) {
        if (prime[i]) {
            for (int j = i * i; j < MAXN; j += i) {
                prime[j] = false;
            }
        }
    }

    for (int i = 2; i < MAXN; i++) {
        if (prime[i]) allPrime.push_back(i);
    }
}

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
        
        vector<int> ar(n);
        
        for(int i = 0; i < n; i++)
        {
            cin >> ar[i];
        }

        ll m = n - 4;
        map<int, ll> mp;
        for(int i = 0; i < m; i++)
        {
            int val = ar[i] + ar[i+2] - ar[i+4];
            mp[val]++;
        }

        ll ans = 0;
        for(auto [val, c] : mp)
        {
            ans += c * (c - 1) / 2;
        }

        for(int i = 0; i + 2 < m; i++)
        {
            ll val_x = ar[i] + ar[i+2] - ar[i+4];
            ll val_y = ar[i + 2] + ar[i + 4] - ar[i + 6];

            if(val_x == val_y)
                ans--;
        }

        for(int i = 0; i + 4 < m; i++)
        {
            ll val_x = ar[i] + ar[i+2] - ar[i+4];
            ll val_y = ar[i + 4] + ar[i + 6] - ar[i + 8];

            if(val_x == val_y)
                ans--;
        }

        cout << ans << '\n';
    }

    return 0;
}
