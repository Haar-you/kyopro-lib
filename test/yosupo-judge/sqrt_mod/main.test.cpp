#define PROBLEM "https://judge.yosupo.jp/problem/sqrt_mod"

#include <iostream>
#include "Mylib/Number/Mod/mod_sqrt.cpp"

void solve(){
  int64_t Y, P; scanf("%lld%lld", &Y, &P);

  auto ans = mod_sqrt(Y, P).value_or(-1);
  printf("%lld\n", ans);
}

int main(){
  int T; scanf("%d", &T);
  while(T--) solve();
  return 0;
}
