#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
ll a[1001], res = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    while(true) {
        int idx = -1;
        for(int i = 1; i <= n; i++) {
            if(a[i] > 0) {
                idx = i;
                break;
            }
        }

        if(idx == -1) {
            break;
        }
        ll minn = 1e9;
        for(int i = idx; i <= n; i++) {
            if(a[i] <= 0) break;
            minn = min(minn, a[i]);
        }

        for(int i = idx; i <= n; i++) {
            if(a[i] <= 0) break;
            a[i] -= minn;
        }

        res++;
    }

    cout << res;

    return 0;
}
