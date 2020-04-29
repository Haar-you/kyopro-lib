#pragma once
#include <vector>
#include <algorithm>
#include "Mylib/TypicalProblem/MaxRectangleProblem/max_rectangle_in_histogram.cpp"

/**
 * @title 最大面積長方形の面積
 * @docs max_rectangle.md
 */
int max_rectangle(const std::vector<std::vector<int>> &d){
  int H = d.size();
  int W = d[0].size();
    
  std::vector<std::vector<int>> c(d);
  for(int i = 1; i < H; ++i){
    for(int j = 0; j < W; ++j){
      if(c[i][j]){
        c[i][j] += c[i-1][j];
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
