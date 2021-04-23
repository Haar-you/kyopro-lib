#pragma once
#include <cstdint>
#include <utility>

namespace haar_lib {
  template <typename Checker>
  void stern_brocot_tree(
      const Checker &check,
      int n,
      std::pair<int, int> &lower,
      std::pair<int, int> &upper,
      int64_t pl = 0, int64_t ql = 1, int64_t pr = 1, int64_t qr = 0) {
    int64_t pm = pl + pr;
    int64_t qm = ql + qr;

    if (pm > n or qm > n) return;

    auto t = check(pm, qm);

    if (t < 0) {
      lower = {pm, qm};
      stern_brocot_tree(check, n, lower, upper, pm, qm, pr, qr);
    } else if (t > 0) {
      upper = {pm, qm};
      stern_brocot_tree(check, n, lower, upper, pl, ql, pm, qm);
    } else {
      lower = {pm, qm};
      upper = {pm, qm};
    }
  }
}  // namespace haar_lib
