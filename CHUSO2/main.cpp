#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll p, x, i;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> p;

    for(i = 1; i <= 14; i++) {
        x = 9 * i * pow(10, i - 1);
        if(p - x >= 0) {
            p -= x;
        } else {
            break;
        }
    }

    x = (ll) pow(10, i - 1) + p / i - 1;
    p %= i;

    if(!p) {
        cout << x % 10;
    } else {
        x++;
        string s = to_string(x);
        cout << s[p - 1];
    }

    return 0;
}
