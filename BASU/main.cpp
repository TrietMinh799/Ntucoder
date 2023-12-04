#include <bits/stdc++.h>

using namespace std;

vector<vector<char>> a(10, vector<char>(10));


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i = 1; i <= 7; i++)
        for(int j = 1; j <= 7; j++)
            cin >> a[i][j];

    for(int i = 1; i <= 7; i++) {
        for(int j = 1; j <= 7; j++) {
            if(a[i][j] == '.') continue;
        }
    }

    return 0;
}
