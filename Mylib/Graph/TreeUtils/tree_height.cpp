#pragma once
#include <vector>
#include <algorithm>
#include "Mylib/Graph/Template/graph.cpp"
#include "Mylib/Graph/TreeUtils/tree_distance.cpp"

namespace haar_lib {
  template <typename T>
  std::vector<T> tree_height(const tree<T> &tr){
    const int n = tr.size();

    auto d = tree_distance(tr, 0);
    int a = std::max_element(d.begin(), d.end()) - d.begin();
    auto d1 = tree_distance(tr, a);
    int b = std::max_element(d1.begin(), d1.end()) - d1.begin();
    auto d2 = tree_distance(tr, b);

    std::vector<T> h(n);
    for(int i = 0; i < n; ++i) h[i] = std::max(d1[i], d2[i]);

    return h;
  }
}
