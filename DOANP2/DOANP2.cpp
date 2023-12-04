#pragma GCC optimize("-O2")

#include <bits/stdc++.h>

using namespace std;

int n;
long long s, d;
map<long long, long long> mp;
map<long long, long long>::iterator itr;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    while(n--) {
        cin >> s >> d;
        itr = mp.find(s);
        if(itr != mp.end()) {
            itr->second = max(itr->second, d);
        } else {
            mp[s] = d;
        }
    }

    itr = mp.begin();
    long long sum = itr->second - itr->first;
    long long Max = itr->second;

    for(++itr; itr != mp.end(); ++itr) {
        if(itr->first >= Max) {
            sum += itr->second - itr->first;
        } else if(itr->second > Max) {
            sum += itr->second - Max;
        }

        Max = max(itr->second, Max);
    }

    cout << sum << "\n";

    return 0;
}
