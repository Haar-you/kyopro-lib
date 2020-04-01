#pragma once

/**
 * @note for each superset b ⊇ a
 */
template <typename Func>
void for_each_superset_desc(int a, int n, const Func &f){
  int x = (1<<n)-1, y = x^(a&x);
  for(int t=y; ; t=(t-1)&y){
    f(t|a);
    if(t==0) break;
  }
}
