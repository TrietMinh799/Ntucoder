#include <bits/stdc++.h>

using namespace std;

int n, ans = 0;

struct Tivi {
    int start, ends;
};

bool cmp(Tivi &tivi1, Tivi &tivi2) {
    return tivi1.start < tivi2.start;
}

int find_lowerbound(vector<Tivi> &ar, int idx, int x) {
    int low = idx, high = ar.size();
    while(low < high) {
        int mid = low + (high - low) / 2;
        if(ar[mid].start >= x) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    if(low < n && ar[low].start < x) {
       low++;
    }
    return low;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    vector<Tivi> ar(n);

    for(int i = 0; i < n; i++)
        cin >> ar[i].start >> ar[i].ends;

    sort(ar.begin(), ar.end(), cmp);

    for(int i = 0; i < n - 1; i++) {
        int k = find_lowerbound(ar, i + 1, ar[i].ends);
        if(k == n + 1) continue;

        ans += k - i - 1;
    }

    cout << ans;


    return 0;
}
