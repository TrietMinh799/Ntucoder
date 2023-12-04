#include <bits/stdc++.h>

using namespace std;

int n;
long long ans = 0, k, a[1000005], sum;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }

    //cout << "t:\n";
    for (int i = 1; i <= n; i++)
    {
        int t = upper_bound(a, a + i, a[i] - k) - a;
        //cout << a[i] << " " << t << "\n";
        ans += t;
    }

    cout << ans;

    return 0;
}
