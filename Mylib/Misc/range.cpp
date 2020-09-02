#pragma once
#include <optional>
#include <utility>
#include <iostream>
#include <algorithm>

/**
 * @docs range.md
 */
template <typename T>
struct Range {
  std::optional<std::pair<std::optional<T>, std::optional<T>>> value;

  Range(){}
  Range(std::optional<T> l, std::optional<T> r): value(std::make_pair(l, r)){}

  friend std::ostream& operator<<(std::ostream &s, const Range<T> &a){
    s << "[";
    if(a.value){
      if((a.value)->first) s << *((a.value)->first);
      else s << "-∞ ";
      s << ",";
      if((a.value)->second) s << *((a.value)->second);
      else s << "∞ ";
    }
    s << "]";
    return s;
  }

  bool is_null() const {
    return not value;
  }

  bool contains(T v) const {
    if(not value) return false;
    if(value->first and v < *(value->first)) return false;
    if(value->second and v > *(value->second)) return false;

    return true;
  }
};

template <typename T>
auto intersect(Range<T> a, Range<T> b){
  if(not a.value or not b.value) return Range<T>();
  std::optional<T> l, r;

  if((a.value)->first){
    l = *((a.value)->first);
  }

  if((b.value)->first){
    if(l) l = std::max(*l, *((b.value)->first));
    else l = *((b.value)->first);
  }

  if((a.value)->second){
    r = *((a.value)->second);
  }

  if((b.value)->second){
    if(r) r = std::min(*r, *((b.value)->second));
    else r = *((b.value)->second);
  }

  if(l and r){
    if(*l > *r){
      return Range<T>();
    }
  }

  return Range<T>(l, r);
}

template <typename T>
auto left_expand(Range<T> a, T x){
  if(a.value and (a.value)->first){
    *((a.value)->first) += x;
    if((a.value)->second and *((a.value)->first) > *((a.value)->second)){
      return Range<T>();
    }
  }

  return a;
}

template <typename T>
auto right_expand(Range<T> a, T x){
  if(a.value and (a.value)->second){
    *((a.value)->second) += x;
    if((a.value)->first and *((a.value)->first) > *((a.value)->second)){
      return Range<T>();
    }
  }

  return a;
}
