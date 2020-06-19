#pragma once
#include <functional>

/**
 * @title Ternary search (Convex upwards)
 * @docs ternary_search_upwards.md
 */
template <typename T = double, typename Func = std::function<T(T)>>
T ternary_search_upwards(T lb, T ub, const Func &f, int LOOP_COUNT = 100){
  T t1 = 0, t2 = 0;
  
  while(LOOP_COUNT--){
    t1 = lb + (ub-lb) / 3;
    t2 = lb + (ub-lb) / 3 * 2;
    
    if(f(t1) > f(t2)){
      ub = t2;
    }else{
      lb = t1;
    }
  }
 
  return lb;
}
