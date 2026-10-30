#include <bits/stdc++.h>
using namespace std;

char grid[1005][1005];
bool vis[1005][1005];
int level[1005][1005];

vector<pair<int, int>> dir = {
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}
};

int n, m;

bool valid(int x, int y)
{
    if(x < 0 || x >= n || y < 0 || y >= m)
        return false;

    return true;
}

void bfs(int sr, int sc)
{
    queue<pair<int, int>> q;
    q.push({sr, sc});

    vis[sr][sc] = true;
    level[sr][sc] = 0;

    while(!q.empty())
    {
        auto par = q.front();
        q.pop();

        int pi = par.first;
        int pj = par.second;

        for(int i = 0; i < 4; i++)
        {
            int ci = pi + dir[i].first;
            int cj = pj + dir[i].second;

            if(valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] != '#')
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                level[ci][cj] = level[pi][pj] + 1;
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    int si = -1, sj = -1;
    int di = -1, dj = -1;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> grid[i][j];

            if(grid[i][j] == 'R')
            {
                si = i;
                sj = j;
            }

            if(grid[i][j] == 'D')
            {
                di = i;
                dj = j;
            }
        }
    }

    memset(level, -1, sizeof(level));

    bfs(si, sj);

    cout << level[di][dj] << '\n';

    return 0;
}