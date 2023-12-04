#include <bits/stdc++.h>

using namespace std;

int l, r, n, m, zero = 0, negative = 0, a, countsZero[200005], countsNegative[200005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;

    countsZero[0] = countsNegative[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a;
        if(a == 0) {
            zero++;
        } else if(a < 0) {
            negative++;
        }

        countsZero[i] = zero;
        countsNegative[i] = negative;
    }

    while(m--) {
        cin >> l >> r;

        if(countsZero[r] - countsZero[l - 1] > 0) {
            cout << 0 << "\n";
        } else if((countsNegative[r] - countsNegative[l - 1]) % 2 == 1) {
            cout << "-" << "\n";
        } else {
            cout << "+" << "\n";
        }
    }

    return 0;
}
