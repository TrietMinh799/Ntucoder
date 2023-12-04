#include <bits/stdc++.h>

using namespace std;

int n, k;
long long ans = 0, a[100005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n, greater<long long>());
    ans = a[0];
    int j = 0;
    for(int i = 1; i < n; i++) {
        if(a[i] + k <= a[j]) {
            j++;
        } else {
            ans += a[i];
        }
    }

    cout << ans;

    return 0;
}
