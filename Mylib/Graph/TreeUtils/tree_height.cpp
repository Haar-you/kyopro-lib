#pragma once
#include <vector>
#include <algorithm>
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/TreeUtils/tree_distance.cpp"

/**
 * @title 木の高さ
 * @docs tree_height.md
 */
template <typename T>
std::vector<T> tree_height(const Tree<T> &tree){
  const int n = tree.size();

  auto d = tree_distance(tree, 0);
  int a = std::max_element(d.begin(), d.end()) - d.begin();
  auto d1 = tree_distance(tree, a);
  int b = std::max_element(d1.begin(), d1.end()) - d1.begin();
  auto d2 = tree_distance(tree, b);

  std::vector<T> h(n);
  for(int i = 0; i < n; ++i) h[i] = std::max(d1[i], d2[i]);
    
  return h;
}
