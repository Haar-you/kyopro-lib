#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"

#include <iostream>
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/AlgebraicStructure/Monoid/affine.cpp"
#include "Mylib/AlgebraicStructure/Monoid/dual.cpp"
#include "Mylib/DataStructure/Queue/sliding_window_aggregation.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

using mint = hl::modint<998244353>;
using M = hl::dual_monoid<hl::affine_monoid<mint>>;

int main(){
  int Q; std::cin >> Q;

  hl::sliding_window_aggregation<M> swag;

  for(auto [type] : hl::input_tuples<int>(Q)){
    if(type == 0){
      int a, b; std::cin >> a >> b;
      swag.push({a, b});
    }else if(type == 1){
      swag.pop();
    }else{
      int x; std::cin >> x;
      auto res = swag.fold();
      if(res){
        auto [a, b] = *res;
        std::cout << a * x + b << std::endl;
      }else{
        std::cout << x << std::endl;
      }
    }
  }

  return 0;
}
