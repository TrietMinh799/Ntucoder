
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, src, des, ans = -1, l = 1, r = 1e7;
vector<pair<int, int>> graph[1005];

bool check(int mid)
{
    vector<bool> visited(n + 1);
    queue<pair<int, int>> q;
    q.push({src, -1});

    while (!q.empty())
    {
        pair<int, int> u = q.front();
        q.pop();

        if (u.first == des)
            return true;

        if (visited[u.first])
            continue;
        visited[u.first] = true;
        for (pair<int, int> &v : graph[u.first])
        {
            if (visited[v.first])
                continue;
            if (mid > v.second)
                continue;
            q.push(v);
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> src >> des;

    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        graph[x].push_back(make_pair(y, z));
        graph[y].push_back(make_pair(x, z));
    }

    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (check(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    cout << ans;

    return 0;
}
