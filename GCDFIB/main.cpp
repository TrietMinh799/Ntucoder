#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll mod, r, l, k;

pair<ll, ll> fib(ll n) {
    if(n == 0) {
        return {0, 1};
    }

    auto p = fib(n >> 1);
    ll c = (p.first % mod) * (2 * p.second % mod - p.first);
    ll d = p.first * p.first + p.second * p.second;
    c %= mod;
    d %= mod;
    if(n & 1) {
        return {d % mod, (c + d) % mod};
    } else {
        return {c % mod, d % mod};
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> mod >> l >> r >> k;

    pair<ll, ll> res = fib((r - l + 1) / k);
    cout << res.second % mod << "\n";

    return 0;
}
