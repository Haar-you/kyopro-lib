#pragma once
#include <vector>
#include <utility>
#include <cassert>
#include <limits>
#include <tuple>

/*
 * @title Project selection problem
 * @docs project_selection_problem.md
 */
namespace haar_lib {
  template <typename T, typename Flow>
  class project_selection_problem {
    int N, s, t;
    std::vector<std::tuple<int, int, T>> g;
    T default_gain;
    int nodes;

    constexpr static T INF = std::numeric_limits<T>::max();

  public:
    project_selection_problem(int N): N(N), s(N), t(N + 1), default_gain(0), nodes(N + 2){}

    void penalty_if_red(int i, T c){
      assert(c >= 0);
      assert(0 <= i and i < N);
      g.emplace_back(i, t, c);
    }

    void gain_if_red(int i, T c){
      assert(c >= 0);
      assert(0 <= i and i < N);
      default_gain += c;
      penalty_if_blue(i, c);
    }

    void penalty_if_blue(int i, T c){
      assert(c >= 0);
      assert(0 <= i and i < N);
      g.emplace_back(s, i, c);
    }

    void gain_if_blue(int i, T c){
      assert(c >= 0);
      assert(0 <= i and i < N);
      default_gain += c;
      penalty_if_red(i, c);
    }

    void penalty_if_red_blue(int i, int j, T c){
      assert(c >= 0);
      assert(0 <= i and i < N);
      assert(0 <= j and j < N);
      g.emplace_back(i, j, c);
    }

    void penalty_if_different(int i, int j, T c){
      assert(c >= 0);
      assert(0 <= i and i < N);
      assert(0 <= j and j < N);
      g.emplace_back(i, j, c);
      g.emplace_back(j, i, c);
    }

    void must_be_red(int i){
      assert(0 <= i and i < N);
      penalty_if_blue(i, INF);
    }

    void must_be_blue(int i){
      assert(0 <= i and i < N);
      penalty_if_red(i, INF);
    }

    void if_red_then_must_be_red(int i, int j){
      assert(0 <= i and i < N);
      assert(0 <= j and j < N);
      penalty_if_red_blue(i, j, INF);
    }

    void gain_if_red_red(int i, int j, T c){
      assert(c >= 0);
      assert(0 <= i and i < N);
      assert(0 <= j and j < N);
      default_gain += c;
      int w = nodes++;

      g.emplace_back(s, w, c);
      g.emplace_back(w, i, INF);
      g.emplace_back(w, j, INF);
    }

    void gain_if_blue_blue(int i, int j, T c){
      assert(c >= 0);
      assert(0 <= i and i < N);
      assert(0 <= j and j < N);
      default_gain += c;
      int w = nodes++;

      g.emplace_back(w, t, c);
      g.emplace_back(i, w, INF);
      g.emplace_back(j, w, INF);
    }

    T solve(){
      Flow flow(nodes);
      for(auto [i, j, w] : g) flow.add_edge(i, j, w);
      return default_gain - flow.solve(s, t);
    }
  };
}
