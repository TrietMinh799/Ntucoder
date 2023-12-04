#include <bits/stdc++.h>

using namespace std;

int n;

void backtracking(vector<vector<int>>& ans, vector<int>& subset) {
    if(subset.size() == n) {
        ans.push_back(subset);
        return;
    }

    for(int i = 0; i <= 1; i++) {
        subset.push_back(i);
        backtracking(ans, subset);
        subset.pop_back();
    }

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    vector<vector<int>> ans;
    vector<int> subset;

    backtracking(ans, subset);

    for(auto x : ans) {
        for(auto e : x)
            cout << e;
        cout << "\n";
    }

    return 0;
}
