#pragma once
#include <initializer_list>
#include <iostream>
#include <tuple>
#include <utility>
#include <vector>
#include "Mylib/IO/input_tuple.cpp"

namespace haar_lib {
  template <typename... Args>
  class InputTuples {
    struct iter {
      using value_type = std::tuple<Args...>;
      value_type value;
      bool fetched = false;
      int N, c = 0;

      value_type operator*() {
        if (not fetched) {
          std::cin >> value;
        }
        return value;
      }

      void operator++() {
        ++c;
        fetched = false;
      }

      bool operator!=(iter &) const {
        return c < N;
      }

      iter(int N) : N(N) {}
    };

    int N;

  public:
    InputTuples(int N) : N(N) {}

    iter begin() const { return iter(N); }
    iter end() const { return iter(N); }
  };

  template <typename... Args>
  auto input_tuples(int N) {
    return InputTuples<Args...>(N);
  }
}  // namespace haar_lib
