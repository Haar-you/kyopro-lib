#pragma once
#include <utility>
#include <vector>

namespace haar_lib {
  namespace monotone_minima_impl {
    template <typename T, typename F>
    auto rec(
        int N, int M, const F &f, int top, int bottom, int left, int right,
        std::vector<std::pair<int, T>> &ret) {
      if (top > bottom) return;
      if (top == bottom) {
        const int i = top;

        int index = left;
        T m       = f(i, index);

        for (int j = left; j <= right; ++j) {
          const auto temp = f(i, j);
          if (temp < m) {
            m     = temp;
            index = j;
          }
        }

        ret[i] = std::make_pair(index, m);
        return;
      }

      const int mid = (top + bottom) / 2;
      rec(N, M, f, mid, mid, left, right, ret);
      rec(N, M, f, top, mid - 1, left, ret[mid].first, ret);
      rec(N, M, f, mid + 1, bottom, ret[mid].first, right, ret);
    }
  }  // namespace monotone_minima_impl

  template <typename T, typename F>
  auto monotone_minima(int N, int M, const F &f) {
    std::vector<std::pair<int, T>> ret(M);
    monotone_minima_impl::rec<T, F>(N, M, f, 0, N - 1, 0, M - 1, ret);

    return ret;
  }
}  // namespace haar_lib
