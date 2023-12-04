#include <iostream>

using namespace std;

int n, a, x, y;

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;

  while(n--) {
    cin >> a;
    if(a == 100)
      x++;
    else
      y++;
  }

  if(x % 2 == 1) {
    cout << "NO";
  } else {
    if(y % 2 == 0) {
        cout << "YES";
    } else {
      if(x != 0) {
        cout << "YES";
      } else {
        cout << "NO";
      }
    }
  }


  return 0;
}
