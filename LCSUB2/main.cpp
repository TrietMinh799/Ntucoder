#include <bits/stdc++.h>

using namespace std;

int n, k, ans = 1, cnt[100005] = {0}, a[100005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;

    for(int i = 0; i < k; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    };

    sort(a, a + k);

    if(cnt[0] == 0) {
        vector<int> v;
        v.push_back(a[0]);
        int length = 1, ans = 1;
        for(int i = 1; i < k; i++) {
            if(a[i] == v.back() + 1) {
                length++;
            } else {
                length = 1;
            }
            v.push_back(a[i]);
            ans = max(ans, length);
        }
        cout << ans;
    } else {
        vector<vector<int>> vs;
        vector<int> v, h;
        v.push_back(a[1]);
        a[k] = 1e9;
        for(int i = cnt[0]; i <= k; i++) {
            if(a[i] == v.back() + 1) {
                v.push_back(a[i]);
            } else {
                vs.push_back(v);
                v.clear();
                v.push_back(a[i]);
            }
        }

        for(int i = 0; i < vs.size() - 1; i++) {
            int temp = cnt[0], j = i + 1, length = vs[i].size();
            int curr1 = vs[i].size() + cnt[0],
                curr2 = vs[i + 1].size() + cnt[0];
            ans = max({ans, curr1, curr2});
            while(temp && j < vs.size()) {
                temp -= vs[j][0] - vs[j - 1].back();
                if(temp >= 0) {
                    length += vs[j].size();
                    ans = max(ans, length);
                }
                j++;
            }
        }

        cout << ans + 1;
    }

    return 0;
}
