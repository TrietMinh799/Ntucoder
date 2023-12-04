#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

typedef long long ll;

int n;
ll x;

int countZero(ll x) {
  int cnt = 0;
  while (x % 10 == 0) {
    x /= 10;
    cnt++;
  }
  return cnt;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;

  while (n--) {
    cin >> x;
    ll cnt5 = 0, cnt2 = 0;
    ll temp = x;
    while (temp % 5 == 0) {
      temp /= 5;
      cnt5++;
    }

    while (temp % 2 == 0) {
      temp /= 2;
      cnt2++;
    }

    cnt5 -= cnt2;
    if (cnt5 <= 0) {
      printf("%lld\n", x);
      continue;
    }
    ll t = cnt5 / 2;
    cnt5 %= 2;

    if (cnt5)
      t++;
    ll newnums = x * (ll)pow(4, t);
    int cnt1 = countZero(newnums), cnt = countZero(x);
    if (cnt1 > cnt)
      printf("%lld \n", newnums);
    else
      printf("%lld \n", x);
  }
  return 0;
}