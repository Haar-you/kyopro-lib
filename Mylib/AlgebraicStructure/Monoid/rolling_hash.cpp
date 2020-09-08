#pragma once
#include <array>
#include <utility>

/**
 * @title Rolling hash monoid
 * @docs rolling_hash.md
 */
namespace haar_lib {
  template <size_t N>
  struct RollingHashMonoid {
    static std::array<int64_t, N> base;
    static int64_t mod;

    using value_type = std::pair<std::array<int64_t, N>, std::array<int64_t, N>>;

    value_type operator()() const {
      value_type ret;
      for(size_t i = 0; i < N; ++i){
        ret.first[i] = 0LL;
        ret.second[i] = 1LL;
      }
      return ret;
    }

    value_type operator()(const value_type &a, const value_type &b) const {
      value_type ret;
      for(size_t i = 0; i < N; ++i){
        ret.first[i] = (a.first[i] + b.first[i] * a.second[i] % mod) % mod;
        ret.second[i] = a.second[i] * b.second[i] % mod;
      }
      return ret;
    }

    template <typename T>
    static value_type make(T a){
      value_type ret;
      for(size_t i = 0; i < N; ++i){
        ret.first[i] = (int64_t)a % mod;
        ret.second[i] = base[i];
      }
      return ret;
    }
  };

  template <size_t N> std::array<int64_t, N> RollingHashMonoid<N>::base;
  template <size_t N> int64_t RollingHashMonoid<N>::mod;
}
