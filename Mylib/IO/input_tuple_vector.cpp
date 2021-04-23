#pragma once
#include <initializer_list>
#include <iostream>
#include <tuple>
#include <utility>
#include <vector>

namespace haar_lib {
  template <typename T, size_t... I>
  void input_tuple_vector_init(T &val, int N, std::index_sequence<I...>) {
    (void) std::initializer_list<int>{(void(std::get<I>(val).resize(N)), 0)...};
  }

  template <typename T, size_t... I>
  void input_tuple_vector_helper(T &val, int i, std::index_sequence<I...>) {
    (void) std::initializer_list<int>{(void(std::cin >> std::get<I>(val)[i]), 0)...};
  }

  template <typename... Args>
  auto input_tuple_vector(int N) {
    std::tuple<std::vector<Args>...> ret;

    input_tuple_vector_init(ret, N, std::make_index_sequence<sizeof...(Args)>());
    for (int i = 0; i < N; ++i) {
      input_tuple_vector_helper(ret, i, std::make_index_sequence<sizeof...(Args)>());
    }

    return ret;
  }
}  // namespace haar_lib
