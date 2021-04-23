#pragma once
#include <algorithm>
#include <iterator>
#include <numeric>
#include <set>
#include <utility>
#include <vector>

namespace haar_lib {
  auto interval_scheduling_k(std::vector<int> l, std::vector<int> r, int k) {
    const int N = l.size();

    std::vector<int> ord(N);
    std::iota(ord.begin(), ord.end(), 0);
    std::sort(ord.begin(), ord.end(), [&](int i, int j) { return r[i] < r[j]; });

    std::multiset<int> a;
    std::vector<std::pair<int, int>> ret;

    for (int i : ord) {
      auto it = a.upper_bound(l[i]);

      if (it != a.begin()) {
        it = std::prev(it);
        a.erase(it);
      }

      if ((int) a.size() < k) {
        a.insert(r[i]);
        ret.emplace_back(l[i], r[i]);
      }
    }

    return ret;
  }
}  // namespace haar_lib
