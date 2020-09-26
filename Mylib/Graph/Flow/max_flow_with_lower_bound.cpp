#pragma once
#include <optional>
#include <cassert>

namespace haar_lib {
  template <typename Flow>
  class max_flow_with_lower_bound {
    using edge = typename Flow::edge;
    using capacity_type = typename Flow::capacity_type;

    int N_, S_, T_;
    Flow flow_;
    capacity_type min_sum_;

  public:
    max_flow_with_lower_bound(){}
    max_flow_with_lower_bound(int N): N_(N), S_(N), T_(N + 1), flow_(N + 2), min_sum_(0){}

    void add_edge(int from, int to, capacity_type lb, capacity_type ub){
      assert(0 <= from and from < N_);
      assert(0 <= to and to < N_);
      assert(0 <= lb and lb <= ub);

      flow_.add_edge(from, to, ub - lb);
      flow_.add_edge(from, T_, lb);
      flow_.add_edge(S_, to, lb);

      min_sum_ += lb;
    }

    std::optional<capacity_type> max_flow(int s, int t){
      assert(0 <= s and s < N_);
      assert(0 <= t and t < N_);

      auto a = flow_.max_flow(S_, T_);
      auto b = flow_.max_flow(s, T_);
      auto c = flow_.max_flow(S_, t);
      auto d = flow_.max_flow(s, t);

      if(a + b == min_sum_ and a + c == min_sum_) return b + d;
      return std::nullopt;
    }
  };
}
