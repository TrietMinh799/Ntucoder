#include <iostream>

using namespace std;

int n;

int main() {
  scanf("%d", &n);
  if(n % 2 == 0) {
    printf("-1");
  } else {
    for(int i = 1; i <= n; ++i) {
      printf("%d ", i);
    }
  }
}