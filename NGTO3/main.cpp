#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1e6 + 11;

int t, n;
vector<bool> sieve(MAXN, true);
vector<int> cnt(MAXN);
void precompute() {

  for (int i = 3; i * i < MAXN; i += 2) {
    if (sieve[i]) {
      for (int j = i * i; j < MAXN; j += 2 * i) {
        sieve[j] = false;
      }
    }
  }

  cnt[1] = 1;
  cnt[2] = 1;

  for (int i = 3; i < MAXN; i += 2) {
    if (sieve[i]) {
      cnt[i] = 1;
    }
  }

  for (int i = 1; i <= MAXN; i++) {
    cnt[i] += cnt[i - 1];
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> t;
  precompute();
  for (int i = 1; i <= t; i++) {
    cin >> n;
    printf("Case #%d: %d\n", i, cnt[n]);
  }
  return 0;
}