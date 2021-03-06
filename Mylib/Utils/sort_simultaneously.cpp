#pragma once
#include <algorithm>
#include <cassert>
#include <initializer_list>
#include <numeric>
#include <utility>
#include <vector>

namespace haar_lib {
  namespace sort_simultaneously_impl {
    template <typename T>
    void helper(int N, const std::vector<int> &ord, std::vector<T> &a) {
      std::vector<T> temp(N);
      for (int i = 0; i < N; ++i) temp[i] = a[ord[i]];
      std::swap(temp, a);
    }
  }  // namespace sort_simultaneously_impl

  template <typename Compare, typename... Args>
  void sort_simultaneously(const Compare &compare, std::vector<Args> &... args) {
    const int N = std::max({args.size()...});
    assert((int) std::min({args.size()...}) == N);
    std::vector<int> ord(N);
    std::iota(ord.begin(), ord.end(), 0);
    std::sort(ord.begin(), ord.end(), compare);

    (void) std::initializer_list<int>{
        (void(sort_simultaneously_impl::helper(N, ord, args)), 0)...};
  }
}  // namespace haar_lib
