#pragma once
#include <vector>
#include <random>
#include <algorithm>
#include "Mylib/Geometry/Float/circumscribed_circle_of_triangle.cpp"

namespace haar_lib {
  template <typename T>
  circle<T> minimum_covering_circle(std::vector<point<T>> ps, int seed = 0){
    if(ps.empty()) return circle<T>();
    if(ps.size() == 1) return circle<T>(ps[0], 0);

    const int N = ps.size();

    std::mt19937 rand(seed);
    std::shuffle(ps.begin(), ps.end(), rand);

    auto make_circle_2 =
      [&](const auto &p, const auto &q){
        const auto c = (p + q) / 2.0;
        return circle<T>(c, abs(p - c));
      };

    auto check =
      [](const auto &p, const auto &c){
        return abs(c.center - p) <= c.radius;
      };

    circle<T> ret = make_circle_2(ps[0], ps[1]);

    for(int i = 2; i < N; ++i){
      if(check(ps[i], ret)) continue;

      ret = make_circle_2(ps[0], ps[i]);

      for(int j = 1; j < i; ++j){
        if(check(ps[j], ret)) continue;

        ret = make_circle_2(ps[i], ps[j]);

        for(int k = 0; k < j; ++k){
          if(check(ps[k], ret)) continue;
          if(i == j or j == k or k == i) continue;

          ret = circumscribed_circle_of_triangle(ps[i], ps[j], ps[k]);
        }
      }
    }

    return ret;
  }
}
