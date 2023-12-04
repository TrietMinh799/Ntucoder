#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<vector<int>> graph(100005);
vector<bool> visited(100005);
vector<int> ans;

void dfs(int k) {
    visited[k] = true;

    for(int vertex : graph[k]) {
        if(!visited[vertex]) {
            dfs(vertex);
        }
    }
    ans.push_back(k);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k;

    for(int i = 1; i <= n; i++) {
        int m, x;
        cin >> m;
        for(int j = 1; j <= m; j++) {
            cin >> x;
            graph[i].push_back(x);
            graph[x].push_back(i);
        }
    }

    dfs(k);

    reverse(ans.begin(), ans.end());
    sort(ans.begin(), ans.end());

    cout << ans.size() << "\n";
    for(auto &x : ans)
        cout << x << " ";

    return 0;
}
