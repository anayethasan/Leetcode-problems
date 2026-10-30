#include <bits/stdc++.h>
using namespace std;

/************************************************************
*                                                          *
*  "If talent doesn't work, believe in yourself and        *
*   do hard work. Allah will give you the best gift."      *
*                                                          *
*************************************************************/
const int maxN = 1000+5;
char grid [maxN][maxN];
bool vis[maxN][maxN];
int n, m;
vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool valid(int i , int j)
{
    if(i >= n || i < 0 || j >= m || j < 0)
        return false;
    return true;
}

int dfs(int si, int sj)
{
    vis[si][sj] = true;
    int sum = 1;
    for(int i = 0; i < 4; i++)
    {
        int ci = si + dir[i].first;
        int cj = sj + dir[i].second;

        if(valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '.')
            sum += dfs(ci, cj);
    }
    return sum;
}

int main() 
{
    ios::sync_with_stdio(0), cin.tie(0);

    // sieve(); 

    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    memset(vis, false, sizeof(vis));

    int ans = INT_MAX;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(!vis[i][j] && grid[i][j] == '.')
            {
                ans = min(ans, dfs(i, j));
            }
        }
    }

    if(ans == INT_MAX)
        cout << -1 << '\n';
    else
        cout << ans << '\n';

    return 0;
}
