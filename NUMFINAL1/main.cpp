#include <cmath>
#include <cstring>
#include <iostream>

using namespace std;

string a, b;

int modulo(int a, string &b) {
  int mod = 0;
  for (int i = 0; i < b.size(); i++)
    mod = (mod * 10 + b[i] - '0') % a;
  return mod;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> a >> b;
  const int n = a.size(), m = b.size();
  if (n == 1 && m == 1 && a[0] == '0' && b[0] == '0') {
    printf("%d", 1);
    return 0;
  }

  if (m == 1 && b[0] == '0') {
    printf("%d", 1);
    return 0;
  }

  if (n == 1 && a[0] == '0') {
    printf("%d", 1);
    return 0;
  }

  int expo = (modulo(4, b) == 0) ? 4 : modulo(4, b);
  int res = pow(a[n - 1] - '0', expo);

  printf("%d", res);

  return 0;
}