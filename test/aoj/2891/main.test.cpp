#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2891"

#include <iostream>
#include "Mylib/IO/input_tuples.cpp"
#include "Mylib/Graph/Template/graph.cpp"
#include "Mylib/Graph/GraphUtils/decompose_pseudotree.cpp"

int main(){
  int N; std::cin >> N;

  Graph<int> g(N);
  g.read<1, false, false>(N);

  auto res = PseudoTree<int>(g);

  int Q; std::cin >> Q;
  for(auto [a, b] : input_tuples<int, int>(Q)){
    --a, --b;

    if(res.in_loop[a] and res.in_loop[b]){
      std::cout << 2 << "\n";
    }else{
      std::cout << 1 << "\n";
    }
  }

  return 0;
}
