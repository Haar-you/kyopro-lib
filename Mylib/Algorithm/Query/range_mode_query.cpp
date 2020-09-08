#pragma once
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>

/**
 * @title Range mode query
 * @docs range_mode_query.md
 */
namespace haar_lib {
  template <typename T>
  class range_mode_query {
    std::vector<T> a, D;
    std::vector<int> b, b_index;

    const int N;
    const int block_size;
    const int block_num;

    int K;

    std::vector<std::vector<int>> index;
    std::vector<std::vector<int>> mode, freq;

  public:
    range_mode_query(std::vector<T> a):
      a(a), D(a), N(a.size()), block_size(sqrt(N)), block_num((N + block_size - 1) / block_size),
      mode(block_num, std::vector<int>(block_num)),
      freq(block_num, std::vector<int>(block_num))
    {
      std::sort(D.begin(), D.end());
      D.erase(std::unique(D.begin(), D.end()), D.end());

      b.resize(N);
      for(int i = 0; i < N; ++i){
        b[i] = std::lower_bound(D.begin(), D.end(), a[i]) - D.begin();
      }

      K = D.size();

      index.resize(K);
      b_index.resize(N);
      for(int i = 0; i < N; ++i){
        b_index[i] = index[b[i]].size();
        index[b[i]].push_back(i);
      }

      for(int i = 0; i < block_num; ++i){
        std::vector<int> temp(K);
        int md = 0, fr = 0;

        for(int j = i; j < block_num; ++j){
          int R = std::min(N, block_size * (j + 1));
          for(int x = block_size * j; x < R; ++x){
            temp[b[x]] += 1;

            if(temp[b[x]] > fr){
              md = b[x];
              fr = temp[b[x]];
            }
          }

          mode[i][j] = md;
          freq[i][j] = fr;
        }
      }
    }

    std::pair<int, T> query(int l, int r){ // [l, r)
      std::pair<int, T> ret = std::make_pair(0, 0);

      int span_l = (l + block_size - 1) / block_size, span_r = r / block_size - 1;

      if(span_l <= span_r){
        ret = std::make_pair(freq[span_l][span_r], D[mode[span_l][span_r]]);
      }

      // prefix
      for(int i = l; i < std::min(r, span_l * block_size); ++i){
        if(b_index[i] - 1 >= 0 and index[b[i]][b_index[i] - 1] >= l) continue;

        if(b_index[i] + ret.first - 1 < 0 or (b_index[i] + ret.first - 1 < (int)index[b[i]].size() and index[b[i]][b_index[i] + ret.first - 1] < r)){
          int fr = ret.first;

          for(int j = b_index[i] + ret.first; j < (int)index[b[i]].size(); ++j){
            if(index[b[i]][j] < r) ++fr;
            else break;
          }

          if(fr > ret.first){
            ret = std::make_pair(fr, D[b[i]]);
          }
        }
      }

      // suffix
      for(int i = r - 1; i >= std::max(l, (span_r + 1) * block_size); --i){
        if(b_index[i] + 1 < (int)index[b[i]].size() and index[b[i]][b_index[i] + 1] < r) continue;

        if(b_index[i] - ret.first + 1 >= (int)index[b[i]].size() or (b_index[i] - ret.first + 1 >= 0 and index[b[i]][b_index[i] - ret.first + 1] >= l)){
          int fr = ret.first;

          for(int j = b_index[i] - ret.first; j >= 0; --j){
            if(index[b[i]][j] >= l) ++fr;
            else break;
          }

          if(fr > ret.first){
            ret = std::make_pair(fr, D[b[i]]);
          }
        }
      }

      return ret;
    }
  };
}
