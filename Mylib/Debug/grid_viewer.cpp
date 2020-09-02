#pragma once
#include <iostream>
#include <string>
#include <functional>
#include <vector>

/**
 * @docs grid_viewer.md
 */
template <typename C, typename T = typename C::value_type, typename F = std::function<T(T)>>
struct GridViewer {
  std::vector<C> A;
  int width;
  F f;

  GridViewer(const std::vector<C> &A, int width, F f = [](T x){return x;}): A(A), width(width), f(f){}

  std::ostream& run(std::ostream &s) const {
    const int H = A.size();
    const int W = A[0].size();

    auto write_horizon =
      [&](){
        for(int j = 0; j < W; ++j){
          s << "┼";
          for(int k = 0; k < width; ++k) s << "─";
        }
        s << "┼" << "\n";
      };

    for(int i = 0; i < H; ++i){
      write_horizon();

      for(int j = 0; j < W; ++j){
        s << "│";
        s << std::setw(width) << f(A[i][j]);
      }
      s << "│" << "\n";
    }

    write_horizon();

    return s;
  }

  friend std::ostream& operator<<(std::ostream &s, const GridViewer &viewer){
    return viewer.run(s);
  }
};
