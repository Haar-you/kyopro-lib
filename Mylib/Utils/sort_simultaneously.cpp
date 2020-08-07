#pragma once
#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <initializer_list>

/**
 * @docs sort_simultaneously.md
 */
template <typename T>
void sort_with_ord(const std::vector<int> &ord, int N, std::vector<T> &a){
  std::vector<T> temp(N);
  for(int i = 0; i < N; ++i) temp[i] = a[ord[i]];
  std::swap(temp, a);
}

template <typename Compare, typename ...Args>
void sort_simultaneously(const Compare &compare, int N, std::vector<Args> &... args){
  std::vector<int> ord(N);
  std::iota(ord.begin(), ord.end(), 0);
  std::sort(ord.begin(), ord.end(), compare);

  (void)std::initializer_list<int>{(sort_with_ord(ord, N, args), 0)...};
}
