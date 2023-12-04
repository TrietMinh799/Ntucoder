#include <bits/stdc++.h>

using namespace std;

int a, b, res = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a >> b;

    while(a <= b) {
        a *= 2;
        res++;
    }

    cout << res - 1;
    return 0;
}
