#include <bits/stdc++.h>

using namespace std;

int t;
string s, r = "";

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s >> t;

    for(char ch : s) {
        int order = ch - 'a';
        if(order - t < 0) {
            r += ((order - t) + 26) + 'a';
        } else {
            r += (order - t) + 'a';
        }
    }

    cout << s;

    return 0;
}
