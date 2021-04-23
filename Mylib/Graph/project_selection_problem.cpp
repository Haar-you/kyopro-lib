#pragma once
#include <cassert>
#include <limits>
#include <tuple>
#include <utility>
#include <vector>

namespace haar_lib {
  template <typename T, typename Flow>
  class project_selection_problem {
    int N_, s_, t_;
    std::vector<std::tuple<int, int, T>> g_;
    T default_gain_;
    int nodes_;

    constexpr static T INF = std::numeric_limits<T>::max();

  public:
    project_selection_problem() {}
    project_selection_problem(int N) : N_(N), s_(N), t_(N + 1), default_gain_(0), nodes_(N + 2) {}

    void penalty_if_red(int i, T c) {
      assert(c >= 0);
      assert(0 <= i and i < N_);
      g_.emplace_back(i, t_, c);
    }

    void gain_if_red(int i, T c) {
      assert(c >= 0);
      assert(0 <= i and i < N_);
      default_gain_ += c;
      penalty_if_blue(i, c);
    }

    void penalty_if_blue(int i, T c) {
      assert(c >= 0);
      assert(0 <= i and i < N_);
      g_.emplace_back(s_, i, c);
    }

    void gain_if_blue(int i, T c) {
      assert(c >= 0);
      assert(0 <= i and i < N_);
      default_gain_ += c;
      penalty_if_red(i, c);
    }

    void penalty_if_red_blue(int i, int j, T c) {
      assert(c >= 0);
      assert(0 <= i and i < N_);
      assert(0 <= j and j < N_);
      g_.emplace_back(i, j, c);
    }

    void penalty_if_different(int i, int j, T c) {
      assert(c >= 0);
      assert(0 <= i and i < N_);
      assert(0 <= j and j < N_);
      g_.emplace_back(i, j, c);
      g_.emplace_back(j, i, c);
    }

    void must_be_red(int i) {
      assert(0 <= i and i < N_);
      penalty_if_blue(i, INF);
    }

    void must_be_blue(int i) {
      assert(0 <= i and i < N_);
      penalty_if_red(i, INF);
    }

    void if_red_then_must_be_red(int i, int j) {
      assert(0 <= i and i < N_);
      assert(0 <= j and j < N_);
      penalty_if_red_blue(i, j, INF);
    }

    void gain_if_red_red(int i, int j, T c) {
      assert(c >= 0);
      assert(0 <= i and i < N_);
      assert(0 <= j and j < N_);
      default_gain_ += c;
      int w = nodes_++;

      g_.emplace_back(s_, w, c);
      g_.emplace_back(w, i, INF);
      g_.emplace_back(w, j, INF);
    }

    void gain_if_blue_blue(int i, int j, T c) {
      assert(c >= 0);
      assert(0 <= i and i < N_);
      assert(0 <= j and j < N_);
      default_gain_ += c;
      int w = nodes_++;

      g_.emplace_back(w, t_, c);
      g_.emplace_back(i, w, INF);
      g_.emplace_back(j, w, INF);
    }

    T solve() {
      Flow flow(nodes_);
      for (auto [i, j, w] : g_) flow.add_edge(i, j, w);
      return default_gain_ - flow.max_flow(s_, t_);
    }
  };
}  // namespace haar_lib
