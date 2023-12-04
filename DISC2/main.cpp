#include <iostream>
#include <list>

using namespace std;

int n, m, x;
list<int> l;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    l.push_front(i);
  }

  for (int i = 0; i < m; i++) {
    cin >> x;
  }

  return 0;
}
