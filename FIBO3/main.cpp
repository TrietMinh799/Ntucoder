#include <bits/stdc++.h>

using namespace std;

long long n;
const long long mod = 1e6 + 7;

pair<long long, long long> fib(long long n)
{
    if(n == 0)
        return {0, 1};

    auto p = fib(n >> 1);
    long long c = (p.first % mod) * (2 * p.second % mod - p.first);
    long long d = (p.first % mod) * p.first + (p.second % mod) * p.second;
    d %= mod;
    c %= mod;
    if(n & 1)
        return {d, c + d};
    else
        return {c, d};
}

void solve()
{
    pair<long long, long long> ans = fib(n);
    cout << ans.first;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    solve();

    return 0;
}
