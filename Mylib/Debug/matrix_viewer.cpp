#pragma once
#include <iostream>
#include <string>
#include <iomanip>

template <typename M>
void matrix_viewer([[maybe_unused]] const M &m, [[maybe_unused]] int w = 10){
#ifdef DEBUG
  const int N = m.size();
  std::cerr << "⎛" << std::string((w + 1) * N, ' ') << "⎞" << std::endl;
  for(int i = 0; i < N; ++i){
    std::cerr << "⎜";
    for(int j = 0; j < N; ++j) std::cerr << std::setw(w) << m[i][j] << " ";
    std::cerr << "⎟";
    std::cerr << std::endl;
  }
  std::cerr << "⎝" << std::string((w + 1) * N, ' ') << "⎠" << std::endl;
#endif
}
