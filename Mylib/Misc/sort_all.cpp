#pragma once
#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>

/**
 * @docs sort_all.md
 */
namespace sort_all{
  template <typename T>
  void sort_with_ord(const std::vector<int> &ord, int N, std::vector<T> &a){
    std::vector<T> temp(N);
    for(int i = 0; i < N; ++i) temp[i] = a[ord[i]];
    std::swap(temp, a);
  }

  template <typename T, typename ...Args>
  void sort_with_ord(const std::vector<int> &ord, int N, std::vector<T> &a, Args&... args){
    std::vector<T> temp(N);
    for(int i = 0; i < N; ++i) temp[i] = a[ord[i]];
    std::swap(temp, a);
    sort_with_ord(ord, N, args...);
  }

  template <typename Compare, typename ...Args>
  void run(const Compare &compare, int N, Args&... args){
    std::vector<int> ord(N);
    std::iota(ord.begin(), ord.end(), 0);
    std::sort(ord.begin(), ord.end(), compare);

    sort_with_ord(ord, N, args...);
  }
};
