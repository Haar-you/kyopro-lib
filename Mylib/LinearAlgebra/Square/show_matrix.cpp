#pragma once
#include <iostream>

/**
 * @docs show_matrix.md
 */
template <typename M, typename T = typename M::value_type>
void show_matrix(const M &m, int w = 10){
#ifdef DEBUG
  const int N = m.size();
  
  std::cerr << "⎛" << std::string((w+1)*N, ' ') << "⎞" << std::endl;
  for(int i = 0; i < N; ++i){
    std::cerr << "⎜";
    for(int j = 0; j < N; ++j) std::cerr << std::setw(w) << m[i][j] << " ";
    std::cerr << "⎟";
    std::cerr << std::endl;
  }
  std::cerr << "⎝" << std::string((w+1)*N, ' ') << "⎠" << std::endl;
#endif
}
