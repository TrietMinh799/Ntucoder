#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int MAXN = 1100, mod = 1e9;
int n, a[MAXN];
vector<ll> f(MAXN, -1);
int solve(int i, int type)
{
    if (a[i] == 2)
        return 0;
    if (a[i] == 1 && type != 0)
        return 0;
    if(i > n + 1) return 0;
    if (i == n + 1)
        return 1;
    if(f[i] != -1)
        return f[i];
    f[i + 1] = solve(i + 1, 0) % mod;
    f[i + 2] = solve(i + 2, 1) % mod;
    if(a[i] == 1)
    {
        f[i] = f[i + 1] + f[i + 2];
        f[i] %= mod;
        return f[i];
    }
    else
    {
        f[i + 3] = solve(i + 3, 2) % mod;
        f[i] = f[i + 1] + f[i + 2] + f[i + 3];
        f[i] %= mod;
        return f[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    a[n + 1] = 0;

    cout << solve(0, 0) % mod;
    return 0;
}
