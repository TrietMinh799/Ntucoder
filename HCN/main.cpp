#include <bits/stdc++.h>

using namespace std;

int n, a[101], b[101], dp[2][101];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

	dp[0][0] = b[0];
	dp[1][0] = a[0];

	for (int i = 1; i < n; ++i) {
		dp[0][i] = b[i] + max(dp[0][i - 1] + abs(a[i] - a[i - 1]), dp[1][i - 1] + abs(a[i] - b[i - 1]));
		dp[1][i] = a[i] + max(dp[0][i - 1] + abs(b[i] - a[i - 1]), dp[1][i - 1] + abs(b[i] - b[i - 1]));
	}

	cout << max(dp[0][n - 1], dp[1][n - 1]);

	return 0;
}
