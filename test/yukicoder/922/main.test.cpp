#define PROBLEM "https://yukicoder.me/problems/no/922"

#include <iostream>
#include <vector>
#include <utility>

#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/TreeUtils/lca_based_on_doubling.cpp"
#include "Mylib/Graph/TreeUtils/forest.cpp"
#include "Mylib/Graph/TreeUtils/rerooting.cpp"
#include "Mylib/IO/input_graph.cpp"
#include "Mylib/IO/input_tuples.cpp"

int main(){
  int N, M, Q; std::cin >> N >> M >> Q;

  auto g = convert_to_graph<int64_t, false>(N, input_edges<int64_t, 1, false>(M));

  int64_t ans = 0;

  Forest<int64_t> forest(g);

  const int tree_num = forest.trees.size();
  std::vector<LCA<int64_t>> lcas(tree_num);

  for(int i = 0; i < tree_num; ++i){
    lcas[i] = LCA(forest.trees[i], 0);
  }

  std::vector<std::vector<int>> plans(tree_num);
  for(int i = 0; i < tree_num; ++i){
    plans[i] = std::vector<int>(forest.trees[i].size());
  }
    
  for(auto [a, b] : input_tuples<int, int>(Q)){
    --a, --b;

    if(forest.in_same_tree(a, b)){
      ans += lcas[forest.tree_id[a]].distance(forest.vertex_id[a], forest.vertex_id[b]);
    }else{
      plans[forest.tree_id[a]][forest.vertex_id[a]] += 1;
      plans[forest.tree_id[b]][forest.vertex_id[b]] += 1;
    }
  }

  for(int i = 0; i < tree_num; ++i){
    const auto &tree = forest.trees[i];
    const auto &plan = plans[i];

    auto res =
      make_rerooting<std::pair<int,int>>(
        tree,
        std::make_pair(0, 0),
        [](const auto &a, const auto &b){
          return std::make_pair(a.first + b.first, a.second + b.second);
        },
        [](const auto &x, const auto &e){
          return std::make_pair(x.first, x.second + x.first);
        },
        [&](const auto &x, int v){
          return std::make_pair(x.first + plan[v], x.second);
        }
      ).result;
      
    ans +=
      std::min_element(
        res.begin(),
        res.end(),
        [](const auto &a, const auto &b){
          return a.second < b.second;
        }
      )->second;
  }
    
  std::cout << ans << std::endl;

  return 0;
}
