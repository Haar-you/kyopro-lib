#pragma once

/**
 * @note for each subset b ⊆ a
 */
template <typename Func>
void for_each_subset_desc(int a, const Func &f){
  for(int t=a; ; t=(t-1)&a){
    f(t);
    if(t==0) break;
  }
}
