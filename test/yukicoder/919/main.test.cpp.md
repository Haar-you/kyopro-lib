---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/DataStructure/WaveletMatrix/succinct_dictionary.cpp
    title: Succinct dictionary
  - icon: ':question:'
    path: Mylib/DataStructure/WaveletMatrix/wavelet_matrix.cpp
    title: Wavelet matrix
  - icon: ':question:'
    path: Mylib/IO/input_vector.cpp
    title: Input vector
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/919
    links:
    - https://yukicoder.me/problems/no/919
  bundledCode: "#line 1 \"test/yukicoder/919/main.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/919\"\
    \n\n#include <iostream>\n#include <vector>\n#include <algorithm>\n#include <climits>\n\
    #line 3 \"Mylib/DataStructure/WaveletMatrix/wavelet_matrix.cpp\"\n#include <utility>\n\
    #include <tuple>\n#include <cassert>\n#include <optional>\n#include <queue>\n\
    #line 5 \"Mylib/DataStructure/WaveletMatrix/succinct_dictionary.cpp\"\n\nnamespace\
    \ haar_lib {\n  class succinct_dict {\n    int N_;\n\n    static const int chunk_size_\
    \ = 256;\n    static const int block_size_ = 64;\n    std::vector<uint64_t> data_;\n\
    \n    std::vector<std::vector<uint8_t>> blocks_;\n\n    std::vector<uint32_t>\
    \ chunks_;\n\n    int chunk_num_;\n    static const int block_num_ = chunk_size_\
    \ / block_size_;\n\n  public:\n    succinct_dict(): N_(0){}\n    succinct_dict(const\
    \ std::vector<bool> &b): N_(b.size()){\n      chunk_num_ = (N_ + chunk_size_ -\
    \ 1) / chunk_size_;\n\n      data_.assign(chunk_num_ * block_num_ + 1, 0);\n\n\
    \      for(int i = 0; i < N_; ++i){\n        if(b[i]){\n          int block_index\
    \ = i / block_size_;\n          int index = i % block_size_;\n          data_[block_index]\
    \ |= (1LL << index);\n        }\n      }\n\n      chunks_.assign(chunk_num_ +\
    \ 1, 0);\n      blocks_.assign(chunk_num_ + 1, std::vector<uint8_t>(block_num_,\
    \ 0));\n\n      for(int i = 0; i < chunk_num_; ++i){\n        for(int j = 0; j\
    \ < block_num_ - 1; ++j){\n          blocks_[i][j + 1] = blocks_[i][j] + __builtin_popcountll(data_[i\
    \ * block_num_ + j]);\n        }\n\n        chunks_[i + 1] = chunks_[i] + blocks_[i][block_num_\
    \ - 1] + __builtin_popcountll(data_[(i + 1) * block_num_ - 1]);\n      }\n   \
    \ }\n\n    int size() const {return N_;}\n\n    /**\n     * @return [0, index)\u306E\
    b\u306E\u500B\u6570\n     */\n    int rank(int index, int b) const {\n      if(b\
    \ == 0){\n        return index - rank(index, 1);\n      }else{\n        if(index\
    \ > N_) index = N_;\n\n        const int chunk_pos = index / chunk_size_;\n  \
    \      const int block_pos = (index % chunk_size_) / block_size_;\n\n        const\
    \ uint64_t mask =\n          data_[chunk_pos * block_num_ + block_pos] & ((1LL\
    \ << (index % block_size_)) - 1);\n\n        const int ret = chunks_[chunk_pos]\
    \ +\n          blocks_[chunk_pos][block_pos] +\n          __builtin_popcountll(mask);\n\
    \n        return ret;\n      }\n    }\n\n    /**\n     * @return [l, r)\u306E\
    b\u306E\u500B\u6570\n     */\n    int count(int l, int r, int b) const {\n   \
    \   return rank(r, b) - rank(l, b);\n    }\n\n    /**\n     * @return b[index]\n\
    \     */\n    int access(int index) const {\n      return (data_[index / block_size_]\
    \ >> (index % block_size_)) & 1;\n    }\n\n    /**\n     * @note n in [1, N]\n\
    \     * @return \u5148\u982D\u304B\u3089n\u756A\u76EE\u306Eb\u306E\u4F4D\u7F6E\
    \n     */\n    std::optional<int> select(int n, int b) const {\n      assert(n\
    \ >= 1);\n\n      if(rank(N_, b) < n) return {};\n\n      int lb = -1, ub = N_;\n\
    \      while(std::abs(lb - ub) > 1){\n        int mid = (lb + ub) / 2;\n\n   \
    \     if(rank(mid, b) >= n){\n          ub = mid;\n        }else{\n          lb\
    \ = mid;\n        }\n      }\n\n      return {lb};\n    }\n  };\n}\n#line 9 \"\
    Mylib/DataStructure/WaveletMatrix/wavelet_matrix.cpp\"\n\nnamespace haar_lib {\n\
    \  template <typename T, int B>\n  class wavelet_matrix {\n  public:\n    using\
    \ value_type = T;\n\n  private:\n    int N_;\n    succinct_dict sdict_[B];\n \
    \   int zero_pos_[B];\n\n  public:\n    wavelet_matrix(){}\n    wavelet_matrix(std::vector<T>\
    \ data): N_(data.size()){\n      std::vector<bool> s(N_);\n\n      for(int k =\
    \ 0; k < B; ++k){\n        std::vector<T> left, right;\n\n        for(int i =\
    \ 0; i < N_; ++i){\n          s[i] = (data[i] >> (B - 1 - k)) & 1;\n         \
    \ if(s[i]){\n            right.push_back(data[i]);\n          }else{\n       \
    \     left.push_back(data[i]);\n          }\n        }\n\n        sdict_[k] =\
    \ succinct_dict(s);\n        zero_pos_[k] = left.size();\n\n        std::swap(data,\
    \ left);\n        data.insert(data.end(), right.begin(), right.end());\n     \
    \ }\n    }\n\n    /**\n     * @return data[index]\n     */\n    T access(int index){\n\
    \      assert(0 <= index and index < N_);\n      T ret = 0;\n\n      int p = index;\n\
    \      for(int i = 0; i < B; ++i){\n        int t = sdict_[i].access(p);\n   \
    \     ret |= ((T)t << (B - 1 - i));\n        p = sdict_[i].rank(p, t) + t * zero_pos_[i];\n\
    \      }\n\n      return ret;\n    }\n\n    std::pair<int, int> rank_aux(int index,\
    \ const T &val){\n      int l = 0, r = index;\n\n      for(int i = 0; i < B; ++i){\n\
    \        int t = (val >> (B - i - 1)) & 1;\n        l = sdict_[i].rank(l, t) +\
    \ t * zero_pos_[i];\n        r = sdict_[i].rank(r, t) + t * zero_pos_[i];\n  \
    \    }\n\n      return std::make_pair(l, r);\n    }\n\n    /**\n     * @return\
    \ data[0, index)\u306B\u542B\u307E\u308C\u308Bval\u306E\u500B\u6570\n     */\n\
    \    int rank(int index, const T &val){\n      auto [l, r] = rank_aux(index, val);\n\
    \      return r - l;\n    }\n\n    /*\n     * @return data[l, r)\u306B\u542B\u307E\
    \u308C\u308Bval\u306E\u500B\u6570\n     */\n    int count(int l, int r, const\
    \ T &val){\n      assert(0 <= l and l <= r and r <= N_);\n      return rank(r,\
    \ val) - rank(l, val);\n    }\n\n    /**\n     * @return count(1-indexed)\u756A\
    \u76EE\u306Eval\u306E\u4F4D\u7F6E\n     */\n    std::optional<int> select(int\
    \ count, const T &val){\n      assert(1 <= count);\n\n      auto [l, r] = rank_aux(N_,\
    \ val);\n      if(r - l < count) return {};\n\n      int p = l + count - 1;\n\n\
    \      for(int i = B - 1; i >= 0; --i){\n        int t = (val >> (B - i - 1))\
    \ & 1;\n        p = *sdict_[i].select(p - t * zero_pos_[i] + 1, t);\n      }\n\
    \n      return {p};\n    }\n\n    /**\n     * @return data[l, r)\u3067k(1-index)\u756A\
    \u76EE\u306B\u5C0F\u3055\u3044\u5024\n     */\n    std::optional<T> quantile(int\
    \ l, int r, int k){\n      assert(0 <= l and l < r and r <= N_);\n      if(k ==\
    \ 0) return {};\n\n      T ret = 0;\n\n      for(int i = 0; i < B; ++i){\n   \
    \     const int count_1 = sdict_[i].rank(r, 1) - sdict_[i].rank(l, 1);\n     \
    \   const int count_0 = r - l - count_1;\n\n        int t = 0;\n\n        if(k\
    \ > count_0){\n          t = 1;\n          ret |= ((T)t << (B - i - 1));\n   \
    \       k -= count_0;\n        }\n\n        l = sdict_[i].rank(l, t) + t * zero_pos_[i];\n\
    \        r = sdict_[i].rank(r, t) + t * zero_pos_[i];\n      }\n\n      return\
    \ {ret};\n    }\n\n    T maximum(int l, int r){\n      assert(l < r);\n      return\
    \ *quantile(l, r, r - l);\n    }\n\n    T minimum(int l, int r){\n      assert(l\
    \ < r);\n      return *quantile(l, r, 1);\n    }\n\n    /**\n     * @return data[l,\
    \ r)\u306Elb\u4EE5\u4E0A\u3067\u6700\u5C0F\u306E\u5024\n     */\n    std::optional<T>\
    \ next_value(int l, int r, T lb){\n      int c = range_freq_lt(l, r, lb);\n  \
    \    return quantile(l, r, c + 1);\n    }\n\n    /**\n     * @return data[l, r)\u306E\
    ub\u672A\u6E80\u3067\u6700\u5927\u306E\u5024\n     */\n    std::optional<T> prev_value(int\
    \ l, int r, T ub){\n      int c = range_freq_lt(l, r, ub);\n      return quantile(l,\
    \ r, c);\n    }\n\n    int range_freq_lt(int l, int r, T ub){\n      int ret =\
    \ 0;\n\n      for(int i = 0; i < B; ++i){\n        int t = (ub >> (B - i - 1))\
    \ & 1;\n\n        if(t){\n          ret += sdict_[i].count(l, r, 0);\n       \
    \ }\n\n        l = sdict_[i].rank(l, t) + t * zero_pos_[i];\n        r = sdict_[i].rank(r,\
    \ t) + t * zero_pos_[i];\n      }\n\n      return ret;\n    }\n\n    /**\n   \
    \  * @return data[l, r)\u5185\u3067[lb, ub)\u3067\u3042\u308B\u3088\u3046\u306A\
    \u5024\u306E\u500B\u6570\n     */\n    int range_freq(int l, int r, T lb, T ub){\n\
    \      return range_freq_lt(l, r, ub) - range_freq_lt(l, r, lb);\n    }\n\n  \
    \  /**\n     * @return data[l, r)\u3067[lb, ub)\u3092\u6E80\u305F\u3059\u3082\u306E\
    \u3092\u51FA\u73FE\u983B\u5EA6\u3068\u5024\u306Epair\u3067\u8FD4\u3059\u3002\n\
    \     */\n    auto range_freq_list(int l, int r, T lb, T ub){\n      std::vector<std::pair<int,\
    \ T>> ret;\n      std::queue<std::tuple<int, int, int, T>> q;\n\n      q.emplace(l,\
    \ r, 0, 0);\n\n      while(not q.empty()){\n        auto [l, r, d, val] = q.front();\
    \ q.pop();\n\n        if(d == B){\n          if(lb <= val and val < ub){\n   \
    \         ret.emplace_back(r - l, val);\n          }\n          continue;\n  \
    \      }\n\n        const T mask = ~(T)0 ^ (((T)1 << (B - d)) - 1);\n        const\
    \ T b = (T)1 << (B - d - 1);\n\n        if(sdict_[d].count(l, r, 0) != 0){\n \
    \         if(val != (lb & mask) or not (lb & b)){\n            int L = sdict_[d].rank(l,\
    \ 0);\n            int R = sdict_[d].rank(r, 0);\n            q.emplace(L, R,\
    \ d + 1, val);\n          }\n        }\n\n        if(sdict_[d].count(l, r, 1)\
    \ != 0){\n          if(val != (ub & mask) or (ub & b)){\n            int L = sdict_[d].rank(l,\
    \ 1) + zero_pos_[d];\n            int R = sdict_[d].rank(r, 1) + zero_pos_[d];\n\
    \            q.emplace(L, R, d + 1, val | b);\n          }\n        }\n      }\n\
    \n      return ret;\n    }\n\n    /**\n     * @return data[l, r)\u3067\u51FA\u73FE\
    \u983B\u5EA6\u304C\u9AD8\u3044\u9806\u306Bk\u500B\u3092\u8FD4\u3059\n     */\n\
    \    auto top_k(int l, int r, int k) const {\n      std::priority_queue<std::tuple<int,\
    \ int, int, int, T>> q;\n      std::vector<std::pair<int, T>> ret;\n\n      q.emplace(r\
    \ - l, l, r, 0, 0);\n\n      while(not q.empty()){\n        auto [len, l, r, d,\
    \ val] = q.top(); q.pop();\n\n        if(d == B){\n          ret.emplace_back(len,\
    \ val);\n          if((int)ret.size() >= k) break;\n          continue;\n    \
    \    }\n\n        if(sdict_[d].count(l, r, 0) != 0){\n          int L = sdict_[d].rank(l,\
    \ 0);\n          int R = sdict_[d].rank(r, 0);\n          q.emplace(R - L, L,\
    \ R, d + 1, val);\n        }\n\n        if(sdict_[d].count(l, r, 1) != 0){\n \
    \         int L = sdict_[d].rank(l, 1) + zero_pos_[d];\n          int R = sdict_[d].rank(r,\
    \ 1) + zero_pos_[d];\n          q.emplace(R - L, L, R, d + 1, val | ((T)1 << (B\
    \ - d - 1)));\n        }\n      }\n\n      return ret;\n    }\n  };\n\n  wavelet_matrix<uint32_t,\
    \ 32> make_wavelet_matrix_int(const std::vector<uint32_t> &data){\n    return\
    \ wavelet_matrix<uint32_t, 32>(data);\n  }\n}\n#line 4 \"Mylib/IO/input_vector.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  std::vector<T> input_vector(int\
    \ N){\n    std::vector<T> ret(N);\n    for(int i = 0; i < N; ++i) std::cin >>\
    \ ret[i];\n    return ret;\n  }\n\n  template <typename T>\n  std::vector<std::vector<T>>\
    \ input_vector(int N, int M){\n    std::vector<std::vector<T>> ret(N);\n    for(int\
    \ i = 0; i < N; ++i) ret[i] = input_vector<T>(M);\n    return ret;\n  }\n}\n#line\
    \ 9 \"test/yukicoder/919/main.test.cpp\"\n\nnamespace hl = haar_lib;\n\nconst\
    \ int H = 1000000000;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int N; std::cin >> N;\n\n  auto A = hl::input_vector<int>(N);\n  for(auto\
    \ &x : A) x += H;\n\n  auto wm = hl::make_wavelet_matrix_int(std::vector<uint32_t>(A.begin(),\
    \ A.end()));\n\n  int64_t ans = LLONG_MIN;\n\n  for(int k = 1; k <= N; ++k){\n\
    \    std::vector<int64_t> left, right;\n    left.push_back(0);\n    right.push_back(0);\n\
    \n    for(int i = 0; i + k <= N; i += k){\n      left.push_back((int)*wm.quantile(i,\
    \ i + k, (k + 1) / 2) - H);\n    }\n\n    for(int i = N; i - k >= 0; i -= k){\n\
    \      right.push_back((int)*wm.quantile(i - k, i, (k + 1) / 2) - H);\n    }\n\
    \n\n    for(int i = 1; i < (int)left.size(); ++i) left[i] += left[i - 1];\n  \
    \  for(int i = 1; i < (int)right.size(); ++i) right[i] += right[i - 1];\n\n  \
    \  for(int i = 1; i < (int)right.size(); ++i) right[i] = std::max(right[i], right[i\
    \ - 1]);\n\n    for(int i = 0; i < (int)left.size(); ++i){\n      ans = std::max(ans,\
    \ (left[i] + right.back()) * k);\n\n      right.pop_back();\n    }\n  }\n\n  std::cout\
    \ << ans << \"\\n\";\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/919\"\n\n#include <iostream>\n\
    #include <vector>\n#include <algorithm>\n#include <climits>\n#include \"Mylib/DataStructure/WaveletMatrix/wavelet_matrix.cpp\"\
    \n#include \"Mylib/IO/input_vector.cpp\"\n\nnamespace hl = haar_lib;\n\nconst\
    \ int H = 1000000000;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int N; std::cin >> N;\n\n  auto A = hl::input_vector<int>(N);\n  for(auto\
    \ &x : A) x += H;\n\n  auto wm = hl::make_wavelet_matrix_int(std::vector<uint32_t>(A.begin(),\
    \ A.end()));\n\n  int64_t ans = LLONG_MIN;\n\n  for(int k = 1; k <= N; ++k){\n\
    \    std::vector<int64_t> left, right;\n    left.push_back(0);\n    right.push_back(0);\n\
    \n    for(int i = 0; i + k <= N; i += k){\n      left.push_back((int)*wm.quantile(i,\
    \ i + k, (k + 1) / 2) - H);\n    }\n\n    for(int i = N; i - k >= 0; i -= k){\n\
    \      right.push_back((int)*wm.quantile(i - k, i, (k + 1) / 2) - H);\n    }\n\
    \n\n    for(int i = 1; i < (int)left.size(); ++i) left[i] += left[i - 1];\n  \
    \  for(int i = 1; i < (int)right.size(); ++i) right[i] += right[i - 1];\n\n  \
    \  for(int i = 1; i < (int)right.size(); ++i) right[i] = std::max(right[i], right[i\
    \ - 1]);\n\n    for(int i = 0; i < (int)left.size(); ++i){\n      ans = std::max(ans,\
    \ (left[i] + right.back()) * k);\n\n      right.pop_back();\n    }\n  }\n\n  std::cout\
    \ << ans << \"\\n\";\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/DataStructure/WaveletMatrix/wavelet_matrix.cpp
  - Mylib/DataStructure/WaveletMatrix/succinct_dictionary.cpp
  - Mylib/IO/input_vector.cpp
  isVerificationFile: true
  path: test/yukicoder/919/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-28 09:27:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yukicoder/919/main.test.cpp
layout: document
redirect_from:
- /verify/test/yukicoder/919/main.test.cpp
- /verify/test/yukicoder/919/main.test.cpp.html
title: test/yukicoder/919/main.test.cpp
---
