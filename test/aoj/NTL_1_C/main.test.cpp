#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_C"

#include <iostream>
#include <vector>
#include "Mylib/Number/binary_gcd.cpp"

int main(){
  int n; std::cin >> n;

  std::vector<int> a(n);
  for(int i = 0; i < n; ++i) std::cin >> a[i];

  int l = 1;
  for(auto x : a){
    l = l / binary_gcd(l, x) * x;
  }

  std::cout << l << "\n";

  return 0;
}
