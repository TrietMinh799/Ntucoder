#include <bits/stdc++.h>

using namespace std;

struct Point
{
    int x, y;
};

int squareDist(Point &p, Point &q)
{
    return (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y);
}

bool isSquare(Point p1, Point p2, Point p3, Point p4)
{
    int dist2 = squareDist(p1, p2);
    int dist3 = squareDist(p1, p3);
    int dist4 = squareDist(p1, p4);

    if (dist2 == dist3 && 2*dist2 == dist4)
    {
        int dist = squareDist(p2, p4);
        return (dist == squareDist(p3, p4) && dist == dist2);
    }

    if (dist3 == dist4 && 2*dist3 == dist2)
    {
        int dist = squareDist(p2, p3);
        return (dist == squareDist(p2, p4) && dist == dist3);
    }

    if (dist2 == dist4 && 2*dist2 == dist3)
    {
        int dist = squareDist(p2, p3);
        return (dist == squareDist(p3, p4) && dist == dist2);
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Point p1, p2, p3, p4;
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;

    if(isSquare(p1, p2, p3, p4)) {
        printf("YES");
    } else {
        printf("NO");
    }


    return 0;
}
