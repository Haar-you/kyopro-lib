#pragma once
#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <initializer_list>
#include <cassert>

namespace haar_lib {
  namespace sort_simultaneously_impl {
    template <typename T>
    void sub(int N, const std::vector<int> &ord, std::vector<T> &a){
      std::vector<T> temp(N);
      for(int i = 0; i < N; ++i) temp[i] = a[ord[i]];
      std::swap(temp, a);
    }
  }

  template <typename Compare, typename ... Args>
  void sort_simultaneously(const Compare &compare, std::vector<Args> &... args){
    const int N = std::max({args.size() ...});
    assert((int)std::min({args.size() ...}) == N);
    std::vector<int> ord(N);
    std::iota(ord.begin(), ord.end(), 0);
    std::sort(ord.begin(), ord.end(), compare);

    (void)std::initializer_list<int>{
      (void(sort_simultaneously_impl::sub(N, ord, args)), 0) ...};
  }
}
