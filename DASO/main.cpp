#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3e4 + 10;
int n, a[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    for(int i = 1; i <= n; i++) cin >> a[i];
    int ans = 0;

    int cur = 3;
    while(cur <= n) {
        int pre = 2;
        while(a[cur] == a[cur - 1] + a[cur - 2]) {
            cur++;
            pre++;
        }
        cur++;
        ans = max(ans, pre);
    }

    cout << (ans == 2 ? -1 : ans);


    return 0;
}
