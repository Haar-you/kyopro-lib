#pragma once
#include <vector>

template <typename T> T determinant(std::vector<std::vector<T>> m){
  const int n = m.size();
  int s = 0;

  for(int i = 0; i < n; ++i){
    if(m[i][i] == 0){
      for(int j = i+1; j < n; ++j){
        if(m[j][i] != 0){
          m[i].swap(m[j]);
          (s += 1) %= 2;
          break; 
        }
        if(j == n-1) return 0;
      }
    }
    
    for(int j = i+1; j < n; ++j){
      T t = m[j][i] / m[i][i];
      for(int k = 0; k < n; ++k) m[j][k] -= m[i][k] * t;
    }
  }

  T ret = s ? -1 : 1;
  for(int i = 0; i < n; ++i) ret *= m[i][i];
  return ret;
}
