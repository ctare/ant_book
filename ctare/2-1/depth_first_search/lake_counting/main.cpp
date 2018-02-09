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
};

Args next_points[8] = {
  {-1, -1}, {-1, 0}, {-1, 1},
  {0, -1}, {0, 1},
  {1, -1}, {1, 0}, {1, 1}
};

void search(int y, int x, int n, int m, bool visited[100][100], string a[n]) {
  stack<Args> stk;
  stk.push({y, x});
  while(!stk.empty()) {
    struct Args args = stk.top();
    stk.pop();

    if(0 <= args.x and 
        args.x < m and 
        0 <= args.y and 
        args.y < n and 
        a[args.y][args.x] == 'W' and
        !visited[args.y][args.x]) {

      visited[args.y][args.x] = true;
      for(auto next_point: next_points) {
        stk.push({args.y + next_point.y, args.x + next_point.x});
      }
    }
  }
}

int main(){
  int in(n, m);
  string list_input(a, n);
  // visitedとか用意せずに、訪れた場所を'.'に置き換えた方がコードが簡潔になったっぽい
  bool visited[100][100] = {};
  rep(i, n) {
    rep(j, m) {
      if(a[i][j] == 'W' and !visited[i][j]) {
        search(i, j, n, m, visited, a);
        out(i, j);
      }
    }
  }
}
