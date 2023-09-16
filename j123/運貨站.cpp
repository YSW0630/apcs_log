#pragma GCC optimize("Ofast,unroll-all-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int>>
#define pqueue priority_queue
#define pb push_back
#define eb emplace_back
#define ep emplace
#define F first
#define S second
#define put(x) cout << x << '\n'
#define all(v) v.begin(), v.end()
#define MEM(x, n) memset(x, n, sizeof(x));
#define lowbit(x) x & (-x)
#define SZ(v) ((int)v.size())
#define FOR(n) for (int i = 0; i < n; ++i)
using namespace std;
constexpr int Inf = 0x7f7f7f7f;
constexpr int Mxn = 1e6 + 1;
constexpr int Mod = 1e9 + 7;
/******************************************************************************/

int r, c, n, y, abandon, space;
bool mtx[35][55];
int R[35];
char t;
/*********************************************************
 (A) *    (B) ***    (C) **   (D)    *    (E)  *  
     *                   **        ***        **
     *                                        **
     *
*********************************************************/

void A(int y) { 
  bool ok, thw = 1;
  int i;
  for (i = 0; i < c; ++i) {
    ok = 1;
    for (int j = 0; j < 4; ++j) {
      if (mtx[y+j][i] == 1 || i < R[y+j]) {
        ok = 0; break;
      }   
    }
    if (ok) {
      for (int j = 0; j < 4; ++j) {
        mtx[y+j][i] = 1;
        R[y+j] = i;
      }
      thw = 0;
      break;
    }
  }
  if (thw) abandon++;
}

void B(int y) {
  bool ok, thw = 1;
  int i;
  for (i = 0; i <= c-3; ++i) {
    ok = 1;
    for (int j = 0; j < 3; ++j) {
      if (mtx[y][i+j] == 1 || i+j < R[y]) {
        ok = 0; break; 
      }
    }
    if (ok) {
      R[y] = i+2;
      for (int j = 0; j < 3; ++j) mtx[y][i+j] = 1;
      thw = 0;
      break;
    }
  }
  if (thw) abandon++;
}

void C(int y) {
  bool ok, thw = 1;
  int i;
  for (i = 0; i < c-1; ++i) {
    ok = 1;
    if (mtx[y][i] == 1 || mtx[y][i+1] == 1 ||
        mtx[y+1][i] == 1 || mtx[y+1][i+1] == 1 ||
        i+1 < R[y] || i+1 < R[y+1]
    ) ok = 0;
    if (ok) {
      mtx[y][i] = 1, mtx[y][i+1] = 1, mtx[y+1][i] = 1, mtx[y+1][i+1] = 1;
      R[y] = i+1, R[y+1] = i+1;
      thw = 0;
      break;
    }
  }
  if (thw) abandon++;
}

void D(int y) {
  bool ok, thw = 1;
  int i;
  for (i = 0; i < c-2; ++i) {
    ok = 1;
    if (mtx[y][i+2] == 1 || mtx[y+1][i] == 1 ||
        mtx[y+1][i+1] == 1 || mtx[y+1][i+2] == 1 ||
        i+2 < R[y] || i+2 < R[y+1]
    ) ok = 0;
    if (ok) {
      mtx[y][i+2] = 1, mtx[y+1][i] = 1, mtx[y+1][i+1] = 1, mtx[y+1][i+2] = 1;
      R[y] = i+2, R[y+1] = i+2;
      thw = 0;
      break;
    } 
  }
  if (thw) abandon++;
}

void E(int y) {
  bool ok, thw = 1;
  int i;
  for (i = 0; i < c-1; ++i) {
    ok = 1;
    if (mtx[y][i+1] == 1 || mtx[y+1][i] == 1 ||
        mtx[y+1][i+1] == 1 || mtx[y+2][i] == 1 ||
        mtx[y+2][i+1] == 1 || i+1 < R[y] ||
        i+1 < R[y+1] || i+1 < R[y+2]
    ) ok = 0;
    if (ok) {
      mtx[y][i+1] = 1, mtx[y+1][i] = 1, mtx[y+1][i+1] = 1, mtx[y+2][i] = 1, mtx[y+2][i+1] = 1;
      R[y] = i+1, R[y+1] = i+1, R[y+2] = i+1;
      thw = 0;
      break;
    } 
  }
  if (thw) abandon++;
}

void sol() {
  cin >> r >> c >> n;
  while (n--) {
    cin >> t >> y;
    switch (t) {
      case 'A':
      A(y); break;
      case 'B':
      B(y); break;
      case 'C':
      C(y); break;
      case 'D':
      D(y); break;
      case 'E':
      E(y); break;
      default: break;
    }
  } 
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (!mtx[i][j]) space++;
    }
  }
  cout << space << ' ' << abandon << '\n';
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  sol();
  return 0;
}
