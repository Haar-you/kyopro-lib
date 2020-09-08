#pragma once
#include <vector>

/**
 * @title 1D Imos algorithm
 * @docs imos_1d.md
 */
namespace haar_lib {
  template <typename T>
  struct imos_1d {
    using value_type = T;

    std::vector<T> data;
    imos_1d(int n): data(n + 1){}

    void add(int a, int b, const T& val){ // [a, b)
      data[a] += 1;
      data[b] -= 1;
    }

    void build(){
      for(int i = 0; i < (int)data.size() - 1; ++i){
        data[i + 1] += data[i];
      }
    }

    T operator[](size_t i) const {return data[i];}
  };
}
