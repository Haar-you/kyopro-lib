#pragma once
#include <string>
#include <vector>

/**
 * @title split
 * @docs split.md
 */
auto split(const std::string &s, const std::string &delim){
  std::vector<std::string> ret;

  size_t i = 0;
  while(1){
    size_t j = s.find(delim, i);
    if(j == std::string::npos) break;

    ret.push_back(s.substr(i,j-i));

    i = j + delim.size();
  }

  ret.push_back(s.substr(i,s.size()-i));

  return ret;
}
