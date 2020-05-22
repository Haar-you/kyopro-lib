#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1595"

#include <iostream>
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/TreeUtils/rerooting.cpp"

int main(){
  int N; std::cin >> N;
  Tree<int> tree(N);

  for(int i = 0; i < N-1; ++i){
    int u, v; std::cin >> u >> v;
    --u, --v;
    add_undirected(tree, u, v, 1);
  }

  auto r = make_rerooting<int>(
    tree,
    0,
    [](const auto &a, const auto &b){
      return std::max(a, b);
    },
    [](const auto &a, const auto &){
      return a + 1;
    },
    [](const auto &a, int){
      return a;
    }
  );

  for(auto &x : r.result){
    std::cout << 2 * (N-1) - x << std::endl;
  }

  return 0;
}
