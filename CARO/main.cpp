#include <bits/stdc++.h>

using namespace std;

int n;
char grid[21][21];

string ans = "Not yet";

bool check(char ch, int x, int y)
{
    int cnt = 0;
    for(int i = x; i < n; i++)
    {
        if(grid[i][y] != ch) break;
        cnt++;
    }
    if(cnt == 5) return true;
    cnt = 0;
    for(int i = x; i >= 0; i--)
    {
        if(grid[i][y] != ch) break;
        cnt++;
    }
    if(cnt == 5) return true;
    cnt = 0;
    for(int i = y; i >= 0; i--)
    {
        if(grid[x][i] != ch) break;
        cnt++;
    }
    if(cnt == 5) return true;
    cnt = 0;
    for(int i = y; i < n; i++)
    {
        if(grid[x][i] != ch) break;
        cnt++;
    }
    if(cnt == 5) return true;
    cnt = 0;
    int i = x, j = y;
    while(i < n && j < n)
    {
        if(grid[i][j] != ch) break;
        cnt++;
        i++;
        j++;
    }

    if(cnt == 5) return true;
    i = x, j = y;
    cnt = 0;
    while(i >= 0 && j >= 0)
    {
        if(grid[i][j] != ch) break;
        cnt++;
        i--;
        j--;
    }
    if(cnt == 5) return true;
    i = x, j = y;
    cnt = 0;
    while(i < n && j >= 0)
    {
        if(grid[i][j] != ch) break;
        cnt++;
        i++;
        j--;
    }
    if(cnt == 5) return true;
    i = x, j = y;
    cnt = 0;
    while(i >= 0 && j < n)
    {
        if(grid[i][j] != ch) break;
        cnt++;
        i--;
        j++;
    }
    if(cnt == 5) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> grid[i][j];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(grid[i][j] == '.') continue;
            if(grid[i][j] == 'o' && check(grid[i][j], i, j))
            {
                ans = "Teo wins";
                cout << ans;
                return 0;
            }
            else if(grid[i][j] == 'x' && check(grid[i][j], i, j))
            {
                ans = "Ti wins";
                cout << ans;
                return 0;
            }
        }
    }

    cout << ans;

    return 0;
}
