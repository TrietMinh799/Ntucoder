#include <bits/stdc++.h>

using namespace std;

const int mod = 1000000;
int n, k, f[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;

    for(int i = 1; i <= k + 1; i++)
        f[i] = i + 1;

    for(int i = k + 1; i <= n; i++)
        f[i] = (f[i - 1] + f[i - k - 1] + 1) % mod;

    cout << f[n] - 2;

    return 0;
}
