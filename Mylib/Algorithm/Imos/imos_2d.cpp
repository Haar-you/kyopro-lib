#pragma once
#include <vector>

/**
 * @title 2D Imos algorithm
 * @docs imos_2d.md
 */
namespace haar_lib {
  template <typename T>
  struct imos_2d {
    using value_type = T;

    std::vector<std::vector<T>> vec;
    int n, m;
    imos_2d(int n, int m): vec(n + 1, std::vector<T>(m + 1)), n(n), m(m){}

    void add(int a1, int b1, int a2, int b2){ // [a1, a2) [b1, b2)
      vec[a1][b1] += 1;
      vec[a2][b2] += 1;
      vec[a1][b2] -= 1;
      vec[a2][b1] -= 1;
    }

    void build(){
      for(int i = 0; i < n; ++i){
        for(int j = 0; j < m + 1; ++j){
          vec[i + 1][j] += vec[i][j];
        }
      }

      for(int i = 0; i < n + 1; ++i){
        for(int j = 0; j < m; ++j){
          vec[i][j + 1] += vec[i][j];
        }
      }
    }

    const std::vector<T>& operator[](size_t i) const {return vec[i];}
  };
}
