#include <bits/stdc++.h>

using namespace std;

int n;
int a[100005], b[100005], c[100005];
map<int, long long> mp1, mp2, mp3;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mp1[a[i]]++;
    }

    for(int i = 0; i < n; i++) {
        cin >> b[i];
        mp2[b[i]]++;
    }

    for(int i = 0; i < n; i++) {
        cin >> c[i];
        mp3[c[i]]++;
    }

    long long ans = 0;

    for(auto &it : mp1) {
        ans += it.second * mp2[it.first] * mp3[it.first];
    }

    cout << ans;

    return 0;
}
