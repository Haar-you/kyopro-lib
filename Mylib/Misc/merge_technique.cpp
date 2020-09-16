#pragma once
#include <set>
#include <utility>

namespace haar_lib {
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
}
