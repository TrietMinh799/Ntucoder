#include <bits/stdc++.h>

using namespace std;

int n, m, k, a[110];
unsigned long long f[110][11000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> k;

    for(int i = 1; i <= n; i++) cin >> a[i];

    f[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            if(j >= a[i]) {
                f[i][j] = f[i - 1][j] + f[i - 1][j - a[i]];
            } else {
                f[i][j] = f[i - 1][j];
            }
        }
    }

    if(f[n][m] < k)
        cout << f[n][m];
    else
        cout << "ENOUGH";

    return 0;
}
