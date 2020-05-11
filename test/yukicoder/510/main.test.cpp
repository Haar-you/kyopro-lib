#define PROBLEM "https://yukicoder.me/problems/no/510"

#include <iostream>
#include <vector>

#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/LinearAlgebra/Square/square_matrix_const_size.cpp"
#include "Mylib/DataStructure/SegmentTree/Static/Normal/segment_tree.cpp"
#include "Mylib/AlgebraicStructure/Monoid/product_matrix.cpp"
#include "Mylib/AlgebraicStructure/Monoid/dual.cpp"

using mint = ModInt<1000000007>;
using Mat = SquareMatrixConst<mint, 4>;
using Monoid = DualMonoid<ProductMatrixMonoid<Mat>>;

auto f(mint x, mint y){
  Mat ret = {
             {1, 0, x, 0},
             {0, y, 0, 1},
             {0, 2*y, y*y, 1},
             {0, 0, 0, 1}
  };
  return ret;
}

int main(){
  int n, q; std::cin >> n >> q;

  SegmentTree<Monoid> seg(n);
  std::vector<mint> x(n), y(n);

  for(int i = 0; i < n; ++i){
    seg.update(i, f(x[i], y[i]));
  }

  while(q--){
    char c; std::cin >> c;

    if(c == 'x'){
      int i, v; std::cin >> i >> v;
      x[i] = v;

      seg.update(i, f(x[i], y[i]));
    }else if(c == 'y'){
      int i, v; std::cin >> i >> v;
      y[i] = v;

      seg.update(i, f(x[i], y[i]));
    }else{
      int i; std::cin >> i;

      auto m = seg.get(0, i);
      auto ans = m[0][0] + m[0][1] + m[0][2] + m[0][3];
      std::cout << ans << "\n";
    }
  }
  
  return 0;
}
