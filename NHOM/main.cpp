#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
int n, t, a[MAXN], k;

void solve(int ts) {
    cin >> n >> k;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a + 1, a + 1 + n);
    int ans = 1;
    for(int i = 2; i <= n; i++) {
        if(a[i] - a[i - 1] <= k) continue;
        else {
            ans++;
        }
    }

    cout << "Case #" << ts << ": " << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;

    for(int ts = 1; ts <= t; ts++) {
        solve(ts);
    }

    return 0;
}
