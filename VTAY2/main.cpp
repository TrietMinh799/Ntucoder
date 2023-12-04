#include <bits/stdc++.h>

using namespace std;

vector<string> ar;
string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;

    const int n = s.size();
    s = s + s;
    for(int i = 0; i < n; i++) {
        ar.push_back(s.substr(i, n));
    }

    sort(ar.begin(), ar.end());

    printf("%s", ar[0].c_str());

    return 0;
}
