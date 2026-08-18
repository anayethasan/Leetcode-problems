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
    map<int, int> cnt;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            cnt[i]++;
            n /= i;
        }
    }
    if (n > 1) {
        cnt[n]++;
    }
    return cnt;
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

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == k)
        {
            int mx = nums[0];
            for(int i = 1; i < n; i++)
            {
                mx = max(mx, nums[i]);
            }
            return mx;
        }

        if(k == 1)
        {
            int freq[52] = {0};
            for(int i = 0; i < n; i++)
            {
                freq[nums[i]]++;
            }
            int ans = -1;
            for(int i = 0; i < 52; i++)
            {
                if(freq[i] == 1)
                    ans = i;
            }
            return ans;
        }

        int first = nums[0], last = nums[n-1];
        int first_cnt = 0, last_cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == first)
                first_cnt++;
            if(nums[i] == last)
                last_cnt++;
        }
        int ans = -1;
        if(first_cnt == 1)
            ans = max(first, ans);
        if(last_cnt == 1)
            ans = max(last, ans);

        return ans;
    }
};