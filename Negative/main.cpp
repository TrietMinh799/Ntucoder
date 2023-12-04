#include <bits/stdc++.h>

using namespace std;

int t, n;

void solve() {
    cin >> n;

    if(n == 0) {
        cout << 1;
        return;
    }

    long long ans = 0;
    int cnt = 0;

    while(n) {
        if(!(n & 1)) {
            ans += pow(2, cnt);
        }
        cnt++;
        n >>= 1;
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}
