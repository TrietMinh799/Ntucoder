#include <bits/stdc++.h>

using namespace std;

int n;
vector<bool> visited(10, false);

void backtracking(vector<vector<int>>& ans, vector<int>& permus) {
    if(permus.size() == n) {
        ans.push_back(permus);
        return;
    }

    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            visited[i] = true;
            permus.push_back(i);
            backtracking(ans, permus);
            permus.pop_back();
            visited[i] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    vector<vector<int>> ans;
    vector<int> permus;
    backtracking(ans, permus);

    cout << ans.size() << "\n";

    for(auto x : ans) {
        for(auto e : x)
            cout << e;
        cout << "\n";
    }

    return 0;
}
