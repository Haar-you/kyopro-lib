#pragma once
#include <string>

bool starts_with(const std::string &str, const std::string &prefix){
  if(str.size() < prefix.size()) return false;
  for(size_t i = 0; i < prefix.size(); ++i){
    if(str[i] != prefix[i]) return false;
  }
  return true;
}
