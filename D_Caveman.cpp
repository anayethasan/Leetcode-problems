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

int n, m;
vector<vector<int>> adj_list(n + 1);
vector<int> degree(n + 1, 0);
vector<int> vis(n + 1, 0);

bool melt = false, many = false;
int comp = 0;

void bfs(int src)
{
    if(vis[src])
        return;

    comp++;

    queue<int> q;
    q.push(src);
    vis[src] = 1;

    int sz = 0;
    int total_deg = 0; 
    int mx_deg = 0;

    while(!q.empty())
    {
        int par = q.front();
        q.pop();

        sz++;
        total_deg += degree[par];
        mx_deg = max(mx_deg, degree[par]);

        for(int child : adj_list[par])
        {
            if(!vis[child])
            {
                vis[child] = 1;
                q.push(child);
            }
        }
    }

    int edges = total_deg / 2;
    if(edges != sz - 1 || mx_deg != sz - 1)
        many = true;
}

int main() 
{
    ios::sync_with_stdio(0), cin.tie(0);

    // sieve(); 

    int t;
    cin >> t;
    while (t--) 
    {
        cin >> n >> m;

        adj_list.assign(n + 1, vector<int>());
        degree.assign(n + 1, 0);
        vis.assign(n + 1, 0);

        melt = false;
        many = false;
        comp = 0;

        while(m--)
        {
            int u, v;
            cin >> u >> v;

            adj_list[u].push_back(v);
            adj_list[v].push_back(u);

            degree[u]++;
            degree[v]++;
        }

        for(int i = 1; i <= n; i++)
        {
            if(degree[i] == 0)
                melt = true;
        }

        if(melt)
        {
            cout << "Brain Melt" << '\n';
            continue;
        }

        for(int i = 1; i <= n; i++)
        {
            if(!vis[i])
                bfs(i);
        }

        if(many || comp > 1)
            cout << "Many" << '\n';
        else
            cout << 2 << '\n';
    }

    return 0;
}
