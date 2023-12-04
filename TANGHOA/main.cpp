#include <iostream>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

int n, m;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  vector<pii> a;
  if (n < m) {
    while (n - 1 >= 0 && m - 2 >= 0) {
      a.push_back((pii){1, 2});
      n--;
      m -= 2;
    }
    while (n - 2 >= 0 && m - 1 >= 0) {
      a.push_back((pii){2, 1});
      n -= 2;
      m--;
    }
  } else {
    while (n - 2 >= 0 && m - 1 >= 0) {
      a.push_back((pii){2, 1});
      n -= 2;
      m--;
    }
    while (n - 1 >= 0 && m - 2 >= 0) {
      a.push_back((pii){1, 2});
      n--;
      m -= 2;
    }
  }

  printf("%d\n", (int)a.size());

  for (const pii &p : a) {
    printf("%d %d\n", p.first, p.second);
  }
  return 0;
}