#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"

#include <iostream>
#include <string>
#include "Mylib/String/rolling_hash.cpp"

int main(){
  auto rh = make_rh(1000000, 1000000007);
  
  std::string t, p; std::cin >> t >> p;
  
  auto t_hashes = rh.gen_hash_table(t);
  auto p_hash = rh.gen_hash(p);

  for(int i = 0; i < (int)t.size(); ++i){
    if(i + p.size() <= t.size() and rh.get(t_hashes, i, i + p.size()) == p_hash){
      std::cout << i << std::endl;
    }
  }
  
  return 0;
}
