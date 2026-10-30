
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl cout << '\n';

const int N = 100005;

vector<int> adj[N];
int a[N], dp[N];
int ans;

void dfs(int u, int parent)
{
    if (parent == 0)
        dp[u] = a[u];
    else
        dp[u] = a[u] ^ dp[parent];

    if (dp[u] == 1)
        ans++;

    for (int v : adj[u])
    {
        if (v != parent)
        {
            dfs(v, u);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    int t;
    cin >> t;

    for (int tc = 1; tc <= t; tc++)
    {
        int n, q;
        cin >> n >> q;

        for (int i = 1; i <= n; i++)
        {
            adj[i].clear();
            dp[i] = 0;
        }

        for (int i = 1; i <= n; i++)
            cin >> a[i];

        for (int i = 1; i < n; i++)
        {
            int u, v;
            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int root = 1;

        cout << "Case " << tc << ":\n";

        while (q--)
        {
            int id, x;
            cin >> id >> x;

            if (id == 1)
                a[x] ^= 1;
            else
                root = x;

            ans = 0;
            dfs(root, 0);

            cout << ans << '\n';
        }
    }

    return 0;
}
