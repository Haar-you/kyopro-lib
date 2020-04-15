#pragma once
#include <functional>
#include <cmath>

/**
 * @title 下に凸の黄金分割探索
 */
template <typename T = double, typename Func = std::function<T(T)>>
T golden_section_search_downwards(T lb, T ub, const Func &f, int LOOP_COUNT = 100){
  static const T phi = (1.0 + std::sqrt(5)) / 2;
  
  T t1, t2;

  while(LOOP_COUNT--){
    t1 = (lb * phi + ub) / (phi + 1.0);
    t2 = (lb + ub * phi) / (phi + 1.0);

    if(f(t1) < f(t2)){
      ub = t2;
    }else{
      lb = t1;
    }
  }

  return lb;
}
