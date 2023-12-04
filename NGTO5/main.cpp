#include <bits/stdc++.h>

using namespace std;

int t, n;
bool isPrime(int x) {
    if(x < 2) return false;
    if(x <= 3) return true;
    if(x % 2 == 0 || x % 3 == 0)
        return false;

    for(int i = 5; i * i <= x; i += 6) {
        if(x % i == 0 || x % (i + 2) == 0) {
            return false;
        }
    }

    return true;
}

void solve() {
    cin >> n;
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(__gcd(i, n) == 1)
            cnt++;
    }

    if(isPrime(cnt)) {
        cout << "TRUE\n";
    } else {
        cout << "FALSE\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;

    while(t--)
        solve();

    return 0;
}
