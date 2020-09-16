#pragma once
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <climits>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include "Mylib/Geometry/Float/geometry_template.cpp"

namespace haar_lib {
  template <typename T>
  int manhattan_segments_intersections(std::vector<segment<T>> segs){
    std::vector<segment<T>> hs;
    std::vector<std::tuple<point<T>, bool, int>> vs;
    int count = 0;

    for(auto s : segs){
      if(s.from.y == s.to.y){
        hs.push_back(s);
      }else{
        vs.emplace_back(s.from, s.from.y < s.to.y, count);
        vs.emplace_back(s.to, s.from.y > s.to.y, count);
        ++count;
      }
    }

    std::sort(hs.rbegin(), hs.rend(), [](const auto &a, const auto &b){return a.from.y < b.from.y;});
    std::sort(vs.rbegin(), vs.rend(), [](const auto &a, const auto &b){return std::get<0>(a).y < std::get<0>(b).y;});

    __gnu_pbds::tree<
      std::pair<T, int>,
      __gnu_pbds::null_type,
      std::less<std::pair<T, int>>,
      __gnu_pbds::rb_tree_tag,
      __gnu_pbds::tree_order_statistics_node_update
      > set;
    int64_t ans = 0;

    while(true){
      if(hs.empty() or vs.empty()) break;

      T ymin = std::min(hs.back().from.y, std::get<0>(vs.back()).y);

      std::vector<segment<T>> rs;
      std::vector<std::tuple<point<T>, bool, int>> ps;

      while(not hs.empty() and hs.back().from.y == ymin){
        rs.push_back(hs.back());
        hs.pop_back();
      }

      while(not vs.empty() and std::get<0>(vs.back()).y == ymin){
        ps.push_back(vs.back());
        vs.pop_back();
      }

      for(auto [a, b, c] : ps){
        if(b) set.insert(std::make_pair(a.x, c));
      }

      for(auto [a, b] : rs){
        auto [x1, x2] = std::minmax(a.x, b.x);

        auto ix1 = set.order_of_key(std::make_pair(x1, 0));
        auto ix2 = set.order_of_key(std::make_pair(x2, INT_MAX));

        ans += ix2 - ix1;
      }

      for(auto [a, b, c] : ps){
        if(not b) set.erase(std::make_pair(a.x, c));
      }
    }

    return ans;
  }
}
