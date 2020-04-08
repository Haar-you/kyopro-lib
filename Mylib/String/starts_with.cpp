#pragma once

/**
 * @title starts_with
 */
template <typename Container, typename T = typename Container::value_type>
bool starts_with(const Container &str, const Container &prefix){
  if(str.size() < prefix.size()) return false;
  for(size_t i = 0; i < prefix.size(); ++i){
    if(str[i] != prefix[i]) return false;
  }
  return true;
}
