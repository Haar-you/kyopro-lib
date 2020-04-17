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

  auto merge = [](const auto &a, const auto &b){return std::max(a, b);};
  auto f = [](const auto &a, const auto &){return a + 1;};
  auto g = [](const auto &a, int){return a;};

  auto r = make_rerooting<int>(tree, 0, merge, f, g);

  for(auto &x : r.result){
    std::cout << 2 * (N-1) - x << std::endl;
  }

  return 0;
}
