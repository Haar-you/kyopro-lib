#pragma once
#include <vector>
#include "Mylib/String/suffix_array.cpp"

/**
 * @title LCP(Longest Common Prefix) array
 * @docs lcp_array.md
 */
template <typename T>
auto lcp_array(const SuffixArray<T> &sa){
  const int n = sa.size();
  std::vector<int> rank(n), ret(n);

  for(int i = 0; i < n; ++i) rank[sa[i]] = i;

  int h = 0;
  for(int i = 0; i < n; ++i){
    if(rank[i] == 0) continue;
    int j = sa[rank[i] - 1];

    if(h) --h;
    while(j + h < n and i + h < n){
      if(sa.s[j + h] != sa.s[i + h]) break;
      ++h;
    }

    ret[rank[i]] = h;
  }

  return ret;
}
