#include <bits/stdc++.h>

using namespace std;

int n, a[300005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];

    int k = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i] == n) {
            k = i;
            break;
        }
    }
    int m = n, res = 0;
    while(k > 0) {
        if(a[k] == m) {
            res++;
            m--;
        }
        k--;
    }

    cout << n - res;


    return 0;
}
