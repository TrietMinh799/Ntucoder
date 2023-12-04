#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t, n;
ll a, b, w;

void dfs(vector<pair<int, int>> &trees, int u, vector<ll> f) {
    f[u] = trees[u].second;
    for(auto &vertices : graph[vertex]) {
        if(!visited[vertices.first]) {
            currSum += vertices.second;
            sum += currSum;
            dfs(graph, vertices.first, visited);
            currSum = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;

    while(t--) {
        cin >> n;

        vector<pair<int, int>> trees[n + 1];
        vector<ll> f(n + 1);
        sum = 0, currSum = 0;
        for(int i = 1; i <= n - 1; i++) {
            cin >> a >> b >> w;
            graph[a].emplace_back(make_pair(b, w));
        }

        dfs(trees, 1, f);
    }
    return 0;
}
