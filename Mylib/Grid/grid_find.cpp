#pragma once
#include <vector>
#include "Mylib/Grid/grid.cpp"

namespace haar_lib {
  template <typename C, typename T = typename C::value_type>
  std::vector<cell> grid_find(const std::vector<C> &A, T value){
    const int H = A.size(), W = A[0].size();

    std::vector<cell> ret;
    for(int i = 0; i < H; ++i){
      for(int j = 0; j < W; ++j){
        if(A[i][j] == value){
          ret.emplace_back(i, j);
        }
      }
    }

    return ret;
  }
}
