#pragma once
#include "Mylib/DataStructure/UnionFind/unionfind.cpp"

namespace haar_lib {
  class bipartite_graph {
    int n_;
    unionfind check_;

  public:
    bipartite_graph(){}
    bipartite_graph(int n): n_(n), check_(2 * n){}

    void add_diff(int i, int j){ // iとjを異なる色で塗る。
      check_.merge(i, j + n_);
      check_.merge(i + n_, j);
    }

    void add_same(int i, int j){ // iとjを同じ色で塗る。 = iとjを同じ頂点と見做す。
      check_.merge(i, j);
      check_.merge(i + n_, j + n_);
    }

    bool is_bipartite_graph(int i){ // iを含む連結グラフが二部グラフかを判定する。
      return not check_.is_same(i, i + n_);
    }

    bool is_same(int i, int j){ // iとjが同じ色で塗られているか判定する。
      return check_.is_same(i, j);
    }
  };
}
