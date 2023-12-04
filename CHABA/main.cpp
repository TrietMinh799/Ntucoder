#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

typedef long long ll;

ll n, k;
const int mod = 100;
unordered_set<ll> seen;
pmr::vector<ll> ar;
int main() {
  scanf("%lld %lld", &n, &k);
  
  while(seen.find(n) == seen.end()) {
    ar.push_back(n);
    seen.insert(n);
    n = n + n % mod;
  }
  
  k %= mod;
  cout << ar[k];
  
  return 0;
}