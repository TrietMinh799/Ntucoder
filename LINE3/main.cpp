#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

vector<vector<bool>> visited(100, vector<bool>(100, false));
int n, grid[100][100];
vector<vector<int>> dist(100, vector<int>(100, 1e9));
pii dir[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}, par[100][100], src, des;
vector<pii> path;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> src.first >> src.second >> des.first >> des.second;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> grid[i][j];

    dist[src.first][src.second] = 0;
    par[src.first][src.second] = (pii){-1, -1};
    queue<pii> q;
    q.push(src);
    grid[des.first][des.second] = 0;

    while(!q.empty())
    {
        pii u = q.front();
        q.pop();
        if(u == des) break;
        if(visited[u.first][u.second]) continue;
        visited[u.first][u.second] = true;

        for(pii &p : dir)
        {
            pii newdir = {p.first + u.first, p.second + u.second};
            if(newdir.first <= 0 || newdir.first > n || newdir.second <= 0 || newdir.second > n || grid[newdir.first][newdir.second] == 1) continue;
            if(visited[newdir.first][newdir.second]) continue;
            if(dist[newdir.first][newdir.second] > dist[u.first][u.second] + 1)
            {
                dist[newdir.first][newdir.second] = dist[u.first][u.second] + 1;
                par[newdir.first][newdir.second] = u;
            }
            q.push(newdir);
        }
    }

    if(dist[des.first][des.second] == 1e9) {
        cout << 0;
        return 0;
    }


    for(pii v = par[des.first][des.second]; v != (pii){-1, -1}; v = par[v.first][v.second]) {
        path.push_back(v);
    }

    reverse(path.begin(), path.end());
    path.push_back(des);
    cout << path.size() << "\n";
    for(const pii &u : path)
        cout << u.first << " " << u.second << "\n";


    return 0;
}
