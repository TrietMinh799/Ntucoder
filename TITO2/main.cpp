#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

const int mod = 1e9 + 7;

__uint128_t n, m, res;

long double a, b;

void print(__uint128_t x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9)
    print(x / 10);
  putchar(x % 10 + '0');
}

int main() {
  scanf("%Lf%Lf", &a, &b);

  a = ceil(a);
  b = floor(b);
  long long x = a - 1, y = b;

  n = x, m = y;

  res = m * (m + 1) * (2 * m + 1) / 6 - (n * (n + 1) * (2 * n + 1)) / 6;
  res %= mod;

  print(res);

  return 0;
}
