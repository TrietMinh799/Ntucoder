#include <bits/stdc++.h>

using namespace std;

set<string> st;
vector<bool> visited(11, false);
string s;

void backtracking(string t) {
    if(t.size() == s.size()) {
        st.insert(t);
        return;
    }

    for(int i = 0; i < s.size(); i++) {
        if(!visited[i]) {
            visited[i] = true;
            t += s[i];
            backtracking(t);
            t.pop_back();
            visited[i] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s;

    backtracking("");

    for(auto &str : st)
        cout << str << "\n";


    return 0;
}
