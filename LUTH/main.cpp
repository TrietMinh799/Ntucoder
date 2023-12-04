#include <bits/stdc++.h>

using namespace std;

const int mod = 10000;

long long a, b, res = 1;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b;

    while(b) {
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }

    cout << res;

    return 0;
}
