#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0323"
#define ERROR 0.001

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include "Mylib/Algorithm/ternary_search_upwards.cpp"
#include "Mylib/IO/input_tuple_vector.cpp"

namespace hl = haar_lib;

int main() {
  int N;
  std::cin >> N;

  auto [x, r] = hl::input_tuple_vector<int64_t, int64_t>(N);

  std::vector<std::pair<int64_t, int>> p;
  for (int i = 0; i < N; ++i) {
    p.emplace_back(x[i] - r[i], -1);
    p.emplace_back(x[i] + r[i], 1);
  }

  std::sort(p.begin(), p.end());

  double left = 0, right = 0;

  int c = 0;
  for (auto &a : p) {
    if (c == N) {
      right = a.first;
    }

    c -= a.second;

    if (c == N) {
      left = a.first;
    }
  }

  auto f =
      [&](double p) {
        double ret = 1e9;

        for (int i = 0; i < N; ++i) {
          double l = std::abs(x[i] - p);
          ret      = std::min(ret, std::sqrt(r[i] * r[i] - l * l));
        }

        return ret;
      };

  auto a = hl::ternary_search_upwards<double>(left, right, f);

  std::cout << std::fixed << std::setprecision(12) << f(a) << std::endl;

  return 0;
}
