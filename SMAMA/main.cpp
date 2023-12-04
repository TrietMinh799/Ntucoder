#include <bits/stdc++.h>

using namespace std;

int k;
string ans = "";

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> k;
    while(k > 0) {
        if(k & 1) {
            ans = "4" + ans;
            k >>= 1;
        } else {
            ans = "7" + ans;
            --k;
            k >>= 1;
        }
    }

    cout << ans;
    return 0;
}
