#pragma once
#include <set>
#include <utility>

/**
 * @docs merge_technique.md
 */
template <typename T>
void merge_technique(std::set<T> &res, std::set<T> &a, std::set<T> &b){
  if(a.size() > b.size()){
    for(const auto &x : b){
      a.insert(x);
    }
    std::swap(res, a);
  }else{
    for(const auto &x : a){
      b.insert(x);
    }
    std::swap(res, b);
  }
}
