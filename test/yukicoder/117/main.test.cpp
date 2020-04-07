#define PROBLEM "https://yukicoder.me/problems/no/117"

#include <iostream>

#include "Mylib/Number/Mint/mint.cpp"
#include "Mylib/Combinatorics/combinatorics.cpp"

using mint = ModInt<1000000007>;
using C = Combinatorics<mint>;

int main(){
  C::init(2000000);
  
  int T; scanf("%d", &T);

  while(T--){
    char type;
    int N, K;
    scanf(" %c(%d,%d)", &type, &N, &K);

    switch(type){
    case 'C': printf("%d\n", (int)C::C(N, K)); break;
    case 'P': printf("%d\n", (int)C::P(N, K)); break;
    case 'H': printf("%d\n", (int)C::H(N, K)); break;
    }
  }

  return 0;
}
