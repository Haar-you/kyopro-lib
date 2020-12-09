#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3118"

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <climits>
#include "Mylib/IO/input_tuples.cpp"
#include "Mylib/IO/input_tuple_vector.cpp"
#include "Mylib/Algorithm/sqrt_decomposition.cpp"

namespace hl = haar_lib;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N, Q; std::cin >> N >> Q;

  hl::sqrt_decomposition sd(N);

  auto [A, B] = hl::input_tuple_vector<int64_t, int64_t>(N);

  const int NUM = sd.block_num();

  std::vector<std::vector<int64_t>> s(NUM);
  std::vector<std::vector<int64_t>> left(NUM), right(NUM);
  std::vector<int64_t> sum(NUM);

  auto f =
    [&](int i, int l, int r){
      const int size = r - l;

      std::vector<int64_t> d(size);
      for(int j = 0; j < size; ++j) d[j] = A[l + j] - B[l + j];

      std::vector<int> ord(size);
      std::iota(ord.begin(), ord.end(), 0);
      std::sort(ord.begin(), ord.end(), [&](int i_, int j_){return d[i_] < d[j_];});

      s[i].assign(size, 0);

      left[i].assign(size, 0);
      right[i].assign(size, 0);

      for(int j = 0; j < size; ++j){
        s[i][j] = d[ord[j]];
        left[i][j] = B[l + ord[j]];
        right[i][j] = A[l + ord[j]];
      }

      for(int j = 1; j < size; ++j){
        left[i][j] = std::min(left[i][j], left[i][j - 1]);
      }

      for(int j = size - 1; --j >= 0;){
        right[i][j] = std::min(right[i][j], right[i][j + 1]);
      }
    };

  sd.init(f);

  for(auto [c] : hl::input_tuples<int>(Q)){
    if(c == 1){
      int l, r, x; std::cin >> l >> r >> x;
      --l;

      sd.query(
        l, r,
        [&](int i, int, int){
          sum[i] += x;
        },
        [&](int i, int L, int R, int l, int r){
          for(int j = L; j < R; ++j) A[j] += sum[i];
          for(int j = l; j < r; ++j) A[j] += x;
          sum[i] = 0;
          f(i, L, R);
        }
      );
    }else{
      int l, r; std::cin >> l >> r;
      --l;

      int64_t ans = LLONG_MAX;

      sd.query(
        l, r,
        [&](int i, int L, int R){
          int k = std::upper_bound(s[i].begin(), s[i].end(), -sum[i]) - s[i].begin();
          if(k - 1 >= 0) ans = std::min(ans, left[i][k - 1]);
          if(k < R - L) ans = std::min(ans, right[i][k] + sum[i]);
        },
        [&](int i, int, int, int l, int r){
          for(int j = l; j < r; ++j) ans = std::min(ans, std::max(A[j] + sum[i], B[j]));
        }
      );

      std::cout << ans << "\n";
    }
  }

  return 0;
}
