#pragma once

template <typename M, typename T = typename M::value_type>
M power(M a, uint64_t p){
  const int N = a.size();

  if(p == 0) return M::make_unit(N);
  if(p == 1) return a;

  M temp = power(a, p >> 1);
  auto ret = temp * temp;

  if(p & 1) ret *= a;  
  
  return ret;
}
