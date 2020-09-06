#define PROBLEM "https://yukicoder.me/problems/447"

#include <iostream>
#include "Mylib/Number/chinese_remainder_algorithm.cpp"

int main(){
  int64_t x1, y1, x2, y2, x3, y3; std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

  int64_t m, r;

  if(CRA({x1, x2, x3}, {y1, y2, y3}, r, m)){
    std::cout << (r == 0 ? m : r) << std::endl;
  }else{
    std::cout << -1 << std::endl;
  }

  return 0;
}
