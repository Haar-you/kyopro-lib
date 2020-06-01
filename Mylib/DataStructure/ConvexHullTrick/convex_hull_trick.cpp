#pragma once
#include <deque>
#include <utility>
#include <functional>

/**
 * @title Convex hull trick
 * @docs convex_hull_trick.md
 */
template <typename T, typename Comparator = std::greater<T>>
class ConvexHullTrick{
  std::deque<std::pair<T,T>> lines;
  bool is_needless(const std::pair<T,T> &a, const std::pair<T,T> &b, const std::pair<T,T> &c){
    return (a.second-b.second)*(a.first-c.first) >= (a.second-c.second)*(a.first-b.first);
  }
  
  T apply(const std::pair<T,T> &f, const T &x){
    return f.first*x + f.second;
  }

  Comparator comp = Comparator();

public:
  ConvexHullTrick(){}
  
  void add(const T &a, const T &b){
    if(!lines.empty()){
      std::pair<T,T> l = lines.back();
      
      if(l.first == a){
        if(not comp(l.second, b)) return;
        lines.pop_back();
      }
    }
    while(lines.size() >= 2 and is_needless(std::make_pair(a,b), lines.back(), *(lines.end()-2))){
      lines.pop_back();
    }
    lines.push_back(std::make_pair(a,b));
  }

  T query(const T &x){
    while(lines.size() >= 2 and comp(apply(lines[0],x), apply(lines[1],x))){
      lines.pop_front();
    }
    return apply(lines[0],x);
  }
};
