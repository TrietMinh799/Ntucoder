#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int n;
ll a[100011], f[100011], s[100011], res = LLONG_MIN;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 3; i <= n; i++)
        s[i] = a[i] + a[i - 1] + a[i - 2];

    for(int i = 3; i <= n; i++) {
        f[i] = max(s[i], f[i - 3] + s[i]);
        res = max(res, f[i]);
    }

    cout << res;

    return 0;
}
