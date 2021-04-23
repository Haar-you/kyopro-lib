#pragma once
#include <algorithm>
#include <map>
#include <string>
#include <tuple>
#include <utility>
#include "Mylib/String/z_algorithm.cpp"

namespace haar_lib {
  namespace run_enumerate_impl {
    auto aux(const std::string &first, const std::string &second) {
      std::vector<std::tuple<int, int, int>> ret;

      const int N = first.size(), M = second.size();

      auto a = z_algorithm(std::string(first.rbegin(), first.rend()));

      std::string t = second + '\0' + first + second;
      auto b        = z_algorithm(t);

      for (int i = 1; i < N; ++i) {
        int l1 = a[i];
        int l2 = b[second.size() + first.size() - i + 1];

        if (l1 + i == N or l2 == M or i > l1 + l2) continue;

        int l = N - i - l1, r = N + l2;
        int t = i;
        ret.emplace_back(t, l, r);
      }

      return ret;
    }

    void run(std::string s, int left, std::vector<std::tuple<int, int, int>> &ret) {
      if (s.size() == 1) return;

      const int N             = s.size();
      const int m             = N / 2;
      const std::string first = s.substr(0, m), second = s.substr(m);

      {
        auto res = aux(first, second);

        for (auto &[t, l, r] : res) {
          ret.emplace_back(t, left + l, left + r);
        }
      }

      {
        auto res = aux(std::string(second.rbegin(), second.rend()), std::string(first.rbegin(), first.rend()));

        for (auto &[t, l, r] : res) {
          ret.emplace_back(t, left + N - r, left + N - l);
        }
      }

      run(first, left, ret);
      run(second, left + first.size(), ret);
    }

    void sub(std::string s, std::vector<std::tuple<int, int, int>> &ret) {
      const int N = s.size();

      {
        auto a = z_algorithm(s);

        for (int i = 1; i < N; ++i) {
          if (i <= a[i]) {
            ret.emplace_back(i, 0, i + a[i]);
          }
        }
      }

      {
        auto a = z_algorithm(std::string(s.rbegin(), s.rend()));

        for (int i = 1; i < N; ++i) {
          if (i <= a[i]) {
            ret.emplace_back(i, N - i - a[i], N);
          }
        }
      }
    }
  }  // namespace run_enumerate_impl

  auto run_enumerate(const std::string &s) {
    std::vector<std::tuple<int, int, int>> ret;
    run_enumerate_impl::run(s, 0, ret);
    run_enumerate_impl::sub(s, ret);

    std::map<std::pair<int, int>, int> m;

    for (auto &[t, l, r] : ret) {
      auto p = std::make_pair(l, r);

      if (m.find(p) != m.end()) {
        m[p] = std::min(m[p], t);
      } else {
        m[p] = t;
      }
    }

    ret.clear();

    for (auto &[p, t] : m) {
      ret.emplace_back(t, p.first, p.second);
    }

    std::sort(ret.begin(), ret.end());
    return ret;
  }
}  // namespace haar_lib
