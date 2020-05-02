#pragma once
#include <vector>
#include <algorithm>
#include <utility>
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/DataStructure/UnionFind/unionfind.cpp"

/**
 * @docs forest.md
 */
template <typename T>
struct Forest{
  std::vector<Tree<T>> trees;

  std::vector<int> tree_id;
  std::vector<int> vertex_id;

  std::vector<std::vector<int>> rid;

  Forest(const Graph<T> &g){
    const int N = g.size();
    UnionFind uf(N);

    for(auto &v : g){
      for(auto &e : v){
        uf.merge(e.from, e.to);
      }
    }
    
    const int tree_num = uf.count_group();
    
    trees.resize(tree_num);

    tree_id.resize(N);
    vertex_id.resize(N);

    rid.resize(tree_num);

    std::vector<int> temp;
    for(int i = 0; i < N; ++i) temp.push_back(uf.get_root(i));
    std::sort(temp.begin(), temp.end());
    temp.erase(std::unique(temp.begin(), temp.end()), temp.end());

    for(int i = 0; i < N; ++i){
      tree_id[i] = std::lower_bound(temp.begin(), temp.end(), uf.get_root(i)) - temp.begin();
      vertex_id[i] = rid[tree_id[i]].size();
      rid[tree_id[i]].push_back(i);
    }

    for(int i = 0; i < tree_num; ++i){
      trees[i].resize(uf.get_size(temp[i]));
    }
    
    for(auto &v : g){
      for(auto &e : v){
        add_edge(trees[tree_id[e.from]], vertex_id[e.from], vertex_id[e.to], e.cost);
      }
    }
  }
  
  std::pair<int, int> forests_id(int i) const {
    return std::make_pair(tree_id[i], vertex_id[i]);
  }

  int original_id(int i, int j) const {
    return rid[i][j];
  }

  bool in_same_tree(int i, int j) const {
    return tree_id[i] == tree_id[j];
  }

  int get_tree_num() const {
    return trees.size();
  }
};
