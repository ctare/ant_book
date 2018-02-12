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

int main(){
  int in(n);
  int list_input(a, n);

  int result = 0;
  rep(i, n - 1) {
    int index1 = distance(a, min_element(a, a + n));
    int value = a[index1];
    a[index1] = INT_MAX;

    int index2 = distance(a, min_element(a, a + n));
    a[index2] += value;

    out(a[index2]);
    result += a[index2];
  }
  out("=====") out(result);
}
