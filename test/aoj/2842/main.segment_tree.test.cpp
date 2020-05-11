#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2842"

#include <iostream>
#include <queue>
#include <tuple>

#include "Mylib/AlgebraicStructure/Monoid/sum.cpp"
#include "Mylib/DataStructure/SegmentTree/Static/Normal/segment_tree_2d.cpp"

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int H,W,T,Q; std::cin >> H >> W >> T >> Q;

  SegmentTree2D<SumMonoid<int>> seg1(H, W), seg2(H, W);

  std::queue<std::tuple<int,int,int>> q;
  
  while(Q--){
    int t,c; std::cin >> t >> c;
    
    while(q.size()){
      auto &a = q.front();
      
      if(t >= std::get<2>(a) + T){
        int x = std::get<0>(a), y = std::get<1>(a);
        
        seg1.update(x, y, seg1.at(x, y) + 1);
        seg2.update(x, y, seg2.at(x, y) - 1);
        
        q.pop();
      }else{
        break;
      }
    }
      
    if(c == 0){
      int h,w; std::cin >> h >> w;
      --h, --w;
      
      seg2.update(h, w, seg2.at(h, w) + 1);
      q.emplace(h, w, t);
    }else if(c==1){
      int h,w; std::cin >> h >> w;
      --h, --w;
      
      if(seg1.at(h, w) == 1) seg1.update(h, w, seg1.at(h, w) - 1);
    }else{
      int h1,w1,h2,w2; std::cin >> h1 >> w1 >> h2 >> w2;
      --h1, --w1;
      
      std::cout << seg1.get(h1, w1, h2, w2) << " " << seg2.get(h1, w1, h2, w2) << std::endl;
    }
  }
  
  return 0;
}
