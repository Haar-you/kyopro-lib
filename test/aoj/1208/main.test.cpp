#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1208"

#include <iostream>
#include <utility>
#include "Mylib/Number/Rational/stern_brocot_tree.cpp"

namespace hl = haar_lib;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int p, n;
  while(std::cin >> p >> n, p){
    std::pair<int, int> lower, upper;
    hl::stern_brocot_tree(
      [p](int64_t pm, int64_t qm){
        auto a = pm * pm;
        auto b = p * qm * qm;
        if(a < b) return -1;
        if(a > b) return 1;
        return 0;
      },
      n, lower, upper
    );
    std::cout << upper.first << "/" << upper.second << " "
              << lower.first << "/" << lower.second << "\n";
  }

  return 0;
}
