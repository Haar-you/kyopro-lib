#pragma once
#include <set>
#include <utility>

/**
 * @docs merge_technique.md
 */
template <typename T>
void merge_technique(std::set<T> &res, std::set<T> &a, std::set<T> &b){
  if(a.size() > b.size()){
    a.insert(b.begin(), b.end());
    std::swap(res, a);
  }else{
    b.insert(a.begin(), a.end());
    std::swap(res, b);
  }
}
