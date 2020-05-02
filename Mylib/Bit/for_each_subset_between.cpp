#pragma once

/**
 * @docs for_each_subset_between.md
 */
template <typename Func>
void for_each_subset_between(int a, int b, const Func &f){
  int x = b^(a&b);
  for(int t=x; ; t=(t-1)&x){
    f(t|a);
    if(t==0) break;
  }
}
