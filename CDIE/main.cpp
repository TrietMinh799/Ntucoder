#include <bits/stdc++.h>

using namespace std;

int n, k, res = 0, a[101];

void solve() {
    cin >> n >> k;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n, greater<int>());
    res = a[0];
    if(k == 1) {
       cout << 0;
       return;
    }
    if(n == 1 && res < k) {
        cout << -1;
        return;
    }
    if(res >= k) {
        cout << 1;
        return;
    }

    for(int i = 1; i < n; i++) {
        res += (a[i] - 1);
        if(res >= k) {
            cout << i + 1;
            return;
        }
    }

    cout << -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();


    return 0;
}
