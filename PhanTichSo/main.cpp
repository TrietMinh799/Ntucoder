#include <bits/stdc++.h>

using namespace std;

int n;
set<int> st;

void bfs() {
    queue<int> q;
    q.push(n);
    while(!q.empty()) {
        int u = q.front();
        q.pop();

        for(int i = 1; i <= sqrt(u); i++) {
            if(u % i == 0) {
                int j = u / i;
                int nums = (i - 1) * (j + 1);
                if(st.find(nums) != st.end())
                    continue;
                q.push(nums);
                st.insert(nums);
            }
        }
    }

    cout << st.size() << "\n";
    for(auto &s : st)
        cout << s << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    bfs();

    return 0;
}
