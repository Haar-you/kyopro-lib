#pragma once
#include <vector>
#include <algorithm>
#include "Mylib/TypicalProblem/MaxRectangleProblem/max_rectangle_in_histogram.cpp"

namespace haar_lib {
  template <typename T>
  int max_rectangle(const std::vector<std::vector<T>> &d, T value){
    const int H = d.size();
    const int W = d[0].size();

    std::vector<std::vector<int>> c(H, std::vector<int>(W));
    for(int i = 0; i < H; ++i){
      for(int j = 0; j < W; ++j){
        if(d[i][j] == value) c[i][j] = 1;
      }
    }

    for(int i = 1; i < H; ++i){
      for(int j = 0; j < W; ++j){
        if(c[i][j]){
          c[i][j] += c[i - 1][j];
        }
      }
    }

    int ret = 0;
    for(int i = 0; i < H; ++i){
      int t = max_rectangle_in_histogram<int>(c[i]);
      ret = std::max(ret, t);
    }

    return ret;
  }
}
