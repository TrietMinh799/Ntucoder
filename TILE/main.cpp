#include <bits/stdc++.h>

using namespace std;

int n, a[101], cnt[101] = {0};

int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] >= ans)
            ans++;
    }

    cout << ans;
    return 0;
}
