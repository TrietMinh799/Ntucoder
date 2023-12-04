#include <bits/stdc++.h>

using namespace std;

long double n, m, t;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> m >> n >> t;
	
	long double res = ceil(n / m) * t;
	cout << (long long) res;
	
	return 0;
}
