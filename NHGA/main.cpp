#include <bits/stdc++.h>

using namespace std;

int n, a[200005], ans = 1e9;;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    for(int i = 1; i <= n; i++)
        cin >> a[i];

    sort(a + 1, a + 1 + n);

    for(int i = 2; i <= n; i++) {
        ans = min(ans, a[i] - a[i - 1]);
    }

    cout << ans;

    return 0;
}
