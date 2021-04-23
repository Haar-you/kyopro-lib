#pragma once

namespace haar_lib {
  template <typename Func>
  void enumerate_supersets_asc(int a, int n, const Func &f) {
    for (int t = a; t < (1 << n); t = (t + 1) | a) {
      if (not f(t)) break;
    }
  }
}  // namespace haar_lib
