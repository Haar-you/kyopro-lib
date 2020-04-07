#pragma once
#include <vector>
#include <tuple>
#include "Mylib/Number/extended_gcd.cpp"

/**
 * @title 中国剰余定理
 */
bool CRA(int64_t b1, int64_t m1, int64_t b2, int64_t m2, int64_t &r, int64_t &m){
  int64_t p,q,d;
  std::tie(d,p,q) = ext_gcd(m1,m2);
  if((b2-b1) % d != 0) return false;
  m = m1 * m2 / d;
  int64_t t = ((b2-b1) * p / d) % (m2 / d);
  r = (b1 + m1 * t + m) % m;
  return true;
}

bool CRA(const std::vector<int64_t> &bs, const std::vector<int64_t> &ms, int64_t &r, int64_t &m){
  int64_t R = 0, M = 1;
  for(int i = 0; i < (int)bs.size(); ++i){
    if(not CRA(R,M,bs[i],ms[i],r,m)) return false;
    R = r;
    M = m;
  }
  return true;
}

