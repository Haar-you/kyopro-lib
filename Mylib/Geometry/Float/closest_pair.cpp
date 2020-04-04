#pragma once
#include <vector>
#include <utility>
#include <limits>
#include <algorithm>
#include <cmath>
#include "Mylib/Geometry/Float/geometry_template.cpp"

/**
 * @title 最近点対
 */
namespace closest_pair{
  template <typename T, typename U = typename T::value_type>
  T closest_pair(std::vector<Point<T>> &s){
    const int N = s.size();

    if(N == 1) return std::numeric_limits<T>::infinity();

    if(N == 2){
      if(s[0].y > s[1].y) std::swap(s[0], s[1]);
      return (s[0] - s[1]).size();
    }
    
    const T mid_x = s[N/2].x;
    
    auto left = std::vector<Point<T>>(s.begin(), s.begin() + N/2);
    auto right = std::vector<Point<T>>(s.begin() + N/2, s.end());

    const T d1 = closest_pair(left);
    const T d2 = closest_pair(right);

    T d = std::min(d1, d2);

    s.clear();

    std::merge(left.begin(), left.end(),
               right.begin(), right.end(),
               std::back_inserter(s),
               [](const auto &a, const auto &b){return a.y < b.y;});

    std::vector<Point<T>> v;

    for(const auto &p : s){
      if((T)std::fabs((U)(p.x - mid_x)) > d) continue;

      for(auto it = v.rbegin(); it != v.rend(); ++it){
        const auto &q = *it;
        if((T)std::fabs((U)(p.y - q.y)) > d) break;

        d = std::min(d, (p - q).size());
      }

      v.push_back(p);
    }
  
    return d;
  }

  template <typename T>
  T solve(std::vector<Point<T>> s){
    std::sort(s.begin(), s.end(), [](const auto &a, const auto &b){return a.x < b.x;});
    return closest_pair(s);
  }
}
