#include <bits/stdc++.h>

using namespace std;

long long a, b, n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> a >> b;

    if(n % __gcd(a, b) != 0) {
        cout << -1;
    } else {
        for(long long i = n / b; i >= 0; i--) {
            if((n - b * i) % a == 0) {
                cout << i + (n - i * b) / a;
                return 0;
            }
        }

        cout << -1;
    }

    return 0;
}
