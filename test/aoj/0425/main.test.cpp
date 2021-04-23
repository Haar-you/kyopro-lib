#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0425"

#include <iostream>
#include <numeric>
#include <tuple>
#include <utility>
#include <vector>
#include "Mylib/Algorithm/mo_algorithm.cpp"
#include "Mylib/IO/input_tuple_vector.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, K, Q;
  std::cin >> N >> K >> Q;

  auto [a, b] = hl::input_tuple_vector<int, int>(K);
  for (auto &x : a) --x;
  for (auto &x : b) --x;

  std::vector<std::tuple<int, int, int, int>> qs;
  for (auto [type, s, t, x] : hl::input_tuples<int, int, int, int>(Q)) {
    --s, --t, --x;
    qs.emplace_back(type, s, t, x);
  }

  std::vector<int> p(N), q(N);
  std::iota(p.begin(), p.end(), 0);
  std::iota(q.begin(), q.end(), 0);

  std::vector<int> ans(Q);

  auto left =
      [&](int i) {
        std::swap(q[p[q[a[i]]]], q[p[q[b[i]]]]);
        std::swap(p[q[a[i]]], p[q[b[i]]]);
      };

  auto right =
      [&](int i) {
        std::swap(q[p[a[i]]], q[p[b[i]]]);
        std::swap(p[a[i]], p[b[i]]);
      };

  auto query =
      [&](int i) {
        if (std::get<0>(qs[i]) == 1)
          ans[i] = p[std::get<3>(qs[i])] + 1;
        else
          ans[i] = q[std::get<3>(qs[i])] + 1;
      };

  auto mo = hl::mo_algorithm(N, Q, left, right, left, right, query);

  for (int i = 0; i < Q; ++i) mo.add(std::get<1>(qs[i]), std::get<2>(qs[i]) + 1);
  mo.run();

  for (int i = 0; i < Q; ++i) std::cout << ans[i] << "\n";

  return 0;
}
