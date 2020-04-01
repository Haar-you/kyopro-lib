#pragma once

template <typename Func>
void for_each_subset_asc(int a, const Func &f){
  for(int t=0; ; t=(t-a)&a){
    f(t);
    if(t==a) break;
  }
}
