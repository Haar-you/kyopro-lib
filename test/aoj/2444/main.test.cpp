#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2444"

#include <iostream>
#include <string>
#include <set>
#include <array>
#include "Mylib/IO/input_tuples.cpp"
#include "Mylib/AlgebraicStructure/Monoid/rolling_hash.cpp"
#include "Mylib/DataStructure/SegmentTree/segment_tree.cpp"

namespace hl = haar_lib;

int main(){
  using Monoid = hl::RollingHashMonoid<2>;
  Monoid::base = {33, 100};
  Monoid::mod = 1000000007;

  int n, m; std::cin >> n >> m;
  std::string s; std::cin >> s;

  hl::SegmentTree<Monoid> seg(n);
  for(int i = 0; i < n; ++i) seg.update(i, Monoid::make(s[i]));

  std::set<std::array<int64_t, 2>> set;
  int l = 0, r = 1;

  for(auto [q] : hl::input_tuples<std::string>(m)){
    if(q[0] == 'L'){
      if(q[1] == '+') ++l;
      else --l;
    }else{
      if(q[1] == '+') ++r;
      else --r;
    }

    set.insert(seg.get(l, r).first);
  }

  std::cout << set.size() << "\n";

  return 0;
}
