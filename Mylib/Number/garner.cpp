#pragma once
#include <vector>
#include "Mylib/Number/Mod/mod_inv.cpp"

/**
 * @title Garner法
 * @docs garner.md
 */
int64_t garner_algorithm(std::vector<int64_t> r, std::vector<int64_t> m, const int64_t mod){
  m.push_back(mod);

  int n = r.size();
  std::vector<int64_t> coeffs(n+1, 1);
  std::vector<int64_t> constants(n+1, 0);

  for(int k = 0; k < n; ++k){
    int64_t t = ((r[k] - constants[k] + m[k]) % m[k] * mod_inv(coeffs[k], m[k])) % m[k];
    for(int i = k+1; i < n+1; ++i){
      (constants[i] += t * coeffs[i] % m[i]) %= m[i];
      (coeffs[i] *= m[k]) %= m[i];
    }
  }

  return constants.back();
}
