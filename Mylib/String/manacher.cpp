#pragma once
#include <vector>

/**
 * @title Manacher algorithm
 * @docs manacher.md
 */
template <typename Container, typename T = typename Container::value_type>
std::vector<int> manacher(const Container &s){
  const int n = s.size();
  std::vector<int> ret(n);
  int center = 0;

  for(int cur = 0; cur < n; ++cur){
    int left = center - (cur - center);

    if(left >= 0 and cur + ret[left] < center + ret[center]){
      ret[cur] = ret[left];
    }else{
      int len = center + ret[center] - cur;
      while(cur - len >= 0 and cur + len < n and s[cur - len] == s[cur + len]) ++len;
      ret[cur] = len;
      center = cur;
    }
  }

  return ret;
}
