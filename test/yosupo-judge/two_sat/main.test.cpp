#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"

#include <iostream>
#include <string>
#include <vector>
#include "Mylib/Graph/two_sat.cpp"
#include "Mylib/IO/input_tuples.cpp"
#include "Mylib/IO/join.cpp"

namespace hl = haar_lib;

int main() {
  std::string p, cnf;
  int N, M;
  std::cin >> p >> cnf >> N >> M;

  hl::two_sat sat(N);

  for (auto [a, b, c] : hl::input_tuples<int, int, int>(M)) {
    sat.add_or(a, b);
  }

  if (auto res = sat.solve(); res) {
    std::vector<int> ans(N);
    for (int i = 0; i < N; ++i) ans[i] = (*res)[i] ? i + 1 : -(i + 1);

    std::cout
        << "s SATISFIABLE" << std::endl
        << "v " << hl::join(ans.begin(), ans.end()) << " " << 0 << std::endl;
  } else {
    std::cout << "s UNSATISFIABLE" << std::endl;
  }

  return 0;
}
