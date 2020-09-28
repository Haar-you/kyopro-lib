#pragma once
#include <vector>
#include <functional>

namespace haar_lib {
  template <typename T, typename Func = std::minus<T>>
  std::vector<T> fast_mobius_transform_superset(std::vector<T> f, const Func &op = std::minus<T>()){
    for(int i = 0; (1 << i) < (int)f.size(); ++i){
      for(int j = 0; j < (int)f.size(); ++j){
        if(not (j & (1 << i))) f[j] = op(f[j], f[j ^ (1 << i)]);
      }
    }
    return f;
  }
}
