#pragma once
#include <optional>
#include <tuple>
#include <vector>

namespace haar_lib {
  template <typename T, typename Compare>
  auto cartesian_tree(const std::vector<T> &a, Compare compare) -> std::tuple<
      int,                              // root
      std::vector<std::optional<int>>,  // parent nodes
      std::vector<std::optional<int>>,  // left nodes
      std::vector<std::optional<int>>   // right nodes
      > {
    const int n = a.size();
    std::vector<std::optional<int>> p(n), l(n), r(n);
    int root = 0;

    for (int i = 0; i < n; ++i) {
      if (i == 0) {
        continue;
      }

      int j = i - 1;

      while (1) {
        if (compare(a[i], a[j])) {
          if (not p[j]) {
            p[j] = i;
            l[i] = j;
            root = i;
            break;
          }

          j = *p[j];
          continue;
        }

        auto t = r[j];
        r[j]   = i;
        p[i]   = j;

        l[i] = t;
        if (t) p[*t] = i;

        break;
      }
    }

    return std::make_tuple(root, p, l, r);
  }
}  // namespace haar_lib
