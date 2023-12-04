#include <bits/stdc++.h>

using namespace std;

int n, tx, ty, dx, dy, grid[10][10];
bool visited[10][10] = {false};

void dfs(int x, int y, bool &flag) {
    if(x <= 0 || x > n || y <= 0 || y > n) return;
    if(flag) return;
    if(visited[x][y]) return;
    if(grid[x][y] == 1) return;

    if(x == dx && y == dy) {
        flag = true;
        return;
    }

    visited[x][y] = true;
    dfs(x + 1, y, flag);
    dfs(x - 1, y, flag);
    dfs(x, y + 1, flag);
    dfs(x, y - 1, flag);
    visited[x][y] = false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> tx >> ty >> dx >> dy;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> grid[i][j];

    grid[tx][ty] = 0;
    bool flag = false;
    dfs(tx, ty, flag);

    if(flag) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
