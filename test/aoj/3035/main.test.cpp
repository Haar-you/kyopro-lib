#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3035"

#include <iostream>
#include <algorithm>
#include <map>
#include <climits>
#include "Mylib/IO/input_vector.cpp"
#include "Mylib/IO/input_tuples.cpp"
#include "Mylib/AlgebraicStructure/Monoid/sum.cpp"
#include "Mylib/AlgebraicStructure/Monoid/max.cpp"
#include "Mylib/AlgebraicStructure/Monoid/min.cpp"
#include "Mylib/AlgebraicStructure/Monoid/with_count.cpp"
#include "Mylib/AlgebraicStructure/MonoidAction/add_max_with_count.cpp"
#include "Mylib/AlgebraicStructure/MonoidAction/add_min_with_count.cpp"
#include "Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp"

namespace hl = haar_lib;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int H, W, Q; std::cin >> H >> W >> Q;
  auto A = hl::input_vector<int64_t>(H);
  auto B = hl::input_vector<int64_t>(W);

  auto seg_h_max = hl::lazy_segment_tree<hl::with_count<hl::max_monoid<int64_t>>, hl::sum_monoid<int64_t>, hl::add_max_with_count>(H);
  auto seg_h_min = hl::lazy_segment_tree<hl::with_count<hl::min_monoid<int64_t>>, hl::sum_monoid<int64_t>, hl::add_min_with_count>(H);
  auto seg_w_max = hl::lazy_segment_tree<hl::with_count<hl::max_monoid<int64_t>>, hl::sum_monoid<int64_t>, hl::add_max_with_count>(W);
  auto seg_w_min = hl::lazy_segment_tree<hl::with_count<hl::min_monoid<int64_t>>, hl::sum_monoid<int64_t>, hl::add_min_with_count>(W);

  seg_h_max.init_with_vector(A);
  seg_h_min.init_with_vector(A);
  seg_w_max.init_with_vector(B);
  seg_w_min.init_with_vector(B);

  for(auto [type] : hl::input_tuples<int>(Q)){
    switch(type){
    case 1: {
      int a, b, v; std::cin >> a >> b >> v;
      --a;
      seg_h_max.update(a, b, v);
      seg_h_min.update(a, b, v);
      break;
    }

    case 2: {
      int c, d, v; std::cin >> c >> d >> v;
      --c;
      seg_w_max.update(c, d, v);
      seg_w_min.update(c, d, v);
      break;
    }

    case 3: {
      int64_t a, b, c, d; std::cin >> a >> b >> c >> d;
      --a, --c;

      std::map<int64_t, int64_t> m;

      auto x = std::vector{seg_h_max.fold(a, b), seg_h_min.fold(a, b)};
      auto y = std::vector{seg_w_max.fold(c, d), seg_w_min.fold(c, d)};

      if(x[0].value == x[1].value) x.pop_back();
      if(y[0].value == y[1].value) y.pop_back();

      int64_t M = LLONG_MAX;
      for(auto p : x){
        for(auto q : y){
          M = std::min(M, *p.value * *q.value);
        }
      }

      if(M == 0){
        int64_t p = 0;
        for(auto e : x) if(e.value == 0) p += e.count;
        int64_t q = 0;
        for(auto e : y) if(e.value == 0) q += e.count;
        m[0] = (b - a) * q + (d - c) * p - p * q;
      }else{
        for(auto p : x){
          for(auto q : y){
            m[*p.value * *q.value] += p.count * q.count;
          }
        }
      }

      std::cout << m.begin()->first << " " << m.begin()->second << "\n";

      break;
    }

    case 4: {
      int64_t a, b, c, d; std::cin >> a >> b >> c >> d;
      --a, --c;

      std::map<int64_t, int64_t> m;

      auto x = std::vector{seg_h_max.fold(a, b), seg_h_min.fold(a, b)};
      auto y = std::vector{seg_w_max.fold(c, d), seg_w_min.fold(c, d)};

      if(x[0].value == x[1].value) x.pop_back();
      if(y[0].value == y[1].value) y.pop_back();

      int64_t M = LLONG_MIN;
      for(auto p : x){
        for(auto q : y){
          M = std::max(M, *p.value * *q.value);
        }
      }

      if(M == 0){
        int64_t p = 0;
        for(auto e : x) if(e.value == 0) p += e.count;
        int64_t q = 0;
        for(auto e : y) if(e.value == 0) q += e.count;
        m[0] = (b - a) * q + (d - c) * p - p * q;
      }else{
        for(auto p : x){
          for(auto q : y){
            m[*p.value * *q.value] += p.count * q.count;
          }
        }
      }

      std::cout << m.rbegin()->first << " " << m.rbegin()->second << "\n";

      break;
    }
    }
  }

  return 0;
}
