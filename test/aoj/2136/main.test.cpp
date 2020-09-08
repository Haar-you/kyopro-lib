#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2136"

#include <iostream>
#include <vector>
#include "Mylib/Geometry/Float/double_eps.cpp"
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/intersect_segments.cpp"
#include "Mylib/Graph/Coloring/chromatic_number.cpp"
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/IO/input_tuples_with_index.cpp"

namespace hl = haar_lib;

using D = hl::DoubleEps<double>;
template <> double D::eps = 1e-7;

bool intersect(const std::vector<hl::Point<D>> &a, const std::vector<hl::Point<D>> &b){
  for(int i = 0; i < (int)a.size() - 1; ++i){
    for(int j = 0; j < (int)b.size() - 1; ++j){
      auto l1 = hl::Line<D>(a[i], a[i + 1]);
      auto l2 = hl::Line<D>(b[j], b[j + 1]);
      if(hl::intersect_segments::check(l1, l2).status != hl::intersect_segments::NOT_INTERSECTING){
        return true;
      }
    }
  }

  return false;
}

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N;

  while(std::cin >> N, N){
    std::vector<std::vector<hl::Point<D>>> lines(N);

    for(auto [i, S] : hl::input_tuples_with_index<int>(N)){
      lines[i] = hl::input_vector<hl::Point<D>>(S);
    }

    std::vector<std::vector<int>> graph(N);

    for(int i = 0; i < N; ++i){
      for(int j = 0; j < i; ++j){
        if(intersect(lines[i], lines[j])){
          graph[j].push_back(i);
          graph[i].push_back(j);
        }
      }
    }

    int ans = hl::chromatic_number(graph);
    std::cout << ans << std::endl;
  }

  return 0;
}
