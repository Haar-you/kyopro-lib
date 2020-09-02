#pragma once

/**
 * @title Enumerate supersets (Descending order)
 * @docs for_each_superset_desc.md
 */
template <typename Func>
void superset_desc(int a, int n, const Func &f){
  const int x = (1 << n) - 1, y = x ^ (a & x);
  for(int t = y; ; t = (t - 1) & y){
    if(not f(t | a)) break;
    if(t == 0) break;
  }
}
