#include <bits/stdc++.h>

using namespace std;

int x, n, res = 0;
multiset<int> m1, m2, w1, w2;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> x;
        if(x <= 0) {
            m2.insert(abs(x));
        } else {
            m1.insert(x);
        }
    }

    for(int i = 1; i <= n; i++) {
        cin >> x;
        if(x <= 0)
            w2.insert(abs(x));
        else
            w1.insert(x);
    }

    for(auto &it : w2) {
        auto itr = m1.upper_bound((it));
        --itr;
        if(itr == m1.end()) {
            continue;
        } else {
            m1.erase(itr);
            ++res;
        }
    }

    for(auto it : w1) {
        auto itr = m2.upper_bound((it));
        if(itr == m2.end()) {
            continue;
        } else {
            m2.erase(itr);
            ++res;
        }
    }

    printf("%d", res);

    return 0;
}
