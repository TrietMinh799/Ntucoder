#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int n, m, t, k, u, v, c[1110][1110], ways[1110][1110], q;
const int mod = 1e6 + 3;

struct Ex
{
    char type;
    int u, v;
};

Ex ar[10];

void solve()
{
    cin >> u >> v;
    queue<pii> q;

    q.push({n, m});

    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();
        if(x == u && y == v) break;
        if (c[x][y] > t)
            continue;
        for (int i = 1; i <= k; ++i)
        {
            int dx = 0, dy = 0;
            if (ar[i].type == 'L')
            {
                if (ar[i].u > x)
                    continue;
                dx = x - ar[i].u, dy = y + ar[i].v;
            }
            else
            {
                if (ar[i].v > y)
                    continue;
                dx = x + ar[i].u, dy = y - ar[i].v;
            }
            if (ways[dx][dy] > 0 && c[dx][dy] == c[x][y] + 1) {
                ways[dx][dy] = ways[x][y];
                ways[dx][dy] %= mod;
                continue;
            }
            else if (ways[dx][dy] == 0)
            {
                c[dx][dy] = c[x][y] + 1;
                ways[dx][dy] = ways[x][y] + 1;
                ways[dx][dy] %= mod;
                q.push({dx, dy});
            }

        }
    }

    cout << c[u][v] << " " << ways[u][v] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> t >> k;

    for (int i = 1; i <= k; ++i)
        cin >> ar[i].type >> ar[i].u >> ar[i].v;

    cin >> q;
    c[n][m] = 0;
    ways[n][m] = 0;

    while (q--)
    {
        solve();
    }
    return 0;
}
