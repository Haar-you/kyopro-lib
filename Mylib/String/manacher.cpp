#pragma once
#include <vector>
#include <string>

/**
 * @title Manacher法
 * @see https://atcoder.jp/contests/ukuku09/submissions/8413843
 * @return 位置iを中心とした最長奇数長回文の片側長さ(回文長Lに対してL/2+1)の配列
 */
std::vector<int> manacher(const std::string &s){
  const int n = s.size();
  std::vector<int> ret(n);
  int center = 0;

  for(int cur = 0; cur < n; ++cur){
    int left = center - (cur - center);
    
    if(left >= 0 and cur + ret[left] < center + ret[center]){
      ret[cur] = ret[left];
    }else{
      int len = center + ret[center] - cur;
      while(cur-len >= 0 and cur+len < n and s[cur-len] == s[cur+len]) ++len;
      ret[cur] = len;
      center = cur;
    }
  }

  return ret;
}
