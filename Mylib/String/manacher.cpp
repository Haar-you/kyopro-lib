#pragma once
#include <optional>
#include <vector>

namespace haar_lib {
  template <typename Container>
  std::vector<int> manacher(const Container &s) {
    const int n = s.size();
    std::vector<int> ret(n);
    int center = 0;

    for (int cur = 0; cur < n; ++cur) {
      int left = center - (cur - center);

      if (left >= 0 and cur + ret[left] < center + ret[center]) {
        ret[cur] = ret[left];
      } else {
        int len = center + ret[center] - cur;
        while (cur - len >= 0 and cur + len < n and s[cur - len] == s[cur + len]) ++len;
        ret[cur] = len;
        center   = cur;
      }
    }

    return ret;
  }

  template <typename Container>
  std::vector<int> manacher_all(const Container &s) {
    using T     = typename Container::value_type;
    const int N = s.size();
    std::vector<int> ret(2 * N - 1);

    {
      auto res = manacher(s);
      for (int i = 0; i < N; ++i) {
        ret[i * 2] = res[i] * 2 - 1;
      }
    }

    {
      std::vector<std::optional<T>> T;
      for (int i = 0; i < N; ++i) {
        if (i) T.push_back(std::nullopt);
        T.push_back(s[i]);
      }

      auto res = manacher(T);
      for (int i = 0; i < N - 1; ++i) {
        ret[i * 2 + 1] = (res[i * 2 + 1] / 2) * 2;
      }
    }

    return ret;
  }
}  // namespace haar_lib
