#pragma once
#include <algorithm>
#include <tuple>
#include <vector>
#include "Mylib/DataStructure/FenwickTree/fenwick_tree_add.cpp"

namespace haar_lib {
  template <typename T>
  class range_set_query {
    std::vector<int> a_;
    std::vector<std::tuple<int, int, int>> qs_;
    int N_;

  public:
    range_set_query() {}
    range_set_query(std::vector<T> a) : N_(a.size()) {
      auto temp = a;
      std::sort(temp.begin(), temp.end());
      temp.erase(std::unique(temp.begin(), temp.end()), temp.end());

      for (auto x : a) {
        const int i = std::lower_bound(temp.begin(), temp.end(), x) - temp.begin();
        a_.push_back(i);
      }
    }

    void add(int l, int r) {  // [l, r)
      const int i = qs_.size();
      qs_.emplace_back(r, l, i);
    }

    auto solve() {
      std::sort(qs_.begin(), qs_.end());

      fenwick_tree_add<int> b(N_);

      const int Q = qs_.size();
      std::vector<int> last_index(N_, -1), ret(Q);

      int cur = 0;
      for (auto [r, l, i] : qs_) {
        while (cur < r) {
          if (last_index[a_[cur]] != -1) {
            b.update(last_index[a_[cur]], -1);
          }

          last_index[a_[cur]] = cur;
          b.update(last_index[a_[cur]], 1);

          ++cur;
        }

        ret[i] = b.fold(l, r);
      }

      return ret;
    }
  };
}  // namespace haar_lib
