#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_C"

#include <iostream>
#include <map>
#include <utility>
#include <vector>
#include "Mylib/DataStructure/RangeTree/range_tree.cpp"
#include "Mylib/IO/input_tuples.cpp"

int main(){
  int n; std::cin >> n;
  RangeTree rt;

  std::map<std::pair<int,int>, int> m;

  for(int i = 0; i < n; ++i){
    int x, y; std::cin >> x >> y;
    rt.add(x,y);
    m[{x,y}] = i;
  }
  rt.build();

  int q; std::cin >> q;

  for(auto [sx, tx, sy, ty] : input_tuples<int, int, int, int>(q)){
    auto res = rt.get(sx, sy, tx+1, ty+1);

    std::vector<int> ans;
    for(auto &p : res) ans.push_back(m[p]);

    std::sort(ans.begin(), ans.end());
    for(auto &x : ans){
      std::cout << x << "\n";
    }
    std::cout << "\n";
  }

  return 0;
}
