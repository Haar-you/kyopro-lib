#define PROBLEM "https://yukicoder.me/problems/no/776"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

#include "Mylib/AlgebraicStructure/Monoid/max_partial_sum.cpp"
#include "Mylib/DataStructure/SegmentTree/Static/Normal/segment_tree.cpp"

using Mon = MaxPartialSumMonoid<int64_t>;

int main(){
  int N,Q; scanf("%d%d", &N, &Q);

  SegmentTree<Mon> seg(N);

  std::vector<int64_t> a(N);

  for(int i = 0; i < N; ++i){
    scanf("%lld", &a[i]);
    seg.update(i, Mon::MaxPartialSum::make(a[i]));
  }

  for(int i = 0; i < Q; ++i){
    std::string type; std::cin >> type;

    if(type == "set"){
      int i, x; scanf("%d%d", &i, &x);
      --i;
      seg.update(i, Mon::MaxPartialSum::make(x));
      a[i] = x;
    }else{
      int l1, l2, r1, r2; scanf("%d%d%d%d", &l1, &l2, &r1, &r2);
      --l1, --l2, --r1, --r2;

      r1 = std::max(l1,r1);
      l2 = std::min(l2,r2);
        
      int64_t ans = LLONG_MIN;
        
      auto f = [&](int L1, int L2, int R1, int R2){
                 auto ret =
                   seg.get(L1, L2+1).value_or(Mon::MaxPartialSum::make(0)).right_max +
                   seg.get(L2+1, R1).value_or(Mon::MaxPartialSum::make(0)).sum +
                   seg.get(R1, R2+1).value_or(Mon::MaxPartialSum::make(0)).left_max;

                 if(L2 == R1) ret -= a[L2];
                   
                 return ret;
               };

      if(l2 <= r1){
        ans = f(l1, l2, r1, r2);
      }else{
        ans = std::max(ans, f(l1, r1, r1, r2));
        ans = std::max(ans, f(l1, l2, l2, r2));
        ans = std::max(ans, seg.get(r1, l2+1)->partial_max);
      }

      printf("%lld\n", ans);
    }
  }

  return 0;
}
