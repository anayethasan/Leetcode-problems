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

const int maxN = 2e5 + 9;
ll ar[maxN], tree[maxN * 4];

void build(int node, int b, int e)
{
    if(b == e)
    {
        tree[node] = ar[b];
        return;
    }
    int mid = (b + e) / 2;
    int l = node * 2, r = node * 2 + 1;

    build(l, b, mid);
    build(r, mid + 1, e);

    tree[node] = tree[l] + tree[r];
}

void update(int node, int b, int e, int idx, int val)
{
    if(b == e)
    {
        tree[node] = val;
        return;
    }
    int mid = (b + e) / 2;
    int l = node * 2, r = node * 2 + 1;

    if(idx <= mid)
        update(l, b, mid, idx, val);
    else
        update(r, mid + 1, e, idx, val);

    tree[node] = tree[l] + tree[r];
}

ll query(int node, int b, int e, int i, int j)
{
    if(e < i || b > j)
        return 0;

    if(b >= i && e <= j)
        return tree[node];

    int mid = (b+e)/2;
    return query(node * 2, b, mid, i, j) + query(node * 2 + 1, mid + 1, e, i, j);
}

int main() 
{
    ios::sync_with_stdio(0), cin.tie(0);

    // sieve(); 
    int n, q;
    cin >> n >> q;

    for(int i = 1; i <= n; i++)
        cin >> ar[i];
    
    build(1, 1, n);

    while(q--)
    {
        int tp;
        cin >> tp;

        if(tp == 1)
        {
            int i, x;
            cin >> i >> x;
            update(1, 1, n, i, x);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << '\n';
        }
    }

    return 0;
}
