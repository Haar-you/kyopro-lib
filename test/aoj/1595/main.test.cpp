#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1595"

#include <iostream>
#include "Mylib/Graph/graph_template.cpp"
#include "Mylib/Graph/TreeUtils/rerooting.cpp"
#include "Mylib/IO/input_graph.cpp"

int main(){
  int N; std::cin >> N;
  auto tree = convert_to_graph<int, false>(N, input_edges<int, 1, false>(N-1));

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
