#pragma once
#include <vector>
#include <utility>
#include <algorithm>
#include "Mylib/DataStructure/FenwickTree/fenwick_tree_add.cpp"
#include "Mylib/Algorithm/Mo/mo_algorithm.cpp"

namespace haar_lib {
  template <typename T>
  class range_inversions_query {
    std::vector<int> data_;
    int N_;
    std::vector<std::pair<int, int>> qs_;

  public:
    range_inversions_query(){}
    range_inversions_query(std::vector<T> a): N_(a.size()){
      auto b = a;
      std::sort(b.begin(), b.end());
      b.erase(std::unique(b.begin(), b.end()), b.end());

      for(auto x : a){
        const int i = std::lower_bound(b.begin(), b.end(), x) - b.begin();
        data_.push_back(i);
      }
    }

    void add(int l, int r){ // [l, r)
      qs_.emplace_back(l, r);
    }

    auto solve(){
      const int Q = qs_.size();
      fenwick_tree_add<int64_t> b(N_);

      int64_t t = 0;
      std::vector<int64_t> ans(Q);

      auto append_left =
        [&](int i){
          t += b.fold(0, data_[i]);
          b.update(data_[i], 1);
        };

      auto append_right =
        [&](int i){
          t += b.fold(data_[i] + 1, N_);
          b.update(data_[i], 1);
        };

      auto remove_left =
        [&](int i){
          t -= b.fold(0, data_[i]);
          b.update(data_[i], -1);
        };

      auto remove_right =
        [&](int i){
          t -= b.fold(data_[i] + 1, N_);
          b.update(data_[i], -1);
        };

      auto query = [&](int i){ans[i] = t;};

      auto mo =
        mo_algorithm(
          N_, Q, append_left, append_right, remove_left, remove_right, query
        );

      for(auto [l, r] : qs_){
        mo.add(l, r);
      }

      mo.run();

      return ans;
    }
  };
}
