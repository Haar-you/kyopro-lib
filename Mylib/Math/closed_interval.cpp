#pragma once
#include <optional>
#include <utility>
#include <iostream>
#include <algorithm>

namespace haar_lib {
  template <typename T>
  struct closed_interval {
    std::optional<std::pair<std::optional<T>, std::optional<T>>> value;

    closed_interval(){}
    closed_interval(std::optional<T> l, std::optional<T> r):
      value(std::make_pair(l, r)){}

    friend std::ostream& operator<<(std::ostream &s, const closed_interval<T> &a){
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
  auto intersect(closed_interval<T> a, closed_interval<T> b){
    if(not a.value or not b.value) return closed_interval<T>();
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
        return closed_interval<T>();
      }
    }

    return closed_interval<T>(l, r);
  }

  template <typename T>
  auto left_expand(closed_interval<T> a, T x){
    if(a.value and (a.value)->first){
      *((a.value)->first) += x;
      if((a.value)->second and *((a.value)->first) > *((a.value)->second)){
        return closed_interval<T>();
      }
    }

    return a;
  }

  template <typename T>
  auto right_expand(closed_interval<T> a, T x){
    if(a.value and (a.value)->second){
      *((a.value)->second) += x;
      if((a.value)->first and *((a.value)->first) > *((a.value)->second)){
        return closed_interval<T>();
      }
    }

    return a;
  }

  template <typename T>
  auto operator+(closed_interval<T> a, T k){
    if(a.value){
      if(a.value->first) a.value->first.value() += k;
      if(a.value->second) a.value->second.value() += k;
    }
    return a;
  }

  template <typename T>
  auto operator-(closed_interval<T> a, T k){
    if(a.value){
      if(a.value->first) a.value->first.value() -= k;
      if(a.value->second) a.value->second.value() -= k;
    }
    return a;
  }

  template <typename T>
  auto operator*(closed_interval<T> a, T k){
    if(a.value){
      if(k < 0) std::swap(a.value->first, a.value->second);
      if(a.value->first) a.value->first.value() *= k;
      if(a.value->second) a.value->second.value() *= k;
    }
    return a;
  }
}
