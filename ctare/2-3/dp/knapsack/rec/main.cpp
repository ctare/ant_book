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
#define rrep(i, n) for(int (i) = (n); (i) >= 0; (i)--)
#define forin(i, a) for(auto i: (a))
#define p(...) printf(__VA_ARGS__); cout << endl;
#define in(...) __VA_ARGS__; input__(__VA_ARGS__);
#define input(...) in(__VA_ARGS__)
#define out(...) output__(__VA_ARGS__);
#define output(...) out(__VA_ARGS__)
#define list_input(x, n) x[(n)]; for(int (i) = 0; (i) < (n); (i)++) cin >> x[i];
#define lambda(a, b, c) [](auto const &a, auto const &b){ return c ;}
#define key(t, x, compare) [](const t &a, const t &b){ return a x compare b x ;}

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

int n, w;
int *weights, *values;
int dp[100][100]; // n, w

int calc_cnt = 0;
int solve(int depth, int weight) {
  calc_cnt++;
  if(dp[depth][weight] != -1) {
    out("memo: ", depth, weight);
    return dp[depth][weight];
  }

  if(depth == n) return 0;
  int result = 0;
  if(weight < weights[depth]) {
    result = solve(depth + 1, weight);
  } else {
    result = max(solve(depth + 1, weight), solve(depth + 1, weight - weights[depth]) + values[depth]);
  }
  dp[depth][weight] = result;
  return result;
}

int main() {
  memset(dp, -1, sizeof dp);
  int in(n_) n = n_;
  int list_input(weights_, n_) weights = weights_;
  int list_input(values_, n) values = values_;
  int in(w_) w = w_;
  out(solve(0, w));
  out("calc count: ", calc_cnt);
}
