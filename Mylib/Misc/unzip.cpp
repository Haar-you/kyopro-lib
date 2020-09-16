#pragma once
#include <vector>
#include <initializer_list>
#include <utility>
#include <tuple>

namespace haar_lib {
  template <typename T, typename U, size_t ... I>
  void unzip_helper(T &ret, U &a, std::index_sequence<I ...>){
    (void)std::initializer_list<int>{(void(std::get<I>(ret).push_back(std::get<I>(a))), 0) ...};
  }

  template <typename ... Args>
  auto unzip(std::vector<std::tuple<Args ...>> a){
    const int N = a.size();
    std::tuple<std::vector<Args> ...> ret;

    for(int i = 0; i < N; ++i){
      unzip_helper(ret, a[i], std::make_index_sequence<sizeof ... (Args)>());
    }

    return ret;
  }
}
