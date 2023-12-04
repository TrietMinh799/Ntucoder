#include <bits/stdc++.h>

using namespace std;

int t, n, x, y;
pair<int, int> dir[4] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};

void generate_sprial(vector<vector<int>> &grid, int n)
{
    int val=0;
    int top=0,right=n-1,left=0,bottom=n-1;
    while(top<=bottom && left<=right)
    {
        for(int i=left; i<=right; i++)
        {
            grid[top][i]=++val;

        }
        top++;
        for(int i=top; i<=bottom; i++)
        {
            grid[i][right]=++val;

        }
        right--;
        if(top<bottom)
        {
            for(int i=right; i>=left; i--)
            {
                grid[bottom][i]=++val;

            }
            bottom--;
        }
        if(left<right)
        {
            for(int i=bottom; i>=top; i--)
            {
                grid[i][left]=++val;
            }
            left++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;

    while (t--)
    {
        cin >> n >> x >> y;
        vector<vector<int>> grid(n, vector<int>(n));
        generate_sprial(grid, n);
        queue<pair<int, int>> q;
        pair<int, int> src, des;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == x)
                {
                    src = make_pair(i, j);
                }

                if (grid[i][j] == y)
                {
                    des = make_pair(i, j);
                }
            }
        }
        q.push(src);
        vector<vector<int>> dist(1001, vector<int>(1001, 10000000));
        bool visited[1001][1001] = {false};
        dist[src.first][src.second] = 0;
        while (!q.empty())
        {
            pair<int, int> u = q.front();
            q.pop();

            if (u == des)
                break;

            for (pair<int, int> &p : dir)
            {
                pair<int, int> newdir = {p.first + u.first, p.second + u.second};
                if (newdir.first < 0 || newdir.first >= n || newdir.second < 0 ||
                        newdir.second >= n)
                    continue;
                if (visited[newdir.first][newdir.second])
                    continue;

                if (__gcd(grid[newdir.first][newdir.second], grid[u.first][u.second]) !=
                        1)
                    continue;

                visited[newdir.first][newdir.second] = true;
                q.push(newdir);
                dist[newdir.first][newdir.second] = dist[u.first][u.second] + 1;
            }
        }

        if (dist[des.first][des.second] == 10000000)
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << dist[des.first][des.second] << "\n";
        }

    }

    return 0;
}
