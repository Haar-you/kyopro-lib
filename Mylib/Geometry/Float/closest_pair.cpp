#pragma once
#include <algorithm>
#include <cmath>
#include <limits>
#include <utility>
#include <vector>
#include "Mylib/Geometry/Float/geometry_template.cpp"

namespace haar_lib {
  namespace closest_pair_impl {
    template <typename T>
    T rec(std::vector<point<T>> &s) {
      const int N = s.size();

      if (N == 1) return std::numeric_limits<T>::infinity();

      if (N == 2) {
        if (s[0].y > s[1].y) std::swap(s[0], s[1]);
        return abs(s[0] - s[1]);
      }

      const T mid_x = s[N / 2].x;

      auto left  = std::vector<point<T>>(s.begin(), s.begin() + N / 2);
      auto right = std::vector<point<T>>(s.begin() + N / 2, s.end());

      const T d1 = rec(left);
      const T d2 = rec(right);

      T d = std::min(d1, d2);

      s.clear();

      std::merge(
          left.begin(), left.end(),
          right.begin(), right.end(),
          std::back_inserter(s),
          [](const auto &a, const auto &b) { return a.y < b.y; });

      std::vector<point<T>> v;

      for (const auto &p : s) {
        if (abs(p.x - mid_x) > d) continue;

        for (auto it = v.rbegin(); it != v.rend(); ++it) {
          const auto &q = *it;
          if (abs(p.y - q.y) > d) break;

          d = std::min(d, abs(p - q));
        }

        v.push_back(p);
      }

      return d;
    }
  }  // namespace closest_pair_impl

  template <typename T>
  T closest_pair(std::vector<point<T>> s) {
    std::sort(s.begin(), s.end(), [](const auto &a, const auto &b) { return a.x < b.x; });
    return closest_pair_impl::rec(s);
  }
}  // namespace haar_lib
