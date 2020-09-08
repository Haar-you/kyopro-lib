#pragma once
#include <vector>
#include <utility>
#include <algorithm>
#include <iterator>

/**
 * @docs range_tree.md
 */
namespace haar_lib {
  class range_tree {
    int N = 0;
    std::vector<int64_t> xs, ys;
    std::vector<int64_t> c_xs;

    int size;
    std::vector<std::vector<std::pair<int64_t, int>>> data;

  public:
    range_tree(){}

    void add(int64_t x, int64_t y){
      ++N;
      xs.push_back(x);
      ys.push_back(y);
    }

    void build(){
      c_xs = xs;
      std::sort(c_xs.begin(), c_xs.end());
      c_xs.erase(std::unique(c_xs.begin(), c_xs.end()), c_xs.end());

      int M = c_xs.size();
      size = 1 << (M > 1 ? 32 - __builtin_clz(M - 1) + 1 : 1);

      data.resize(size);

      for(int i = 0; i < N; ++i){
        int j = std::lower_bound(c_xs.begin(), c_xs.end(), xs[i]) - c_xs.begin();
        data[size / 2 + j].emplace_back(ys[i], j);
      }

      for(int i = size / 2; i < size; ++i){
        std::sort(data[i].begin(), data[i].end());
      }

      for(int i = size / 2 - 1; i > 0; --i){
        auto &a = data[i << 1 | 0];
        auto &b = data[i << 1 | 1];

        std::merge(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(data[i]));
      }
    }

    /**
     * @attention [sx, tx), [sy, ty)
     */
    std::vector<std::pair<int64_t, int64_t>> get(int64_t sx, int64_t sy, int64_t tx, int64_t ty) const {
      std::vector<std::pair<int64_t, int64_t>> ret;

      int L = std::lower_bound(c_xs.begin(), c_xs.end(), sx) - c_xs.begin();
      int R = std::lower_bound(c_xs.begin(), c_xs.end(), tx) - c_xs.begin();

      L += size / 2;
      R += size / 2;

      while(L < R){
        if(R & 1){
          auto &a = data[--R];

          auto it = std::lower_bound(a.begin(), a.end(), std::make_pair(sy, 0));

          while(it != a.end()){
            if(it->first >= ty) break;

            ret.emplace_back(c_xs[it->second], it->first);

            ++it;
          }
        }

        if(L & 1){
          auto &a = data[L++];

          auto it = std::lower_bound(a.begin(), a.end(), std::make_pair(sy, 0));

          while(it != a.end()){
            if(it->first >= ty) break;

            ret.emplace_back(c_xs[it->second], it->first);

            ++it;
          }
        }

        L >>= 1;
        R >>= 1;
      }

      return ret;
    }
  };
}
