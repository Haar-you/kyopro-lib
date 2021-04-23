#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2171"
#define ERROR 1e-8

#include <iomanip>
#include <iostream>
#include <vector>
#include "Mylib/Graph/ShortestPath/warshall_floyd_for_matrix_graph.cpp"
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/LinearAlgebra/simultaneous_linear_equations_float.cpp"

namespace hl = haar_lib;

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int n, s, t;
  while (std::cin >> n >> s >> t, n) {
    --s, --t;

    auto q = hl::input_vector<int>(n);
    auto g = hl::input_vector<int>(n, n);

    auto dist = hl::warshall_floyd_for_matrix<int, 0>(g);

    if (not dist[s][t]) {
      std::cout << "impossible" << std::endl;
      continue;
    }

    std::vector<std::vector<double>> a(n, std::vector<double>(n));
    std::vector<double> b(n);

    for (int i = 0; i < n; ++i) {
      if (i == t) {
        a[i][i] = 1;
        b[i]    = 0;
        continue;
      }

      if (q[i]) {
        int d = *dist[i][t];

        int k = 0;
        for (int j = 0; j < n; ++j) {
          if (g[i][j] > 0 and g[i][j] + *dist[j][t] == d) {
            ++k;
          }
        }

        for (int j = 0; j < n; ++j) {
          if (g[i][j] > 0 and g[i][j] + *dist[j][t] == d) {
            a[i][j] = -1;
            b[i] += g[i][j];
          }
        }

        a[i][i] += k;
      } else {
        int k = 0;
        for (int j = 0; j < n; ++j) {
          if (g[i][j] > 0) {
            ++k;
          }
        }

        for (int j = 0; j < n; ++j) {
          if (g[i][j] > 0) {
            a[i][j] = -1;
            b[i] += g[i][j];
          }
        }

        a[i][i] += k;
      }
    }

    auto res = hl::float_simultaneous_linear_equations(a, b, ERROR);

    double ans = (*res).solution[s];
    std::cout << std::setprecision(12) << std::fixed << ans << std::endl;
  }

  return 0;
}
