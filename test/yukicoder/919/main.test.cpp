#define PROBLEM "https://yukicoder.me/problems/no/919"

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include "Mylib/DataStructure/WaveletMatrix/wavelet_matrix.cpp"
#include "Mylib/IO/input_vector.cpp"

namespace hl = haar_lib;

const int H = 1000000000;

int main(){
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  int N; std::cin >> N;

  auto A = hl::input_vector<int>(N);
  for(auto &x : A) x += H;

  auto wm = hl::make_wavelet_matrix_int(std::vector<uint32_t>(A.begin(), A.end()));

  int64_t ans = LLONG_MIN;

  for(int k = 1; k <= N; ++k){
    std::vector<int64_t> left, right;
    left.push_back(0);
    right.push_back(0);

    for(int i = 0; i + k <= N; i += k){
      left.push_back((int)*wm.quantile(i, i + k, (k + 1) / 2) - H);
    }

    for(int i = N; i - k >= 0; i -= k){
      right.push_back((int)*wm.quantile(i - k, i, (k + 1) / 2) - H);
    }


    for(int i = 1; i < (int)left.size(); ++i) left[i] += left[i - 1];
    for(int i = 1; i < (int)right.size(); ++i) right[i] += right[i - 1];

    for(int i = 1; i < (int)right.size(); ++i) right[i] = std::max(right[i], right[i - 1]);

    for(int i = 0; i < (int)left.size(); ++i){
      ans = std::max(ans, (left[i] + right.back()) * k);

      right.pop_back();
    }
  }

  std::cout << ans << "\n";

  return 0;
}
