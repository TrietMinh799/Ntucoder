#pragma GCC optimize("O2")

#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> a(1001);
int n, W, val[1001], dp[1001][1001], ans;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> W;

    for(int i = 0; i < n; i++) {
        cin >> a[i].first >> val[i];
        a[i].second = i + 1;
    }

    for(int i = 0; i <= n; i++) {
        for(int w = 0; w <= W; w++) {
            if(i == 0 || w == 0)
                dp[i][w] = 0;
            else if(w - a[i - 1].first >= 0)
                dp[i][w] = max(dp[i - 1][w], val[i - 1] + dp[i - 1][w - a[i - 1].first]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    ans = dp[n][W];

    cout << ans << "\n";

    int w = W;

    for(int i = n; i > 0 && ans > 0; i--) {
        if(ans == dp[i- 1][w])
            continue;
        else {
            cout << a[i - 1].second << " ";
            ans -= val[i - 1];
            w -= a[i - 1].first;
        }
    }

    return 0;
}
