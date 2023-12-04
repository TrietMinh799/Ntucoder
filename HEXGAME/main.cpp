#include <iostream>
#include <queue>
#include <utility>

using namespace std;

class Node
{
private:

    int a[10];
public:
    node() {}

    void input()
    {
        for(int i = 0; i < 10; i++)
        {
            cin >> a[i];
        }
    }

    Node rotateleft()
    {
        Node b;

        b.a[0] = a[3];
        b.a[1] = a[0];
        b.a[2] = a[2];
        b.a[3] = a[7];
        b.a[4] = a[4];
        b.a[5] = a[1];
        b.a[6] = a[6];
        b.a[7] = a[8];
        b.a[8] = a[5];
        b.a[9] = a[9];

        return b;
    }

    Node rotateright()
    {
        Node b;
        b.a[0] = a[0];
        b.a[1] = a[4];
        b.a[2] = a[1];
        b.a[3] = a[3];
        b.a[4] = a[8];
        b.a[5] = a[5];
        b.a[6] = a[2];
        b.a[7] = a[7];
        b.a[8] = a[9];
        b.a[9] = a[6];


        return b;
    }

    bool isRoot()
    {
        if(a[0] != 1 || a[1] != 2 || a[2] != 3 || a[3] != 8
                || a[4] != 0 || a[5] != 0 || a[6] != 4 ||
                a[7] != 7 || a[8] != 6 || a[9] != 5)
            return false;

        return true;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Node node;
    node.input();

    queue<pair<Node, int>> q;
    q.push(make_pair(node, 0));
    Node u;

    while(!q.empty())
    {
        u = q.front().first;
        int &dist = q.front().second;
        q.pop();

        if(u.isRoot())
        {
            cout << dist << "\n";
            return 0;
        }

        q.push(make_pair(u.rotateleft(), dist + 1));
        q.push(make_pair(u.rotateright(), dist + 1));
    }

    return 0;
}
