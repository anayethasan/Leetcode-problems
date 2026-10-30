#include <bits/stdc++.h>
using namespace std;

/************************************************************
*                                                          *
*  "If talent doesn't work, believe in yourself and        *
*   do hard work. Allah will give you the best gift."      *
*                                                          *
*************************************************************/

const int maxN = 2e5 + 9;
vector<int> adj_list[maxN];
bool vis[maxN];
int level[maxN], parent[maxN];

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;

    while(!q.empty())
    {
        int par = q.front();
        q.pop();

        for(auto child : adj_list[par])
        {
            if(!vis[child])
            {
                q.push(child);
                vis[child] = true;
                level[child] = level[par] + 1;
                parent[child] = par;
            }
        }
    }
}

int main() 
{
    ios::sync_with_stdio(0), cin.tie(0);

    // sieve(); 
    int n, e;
    cin >> n >> e;
    while(e--)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    
    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));
    memset(parent, -1, sizeof(parent));

    int src, dist;
    cin >> src >> dist;

    bfs(src);
    if(level[dist] == -1)
    {
        cout << -1 << '\n';
        return 0;
    }

    cout << level[dist] << '\n';
    vector<int> path;
    int node = dist;
    while(node != -1)
    {
        path.push_back(node);
        node = parent[node];
    }

    reverse(path.begin(), path.end());

    for(auto val : path)
        cout << val << ' ';
    cout << '\n';

    return 0;
}
