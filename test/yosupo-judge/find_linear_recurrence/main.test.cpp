#define PROBLEM "https://judge.yosupo.jp/problem/find_linear_recurrence"

#include "Mylib/IO/input_vector.cpp"
#include "Mylib/IO/join.cpp"
#include "Mylib/Math/berlekamp_massey.cpp"
#include "Mylib/Number/Mint/mint.cpp"

namespace hl = haar_lib;

constexpr int mod = 998244353;
using mint        = hl::modint<mod>;

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N;
  std::cin >> N;
  auto a = hl::input_vector<mint>(N);

  auto c = berlekamp_massey(a);
  std::cout << c.size() << "\n"
            << hl::join(c.begin(), c.end()) << "\n";

  return 0;
}
