#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int n, a, b;
struct Datas
{
  int x1, y, z;
};
Datas ar[100005];

bool cmp(const Datas &p1, const Datas &p2)
{
  return (p1.x1 < p2.x1);
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> a >> b;

  for (int i = 0; i < n; i++)
  {
    cin >> ar[i].x1 >> ar[i].y;
    ar[i].z = i + 1;
  }
  sort(ar, ar + n, cmp);
  bool check = false;
  int j = 0, maxid = ar[0].z, maxy = ar[0].y;
  vector<int> res;
  while (!check)
  {
    bool check2 = false;
    int idx = upper_bound(ar + j, ar + n, Datas{a}, cmp) - ar;
    for (int i = j; i < idx; i++)
    {
      if (ar[i].z != 0)
      {
        check2 = true;
        if (ar[i].y > maxy)
        {
          maxy = ar[i].y;
          maxid = ar[i].z;
        }
        ar[i].z = 0;
      }
    }
    if (!check2)
      break;

    res.push_back(maxid);
    if (maxy >= b)
    {
      check = true;
      break;
    }
    else
    {
      a = maxy;
      j = idx;
    }
  }

  if (!check)
  {
    cout << -1;
  }
  else
  {
    cout << res.size() << "\n";
    for (int &x : res)
      cout << x << " ";
  }
  return 0;
}
