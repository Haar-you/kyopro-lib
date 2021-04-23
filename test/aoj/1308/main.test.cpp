#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1308"

#include <bitset>
#include <iostream>
#include <vector>
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/LinearAlgebra/simultaneous_linear_equations_binary.cpp"

namespace hl = haar_lib;

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int m, n, d;
  while (std::cin >> m >> n >> d, m) {
    auto s = hl::input_vector<int>(n, m);

    auto a = std::vector(n * m, std::bitset<25 * 25>());
    std::vector<bool> b(n * m);

    std::vector<std::vector<int>> p(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        p[i][j] = j + i * m;
      }
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        b[p[i][j]] = s[i][j];
      }
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        a[p[i][j]][p[i][j]] = 1;

        for (int x = 0; x < n; ++x) {
          for (int y = 0; y < m; ++y) {
            if (abs(i - x) + abs(j - y) == d) {
              a[p[x][y]][p[i][j]] = 1;
            }
          }
        }
      }
    }

    std::cout << (bool) (hl::binary_simultaneous_linear_equations(a, b)) << std::endl;
  }

  return 0;
}
