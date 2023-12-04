#include <bits/stdc++.h>

using namespace std;

int t, x, cnt[7] = {0, 1, 1, 1, 2, 1, 2};
void solve() {
    cin >> x;

    if(x < 2) {
        cout << -1 << "\n";
    } else {
        cout << cnt[x % 7] + x / 7 << "\n";
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;

    while(t--) solve();
    return 0;
}
