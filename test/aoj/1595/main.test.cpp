#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1595"

#include <iostream>
#include "Mylib/Graph/TreeUtils/rerooting.cpp"
#include "Mylib/Graph/Template/graph.cpp"

int main(){
  int N; std::cin >> N;

  Tree<int> tree(N);
  tree.read<1, false, false>(N - 1);

  auto r = rerooting<int>(
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

  for(auto &x : r){
    std::cout << 2 * (N-1) - x << std::endl;
  }

  return 0;
}
