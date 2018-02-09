#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <numeric>
#include <regex>

#define FOR(i, f, n) for(int (i) = (f); (i) < (n); (i)++)
#define RFOR(i, f, n) for(int (i) = (f); (i) >= (n); (i)--)
#define REP(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define RREP(i, n) for(int (i) = (n); (i) >= 0; (i)--)
#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define rrep(i, n) for(int (i) = (n); (i) >= 0; (i)++)
#define p(...) printf(__VA_ARGS__); cout << endl;
#define in(...) __VA_ARGS__; input__(__VA_ARGS__);
#define input(...) in(__VA_ARGS__)
#define out(...) output__(__VA_ARGS__);
#define output(...) out(__VA_ARGS__)
#define list_input(x, n) x[(n)]; for(int (i) = 0; (i) < (n); (i)++) cin >> x[i];
#define lambda(a, b, c) [](const a, const b){ return c ;}
#define key(t, x, compare) [](const t& a, const t& b){ return a x compare b x ;}

using namespace std;

using pii = pair<int, int>;

template <class... T>
void input__(T &...a) {
  for(auto v: {&a...}) {
    cin >> *v;
  }
}

void output__(){
  cout << endl;
}

template <class Head, class... T>
void output__(Head const &v, T const &...a) {
  if(sizeof...(a) == 0) {
    cout << v;
  } else {
    cout << v << " ";
  }
  output__(a...);
}

struct Args {
  int y, x;
  int cnt;
};

Args next_points[4] = {
  {-1, 0},
  {1, 0},
  {0, -1},
  {0, 1}
};

int main(){
  int in(n, m);
  string list_input(a, n);
  rep(i, n) rep(j, m) {
    if(a[i][j] == 'S') {
      queue<Args> que;
      que.push({i, j});
      a[i][j] = '.';

      while(!que.empty()) {
        Args args = que.front();
        que.pop();

        if(0 <= args.x and 
            args.x < m and 
            0 <= args.y and 
            args.y < n) {

          if(a[args.y][args.x] == 'G') {
            out(args.cnt);
            out("=========");
            rep(i_, n) out(a[i_]);
            exit(0);
          } else if(a[args.y][args.x] == '.') {
            a[args.y][args.x] = 'o';
            for(auto next_point: next_points) {
              que.push({args.y + next_point.y, args.x + next_point.x, args.cnt + 1});
            }
          }
        }
      }
    }
  }
}
