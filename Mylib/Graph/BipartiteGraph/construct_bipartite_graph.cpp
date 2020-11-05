#pragma once

namespace haar_lib {
  template <typename UF>
  class bipartite_graph : public UF {
    int n_;

    using super = UF;

  public:
    bipartite_graph(){}
    bipartite_graph(int n): super(2 * n), n_(n){}

    void add_diff(int i, int j){ // iとjを異なる色で塗る。
      super::merge(i, j + n_);
      super::merge(i + n_, j);
    }

    void add_same(int i, int j){ // iとjを同じ色で塗る。 = iとjを同じ頂点と見做す。
      super::merge(i, j);
      super::merge(i + n_, j + n_);
    }

    bool is_bipartite_graph(int i){ // iを含む連結グラフが二部グラフかを判定する。
      return not super::is_same(i, i + n_);
    }

    bool is_same(int i, int j){ // iとjが同じ色で塗られているか判定する。
      return super::is_same(i, j);
    }
  };
}
