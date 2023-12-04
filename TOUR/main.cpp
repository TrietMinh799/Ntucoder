#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int u, id;
    Edge(int u, int id)
        :u(u), id(id) {

    }
};

int n, m, u, v, bridge = 0, cnt = 0, low[200005], pre[200005];
vector<Edge> graph[200005];

int dfs(int u, int p, int id)
{
	if(pre[u]) {
		low[p] = min(low[p], pre[u]);
		return low[p];
	}
    low[u] = pre[u] = ++cnt;

    for (const Edge &v : graph[u])
    {
        if (v.id == id)
            continue;
		if(dfs(v.u, u, v.id) < 1) {
			low[u] = min(low[u], low[v.u]);
			if(low[v.u] == pre[v.u]) {
				bridge++;
			}
		}
    }
	
	return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
	
	int id = 1;

    for (int i = 1; i <= n - 1; i++)
    {
        cin >> u >> v;
        graph[u].push_back(Edge(v, id));
        graph[v].push_back(Edge(u, id));
		id++;
    }

    cin >> m;

    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        graph[u].push_back(Edge(v, id));
        graph[v].push_back(Edge(u, id));
		id++;
    }

    dfs(1, 1, id);

    cout << bridge << "\n";
    cout.flush();

    return 0;
}
