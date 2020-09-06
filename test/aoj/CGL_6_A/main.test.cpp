#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_6_A"

#include <iostream>
#include <vector>
#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/manhattan_segments_intersections.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int n; std::cin >> n;
  std::vector<Segment<int>> s(n);
  for(int i = 0; i < n; ++i){
    std::cin >> s[i].from >> s[i].to;
  }

  auto ans = manhattan_segments_intersections(s);
  std::cout << ans << "\n";

  return 0;
}
