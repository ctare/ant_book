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

int main(){
  int list_input(c, 6);
  int coins[6] = {1, 5, 10, 50, 100, 500};
  int in(a);

  int tmp[6] = {};

  int result = 0;
  rrep(i, 6 - 1) {
    // 全部引き算して計算せずに、割り算使うと早い
    // min(a / coins[i], c[i])
    while(true) {
      if(c[i] > 0 and a - coins[i] >= 0) {
        a -= coins[i];
        result++;
        c[i]--;

        // debug
        out("use: ", coins[i]);
        tmp[i]++;

      } else {
        break;
      }

      if(a == 0) goto END;
    }
  }

END:
  out("---------");
  out(result);

  rep(i, 6) {
    printf("%d: x%d\n", coins[i], tmp[i]);
  }
}
