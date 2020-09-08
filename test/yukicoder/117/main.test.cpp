#define PROBLEM "https://yukicoder.me/problems/no/117"

#include <iostream>
#include <string>
#include <regex>
#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/Combinatorics/factorial_table.cpp"
#include "Mylib/IO/input_tuples.cpp"

namespace hl = haar_lib;

using mint = hl::modint<1000000007>;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  auto ft = hl::factorial_table<mint>(2000000);

  int T; std::cin >> T;

  std::regex re(R"((.)\((.+),(.+)\))");

  for(auto [s] : hl::input_tuples<std::string>(T)){
    std::smatch m;
    std::regex_match(s, m, re);

    char type = m[1].str()[0];
    int N = std::stoi(m[2].str());
    int K = std::stoi(m[3].str());

    switch(type){
    case 'C': std::cout << ft.C(N, K) << "\n"; break;
    case 'P': std::cout << ft.P(N, K) << "\n"; break;
    case 'H': std::cout << ft.H(N, K) << "\n"; break;
    }
  }

  return 0;
}
