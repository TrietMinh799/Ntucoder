#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, a, b, res = 0;
vector<pair<int, int>> ar;

bool cmp(pair<int, int> a, pair<int, int> b) {
  if(a.second == b.second)
    return a.first > b.first;
  return a.second > b.second;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;

  for(int i = 0; i < n; i++) {
    cin >> a >> b;
    ar.push_back(make_pair(a, b));
  }

  sort(ar.begin(), ar.end(), cmp);

  b = 0;

  res = ar[0].first;
  b = ar[0].second;

  for(int i = 1; i < n; i++) {

    if(b <= 0)
      break;

    res += ar[i].first;
    b = b - 1 + ar[i].second;
  }

  cout << res << endl;

  return 0;
}
