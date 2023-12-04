#include <iostream>

using namespace std;

int n, k, a = 0, b = 0, c = 0;


void hanoiTower(int k, int n, int start, int end) {
  if(k == 0) return;
  if(n == 1) return;
  else {
    int other = 6 - (start + end);
    hanoiTower(k--, n - 1, start, other);
    hanoiTower(k--, n - 1, other, end);
  }
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);cout.tie(NULL);

  cin >> n >> k;

  hanoiTower(k, n, 1, 3);
  
  return 0;
}
