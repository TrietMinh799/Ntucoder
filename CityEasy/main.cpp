#include <iostream>
#include <unordered_map>

using namespace std;

int m, n, k, a[1110][1110], f[1110][1110], c;
unordered_map<int, bool> mp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            f[i][j] = a[i - 1][j] + a[i + 1][j] + a[i][j - 1] + a[i][j + 1] + a[i - 1][j + 1] + a[i - 1][j - 1] + a[i + 1][j - 1] + a[i + 1][j + 1];
            mp[f[i][j]] = true;
        }
    }

    while (k--)
    {
        cin >> c;
        cout << mp[c] << "\n";
    }

    return 0;
}