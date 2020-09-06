#pragma once
#include <cstddef>

/**
 * @title starts_with
 * @docs starts_with.md
 */
template <typename Container, typename T = typename Container::value_type>
bool starts_with(const Container &str, const Container &prefix){
  if(str.size() < prefix.size()) return false;
  for(size_t i = 0; i < prefix.size(); ++i){
    if(str[i] != prefix[i]) return false;
  }
  return true;
}
