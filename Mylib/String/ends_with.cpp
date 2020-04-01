#pragma once
#include <string>

bool ends_with(const std::string &str, const std::string &suffix){
  if(str.size() < suffix.size()) return false;
  int n = str.size(), m = suffix.size();
  for(size_t i = 0; i < suffix.size(); ++i){
    if(str[n-1-i] != suffix[m-1-i]) return false;
  }
  return true;
}
