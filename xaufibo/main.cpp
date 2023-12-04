#include <bits/stdc++.h>

#define ll long long

using namespace std;

int t, n;
ll k, f[46] = {1, 1}, dp[46] = {1, 0};

ll cal(int n, ll k) {
    if(n == 0) return 1;
    if(n == 1) return 0;

    if(f[n - 2] >= k) return cal(n - 2, k);
    return dp[n - 2] + cal(n - 1, k - f[n - 2]);
}

void solve() {
    cin >> n >> k;

    cout << cal(n, k) << "\n";
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;

    for(int i = 2; i <= 45; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
        f[i] = f[i - 1] + f[i - 2];
    }

    while(t--) solve();

    return 0;
}
