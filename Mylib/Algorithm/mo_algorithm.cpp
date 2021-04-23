#pragma once
#include <algorithm>
#include <cassert>
#include <cmath>
#include <vector>

namespace haar_lib {
  template <typename AppendLeft, typename AppendRight, typename RemoveLeft, typename RemoveRight, typename Query>
  class mo_algorithm {
    int N_, Q_, index_, width_;
    std::vector<int> left_, right_, ord_;

    AppendLeft append_left_;
    AppendRight append_right_;
    RemoveLeft remove_left_;
    RemoveRight remove_right_;
    Query query_;

    bool is_built_ = false;

  public:
    mo_algorithm() {}
    mo_algorithm(
        int N, int Q,
        const AppendLeft &append_left, const AppendRight &append_right,
        const RemoveLeft &remove_left, const RemoveRight &remove_right,
        const Query &query) : N_(N), Q_(Q), index_(0), width_(std::sqrt(N)), left_(Q), right_(Q), ord_(Q), append_left_(append_left), append_right_(append_right), remove_left_(remove_left), remove_right_(remove_right), query_(query) {}

    // [l, r)
    void add(int l, int r) {
      left_[index_]  = l;
      right_[index_] = r;
      ord_[index_]   = index_;
      ++index_;
    }

    void run() {
      std::sort(
          ord_.begin(), ord_.end(),
          [&](int i, int j) {
            const int a = left_[i] / width_, b = left_[j] / width_;
            if (a == b) {
              if (a & 1)
                return right_[i] < right_[j];
              else
                return right_[i] > right_[j];
            } else {
              return a < b;
            }
          });

      int q = 0;
      int l = left_[ord_[0]], r = left_[ord_[0]];

      for (int i = 0; i < Q_; ++i) {
        int id = ord_[q++];

        while (l != left_[id] or r != right_[id]) {
          if (l > left_[id]) append_left_(--l);
          if (l < left_[id]) remove_left_(l++);
          if (r < right_[id]) append_right_(r++);
          if (r > right_[id]) remove_right_(--r);
        }

        query_(id);
      }
    }
  };
}  // namespace haar_lib
