#pragma once
#include <vector>
#include <utility>

/**
 * @title 連長圧縮
 */
template <typename Container, typename T = typename Container::value_type>
auto run_length_encode(const Container &v){
  std::vector<std::pair<T,int64_t>> ret;

  for(auto &x : v){
    if(ret.empty()) ret.push_back({x,1});
    else if(ret.back().first == x) ++ret.back().second;
    else ret.push_back({x,1});
  }

  return ret;
}
