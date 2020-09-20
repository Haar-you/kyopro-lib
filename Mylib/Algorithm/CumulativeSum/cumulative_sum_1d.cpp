#pragma once
#include <vector>
#include <functional>
#include <cassert>

namespace haar_lib {
  template <typename T, typename Add = std::plus<T>, typename Minus = std::minus<T>>
  class cumulative_sum_1d {
    std::vector<T> data;
    int N;
    Add add;
    Minus minus;
    bool is_built = false;

  public:
    cumulative_sum_1d(){}
    cumulative_sum_1d(
      int N, const T &e = 0, const Add &add = Add(), const Minus &minus = Minus()
    ): N(N), add(add), minus(minus)
    {
      data.assign(N + 1, e);
    }

    auto& update(const std::vector<T> &a){
      assert(not is_built);
      for(int i = 0; i < N; ++i) data[i + 1] = add(data[i + 1], a[i]);
      return *this;
    }

    auto& update(int i, const T &val){
      assert(not is_built);
      data[i + 1] = add(data[i + 1], val);
      return *this;
    }

    auto& build(){
      assert(not is_built);
      for(int i = 0; i < N; ++i) data[i + 1] = add(data[i + 1], data[i]);
      is_built = true;
      return *this;
    }

    T get(int i, int j) const {
      assert(is_built);
      return minus(data[j], data[i]);
    }
  };
}
