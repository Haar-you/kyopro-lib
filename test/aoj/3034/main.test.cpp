#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3034"
#define ERROR 1e-3

#include <iomanip>
#include <iostream>
#include <vector>
#include "Mylib/Bit/enumerate_subsets_asc.cpp"
#include "Mylib/Geometry/Float/double_eps.cpp"
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/minimum_covering_circle.cpp"
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/Utils/fix_point.cpp"

namespace hl = haar_lib;

static constexpr double eps = ERROR;
using D                     = hl::double_eps<double, eps>;

D dp[15][1 << 14];
bool check[15][1 << 14];

const D INF = 1e9;

int main() {
  int N, M;
  std::cin >> N >> M;

  auto ps = hl::input_vector<hl::point<D>>(N);

  std::vector<double> memo(1 << N);

  for (int t = 0; t < (1 << N); ++t) {
    std::vector<hl::point<D>> q;
    for (int i = 0; i < N; ++i) {
      if (t & (1 << i)) q.push_back(ps[i]);
    }
    memo[t] = (double) hl::minimum_covering_circle(q).radius;
  }

  const int mask = (1 << N) - 1;

  auto ans =
      hl::make_fix_point(
          [&](auto &&rec, int d, int s) -> D {
            if (d == M) {
              if (s != 0) return dp[d][s] = INF;
              return dp[d][s] = 0;
            }

            if (check[d][s]) return dp[d][s];
            check[d][s] = true;

            D ret = INF;

            hl::enumerate_subsets_asc(
                s,
                [&](int t) {
                  D val = std::max((double) rec(d + 1, s ^ t), memo[t]);
                  ret   = std::min((double) ret, (double) val);
                  return true;
                });

            return dp[d][s] = ret;
          })(0, mask);

  std::cout << std::fixed << std::setprecision(12) << ans << std::endl;

  return 0;
}
