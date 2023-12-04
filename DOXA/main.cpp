#include <bits/stdc++.h>

using namespace std;

int n, a[101], res = 0, x[101], t = 1e5;

void solve() {
    cin >> n;

    for(int i = 0; i < n - 1; i++)
        cin >> a[i];

    for(int i = 0; i < n; i++)
        cin >> x[i];

    for(int i = 0; i < n; i++) {
        t = min(t, x[i]);
        res += t * a[i];
    }

    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}
