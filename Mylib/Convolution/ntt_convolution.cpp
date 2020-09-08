#pragma once
#include <vector>
#include <cassert>
#include <utility>
#include <algorithm>
#include "Mylib/Number/Mint/mint.cpp"

/**
 * @title Number theoretic transform
 * @docs ntt_convolution.md
 */
namespace haar_lib {
  template <typename T, int PRIM_ROOT, int MAX_SIZE>
  class number_theoretic_transform {
  public:
    using value_type = T;
    constexpr static int primitive_root = PRIM_ROOT;

  private:
    const int MAX_POWER;
    std::vector<T> BASE, INV_BASE;

  public:
    number_theoretic_transform():
      MAX_POWER(__builtin_ctz(MAX_SIZE)),
      BASE(MAX_POWER + 1),
      INV_BASE(MAX_POWER + 1)
    {
      static_assert((MAX_SIZE & (MAX_SIZE - 1)) == 0, "MAX_SIZE must be power of 2.");

      T t = T::power(PRIM_ROOT, (T::MOD - 1) >> (MAX_POWER + 2));
      T s = t.inv();

      for(int i = MAX_POWER - 1; i >= 0; --i){
        t *= t;
        s *= s;
        BASE[i] = -t;
        INV_BASE[i] = -s;
      }
    }

    void run(std::vector<T> &f, bool INVERSE = false){
      const int n = f.size();
      assert((n & (n - 1)) == 0 and n <= MAX_SIZE); // データ数は2の冪乗個

      if(INVERSE){
        for(int b = 1; b < n; b <<= 1){
          T w = 1;
          for(int j = 0, k = 1; j < n; j += 2 * b, ++k){
            for(int i = 0; i < b; ++i){
              const auto s = f[i + j];
              const auto t = f[i + j + b];

              f[i + j] = s + t;
              f[i + j + b] = (s - t) * w;
            }
            w *= INV_BASE[__builtin_ctz(k)];
          }
        }

        const T t = T::inv(n);
        for(auto &x : f) x *= t;
      }else{
        for(int b = n >> 1; b; b >>= 1){
          T w = 1;
          for(int j = 0, k = 1; j < n; j += 2 * b, ++k){
            for(int i = 0; i < b; ++i){
              const auto s = f[i + j];
              const auto t = f[i + j + b] * w;

              f[i + j] = s + t;
              f[i + j + b] = s - t;
            }
            w *= BASE[__builtin_ctz(k)];
          }
        }
      }
    }

    template <typename U>
    std::vector<T> convolve(std::vector<U> f, std::vector<U> g){
      const int m = f.size() + g.size() - 1;
      int n = 1;
      while(n < m) n *= 2;

      std::vector<T> f2(n), g2(n);

      for(int i = 0; i < (int)f.size(); ++i) f2[i] = f[i];
      for(int i = 0; i < (int)g.size(); ++i) g2[i] = g[i];

      run(f2);
      run(g2);

      for(int i = 0; i < n; ++i) f2[i] *= g2[i];
      run(f2, true);

      return f2;
    }
  };

  template <typename T, typename U>
  std::vector<T> convolve_general_mod(std::vector<U> f, std::vector<U> g){
    static constexpr int M1 = 167772161, P1 = 3;
    static constexpr int M2 = 469762049, P2 = 3;
    static constexpr int M3 = 1224736769, P3 = 3;

    for(auto &x : f) x %= T::MOD;
    for(auto &x : g) x %= T::MOD;

    auto res1 = number_theoretic_transform<modint<M1>, P1, 1 << 20>().convolve(f, g);
    auto res2 = number_theoretic_transform<modint<M2>, P2, 1 << 20>().convolve(f, g);
    auto res3 = number_theoretic_transform<modint<M3>, P3, 1 << 20>().convolve(f, g);

    const int n = res1.size();

    std::vector<T> ret(n);

    const int64_t M12 = (int64_t)modint<M2>::inv(M1);
    const int64_t M13 = (int64_t)modint<M3>::inv(M1);
    const int64_t M23 = (int64_t)modint<M3>::inv(M2);

    for(int i = 0; i < n; ++i){
      const int64_t r[3] = {(int64_t)res1[i], (int64_t)res2[i], (int64_t)res3[i]};

      const int64_t t0 = r[0] % M1;
      const int64_t t1 = (r[1] - t0 + M2) * M12 % M2;
      const int64_t t2 = ((r[2] - t0 + M3) * M13 % M3 - t1 + M3) * M23 % M3;

      ret[i] = T(t0) + T(t1) * M1 + T(t2) * M1 * M2;
    }

    return ret;
  }
}
