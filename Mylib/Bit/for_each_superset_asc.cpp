#pragma once

/**
 * @docs for_each_superset_asc.md
 */
template <typename Func>
void for_each_superset_asc(int a, int n, const Func &f){
  for(int t=a; t<(1<<n); t=(t+1)|a){
    f(t);
  }
}
