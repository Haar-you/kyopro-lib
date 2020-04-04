#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2136"

#include <iostream>
#include <vector>

#include "Mylib/Geometry/Float/double_eps.cpp"
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/intersect_segments.cpp"
#include "Mylib/Graph/Coloring/chromatic_number.cpp"

using D = DoubleEps<double>;
template <> double D::eps = 1e-7;

bool intersect(const std::vector<Point<D>> &a, const std::vector<Point<D>> &b){
  for(int i = 0; i < (int)a.size()-1; ++i){
    for(int j = 0; j < (int)b.size()-1; ++j){
      auto l1 = Line<D>(a[i], a[i+1]);
      auto l2 = Line<D>(b[j], b[j+1]);
      if(intersect_segments::check(l1, l2).status != intersect_segments::NOT_INTERSECTING){
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
    std::vector<std::vector<Point<D>>> lines(N);

    for(int i = 0; i < N; ++i){
      int S; std::cin >> S;
      lines[i].resize(S);
      for(int j = 0; j < S; ++j){
        std::cin >> lines[i][j].x >> lines[i][j].y;
      }
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

    int ans = chromatic_number(graph);
    std::cout << ans << std::endl;
  }

  return 0;
}
