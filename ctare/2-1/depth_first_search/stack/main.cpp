#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <numeric>
#include <regex>
#include <stack>

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
  int sum, depth;
};

int main(){
  int in(n);
  int list_input(a, n);
  int in(k);

  stack<Args> stk;
  stk.push({0, 0});
  while(!stk.empty()) {
    struct Args args = stk.top();
    stk.pop();

    if(args.sum == k) {
      out(true);
      exit(0);
    }
    if(args.depth < n) {
      stk.push({args.sum + a[args.depth], args.depth + 1});
      stk.push({args.sum, args.depth + 1});
    }
  }

  out(false);
}
