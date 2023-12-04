#include <iostream>

using namespace std;

typedef long long ll;

ll n;
const int mod = 1e6;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;

  ll i = 1, res = 0;
  while (i <= n) {
    ll val = n / i;
    ll last = (n / val);
    res += (last - i + 1) * val;
    res %= mod;
    i = last + 1;
  }

  printf("%lld", res % mod);

  return 0;
}