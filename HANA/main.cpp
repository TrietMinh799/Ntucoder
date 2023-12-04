#include <bits/stdc++.h>

using namespace std;

int n, m, grid[21][21];
bool visited[21][21] = {false};
vector<pair<int, int>> paths;
bool ok = false;
int dx[2] = {0, 1};
int dy[2] = {1, 0};

bool check() {
    int counts[4] = {0}, c = 0;
    for(pair<int, int> &p : paths)
        counts[grid[p.first][p.second]]++;

    for(int i = 1; i <= 3; i++) {
        if(counts[i] > 0) {
            c++;
        }
    }

    if(c > 1) return true;
    return false;
}

void dfs(int i, int j) {
    if(i == n && j == m) {
        if(check() && !ok) {
            for(pair<int, int> &p : paths)
                cout << p.first << " " << p.second << "\n";
            ok = true;

        }
        return;
    }
    visited[i][j] = true;
    for(int x = 0; x < 2; x++) {
        int newx = dx[x] + i;
        int newy = dy[x] + j;
        if(newx <= 0 || newx > n || newy <= 0 || newy > m) continue;
        if(visited[newx][newy]) continue;
        if(grid[newx][newy] == -1) continue;
        paths.push_back(make_pair(newx, newy));
        dfs(newx, newy);
        paths.pop_back();
    }

    visited[i][j] = false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> grid[i][j];
    paths.push_back(make_pair(1, 1));
    dfs(1, 1);

    if(!ok) {
        cout << -1;
    }

    return 0;
}
