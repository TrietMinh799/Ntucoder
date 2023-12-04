#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<string>> ar(110, vector<string>(110, "*"));

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  int cnt = 1;
  for (int i = 1; i <= n / 2 + 1; i++) {
    int k = n / 2 + 1, j = n / 2 + 1;
    while (k >= 1 && j <= n && j - k + 1 <= cnt) {
      ar[i][j] = "D";
      ar[i][k] = "D";
      ar[n - i + 1][j] = "D";
      ar[n - i + 1][k] = "D";
      k--;
      j++;
    }

    cnt += 2;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      printf("%s", ar[i][j].c_str());
    }
    printf("\n");
  }
  return 0;
}
