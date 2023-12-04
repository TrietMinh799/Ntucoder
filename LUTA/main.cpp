#include <bits/stdc++.h>

using namespace std;

int n, ans = 0;
long long c;

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> c;

    vector<pair<long long, long long>> a(n);

    for(int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;

    sort(a.begin(), a.end());

    for(int i = 0; i < n; i++) {
        if(c < a[i].first) {
            break;
        }

        c += a[i].second;
        ans++;
    }

    cout << ans;


    return 0;
}
