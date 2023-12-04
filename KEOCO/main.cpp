#include <bits/stdc++.h>

using namespace std;

int n, a[110], totalSum = 0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        totalSum += a[i];
    }

    vector<vector<bool>> f(n + 1, vector<bool>(totalSum + 1));

    for(int i = 0; i <= n; i++)
        f[i][0] = true;

    for(int i = 1; i <= totalSum; i++)
        f[0][i] = false;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= totalSum; j++) {
            f[i][j] = f[i - 1][j];
            if(j >= a[i - 1]) {
                f[i][j] = f[i][j] | f[i - 1][j - a[i - 1]];
            }
        }
    }

    for(int i = totalSum / 2; i >= 0; i--) {
        if(f[n][i]) {
            cout << i << " " << totalSum - i;
            return 0;
        }
    }

    return 0;
}
