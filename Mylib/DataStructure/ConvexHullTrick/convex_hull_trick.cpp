#pragma once
#include <deque>
#include <utility>
#include <functional>

/**
 * @title Convex hull trick
 * @docs convex_hull_trick.md
 */
namespace haar_lib {
  template <typename T, typename Comparator = std::greater<T>>
  class convex_hull_trick {
    using line = std::pair<T, T>;
    std::deque<line> lines;
    bool is_needless(const line &a, const line &b, const line &c){
      return (a.second - b.second) * (a.first - c.first) >= (a.second - c.second) * (a.first - b.first);
    }

    T apply(const line &f, const T &x){
      return f.first * x + f.second;
    }

    Comparator comp = Comparator();

  public:
    convex_hull_trick(){}

    void add(const T &a, const T &b){
      if(!lines.empty()){
        auto l = lines.back();

        if(l.first == a){
          if(not comp(l.second, b)) return;
          lines.pop_back();
        }
      }
      while(lines.size() >= 2 and is_needless(std::make_pair(a, b), lines.back(), *(lines.end() - 2))){
        lines.pop_back();
      }
      lines.emplace_back(a, b);
    }

    T operator()(const T &x){
      while(lines.size() >= 2 and comp(apply(lines[0], x), apply(lines[1], x))){
        lines.pop_front();
      }
      return apply(lines[0], x);
    }
  };
}
