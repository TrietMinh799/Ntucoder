#include <bits/stdc++.h>

using namespace std;

int n;
string s;
vector<string> v;

void backtracking(int l, int r, string s) {
    if(s.size() == n) {
        v.push_back(s);
        return;
    }

    if(l < n / 2)
        backtracking(l + 1, r, s + "(");

    if(r < l)
        backtracking(l, r + 1, s + ")");

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    backtracking(0, 0, s);

    for(auto& str : v)
        cout << str << "\n";

    cout << v.size() << "\n";

    return 0;
}
