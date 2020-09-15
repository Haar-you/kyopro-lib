#pragma once
#include <vector>
#include <tuple>
#include <algorithm>
#include "Mylib/DataStructure/FenwickTree/fenwick_tree_add.cpp"

/**
 * @title Range count query
 * @docs range_count_query.md
 */
namespace haar_lib {
  template <typename T>
  struct range_count_query {
    std::vector<int> a;
    std::vector<std::tuple<int, int, int>> qs;
    int N;

    range_count_query(std::vector<T> a_): N(a_.size()){
      auto temp = a_;
      std::sort(temp.begin(), temp.end());
      temp.erase(std::unique(temp.begin(), temp.end()), temp.end());

      for(auto x : a_){
        int i = std::lower_bound(temp.begin(), temp.end(), x) - temp.begin();
        a.push_back(i);
      }
    }

    void add(int l, int r){ // [l, r)
      const int i = qs.size();
      qs.emplace_back(r, l, i);
    }

    auto solve(){
      std::sort(qs.begin(), qs.end());

      fenwick_tree_add<int> b(N);

      const int Q = qs.size();
      std::vector<int> last_index(N, -1);
      std::vector<int> ret(Q);

      int cur = 0;
      for(auto [r, l, i] : qs){
        while(cur < r){
          if(last_index[a[cur]] != -1){
            b.update(last_index[a[cur]], -1);
          }

          last_index[a[cur]] = cur;
          b.update(last_index[a[cur]], 1);

          ++cur;
        }

        ret[i] = b.get(l, r);
      }

      return ret;
    }
  };
}