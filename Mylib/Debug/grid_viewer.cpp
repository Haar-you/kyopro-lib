#pragma once
#include <iostream>
#include <string>
#include <functional>
#include <vector>

/**
 * @docs grid_viewer.md
 */
template <typename C>
void grid_viewer([[maybe_unused]] const C &A, [[maybe_unused]] int width = 10){
#ifdef DEBUG
  const int H = A.size();
  const int W = A[0].size();

  std::cerr << "    ";
  for(int j = 0; j < W; ++j){
    std::cerr << "\e[1;32m" << std::left << std::setw(width) << j << "\e[m";
  }
  std::cerr << "\n";
  std::cerr << std::right;

  for(int i = 0; i < H; ++i){
    std::cerr << "\e[1;32m" << std::setw(2) << i << "|\e[m ";

    for(int j = 0; j < W; ++j){
      std::stringstream ss;
      ss << A[i][j];
      auto s = ss.str();
      if(s.size() > width){
        s.resize(width);
      }else{
        while(s.size() < width) s.push_back(' ');
      }

      std::cerr << s << "";
    }

    std::cerr << "\n";
  }

  std::cerr << std::right;
  std::cerr << std::setw(0);
#endif
}
