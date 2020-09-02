#pragma once
#include <vector>

/**
 * @docs Polynomial Taylor shift
 * @title polynomial_taylor_shift.md
 */
template <typename T, typename Conv>
auto polynomial_taylor_shift(std::vector<T> a, T c, const Conv &convolve){
  const int N = a.size();
  T f = 1;
  std::vector<T> A(2 * N - 1);
  for(int i = 0; i < N; ++i){
    if(i) f *= i;
    A[i + N - 1] = a[i] * f;
  }

  T d = 1;

  std::vector<T> g(N);
  g[N - 1] = f.inv();
  for(int i = N - 2; i >= 0; --i) g[i] = g[i + 1] * (i + 1);

  std::vector<T> B(2 * N - 1);
  for(int i = 0; i < N; ++i){
    B[N - i - 1] = d * g[i];
    d *= c;
  }

  auto C = convolve(A, B);

  std::vector<T> ret(N);
  for(int i = 0; i < N; ++i) ret[i] = C[(N - 1) * 2 + i] * g[i];

  return ret;
}

