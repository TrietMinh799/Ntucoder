#include <bits/stdc++.h>

using namespace std;

int n, a, pref[1001], sum = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a;
        sum += a;
        pref[i] = sum;
    }

    int maxCounts = 0;
    for(int i = 0; i < n; i++) {
        int x = 2 * pref[i], j = i + 1;
        bool check = false;
        int counts = 1;
        while(j < n) {
            j = lower_bound(pref + j, pref + n, x) - pref;
            if(j != n && pref[j] == x) {
                counts++;
                x += pref[i];
            } else {
                check = true;
                break;
            }
        }
        if(check) {
            maxCounts = max(maxCounts, counts);
            break;
        }
    }

    cout << maxCounts;

    return 0;
}
