#include <bits/stdc++.h>

using namespace std;

int n, m, srcX, srcY, grid[21][21];
bool visited[21][21];
pair<int, int> previous[2001][2001];
vector<pair<int, int>> directions = {{1, 0}, {0, 1}};


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> grid[i][j];

    cin >> srcX >> srcY;

    queue<pair<int, int>> q;
    pair<int, int> endLocate = make_pair(srcX, srcY);

    q.push({1, 1});

    while(!q.empty()) {
        pair<int, int> u = q.front();
        q.pop();
        if(u == endLocate) {
            break;
        }
        visited[u.first][u.second] = true;
        for(pair<int, int> &e : directions) {
            pair<int, int> newDir = {u.first + e.first, u.second + e.second};
            if(newDir.first > 0 && newDir.first <= n && newDir.second > 0 && newDir.second <= m) {
                if(!visited[newDir.first][newDir.second] && grid[newDir.first][newDir.second] == 0) {
                    visited[newDir.first][newDir.second] = true;
                    previous[newDir.first][newDir.second] = newDir;
                    q.push(newDir);
                }
            }
        }
    }

    if(!visited[srcX][srcY]) {
        cout << 0 << "\n";
        return 0;
    }


    return 0;
}
