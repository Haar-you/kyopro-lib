#pragma once
#include "Mylib/DataStructure/UnionFind/unionfind.cpp"

/**
 * @title Unionfindによる二部グラフ判定
 * @see https://atcoder.jp/contests/code-festival-2017-qualb/submissions/4508202
 * @see https://atcoder.jp/contests/arc036/submissions/4199773
 */
class BipartiteGraph{
  int n;
  UnionFind check;

public:
  BipartiteGraph(int n): n(n), check(2*n){}

  void add_diff(int i, int j){ // iとjを異なる色で塗る。
    check.merge(i,j+n);
    check.merge(i+n,j);
  }

  void add_same(int i, int j){ // iとjを同じ色で塗る。 = iとjを同じ頂点と見做す。
    check.merge(i,j);
    check.merge(i+n,j+n);
  }

  bool is_bipartite_graph(int i){ // iを含む連結グラフが二部グラフかを判定する。
    return !check.is_same(i,i+n);
  }

  bool is_same(int i, int j){ // iとjが同じ色で塗られているか判定する。
    return check.is_same(i,j);
  }
};
