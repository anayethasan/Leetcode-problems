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

struct DSU
{
    vector<int> par, siz;
    int c;

    DSU(int n): par(n+1), siz(n+1, 1), c(n)
    {
        for(int i = 1; i <= n; i++)
        {
            par[i] = i;
        }
    }

    int find(int u)
    {
        if(par[u] == u)
            return u;
        return par[u] = find(par[u]);
    }

    bool same(int u, int v)
    {
        return find(u) == find(v);
    }

    void marge(int u, int v)
    {
        u = find(u);
        v = find(v);

        if(u == v)
            return;

        if(siz[u] > siz[v])
            swap(u, v);

        par[u] = v;
        siz[v] += siz[u];
        c--;
    }
};


int main() 
{
    ios::sync_with_stdio(0), cin.tie(0);

    // sieve(); 
    int n, m;
    cin >> n >> m;

    DSU d(n);
    while(m--)
    {
        int u, v;
        cin >> u >> v;
        d.marge(u, v);
    }
    cout << d.c - 1 << '\n';

    return 0;
}
