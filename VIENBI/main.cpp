#include <bits/stdc++.h>

using namespace std;

long long a, b, c;


int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> a >> b >> c;
	
	if(b == c) {
		cout << "YES";
	} else if(b > c) {
		long long diff = b - c;
		if(diff % 2 == 1) {
			cout << "YES\n";
		}
	} else {
		
	}
	
	return 0;
}
