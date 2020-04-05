#pragma once
#include <vector>
#include <utility>
#include <algorithm>

/**
 * @title Sparse table
 */
template <typename Semilattice>
class SparseTable{
  using value_type = typename Semilattice::value_type;
  
  std::vector<std::vector<value_type>> a;
  std::vector<int> log_table;
  
public:
  SparseTable(const std::vector<value_type> &v){
    int n = v.size();
    int logn = 0;
    while((1 << logn) <= n) ++logn;
    
    a.assign(n, std::vector<value_type>(logn));
    for(int i = 0; i < n; ++i) a[i][0] = v[i];
    for(int j = 1; j < logn; ++j){
      for(int i = 0; i < n; ++i){
        a[i][j] = Semilattice::op(a[i][j-1], a[std::min<int>(n-1, i+(1<<(j-1)))][j-1]);
      }
    }

    log_table.assign(n+1, 0);
    for(int i = 2; i < n+1; ++i) log_table[i] = log_table[i>>1] + 1;
  }
  
  inline value_type get(int s, int t) const { // [s,t)
    int k = log_table[t-s];
    return Semilattice::op(a[s][k], a[t-(1<<k)][k]);
  }

  inline value_type get(std::vector<std::pair<int,int>> st) const {
    value_type ret;
    bool t = true;

    for(const auto &p : st){
      if(p.first < p.second){
        if(t){
          ret = get(p.first, p.second);
          t = false;
        }else{
          ret = Semilattice::op(ret, get(p.first, p.second));
        }
      }
    }

    return ret;
  }
};
