#pragma once
#include <vector>
#include "Mylib/String/suffix_array.cpp"

template <typename T>
struct LCPArray{
  const int n;
  std::vector<int> rank, lcp_array;

  LCPArray(const SuffixArray<T> &sa): n(sa.n), rank(n), lcp_array(n-1){
    for(int i = 0; i < n; ++i) rank[sa[i]] = i;

    int h = 0;
    for(int i = 0; i < n; ++i){
      if(rank[i] == 0) continue;
      int j = sa[rank[i]-1];

      if(h) --h;
      while(j+h < n and i+h < n){
        if(sa.str[j+h] != sa.str[i+h]) break;
        ++h;
      }

      lcp_array[rank[i]-1] = h;
    }
  }
};
