#include <bits/stdc++.h>

using namespace std;

int n, m;
int grid[101][101];
bool visited[101][101] = {false};
int track[101][101] = {0}, dist[101][101] = {1e9};
pair<int, int> dir[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
pair<int, int> src, des;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> src.first >> src.second >> des.first >> des.second;
    queue<pair<int, int>> q;
    q.push(src);
    visited[src.first][src.second] = true;
    dist[src.first][src.second] = true;

    while(!q.empty()) {
        pair<int, int> u = q.front();
        q.pop();

        if(u == des) {
            break;
        }
    }

    return 0;
}
