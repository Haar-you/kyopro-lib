#pragma once
#include <vector>
#include "Mylib/Grid/grid.cpp"

/**
 * @title グリッドで条件を満たす点を列挙する
 * @docs grid_find.md
 */
template <typename C, typename T = typename C::value_type>
auto grid_find(const std::vector<C> &A, T value){
  const int H = A.size(), W = A[0].size();
  
  std::vector<Point> ret;
  for(int i = 0; i < H; ++i){
    for(int j = 0; j < W; ++j){
      if(A[i][j] == value){
        ret.emplace_back(i, j);
      }
    }
  }

  return ret;  
}
