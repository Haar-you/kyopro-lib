#pragma once
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
#include <vector>

namespace haar_lib {
  std::vector<int> index_to_permutation(int64_t N, int S) {
    std::vector<int> ret;

    __gnu_pbds::tree<
        int, __gnu_pbds::null_type, std::less<int>,
        __gnu_pbds::rb_tree_tag,
        __gnu_pbds::tree_order_statistics_node_update>
        set;

    std::vector<int64_t> p(S + 1, 1);
    for (int i = 0; i < S; ++i) {
      p[i + 1] = p[i] * (i + 1);
      set.insert(i);
    }

    for (int i = S; --i >= 0;) {
      int64_t index = N / p[i];

      int j = *set.find_by_order(index);
      ret.push_back(j);
      set.erase(j);

      N %= p[i];
    }

    return ret;
  }

  template <typename T = int64_t>
  T permutation_to_index(const std::vector<int> &a) {
    const int N = a.size();
    T ret       = 0;

    __gnu_pbds::tree<
        int, __gnu_pbds::null_type, std::less<int>,
        __gnu_pbds::rb_tree_tag,
        __gnu_pbds::tree_order_statistics_node_update>
        set;

    std::vector<T> p(N + 1, 1);
    for (int i = 0; i < N; ++i) {
      p[i + 1] = p[i] * (i + 1);
      set.insert(i);
    }

    for (int i = 0; i < N; ++i) {
      int k = set.order_of_key(a[i]);
      ret += p[N - 1 - i] * k;
      set.erase(a[i]);
    }

    return ret;
  }

  std::vector<int> inverse_permutation(const std::vector<int> &a) {
    const int N = a.size();
    std::vector<int> ret(N);
    for (int i = 0; i < N; ++i) {
      ret[a[i]] = i;
    }

    return ret;
  }
}  // namespace haar_lib
