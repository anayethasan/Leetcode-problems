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
vector<int> adj_list[maxN];
bool vis[maxN];

void dfs(int src) 
{
    vis[src] = true;

    for(auto child : adj_list[src])
    {
        if(!vis[child])
            dfs(child);
    }
}

int main() 
{
    ios::sync_with_stdio(0), cin.tie(0);

    // sieve(); 
    int n, m;
    cin >> n >> m;

    while(m--)
    {
        int u, v;
        cin >> u >> v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    int ans = 0;

    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            ans++;
            dfs(i);
        }
    }
    cout << ans << '\n';

    return 0;
}
