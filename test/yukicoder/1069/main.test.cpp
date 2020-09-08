#define PROBLEM "https://yukicoder.me/problems/no/1069"
#define ERROR 1e-4

#include <iostream>
#include <iomanip>
#include <cmath>
#include "Mylib/IO/input_tuple_vector.cpp"
#include "Mylib/IO/input_tuples.cpp"
#include "Mylib/Graph/ShortestPath/yen_algorithm.cpp"

namespace hl = haar_lib;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, M, K, X, Y; std::cin >> N >> M >> K >> X >> Y;
  --X, --Y;

  auto [p, q] = hl::input_tuple_vector<long double, long double>(N);

  hl::graph<long double> g(N);
  for(auto [P, Q] : hl::input_tuples<int, int>(M)){
    --P, --Q;

    long double dx = p[P] - p[Q];
    long double dy = q[P] - q[Q];

    long double L = std::sqrt(dx * dx + dy * dy);

    g.add_undirected(P, Q, L);
  }

  auto res = hl::yen_algorithm(g, X, Y, K);

  for(auto x : res){
    if(not x){
      std::cout << -1 << "\n";
    }else{
      std::cout << std::fixed << std::setprecision(12) << x->first << "\n";
    }
  }

  return 0;
}
