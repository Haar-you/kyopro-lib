#pragma once
#include <vector>
#include <utility>
#include <climits>
#include <cassert>

namespace haar_lib {
  template <typename MaxFlow>
  class bipartite_matching {
    int L_, R_, s_, t_;
    MaxFlow f_;

  public:
    bipartite_matching(){}
    bipartite_matching(int L, int R):
      L_(L), R_(R), s_(L + R), t_(s_ + 1), f_(L + R + 2){
      for(int i = 0; i < L_; ++i) f_.add_edge(s_, i, 1);
      for(int i = 0; i < R_; ++i) f_.add_edge(L_ + i, t_, 1);
    }

    void add_edge(int i, int j){
      assert(0 <= i and i < L_ and 0 <= j and j < R_);
      f_.add_edge(i, L_ + j, 1);
    }

    int match(){
      return f_.max_flow(s_, t_);
    }

    auto get_matching(){
      const auto g = f_.edges();
      std::vector<std::pair<int, int>> ret;

      for(auto &e : g){
        if(not e.is_rev and e.cap == 0 and e.from != s_ and e.to != t_){
          ret.emplace_back(e.from, e.to - L_);
        }
      }

      return ret;
    }
  };
}
