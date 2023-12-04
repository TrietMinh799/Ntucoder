#include <bits/stdc++.h>

using namespace std;

int n, a[20];
vector<vector<char>> ans;

void backtracking(int sumA, int sumB, int idx, vector<char>& chosen) {
    if(idx == n) {
        if(sumA == sumB) {
            ans.push_back(chosen);
        }
        return;
    }

    chosen.push_back('A');
    backtracking(sumA + a[idx], sumB, idx + 1, chosen);
    chosen.pop_back();
    chosen.push_back('B');
    backtracking(sumA, sumB + a[idx], idx + 1, chosen);
    chosen.pop_back();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    for(int i = 0; i < n; i++) cin >> a[i];
    vector<char> chosen;

    backtracking(0, 0, 0, chosen);

    if(ans.size() == 0) {
        cout << "khong chia duoc";
        return 0;
    }

    cout << ans.size() << "\n";
    for(vector<char> v : ans) {
        for(char c : v) {
            cout << c << " ";
        }

        cout << "\n";
    }

    return 0;
}
