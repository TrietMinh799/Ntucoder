#include <bits/stdc++.h>

using namespace std;

long long res = 1, n;
const long long mod = 123456789;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    n--;
    long long a = 2;
    while(n) {
        if(n & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        n /= 2;
    }

    cout << res;

    return 0;
}
