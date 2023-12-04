#include <bits/stdc++.h>

using namespace std;

int n, m, currX, currY, points = 0;
int ar[101][101];
vector<vector<int>> visited(101, vector<int>(101, false));

void floodfill(int r, int c) {
    if(r <= 0 || r > n || c <= 0 || c > m) return;
    if(visited[r][c]) return;
    if(ar[r][c] == 1) return;

    visited[r][c] = true;
    points++;
    floodfill(r, c + 1);
    floodfill(r, c - 1);
    floodfill(r - 1, c);
    floodfill(r + 1, c);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> currX >> currY;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> ar[i][j];

    floodfill(currX, currY);

    cout << points;

    return 0;
}
