#pragma once
#include <deque>
#include <utility>
#include <functional>

namespace haar_lib {
  template <typename T, typename Comparator = std::greater<T>>
  class convex_hull_trick {
  public:
    using value_type = T;

  private:
    using line = std::pair<T, T>;

    std::deque<line> lines_;
    Comparator comp_ = Comparator();

    bool is_needless(const line &a, const line &b, const line &c){
      return (a.second - b.second) * (a.first - c.first) >= (a.second - c.second) * (a.first - b.first);
    }

    T apply(const line &f, const T &x){
      return f.first * x + f.second;
    }

  public:
    convex_hull_trick(){}

    void add(const T &a, const T &b){
      if(not lines_.empty()){
        auto l = lines_.back();

        if(l.first == a){
          if(not comp_(l.second, b)) return;
          lines_.pop_back();
        }
      }
      while(lines_.size() >= 2 and is_needless(std::make_pair(a, b), lines_.back(), *(lines_.end() - 2))){
        lines_.pop_back();
      }
      lines_.emplace_back(a, b);
    }

    T operator()(const T &x){
      while(lines_.size() >= 2 and comp_(apply(lines_[0], x), apply(lines_[1], x))){
        lines_.pop_front();
      }
      return apply(lines_[0], x);
    }
  };
}
