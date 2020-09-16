#pragma once
#include <vector>
#include <utility>
#include <cstdint>

namespace haar_lib {
  template <typename Container>
  auto run_length_encoding(const Container &v){
    using T = typename Container::value_type;

    std::vector<std::pair<T, int64_t>> ret;

    for(auto &x : v){
      if(ret.empty()) ret.emplace_back(x, 1);
      else if(ret.back().first == x) ++ret.back().second;
      else ret.emplace_back(x, 1);
    }

    return ret;
  }
}
