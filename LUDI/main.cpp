#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int n;
pii ar[1001];

bool cmp(const pii &a, const pii &b) {
    return a.second < b.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    for(int i = 1; i <= n; i++)
        cin >> ar[i].first >> ar[i].second;

    sort(ar + 1, ar + 1 + n, cmp);
    int ans = 1, temp = ar[1].second;
    for(int i = 2; i <= n; i++) {
        if(temp < ar[i].first) {
            ans++;
            temp = ar[i].second;
        }
    }

    cout << ans;

    return 0;
}
