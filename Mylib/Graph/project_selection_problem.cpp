#pragma once
#include <vector>
#include <utility>
#include <cassert>
#include "Mylib/Graph/Flow/dinic.cpp"

/*
 * @title Project Selection Problem
 * @see https://kimiyuki.net/blog/2017/12/05/minimum-cut-and-project-selection-problem/
 * @see https://ei1333.github.io/luzhiled/snippets/memo/project-selection.html
 * @see https://ferin-tech.hatenablog.com/entry/2019/10/28/%E7%87%83%E3%82%84%E3%81%99%E5%9F%8B%E3%82%81%E3%82%8B%E5%95%8F%E9%A1%8C
 
 * @see https://atcoder.jp/contests/arc085/submissions/8399754
 * @see http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3058
 * @see http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2903
 */
template <typename T, T INF>
class ProjectSelectionProblem{
  int N, s, t;
  std::vector<std::vector<std::pair<int,T>>> graph;
  T default_gain;

public:
  ProjectSelectionProblem(int N): N(N), s(N), t(N+1), graph(N+2), default_gain(0){}

  void penalty_if_red(int i, T c){
    assert(c >= 0);
    graph[i].emplace_back(t, c);
  }

  void gain_if_red(int i, T c){
    assert(c >= 0);
    default_gain += c;
    penalty_if_blue(i, c);
  }
  
  void penalty_if_blue(int i, T c){
    assert(c >= 0);
    graph[s].emplace_back(i, c);
  }

  void gain_if_blue(int i, T c){
    assert(c >= 0);
    default_gain += c;
    penalty_if_red(i, c);
  }

  void penalty_if_red_blue(int i, int j, T c){
    assert(c >= 0);
    graph[i].emplace_back(j, c);
  }

  void penalty_if_different(int i, int j, T c){
    assert(c >= 0);
    graph[i].emplace_back(j, c);
    graph[j].emplace_back(i, c);
  }

  void must_be_red(int i){
    penalty_if_blue(i, INF);
  }

  void must_be_blue(int i){
    penalty_if_red(i, INF);
  }

  void if_red_then_must_be_red(int i, int j){
    penalty_if_red_blue(i, j, INF);
  }

  void gain_if_red_red(int i, int j, T c){
    assert(c >= 0);
    default_gain += c;
    int w = graph.size();
    graph.push_back({});

    graph[s].emplace_back(w, c);
    graph[w].emplace_back(i, INF);
    graph[w].emplace_back(j, INF);
  }

  void gain_if_blue_blue(int i, int j, T c){
    assert(c >= 0);
    default_gain += c;
    int w = graph.size();
    graph.push_back({});
    
    graph[w].emplace_back(t, c);
    graph[i].emplace_back(w, INF);
    graph[j].emplace_back(w, INF);
  }

  T solve(){
    Dinic<T,INF> flow(graph);
    return default_gain - flow.solve(s, t);
  }
};
