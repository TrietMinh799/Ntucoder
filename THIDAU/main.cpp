#include <iostream>

using namespace std;

int n, k, a[110], b[110], f[110], ans = 0;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k;

  for(int i = 1; i <= n; i++)
    cin >> a[i];

  for(int i = 1; i <= n; i++)
    cin >> b[i];

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j < n; j++) {
      if(a[i] - a[j] >= k) {
        f[i] = max(f[i], f[j]);
      }
    }
    f[i] += b[i];
    ans = max(ans, f[i]);
  }

  cout << ans;

  return 0;
}
