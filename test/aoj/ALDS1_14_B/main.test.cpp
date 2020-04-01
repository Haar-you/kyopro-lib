#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"

#include <iostream>
#include <string>
#include "Mylib/String/rolling_hash.cpp"

using RH = RollingHash<std::string, 30, 1000000007>;

int main(){
  RH::init(1000000);
  
  std::string t, p; std::cin >> t >> p;
  
  auto t_hashs = RH::gen_hash_table(t);
  auto p_hash = RH::gen_hash(p);

  for(int i = 0; i < (int)t.size(); ++i){
    if(i + p.size() <= t.size() and t_hashs.get(i, i + p.size()) == p_hash){
      std::cout << i << std::endl;
    }
  }
  
  return 0;
}
