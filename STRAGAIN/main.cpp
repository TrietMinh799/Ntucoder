#include <iostream>
#include <map>
#include <string>
#include <queue>
#include <set>

using namespace std;

int n;
string s;
set<string> st;
map<string, int> d;
string ans = "";

bool check(string  s) {
    int countsA = 0, countsB = 0, i = 0, j = n - 1;
    while(i <= j) {
        if(i != j) {
            if(s[i] == 'A')
                countsA++;
            else if(s[j] == 'A')
                countsA++;
            else if(s[i] == 'B')
                countsB++;
            else if(s[j] == 'B')
                countsB++;
        } else if(i == j) {
            else if(s[i] == 'A')
                countsA++;
            else if(s[i] == 'B')
                countsB++;
        }
        i++;
        j--;
    }
    return countsA == n || countsB == n;
}

void bfs() {
    queue<string> q;
    q.push(s);
    st.insert(s);
    d[s] = 0;
    while(!q.empty()) {
        string u = q.front();
        q.pop();
        if(check(u)) {
            ans = u;
            break;
        }
        for(int i = 0; i < u.size() - 2; i++) {
            string temp = u;
            int m = i + 3;
            for(int j = i; j < m; j++) {
                if(temp[j] == 'A') temp[j] = 'B';
                else temp[j] = 'A';
            }
            if(st.find(temp) != st.end())
                continue;
            st.insert(temp);
            d[temp] = d[u] + 1;
            q.push(temp);
        }

        for(int i = 0; i < u.size() - 1; i++) {
            string temp = u;
            int m = i + 2;
            for(int j = i; j < m; j++) {
                if(temp[j] == 'A') temp[j] = 'B';
                else temp[j] = 'A';
            }
            if(st.find(temp) != st.end())
                continue;
            st.insert(temp);
            d[temp] = d[u] + 1;
            q.push(temp);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    cin.ignore();
    getline(cin, s);
    bfs();
    cout << d[ans];

    return 0;
}
