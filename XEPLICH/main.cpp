#include <bits/stdc++.h>

using namespace std;

int k, n, a[101][101], dp[101][101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> k >> n;
    for(int i = 1; i <= k; i++)
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];

    for(int i = 1; i <= k; i++) {
        for(int j = 1; j <= n; j++) {
            if(j >= i)
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - 1] + a[i][j]);
        }
    }

    cout << dp[k][n];


    return 0;
}
