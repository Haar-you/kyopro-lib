#pragma once
#include <cstdint>
#include <vector>

namespace haar_lib {
  namespace inversion_number_impl {
    template <typename T, typename Compare>
    int64_t rec(std::vector<T> &a, const Compare &compare) {
      const int n = a.size();
      if (n <= 1) return 0;

      int64_t ret = 0;

      std::vector<T> b(a.begin(), a.begin() + n / 2);
      std::vector<T> c(a.begin() + n / 2, a.end());

      ret += rec(b, compare);
      ret += rec(c, compare);

      int ai = 0, bi = 0, ci = 0;

      while (ai < n) {
        if (bi < (int) b.size() and (ci == (int) c.size() or not compare(b[bi], c[ci]))) {
          a[ai] = b[bi];
          ++bi;
        } else {
          ret += n / 2 - bi;
          a[ai] = c[ci];
          ++ci;
        }
        ++ai;
      }

      return ret;
    }
  }  // namespace inversion_number_impl

  template <typename T, typename Compare>
  int64_t inversion_number(std::vector<T> a, const Compare &compare) {
    return inversion_number_impl::rec(a, compare);
  }
}  // namespace haar_lib
