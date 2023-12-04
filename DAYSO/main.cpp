#include <climits>
#include <iostream>

using namespace std;

typedef long long ll;

int n;
ll a[1011], f[1011], t[1011], res = LLONG_MIN;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;

  for (int i = 1; i <= n; i++)
    cin >> a[i];

  for (int i = 3; i <= n; i++)
    t[i] = a[i] + a[i - 1] + a[i - 2];

  for (int i = 3; i <= n; i++) {
    f[i] = max(t[i], f[i - 3] + t[i]);
    res = max(res, f[i]);
  }

  cout << res;
  cout.flush();
  return 0;
}