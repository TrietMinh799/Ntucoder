#include <iostream>
#include <unordered_map>

using namespace std;

int n;
long long b, a[100005], ans = 0;
;
unordered_map<long long, long long> mp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> b;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (mp[b - a[i]] != 0)
        {
            ans += mp[b - a[i]];
        }
        mp[a[i]]++;
    }

    cout << ans;

    return 0;
}