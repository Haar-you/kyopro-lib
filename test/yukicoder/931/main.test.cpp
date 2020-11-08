#define PROBLEM "https://yukicoder.me/problems/no/931"

#include <iostream>
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/Number/Prime/primitive_root.cpp"
#include "Mylib/Number/Mod/mod_pow.cpp"
#include "Mylib/Convolution/ntt_convolution.cpp"
#include "Mylib/Convolution/convolution_multiply.cpp"
#include "Mylib/IO/join.cpp"

namespace hl = haar_lib;

constexpr int mod = 998244353;
constexpr int prim_root = hl::primitive_root(mod);
using mint = hl::modint<mod>;
using NTT = hl::number_theoretic_transform<mint, prim_root, 1 << 20>;
const static auto ntt = NTT();

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int P; std::cin >> P;
  std::vector<mint> A(P), B(P);
  for(int i = 1; i < P; ++i) std::cin >> A[i];
  for(int i = 1; i < P; ++i) std::cin >> B[i];

  std::vector<mint> ans = hl::convolution_multiply<mint, ntt>(A, B, P);

  std::cout << hl::join(ans.begin() + 1, ans.end()) << "\n";

  return 0;
}
