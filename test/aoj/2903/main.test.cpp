#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2903"

#include <iostream>
#include <string>
#include <vector>
#include "Mylib/Graph/Flow/ford_fulkerson.cpp"
#include "Mylib/Graph/project_selection_problem.cpp"
#include "Mylib/IO/input_vector.cpp"

namespace hl = haar_lib;

int main() {
  int R, C;
  std::cin >> R >> C;

  auto S = hl::input_vector<std::string>(R);

  hl::project_selection_problem<int, hl::ford_fulkerson<int>> psp(R * C);
  // red: horizontal
  // blue: vertical

  for (int i = 0; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      if (S[i][j] == '#') {
        int k = i * C + j;
        psp.penalty_if_red(k, 1);
        psp.penalty_if_blue(k, 1);
      }
    }
  }

  for (int i = 1; i < R; ++i) {
    for (int j = 0; j < C; ++j) {
      if (S[i][j] == '#' and S[i - 1][j] == '#') {
        psp.gain_if_blue_blue(i * C + j, (i - 1) * C + j, 1);
      }
    }
  }

  for (int i = 0; i < R; ++i) {
    for (int j = 1; j < C; ++j) {
      if (S[i][j] == '#' and S[i][j - 1] == '#') {
        psp.gain_if_red_red(i * C + j, i * C + (j - 1), 1);
      }
    }
  }

  auto ans = -psp.solve();
  std::cout << ans << std::endl;

  return 0;
}
