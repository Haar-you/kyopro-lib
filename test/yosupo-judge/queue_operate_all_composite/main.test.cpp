#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"

#include <iostream>
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/AlgebraicStructure/Monoid/affine.cpp"
#include "Mylib/Algorithm/SlidingWindow/sliding_window_aggregation.cpp"

using mint = ModInt<998244353>;
using M = AffineMonoid<mint>;

int main(){
  int Q; std::cin >> Q;

  SlidingWindowAggregation<M> swag;
  
  while(Q--){
    int type; std::cin >> type;

    if(type == 0){
      int a,b; std::cin >> a >> b;
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