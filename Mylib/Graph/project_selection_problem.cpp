#pragma once
#include <vector>
#include <utility>
#include <cassert>
#include <limits>

/*
 * @title Project selection problem
 * @docs project_selection_problem.md
 */
template <typename T, typename Flow>
class ProjectSelectionProblem{
  int N, s, t;
  std::vector<std::vector<std::pair<int,T>>> graph;
  T default_gain;

  constexpr static T INF = std::numeric_limits<T>::max();

public:
  ProjectSelectionProblem(int N): N(N), s(N), t(N+1), graph(N+2), default_gain(0){}

  void penalty_if_red(int i, T c){
    assert(c >= 0);
    assert(0 <= i and i < N);
    graph[i].emplace_back(t, c);
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
    graph[s].emplace_back(i, c);
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
    graph[i].emplace_back(j, c);
  }

  void penalty_if_different(int i, int j, T c){
    assert(c >= 0);
    assert(0 <= i and i < N);
    assert(0 <= j and j < N);
    graph[i].emplace_back(j, c);
    graph[j].emplace_back(i, c);
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
    int w = graph.size();
    graph.push_back({});

    graph[s].emplace_back(w, c);
    graph[w].emplace_back(i, INF);
    graph[w].emplace_back(j, INF);
  }

  void gain_if_blue_blue(int i, int j, T c){
    assert(c >= 0);
    assert(0 <= i and i < N);
    assert(0 <= j and j < N);
    default_gain += c;
    int w = graph.size();
    graph.push_back({});
    
    graph[w].emplace_back(t, c);
    graph[i].emplace_back(w, INF);
    graph[j].emplace_back(w, INF);
  }

  T solve(){
    Flow flow(graph);
    return default_gain - flow.solve(s, t);
  }
};
