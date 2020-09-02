#pragma once
#include <vector>
#include <set>
#include <iterator>
#include <algorithm>
#include <utility>
#include <numeric>

/**
 * @title Interval scheduling problem (Allow no more than k intervals to overlap)
 * @docs interval_scheduling_k.md
 */
auto interval_scheduling_k(std::vector<int> l, std::vector<int> r, int k){
  const int N = l.size();

  std::vector<int> ord(N);
  std::iota(ord.begin(), ord.end(), 0);
  std::sort(ord.begin(), ord.end(), [&](int i, int j){return r[i] < r[j];});

  std::multiset<int> a;
  std::vector<std::pair<int, int>> ret;

  for(int i : ord){
    auto it = a.upper_bound(l[i]);

    if(it != a.begin()){
      it = std::prev(it);
      a.erase(it);
    }

    if((int)a.size() < k){
      a.insert(r[i]);
      ret.emplace_back(l[i], r[i]);
    }
  }

  return ret;
}
