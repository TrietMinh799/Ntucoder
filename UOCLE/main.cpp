#include <cmath>
#include <iostream>

using namespace std;

typedef long double lb;

int t;
lb l, r;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> t;

  while (t--) {
    cin >> l >> r;

    long long res = floor(sqrtl(r)) - ceil(sqrtl(l));
    cout << res + 1 << "\n";
  }

  cout.flush();

  return 0;
}