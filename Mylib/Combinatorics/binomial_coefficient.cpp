#pragma once
#include "Mylib/Number/Mod/mod_inv.cpp"
#include "Mylib/Number/Mod/mod_pow.cpp"
#include "Mylib/Number/chinese_remainder_algorithm.cpp"
#include "Mylib/Number/extended_gcd.cpp"

namespace haar_lib {
  class ext_lucas {
    std::vector<int64_t> prod_, inv_;
    int p_, q_;
    int64_t m_;

  public:
    ext_lucas(int p, int q) : p_(p), q_(q), m_(1) {
      for (int i = 0; i < q; ++i) m_ *= p_;

      prod_.assign(m_, 1);
      inv_.assign(m_, 1);

      for (int i = 1; i < m_; ++i) {
        prod_[i] = prod_[i - 1] * (i % p_ == 0 ? 1 : i) % m_;
      }

      inv_[m_ - 1] = mod_inv(prod_[m_ - 1], m_);
      for (int i = m_ - 1; i > 0; --i) {
        inv_[i - 1] = inv_[i] * (i % p_ == 0 ? 1 : i) % m_;
      }
    }

    int64_t operator()(int64_t n, int64_t k) const {
      int64_t r   = n - k;
      int64_t e   = 0;
      int64_t eq  = 0;
      int64_t ret = 1;

      for (int i = 0;;) {
        if (n == 0) { break; }

        (ret *= prod_[n % m_]) %= m_;
        (ret *= inv_[k % m_]) %= m_;
        (ret *= inv_[r % m_]) %= m_;

        n /= p_;
        k /= p_;
        r /= p_;

        e += n - k - r;

        if (e >= q_) return 0;

        i += 1;
        if (i >= q_) eq += n - k - r;
      }

      if ((p_ != 2 or q_ < 3) and eq % 2 == 1) ret = m_ - ret;

      (ret *= mod_pow(p_, e, m_)) %= m_;

      return ret;
    }
  };

  class binomial_coefficient {
    std::vector<std::pair<int, int>> m_primes;
    std::vector<ext_lucas> lu;
    std::vector<int64_t> ms;

  public:
    binomial_coefficient(int m) {
      for (int64_t i = 2LL; i * i <= m; ++i) {
        if (m % i == 0) {
          int t = 1, c = 0;
          while (m % i == 0) {
            m /= i;
            ++c;
            t *= i;
          }
          m_primes.emplace_back(i, c);
          ms.push_back(t);
        }
      }

      if (m != 1) {
        m_primes.emplace_back(m, 1);
        ms.push_back(m);
      }

      for (auto [p, q] : m_primes) {
        lu.push_back(ext_lucas(p, q));
      }
    }

    int64_t operator()(int64_t n, int64_t k) const {
      if (n < k or n < 0 or k < 0) return 0;

      std::vector<int64_t> bs;
      for (auto &a : lu) { bs.push_back(a(n, k)); }

      return chinese_remainder_algorithm(bs, ms).value().first;
    }
  };
}  // namespace haar_lib
