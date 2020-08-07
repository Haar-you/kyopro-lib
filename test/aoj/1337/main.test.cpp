#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1337"

#include <iostream>
#include <vector>
#include "Mylib/Utils/compressor.cpp"
#include "Mylib/DataStructure/UnionFind/unionfind.cpp"
#include "Mylib/IO/input_tuple_vector.cpp"

const int H = 200;
const int W = 200;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  
  int n;

  while(std::cin >> n, n){
    auto [l, t, r, b] = input_tuple_vector<int, int, int, int>(n);

    int64_t a[H][W] = {};

    Compressor<int>().add(l, r, -1).build().compress(l, r);
    Compressor<int>().add(t, b, -1).build().compress(t, b);

    for(int i = 0; i < n; ++i){
      for(int x = l[i]; x < r[i]; ++x){
        for(int y = b[i]; y < t[i]; ++y){
          a[x][y] |= (1LL << i);
        }
      }
    }

    UnionFind uf(H * W);
    int index[H][W];
    {
      int k = 0;
      for(int i = 0; i < H; ++i){
        for(int j = 0; j < W; ++j){
          index[i][j] = k;
          ++k;
        }
      }
    }
    
    for(int i = 0; i < H; ++i){
      for(int j = 0; j < W; ++j){
        if(i+1 < H and a[i][j] == a[i+1][j]) uf.merge(index[i][j], index[i+1][j]);
        if(j+1 < W and a[i][j] == a[i][j+1]) uf.merge(index[i][j], index[i][j+1]);
      }
    }

    int ans = uf.count_group();

    std::cout << ans << "\n";
  }
  
  return 0;
}
