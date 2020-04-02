#pragma once
#include <vector>
#include <utility>

/**
 * @title 掃き出し法
 */
template <typename T> int gaussian_elimination(std::vector<std::vector<T>> &a){
  const int h = a.size();
  const int w = a[0].size();
  int rank = 0;
  
  for(int j = 0; j < w; ++j){
    int pivot = -1;
    
    for(int i = rank; i < h; ++i){
      if(a[i][j] != 0){
        pivot = i;
        break;
      }
    }

    if(pivot == -1) continue;

    std::swap(a[pivot], a[rank]);

    auto d = a[rank][j];
    for(int k = 0; k < w; ++k) a[rank][k] /= d;

    for(int i = 0; i < h; ++i){
      if(i == rank or a[i][j] == 0) continue;
      auto d = a[i][j];
      for(int k = 0; k < w; ++k){
        a[i][k] -= a[rank][k] * d;
      }
    }

    ++rank;
  }

  return rank;
}
