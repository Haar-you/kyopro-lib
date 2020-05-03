#pragma once
#include <vector>
#include <set>
#include <iterator>
#include <algorithm>
#include <utility>

/**
 * @title 区間スケジューリング問題 (重複要素をk個まで許容する)
 * @docs interval_scheduling_k.md
 */
std::vector<std::pair<int,int>> interval_scheduling_k(std::vector<std::pair<int,int>> s, int k){
  std::sort(s.begin(), s.end(), [](const auto &a, const auto &b){
                             return a.second == b.second ? a.first < b.first : a.second < b.second;
                           });

  std::multiset<int> a;
  std::vector<std::pair<int,int>> ret;

  for(auto &p : s){
    auto it = a.lower_bound(p.first);

    if(it != a.begin()){
      it = std::prev(it);
      a.erase(it);
    }

    if((int)a.size() < k){
      a.insert(p.second);
      ret.emplace_back(p);
    }
  }
  
  return ret;
}
