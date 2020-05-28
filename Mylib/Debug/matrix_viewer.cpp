#pragma once
#include <iostream>
#include <string>
#include <iomanip>

/**
 * @docs matrix_viewer.md
 */
template <typename M, typename T = typename M::value_type>
struct MatrixViewer{
  M m;
  int w;

  MatrixViewer(const M &m, int w = 10): m(m), w(w){}

  friend std::ostream& operator<<(std::ostream &s, const MatrixViewer &viewer){
    int w = viewer.w;
    const auto m = viewer.m;
    const int N = m.size();

    s << "⎛" << std::string((w+1)*N, ' ') << "⎞" << std::endl;
    for(int i = 0; i < N; ++i){
      s << "⎜";
      for(int j = 0; j < N; ++j) s << std::setw(w) << m[i][j] << " ";
      s << "⎟";
      s << std::endl;
    }
    s << "⎝" << std::string((w+1)*N, ' ') << "⎠" << std::endl;

    return s;
  }
};
