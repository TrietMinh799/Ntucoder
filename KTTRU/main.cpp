#include <bits/stdc++.h>

using namespace std;

string s;
long long l, r;
int q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s >> q;
    const int n = s.size();
    while(q--) {
        cin >> l >> r;
        --l, --r;
        l %= n, r %= n;
        if(s[l] == s[r]) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}
