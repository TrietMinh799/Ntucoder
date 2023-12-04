#include <bits/stdc++.h>

using namespace std;

int k, n;

void backtracking(vector<vector<int>>& ans, vector<int>& subset) {
    if(subset.size() == n) {
        ans.push_back(subset);
        return;
    }

    for(int i = 1; i <= k; i++) {
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
    cin >> k >> n;

    vector<vector<int>> ans;
    vector<int> subset;
    backtracking(ans, subset);

    cout << ans.size() << "\n";

    for(auto &ar : ans) {
        for(auto &element : ar)
            cout << element;

        cout << "\n";
    }

    return 0;
}
