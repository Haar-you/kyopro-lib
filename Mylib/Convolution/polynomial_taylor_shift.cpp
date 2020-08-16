#pragma once
#include <vector>

/**
 * @docs Polynomial Taylor shift
 * @title polynomial_taylor_shift.md
 */
template <typename T, typename Ft, typename Conv>
auto polynomial_taylor_shift(std::vector<T> a, T c, const Ft &ft, const Conv &convolve){
  const int N = a.size();
  
  std::vector<T> A(2 * N - 1);
  for(int i = 0; i < N; ++i){
    A[i + N - 1] = a[i] * ft.factorial(i);
  }

  T d = 1;
  
  std::vector<T> B(2 * N - 1);
  for(int i = 0; i < N; ++i){
    B[N - i - 1] = d * ft.inv_factorial(i);
    d *= c;
  }

  auto C = convolve(A, B);

  std::vector<T> ret(N);
  for(int i = 0; i < N; ++i) ret[i] = C[(N - 1) * 2 + i] * ft.inv_factorial(i);

  return ret;
}
