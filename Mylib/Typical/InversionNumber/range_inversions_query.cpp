#pragma once
#include <vector>
#include <utility>
#include <algorithm>
#include "Mylib/DataStructure/FenwickTree/fenwick_tree_add.cpp"
#include "Mylib/Algorithm/Mo/mo_algorithm.cpp"

namespace haar_lib {
  template <typename T>
  class range_inversions_query {
    std::vector<int> a;
    int N;
    std::vector<std::pair<int, int>> qs;

  public:
    range_inversions_query(std::vector<T> a_): N(a_.size()){
      auto b = a_;
      std::sort(b.begin(), b.end());
      b.erase(std::unique(b.begin(), b.end()), b.end());

      for(auto x : a_){
        const int i = std::lower_bound(b.begin(), b.end(), x) - b.begin();
        a.push_back(i);
      }
    }

    void add(int l, int r){ // [l, r)
      qs.emplace_back(l, r);
    }

    auto solve(){
      const int Q = qs.size();
      fenwick_tree_add<int64_t> b(N);

      int64_t t = 0;
      std::vector<int64_t> ans(Q);

      auto append_left =
        [&](int i){
          t += b.fold(0, a[i]);
          b.update(a[i], 1);
        };

      auto append_right =
        [&](int i){
          t += b.fold(a[i] + 1, N);
          b.update(a[i], 1);
        };

      auto remove_left =
        [&](int i){
          t -= b.fold(0, a[i]);
          b.update(a[i], -1);
        };

      auto remove_right =
        [&](int i){
          t -= b.fold(a[i] + 1, N);
          b.update(a[i], -1);
        };

      auto query = [&](int i){ans[i] = t;};

      auto mo =
        mo_algorithm(
          N, Q, append_left, append_right, remove_left, remove_right, query
        );

      for(auto [l, r] : qs){
        mo.add(l, r);
      }

      mo.run();

      return ans;
    }
  };
}