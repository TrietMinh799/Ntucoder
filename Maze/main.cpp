#include <bits/stdc++.h>

using namespace std;

int n, m;
pair<int, int> des;
pair<int, int> directions[3] = {{1,0}, {-1, 0}, {0, 1}};
string direction = "";

void bfs() {

    queue<pair<int, int>> q;

    q.push(make_pair{1, 1});

    while(!q.empty()) {
        q.empty();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> grid[i][j];
        }
    }

    cin >> des.first >> des.second;

    return 0;
}
