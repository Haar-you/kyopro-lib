#define PROBLEM "https://judge.yosupo.jp/problem/discrete_logarithm_mod"

#include <iostream>
#include "Mylib/Number/Mod/mod_log.cpp"

void solve(){
  int X, Y, M; scanf("%d%d%d", &X, &Y, &M);
  auto ans = mod_log(X, Y, M);
  
  printf("%lld\n", ans.value_or(-1));
}


int main(){
  int T; scanf("%d", &T);
  
  while(T--){
    solve();
  }

  return 0;
}
