#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
using namespace std;

/***************************************************************/
struct king;
void sol();
/***************************************************************/

struct king {
  int r, c, s, t;
  bool alive = 1;
};

void sol() {
  bool ok = 1;
  int n, m, k, x, y; cin >> n >> m >> k;
  map<pii, short> mtx; // 0: no_bomb, 1: has_bomb
  vector<king> kings(k);
  for (king &k : kings)
    cin >> k.r >> k.c >> k.s >> k.t;
  while (1) {
    // put bomb
    for (king &k : kings) {
      if (k.alive && 0 <= k.r && k.r < n && 0 <= k.c && k.c < m) {
        mtx[{k.r, k.c}] = 1;
      }
    }
    // move all king 
    for (king &k : kings) {
      if (k.alive) {
        x = k.r + k.s, y = k.c + k.t;
        if (0 <= x && x < n && 0 <= y && y < m) {
          k.r = x, k.c = y;
          if (mtx[{k.r, k.c}] == 1 || mtx[{k.r, k.c}] == 2) {
            k.alive = 0;
            mtx[{k.r, k.c}] = 2;
          }
        } else k.alive = 0;
      }
    }
    // check place has bomb or not
    for (auto it = mtx.begin(); it != mtx.end();) {
      if (it -> second == 2) {
        it = mtx.erase(it);
      } else {
        ++it;
      }
    }
    // check_all_king
    ok = 1;
    for (const king &k : kings) {
      if (k.alive) {
        ok = 0;
        break;
      }
    }
    if (ok) break;
  }
  cout << mtx.size() << '\n';
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  sol();
  return 0;
}
