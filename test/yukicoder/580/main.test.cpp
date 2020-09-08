#define PROBLEM "https://yukicoder.me/problems/no/580"

#include <iostream>
#include <vector>
#include "Mylib/TypicalProblem/IntervalSchedulingProblem/interval_scheduling_k.cpp"

namespace hl = haar_lib;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int n, m; std::cin >> n >> m;

  std::vector<int> l(m), r(m);

  for(int i = 0; i < m; ++i){
    int d; std::cin >> d;
    int h1, m1; std::cin >> h1; std::cin.ignore(); std::cin >> m1;

    int o; std::cin >> o;
    int h2, m2; std::cin >> h2; std::cin.ignore(); std::cin >> m2;

    l[i] = d * 24 * 60 + h1 * 60 + m1;
    r[i] = o * 24 * 60 + h2 * 60 + m2 + 1;
  }

  auto res = hl::interval_scheduling_k(l, r, n);
  std::cout << res.size() << "\n";

  return 0;
}
