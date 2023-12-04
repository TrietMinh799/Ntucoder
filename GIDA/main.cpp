#include <bits/stdc++.h>
using namespace std;

int n, ans = 0, a[100005], b[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;

	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];

	sort(a, a + n);
	sort(b, b + n);

	int j = 0;
	for(int i = 0; i < n; i++) {
		while(j < n && b[i] > a[j]) {
			ans++;
			j++;
			break;
		}
	}

	cout << ans;

	return 0;
}
