#include <bits/stdc++.h>

using namespace std;

int t, n, l;
string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;

    while(t--) {
        cin >> n >> l >> s;

        l %= 2;
        if(l == 0) {
            cout << s << "\n";
            continue;
        }
        for(char &ch : s) {
            if(ch == 'S') ch = 's';
            else ch = 'S';
        }

        cout << s << "\n";
    }

    return 0;
}
