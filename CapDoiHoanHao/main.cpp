#include <iostream>
#include <vector>
#include <cstring>

#define MAXSIZE 1000005

using namespace std;

int n, k, root = -1;
long long ans = 0, f[MAXSIZE];
bool check[MAXSIZE];
vector<int> trees[MAXSIZE];

void update1(int m)
{
    while (m < MAXSIZE)
    {
        f[m]++;
        m += (m & (-m));
    }
}

void update2(int m)
{
    while (m < MAXSIZE)
    {
        f[m]--;
        m += (m & (-m));
    }
}

int gets(int m)
{
    int res = 0;
    while (m > 0)
    {
        res += f[m];
        m -= (m & (-m));
    }
    return res;
}

void dfs(int u)
{
    check[u] = true;
    for (int &v : trees[u])
    {
        if (!check[v])
        {
            ans += gets(v + k) - gets(max(0, v - k - 1));
            update1(v);
            // cout << u << " " << v << " " << gets(v + k) << " " << gets(abs(v - k - 1)) << "\n";
            dfs(v);
            update2(v);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;

    memset(check, false, n + 1);

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        trees[u].push_back(v);
        check[v] = true;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!check[i] && trees[i].size() > 0)
        {
            root = i;
            break;
        }
    }

    // cout << root << "\n";

    memset(check, false, n + 1);
    // cout << "testcase:\n";
    update1(root);
    dfs(root);
    cout << ans << "\n";

    return 0;
}