#pragma once
#include <vector>
#include <optional>
#include <cassert>
#include "Mylib/Graph/Template/graph.cpp"
#include "Mylib/Graph/GraphUtils/strongly_connected_components.cpp"

namespace haar_lib {
  class two_sat {
    const int n;
    graph<int> g;

    int f(int i){
      assert(i != 0);
      assert(std::abs(i) <= n);
      if(i > 0) return i - 1;
      else return std::abs(i) - 1 + n;
    }

  public:
    two_sat(int n): n(n), g(2 * n){}

    /**
     * @note a→bを導入する
     */
    void add_if(int a, int b){
      g.add_edge(f(a), f(b), 1);
    }

    /**
     * @note a∨bを導入する
     * @note a ∨ b <=> (!a => b) ∧ (!b => a)
     */
    void add_or(int a, int b){
      add_if(-a, b);
      add_if(-b, a);
    }

    /**
     * @note ¬(a∧b)を導入する
     * @note !(A ∧ B) <=> (!A ∨ !B)
     */
    void not_coexist(int a, int b){
      add_or(-a, -b);
    }

  public:
    std::optional<std::vector<bool>> solve() const {
      auto [scc, m] = strongly_connected_components(g);

      for(int i = 0; i < n; ++i){
        if(scc[i] == scc[i + n]) return std::nullopt;
      }

      std::vector<bool> ret(n);
      for(int i = 0; i < n; ++i) ret[i] = scc[i] > scc[i + n];

      return ret;
    }
  };
}
