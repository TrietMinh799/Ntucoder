#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, m, res = LONG_MAX;

ll solve(ll x)
{
  ll ret = 0, nn = n;
  while (nn /= x)
    ret += nn;

  return ret;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  ll cnt = 0;
  while (m % 2 == 0)
  {
    ++cnt;
    m /= 2;
  }
  if (cnt > 0)
    res = min(res, solve(2) / cnt);
  for (ll i = 3; i * i <= m; i += 2)
  {
    cnt = 0;
    while (m % i == 0)
    {
      m /= i;
      ++cnt;
    }
    if (cnt > 0)
    {
      res = min(res, solve(i) / cnt);
    }
  }

  if (m > 2)
    res = min(res, solve(m));

  printf("%lld", res);
  return 0;
}