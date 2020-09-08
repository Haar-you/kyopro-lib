#pragma once
#include <vector>
#include <tuple>
#include <algorithm>

/**
 * @title Zip function
 * @docs zip.md
 */
namespace haar_lib {
  template <typename ... Args>
  auto zip(std::vector<Args> ... a){
    const int N = std::min({a.size() ...});
    std::vector<std::tuple<Args ...>> ret(N);

    for(int i = 0; i < N; ++i){
      ret[i] = std::make_tuple(a[i] ...);
    }

    return ret;
  }
}
