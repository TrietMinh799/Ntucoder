#include <iostream>

using namespace std;

typedef long long ll;

const int MAXSIZE = 1011;

int n, q, x, y, u, v;
ll a[MAXSIZE][MAXSIZE], t[4 * MAXSIZE][4 * MAXSIZE], w;
char type;

void build_y(int vx, int lx, int rx, int vy, int ly, int ry) {
  if (ly == ry) {
    if (lx == rx)
      t[vx][vy] = a[lx][ly];
    else
      t[vx][vy] = min(t[vx * 2][vy], t[vx * 2 + 1][vy]);
    return;
  }

  int ymid = ly + (ry - ly) / 2;
  build_y(vx, lx, rx, vy * 2, ly, ymid);
  build_y(vx, lx, rx, vy * 2 + 1, ymid + 1, ry);

  t[vx][vy] = min(t[vx][vy * 2], t[vx][vy * 2 + 1]);
}

void build_x(int vx, int lx, int rx) {
  if (lx != rx) {
    int vmid = lx + (rx - lx) / 2;
    build_x(vx * 2, lx, vmid);
    build_x(vx * 2 + 1, vmid + 1, rx);
  }
  build_y(vx, lx, rx, 1, 0, n - 1);
}

ll min_y(int vx, int vy, int tly, int try_, int ly, int ry) {
  if (ly > ry)
    return 2e9;

  if (ly == tly && try_ == ry) {
    return t[vx][vy];
  }

  int tmy = tly + (try_ - tly) / 2;

  return min(min_y(vx, vy * 2, tly, tmy, ly, min(ry, tmy)),
             min_y(vx, vy * 2 + 1, tmy + 1, try_, max(ly, tmy + 1), ry));
}

ll min_x(int vx, int tlx, int trx, int lx, int rx, int ly, int ry) {
  if (lx > rx)
    return 2e9;

  if (lx == tlx && trx == rx)
    return min_y(vx, 1, 0, n - 1, ly, ry);

  int tmx = tlx + (trx - tlx) / 2;
  return min(min_x(vx * 2, tlx, tmx, lx, min(rx, tmx), ly, ry),
             min_x(vx * 2 + 1, tmx + 1, trx, max(lx, tmx + 1), rx, ly, ry));
}

void update_y(int vx, int lx, int rx, int vy, int ly, int ry, int x, int y,
              ll new_val) {
  if (ly == ry) {
    if (lx == rx)
      t[vx][vy] = new_val;
    else
      t[vx][vy] = min(t[vx * 2][vy], t[vx * 2 + 1][vy]);
    return;
  }

  int my = (ly + ry) / 2;
  if (y <= my)
    update_y(vx, lx, rx, vy * 2, ly, my, x, y, new_val);
  else
    update_y(vx, lx, rx, vy * 2 + 1, my + 1, ry, x, y, new_val);
  t[vx][vy] = min(t[vx][vy * 2], t[vx][vy * 2 + 1]);
}

void update_x(int vx, int lx, int rx, int x, int y, int new_val) {
  if (lx != rx) {
    int mx = (lx + rx) / 2;
    if (x <= mx)
      update_x(vx * 2, lx, mx, x, y, new_val);
    else
      update_x(vx * 2 + 1, mx + 1, rx, x, y, new_val);
  }
  update_y(vx, lx, rx, 1, 0, n - 1, x, y, new_val);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }

  build_x(1, 0, n - 1);

  cin >> q;

  while (q--) {
    cin >> type;
    if (type == 'c') {
      cin >> x >> y >> w;
      --x, --y;
      update_x(1, 0, n - 1, x, y, w);
    } else {
      cin >> x >> y >> u >> v;
      --x, --y, --u, --v;
      cout << min_x(1, 0, n - 1, x, y, u, v) << "\n";
    }
  }

  cout.flush();
  return 0;
}