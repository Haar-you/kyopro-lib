---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Mylib/Number/Mod/mod_inv.cpp
    title: Mod inverse
  - icon: ':question:'
    path: Mylib/Number/Mod/mod_pow.cpp
    title: Mod pow
  - icon: ':x:'
    path: Mylib/Number/chinese_remainder_algorithm.cpp
    title: Chinese remainder theorem
  - icon: ':x:'
    path: Mylib/Number/extended_gcd.cpp
    title: Extended Euclidean algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo-judge/binomial_coefficient/main.test.cpp
    title: test/yosupo-judge/binomial_coefficient/main.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/Number/Mod/mod_inv.cpp\"\n#include <cstdint>\n#include\
    \ <utility>\n\nnamespace haar_lib {\n  constexpr int64_t mod_inv(int64_t a, int64_t\
    \ m) {\n    int64_t b = m, u = 1, v = 0;\n\n    while (b) {\n      int64_t t =\
    \ a / b;\n      a -= t * b;\n      a = a ^ b;\n      b = a ^ b;\n      a = a ^\
    \ b;\n\n      u -= t * v;\n      u = u ^ v;\n      v = u ^ v;\n      u = u ^ v;\n\
    \    }\n\n    u %= m;\n    if (u < 0) u += m;\n\n    return u;\n  }\n}  // namespace\
    \ haar_lib\n#line 3 \"Mylib/Number/Mod/mod_pow.cpp\"\n\nnamespace haar_lib {\n\
    \  constexpr int64_t mod_pow(int64_t n, int64_t p, int64_t m) {\n    int64_t ret\
    \ = 1;\n    while (p > 0) {\n      if (p & 1) (ret *= n) %= m;\n      (n *= n)\
    \ %= m;\n      p >>= 1;\n    }\n    return ret;\n  }\n}  // namespace haar_lib\n\
    #line 2 \"Mylib/Number/chinese_remainder_algorithm.cpp\"\n#include <cassert>\n\
    #include <optional>\n#include <vector>\n#line 2 \"Mylib/Number/extended_gcd.cpp\"\
    \n#include <tuple>\n\nnamespace haar_lib {\n  auto ext_gcd(int64_t a, int64_t\
    \ b) -> std::tuple<\n      int64_t,  // gcd\n      int64_t,  // p\n      int64_t\
    \   // q\n      > {\n    if (b == 0) return std::make_tuple(a, 1, 0);\n    const\
    \ auto [d, q, p] = ext_gcd(b, (a + b) % b);\n    return std::make_tuple(d, p,\
    \ q - a / b * p);\n  }\n}  // namespace haar_lib\n#line 6 \"Mylib/Number/chinese_remainder_algorithm.cpp\"\
    \n\nnamespace haar_lib {\n  std::optional<std::pair<int64_t, int64_t>> chinese_remainder_algorithm(\n\
    \      int64_t b1, int64_t m1,\n      int64_t b2, int64_t m2) {\n    const auto\
    \ [d, p, q] = ext_gcd(m1, m2);\n    if ((b2 - b1) % d != 0) return std::nullopt;\n\
    \    const int64_t m = m1 * m2 / d;\n    const int64_t t = ((b2 - b1) * p / d)\
    \ % (m2 / d);\n    const int64_t r = (b1 + m1 * t + m) % m;\n    return {{r, m}};\n\
    \  }\n\n  std::optional<std::pair<int64_t, int64_t>> chinese_remainder_algorithm(\n\
    \      const std::vector<int64_t> &bs,\n      const std::vector<int64_t> &ms)\
    \ {\n    assert(bs.size() == ms.size());\n    int64_t R = 0, M = 1;\n    for (int\
    \ i = 0; i < (int) bs.size(); ++i) {\n      const auto res = chinese_remainder_algorithm(R,\
    \ M, bs[i], ms[i]);\n      if (not res) return std::nullopt;\n      const auto\
    \ [r, m] = *res;\n      R                 = r;\n      M                 = m;\n\
    \    }\n    return {{R, M}};\n  }\n}  // namespace haar_lib\n#line 6 \"Mylib/Combinatorics/binomial_coefficient.cpp\"\
    \n\nnamespace haar_lib {\n  class ext_lucas {\n    std::vector<int64_t> prod_,\
    \ inv_;\n    int p_, q_;\n    int64_t m_;\n\n  public:\n    ext_lucas(int p, int\
    \ q) : p_(p), q_(q), m_(1) {\n      for (int i = 0; i < q; ++i) m_ *= p_;\n\n\
    \      prod_.assign(m_, 1);\n      inv_.assign(m_, 1);\n\n      for (int i = 1;\
    \ i < m_; ++i) {\n        prod_[i] = prod_[i - 1] * (i % p_ == 0 ? 1 : i) % m_;\n\
    \      }\n\n      inv_[m_ - 1] = mod_inv(prod_[m_ - 1], m_);\n      for (int i\
    \ = m_ - 1; i > 0; --i) {\n        inv_[i - 1] = inv_[i] * (i % p_ == 0 ? 1 :\
    \ i) % m_;\n      }\n    }\n\n    int64_t operator()(int64_t n, int64_t k) const\
    \ {\n      int64_t r   = n - k;\n      int64_t e   = 0;\n      int64_t eq  = 0;\n\
    \      int64_t ret = 1;\n\n      for (int i = 0;;) {\n        if (n == 0) { break;\
    \ }\n\n        (ret *= prod_[n % m_]) %= m_;\n        (ret *= inv_[k % m_]) %=\
    \ m_;\n        (ret *= inv_[r % m_]) %= m_;\n\n        n /= p_;\n        k /=\
    \ p_;\n        r /= p_;\n\n        e += n - k - r;\n\n        if (e >= q_) return\
    \ 0;\n\n        i += 1;\n        if (i >= q_) eq += n - k - r;\n      }\n\n  \
    \    if ((p_ != 2 or q_ < 3) and eq % 2 == 1) ret = m_ - ret;\n\n      (ret *=\
    \ mod_pow(p_, e, m_)) %= m_;\n\n      return ret;\n    }\n  };\n\n  class binomial_coefficient\
    \ {\n    std::vector<std::pair<int, int>> m_primes;\n    std::vector<ext_lucas>\
    \ lu;\n    std::vector<int64_t> ms;\n\n  public:\n    binomial_coefficient(int\
    \ m) {\n      for (int64_t i = 2LL; i * i <= m; ++i) {\n        if (m % i == 0)\
    \ {\n          int t = 1, c = 0;\n          while (m % i == 0) {\n           \
    \ m /= i;\n            ++c;\n            t *= i;\n          }\n          m_primes.emplace_back(i,\
    \ c);\n          ms.push_back(t);\n        }\n      }\n\n      if (m != 1) {\n\
    \        m_primes.emplace_back(m, 1);\n        ms.push_back(m);\n      }\n\n \
    \     for (auto [p, q] : m_primes) {\n        lu.push_back(ext_lucas(p, q));\n\
    \      }\n    }\n\n    int64_t operator()(int64_t n, int64_t k) const {\n    \
    \  if (n < k or n < 0 or k < 0) return 0;\n\n      std::vector<int64_t> bs;\n\
    \      for (auto &a : lu) { bs.push_back(a(n, k)); }\n\n      return chinese_remainder_algorithm(bs,\
    \ ms).value().first;\n    }\n  };\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include \"Mylib/Number/Mod/mod_inv.cpp\"\n#include \"Mylib/Number/Mod/mod_pow.cpp\"\
    \n#include \"Mylib/Number/chinese_remainder_algorithm.cpp\"\n#include \"Mylib/Number/extended_gcd.cpp\"\
    \n\nnamespace haar_lib {\n  class ext_lucas {\n    std::vector<int64_t> prod_,\
    \ inv_;\n    int p_, q_;\n    int64_t m_;\n\n  public:\n    ext_lucas(int p, int\
    \ q) : p_(p), q_(q), m_(1) {\n      for (int i = 0; i < q; ++i) m_ *= p_;\n\n\
    \      prod_.assign(m_, 1);\n      inv_.assign(m_, 1);\n\n      for (int i = 1;\
    \ i < m_; ++i) {\n        prod_[i] = prod_[i - 1] * (i % p_ == 0 ? 1 : i) % m_;\n\
    \      }\n\n      inv_[m_ - 1] = mod_inv(prod_[m_ - 1], m_);\n      for (int i\
    \ = m_ - 1; i > 0; --i) {\n        inv_[i - 1] = inv_[i] * (i % p_ == 0 ? 1 :\
    \ i) % m_;\n      }\n    }\n\n    int64_t operator()(int64_t n, int64_t k) const\
    \ {\n      int64_t r   = n - k;\n      int64_t e   = 0;\n      int64_t eq  = 0;\n\
    \      int64_t ret = 1;\n\n      for (int i = 0;;) {\n        if (n == 0) { break;\
    \ }\n\n        (ret *= prod_[n % m_]) %= m_;\n        (ret *= inv_[k % m_]) %=\
    \ m_;\n        (ret *= inv_[r % m_]) %= m_;\n\n        n /= p_;\n        k /=\
    \ p_;\n        r /= p_;\n\n        e += n - k - r;\n\n        if (e >= q_) return\
    \ 0;\n\n        i += 1;\n        if (i >= q_) eq += n - k - r;\n      }\n\n  \
    \    if ((p_ != 2 or q_ < 3) and eq % 2 == 1) ret = m_ - ret;\n\n      (ret *=\
    \ mod_pow(p_, e, m_)) %= m_;\n\n      return ret;\n    }\n  };\n\n  class binomial_coefficient\
    \ {\n    std::vector<std::pair<int, int>> m_primes;\n    std::vector<ext_lucas>\
    \ lu;\n    std::vector<int64_t> ms;\n\n  public:\n    binomial_coefficient(int\
    \ m) {\n      for (int64_t i = 2LL; i * i <= m; ++i) {\n        if (m % i == 0)\
    \ {\n          int t = 1, c = 0;\n          while (m % i == 0) {\n           \
    \ m /= i;\n            ++c;\n            t *= i;\n          }\n          m_primes.emplace_back(i,\
    \ c);\n          ms.push_back(t);\n        }\n      }\n\n      if (m != 1) {\n\
    \        m_primes.emplace_back(m, 1);\n        ms.push_back(m);\n      }\n\n \
    \     for (auto [p, q] : m_primes) {\n        lu.push_back(ext_lucas(p, q));\n\
    \      }\n    }\n\n    int64_t operator()(int64_t n, int64_t k) const {\n    \
    \  if (n < k or n < 0 or k < 0) return 0;\n\n      std::vector<int64_t> bs;\n\
    \      for (auto &a : lu) { bs.push_back(a(n, k)); }\n\n      return chinese_remainder_algorithm(bs,\
    \ ms).value().first;\n    }\n  };\n}  // namespace haar_lib\n"
  dependsOn:
  - Mylib/Number/Mod/mod_inv.cpp
  - Mylib/Number/Mod/mod_pow.cpp
  - Mylib/Number/chinese_remainder_algorithm.cpp
  - Mylib/Number/extended_gcd.cpp
  isVerificationFile: false
  path: Mylib/Combinatorics/binomial_coefficient.cpp
  requiredBy: []
  timestamp: '2021-04-29 01:47:26+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo-judge/binomial_coefficient/main.test.cpp
documentation_of: Mylib/Combinatorics/binomial_coefficient.cpp
layout: document
title: Binomial coefficient
---

## Operations

- `ext_lucas(p, q)`
  - `operator(n, k)`
    - $\binom{n}{k} \bmod p ^ q$

- `binomial_coefficient(m)`
  - `operator(n, k)`
    - $\binom{n}{k} \bmod m$

## Requirements

## Notes

## Problems

## References

- [https://ferin-tech.hatenablog.com/entry/2018/01/17/010829](https://ferin-tech.hatenablog.com/entry/2018/01/17/010829)
- [https://w.atwiki.jp/uwicoder/pages/2118.html](https://w.atwiki.jp/uwicoder/pages/2118.html)
