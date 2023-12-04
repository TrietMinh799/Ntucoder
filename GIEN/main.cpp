#include <bits/stdc++.h>

using namespace std;

int n;
string a, b;
vector<string> v;
void backtracking(string g, vector<char>& chars, int idx) {
    if(g.size() == n) {
        v.push_back(g);
        return;
    }
    for(int i = idx; i < chars.size(); i++) {
        g += chars[i];
        backtracking(g, chars, i + 1);
        g.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    cin >> a;
    cin >> b;

    vector<char> a1, b1;
    unordered_set<char> s;
    string g = "";

    for(int i = 1; i < n; i++) {
        s.insert(a[i]);
        s.insert(b[i]);
    }

    for(auto &st : s)
        b1.push_back(st);

    g = a[0];
    backtracking(g, b1, 0);
    g = b[0];
    backtracking(g, b1, 0);

    sort(v.begin(), v.end());

    cout << v.size() << "\n";
    for(auto &str : v) {
        cout << str << "\n";
    }

    return 0;
}
