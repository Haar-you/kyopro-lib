#pragma once
#include <vector>

/**
 * @title 1D Imos algorithm (Linear addition)
 * @docs linear_imos_1d.md
 */
namespace haar_lib {
  template <typename T>
  struct LinearImos1D {
    using value_type = T;

    std::vector<T> vec_a, vec_a_end, vec_b, vec;
    int n;

    LinearImos1D(int n): vec_a(n + 1), vec_a_end(n + 1), vec_b(n + 1), vec(n + 1), n(n){}

    void add(int s, int t, const T &a, const T &b){ // x ∈ [s, t)にax+bを加算する。
      vec_a[s + 1] += a;
      vec_a[t] -= a;

      vec_a_end[t] -= a * (t - s - 1);

      vec_b[s] += a * s + b;
      vec_b[t] -= a * s + b;
    }

    void build(){
      for(int i = 0; i < n; ++i) vec_a[i + 1] += vec_a[i];
      for(int i = 0; i <= n; ++i) vec_a[i] += vec_a_end[i];
      for(int i = 0; i < n; ++i) vec_a[i + 1] += vec_a[i];

      for(int i = 0; i < n; ++i) vec_b[i + 1] += vec_b[i];

      for(int i = 0; i <= n; ++i) vec[i] = vec_a[i] + vec_b[i];
    }

    T operator[](size_t i) const {return vec[i];}
  };
}
