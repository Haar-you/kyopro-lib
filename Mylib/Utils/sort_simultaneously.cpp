#pragma once
#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <initializer_list>

/**
 * @docs sort_simultaneously.md
 */
template <typename Compare, typename ... Args>
void sort_simultaneously(const Compare &compare, std::vector<Args> &... args){
  const int N = std::max({args.size() ...});
  std::vector<int> ord(N);
  std::iota(ord.begin(), ord.end(), 0);
  std::sort(ord.begin(), ord.end(), compare);

  (void)std::initializer_list<int>{
    (void(
      [&](){
        auto temp = args;
        for(int i = 0; i < N; ++i) temp[i] = args[ord[i]];
        std::swap(temp, args);
      }()
    ), 0) ...};
}
