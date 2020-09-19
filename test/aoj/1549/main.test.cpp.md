---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/DataStructure/WaveletMatrix/wavelet_matrix.cpp
    title: Wavelet matrix
  - icon: ':question:'
    path: Mylib/DataStructure/WaveletMatrix/succinct_dictionary.cpp
    title: Succinct dictionary
  - icon: ':question:'
    path: Mylib/IO/input_vector.cpp
    title: Mylib/IO/input_vector.cpp
  - icon: ':question:'
    path: Mylib/IO/input_tuples.cpp
    title: Mylib/IO/input_tuples.cpp
  - icon: ':question:'
    path: Mylib/IO/input_tuple.cpp
    title: Mylib/IO/input_tuple.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1549
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1549
  bundledCode: "#line 1 \"test/aoj/1549/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1549\"\
    \n\n#include <iostream>\n#include <vector>\n#include <climits>\n#include <algorithm>\n\
    #line 3 \"Mylib/DataStructure/WaveletMatrix/wavelet_matrix.cpp\"\n#include <utility>\n\
    #include <tuple>\n#include <cassert>\n#include <optional>\n#include <queue>\n\
    #line 5 \"Mylib/DataStructure/WaveletMatrix/succinct_dictionary.cpp\"\n\nnamespace\
    \ haar_lib {\n  struct succinct_dict {\n    int N;\n\n    static const int chunk_size\
    \ = 256;\n    static const int block_size = 64;\n    std::vector<uint64_t> data;\n\
    \n    std::vector<std::vector<uint8_t>> blocks;\n\n    std::vector<uint32_t> chunks;\n\
    \n    int chunk_num;\n    static const int block_num = chunk_size / block_size;\n\
    \n    succinct_dict(): N(0){}\n    succinct_dict(const std::vector<bool> &b):\
    \ N(b.size()){\n      chunk_num = (N + chunk_size - 1) / chunk_size;\n\n     \
    \ data.assign(chunk_num * block_num + 1, 0);\n\n      for(int i = 0; i < N; ++i){\n\
    \        if(b[i]){\n          int block_index = i / block_size;\n          int\
    \ index = i % block_size;\n          data[block_index] |= (1LL << index);\n  \
    \      }\n      }\n\n      chunks.assign(chunk_num + 1, 0);\n      blocks.assign(chunk_num\
    \ + 1, std::vector<uint8_t>(block_num, 0));\n\n      for(int i = 0; i < chunk_num;\
    \ ++i){\n        for(int j = 0; j < block_num - 1; ++j){\n          blocks[i][j\
    \ + 1] = blocks[i][j] + __builtin_popcountll(data[i * block_num + j]);\n     \
    \   }\n\n        chunks[i + 1] = chunks[i] + blocks[i][block_num - 1] + __builtin_popcountll(data[(i\
    \ + 1) * block_num - 1]);\n      }\n    }\n\n    /**\n     * @return [0, index)\u306E\
    b\u306E\u500B\u6570\n     */\n    int rank(int index, int b) const {\n      if(b\
    \ == 0){\n        return index - rank(index, 1);\n      }else{\n        if(index\
    \ > N) index = N;\n\n        const int chunk_pos = index / chunk_size;\n     \
    \   const int block_pos = (index % chunk_size) / block_size;\n\n        const\
    \ uint64_t mask =\n          data[chunk_pos * block_num + block_pos] & ((1LL <<\
    \ (index % block_size)) - 1);\n\n        const int ret = chunks[chunk_pos] +\n\
    \          blocks[chunk_pos][block_pos] +\n          __builtin_popcountll(mask);\n\
    \n        return ret;\n      }\n    }\n\n    /**\n     * @return [l, r)\u306E\
    b\u306E\u500B\u6570\n     */\n    int count(int l, int r, int b) const {\n   \
    \   return rank(r, b) - rank(l, b);\n    }\n\n    /**\n     * @return b[index]\n\
    \     */\n    int access(int index) const {\n      return (data[index / block_size]\
    \ >> (index % block_size)) & 1;\n    }\n\n    /**\n     * @note n in [1, N]\n\
    \     * @return \u5148\u982D\u304B\u3089n\u756A\u76EE\u306Eb\u306E\u4F4D\u7F6E\
    \n     */\n    std::optional<int> select(int n, int b) const {\n      assert(n\
    \ >= 1);\n\n      if(rank(N, b) < n) return {};\n\n      int lb = -1, ub = N;\n\
    \      while(std::abs(lb - ub) > 1){\n        int mid = (lb + ub) / 2;\n\n   \
    \     if(rank(mid, b) >= n){\n          ub = mid;\n        }else{\n          lb\
    \ = mid;\n        }\n      }\n\n      return {lb};\n    }\n  };\n}\n#line 9 \"\
    Mylib/DataStructure/WaveletMatrix/wavelet_matrix.cpp\"\n\nnamespace haar_lib {\n\
    \  template <typename T, int B>\n  class wavelet_matrix {\n  public:\n    const\
    \ int N;\n\n    succinct_dict sdict[B];\n    int zero_pos[B];\n\n    wavelet_matrix(std::vector<T>\
    \ data): N(data.size()){\n      std::vector<bool> s(N);\n\n      for(int k = 0;\
    \ k < B; ++k){\n        std::vector<T> left, right;\n\n        for(int i = 0;\
    \ i < N; ++i){\n          s[i] = (data[i] >> (B - 1 - k)) & 1;\n          if(s[i]){\n\
    \            right.push_back(data[i]);\n          }else{\n            left.push_back(data[i]);\n\
    \          }\n        }\n\n        sdict[k] = succinct_dict(s);\n        zero_pos[k]\
    \ = left.size();\n\n        std::swap(data, left);\n        data.insert(data.end(),\
    \ right.begin(), right.end());\n      }\n    }\n\n    /**\n     * @return data[index]\n\
    \     */\n    T access(int index){\n      assert(0 <= index and index < N);\n\
    \      T ret = 0;\n\n      int p = index;\n      for(int i = 0; i < B; ++i){\n\
    \        int t = sdict[i].access(p);\n        ret |= ((T)t << (B - 1 - i));\n\
    \        p = sdict[i].rank(p, t) + t * zero_pos[i];\n      }\n\n      return ret;\n\
    \    }\n\n    std::pair<int, int> rank_aux(int index, const T &val){\n      int\
    \ l = 0, r = index;\n\n      for(int i = 0; i < B; ++i){\n        int t = (val\
    \ >> (B - i - 1)) & 1;\n        l = sdict[i].rank(l, t) + t * zero_pos[i];\n \
    \       r = sdict[i].rank(r, t) + t * zero_pos[i];\n      }\n\n      return std::make_pair(l,\
    \ r);\n    }\n\n    /**\n     * @return data[0, index)\u306B\u542B\u307E\u308C\
    \u308Bval\u306E\u500B\u6570\n     */\n    int rank(int index, const T &val){\n\
    \      auto [l, r] = rank_aux(index, val);\n      return r - l;\n    }\n\n   \
    \ /*\n     * @return data[l, r)\u306B\u542B\u307E\u308C\u308Bval\u306E\u500B\u6570\
    \n     */\n    int count(int l, int r, const T &val){\n      assert(0 <= l and\
    \ l <= r and r <= N);\n      return rank(r, val) - rank(l, val);\n    }\n\n  \
    \  /**\n     * @return count(1-indexed)\u756A\u76EE\u306Eval\u306E\u4F4D\u7F6E\
    \n     */\n    std::optional<int> select(int count, const T &val){\n      assert(1\
    \ <= count);\n\n      auto [l, r] = rank_aux(N, val);\n      if(r - l < count)\
    \ return {};\n\n      int p = l + count - 1;\n\n      for(int i = B - 1; i >=\
    \ 0; --i){\n        int t = (val >> (B - i - 1)) & 1;\n        p = *sdict[i].select(p\
    \ - t * zero_pos[i] + 1, t);\n      }\n\n      return {p};\n    }\n\n    /**\n\
    \     * @return data[l, r)\u3067k(1-index)\u756A\u76EE\u306B\u5C0F\u3055\u3044\
    \u5024\n     */\n    std::optional<T> quantile(int l, int r, int k){\n      assert(0\
    \ <= l and l < r and r <= N);\n      if(k == 0) return {};\n\n      T ret = 0;\n\
    \n      for(int i = 0; i < B; ++i){\n        const int count_1 = sdict[i].rank(r,\
    \ 1) - sdict[i].rank(l, 1);\n        const int count_0 = r - l - count_1;\n\n\
    \        int t = 0;\n\n        if(k > count_0){\n          t = 1;\n          ret\
    \ |= ((T)t << (B - i - 1));\n          k -= count_0;\n        }\n\n        l =\
    \ sdict[i].rank(l, t) + t * zero_pos[i];\n        r = sdict[i].rank(r, t) + t\
    \ * zero_pos[i];\n      }\n\n      return {ret};\n    }\n\n    T maximum(int l,\
    \ int r){\n      assert(l < r);\n      return *quantile(l, r, r - l);\n    }\n\
    \n    T minimum(int l, int r){\n      assert(l < r);\n      return *quantile(l,\
    \ r, 1);\n    }\n\n    /**\n     * @return data[l, r)\u306Elb\u4EE5\u4E0A\u3067\
    \u6700\u5C0F\u306E\u5024\n     */\n    std::optional<T> next_value(int l, int\
    \ r, T lb){\n      int c = range_freq_lt(l, r, lb);\n      return quantile(l,\
    \ r, c + 1);\n    }\n\n    /**\n     * @return data[l, r)\u306Eub\u672A\u6E80\u3067\
    \u6700\u5927\u306E\u5024\n     */\n    std::optional<T> prev_value(int l, int\
    \ r, T ub){\n      int c = range_freq_lt(l, r, ub);\n      return quantile(l,\
    \ r, c);\n    }\n\n    int range_freq_lt(int l, int r, T ub){\n      int ret =\
    \ 0;\n\n      for(int i = 0; i < B; ++i){\n        int t = (ub >> (B - i - 1))\
    \ & 1;\n\n        if(t){\n          ret += sdict[i].count(l, r, 0);\n        }\n\
    \n        l = sdict[i].rank(l, t) + t * zero_pos[i];\n        r = sdict[i].rank(r,\
    \ t) + t * zero_pos[i];\n      }\n\n      return ret;\n    }\n\n    /**\n    \
    \ * @return data[l, r)\u5185\u3067[lb, ub)\u3067\u3042\u308B\u3088\u3046\u306A\
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
    \ T b = (T)1 << (B - d - 1);\n\n        if(sdict[d].count(l, r, 0) != 0){\n  \
    \        if(val != (lb & mask) or not (lb & b)){\n            int L = sdict[d].rank(l,\
    \ 0);\n            int R = sdict[d].rank(r, 0);\n            q.emplace(L, R, d\
    \ + 1, val);\n          }\n        }\n\n        if(sdict[d].count(l, r, 1) !=\
    \ 0){\n          if(val != (ub & mask) or (ub & b)){\n            int L = sdict[d].rank(l,\
    \ 1) + zero_pos[d];\n            int R = sdict[d].rank(r, 1) + zero_pos[d];\n\
    \            q.emplace(L, R, d + 1, val | b);\n          }\n        }\n      }\n\
    \n      return ret;\n    }\n\n    /**\n     * @return data[l, r)\u3067\u51FA\u73FE\
    \u983B\u5EA6\u304C\u9AD8\u3044\u9806\u306Bk\u500B\u3092\u8FD4\u3059\n     */\n\
    \    auto top_k(int l, int r, int k) const {\n      std::priority_queue<std::tuple<int,\
    \ int, int, int, T>> q;\n      std::vector<std::pair<int, T>> ret;\n\n      q.emplace(r\
    \ - l, l, r, 0, 0);\n\n      while(not q.empty()){\n        auto [len, l, r, d,\
    \ val] = q.top(); q.pop();\n\n        if(d == B){\n          ret.emplace_back(len,\
    \ val);\n          if((int)ret.size() >= k) break;\n          continue;\n    \
    \    }\n\n        if(sdict[d].count(l, r, 0) != 0){\n          int L = sdict[d].rank(l,\
    \ 0);\n          int R = sdict[d].rank(r, 0);\n          q.emplace(R - L, L, R,\
    \ d + 1, val);\n        }\n\n        if(sdict[d].count(l, r, 1) != 0){\n     \
    \     int L = sdict[d].rank(l, 1) + zero_pos[d];\n          int R = sdict[d].rank(r,\
    \ 1) + zero_pos[d];\n          q.emplace(R - L, L, R, d + 1, val | ((T)1 << (B\
    \ - d - 1)));\n        }\n      }\n\n      return ret;\n    }\n  };\n\n  wavelet_matrix<uint32_t,\
    \ 32> make_wavelet_matrix_int(const std::vector<uint32_t> &data){\n    return\
    \ wavelet_matrix<uint32_t, 32>(data);\n  }\n}\n#line 4 \"Mylib/IO/input_vector.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  std::vector<T> input_vector(int\
    \ N){\n    std::vector<T> ret(N);\n    for(int i = 0; i < N; ++i) std::cin >>\
    \ ret[i];\n    return ret;\n  }\n\n  template <typename T>\n  std::vector<std::vector<T>>\
    \ input_vector(int N, int M){\n    std::vector<std::vector<T>> ret(N);\n    for(int\
    \ i = 0; i < N; ++i) ret[i] = input_vector<T>(M);\n    return ret;\n  }\n}\n#line\
    \ 6 \"Mylib/IO/input_tuples.cpp\"\n#include <initializer_list>\n#line 6 \"Mylib/IO/input_tuple.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T, size_t ... I>\n  static void\
    \ input_tuple_helper(std::istream &s, T &val, std::index_sequence<I ...>){\n \
    \   (void)std::initializer_list<int>{(void(s >> std::get<I>(val)), 0) ...};\n\
    \  }\n\n  template <typename T, typename U>\n  std::istream& operator>>(std::istream\
    \ &s, std::pair<T, U> &value){\n    s >> value.first >> value.second;\n    return\
    \ s;\n  }\n\n  template <typename ... Args>\n  std::istream& operator>>(std::istream\
    \ &s, std::tuple<Args ...> &value){\n    input_tuple_helper(s, value, std::make_index_sequence<sizeof\
    \ ... (Args)>());\n    return s;\n  }\n}\n#line 8 \"Mylib/IO/input_tuples.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename ... Args>\n  class InputTuples\
    \ {\n    struct iter {\n      using value_type = std::tuple<Args ...>;\n     \
    \ value_type value;\n      bool fetched = false;\n      int N, c = 0;\n\n    \
    \  value_type operator*(){\n        if(not fetched){\n          std::cin >> value;\n\
    \        }\n        return value;\n      }\n\n      void operator++(){\n     \
    \   ++c;\n        fetched = false;\n      }\n\n      bool operator!=(iter &) const\
    \ {\n        return c < N;\n      }\n\n      iter(int N): N(N){}\n    };\n\n \
    \   int N;\n\n  public:\n    InputTuples(int N): N(N){}\n\n    iter begin() const\
    \ {return iter(N);}\n    iter end() const {return iter(N);}\n  };\n\n  template\
    \ <typename ... Args>\n  auto input_tuples(int N){\n    return InputTuples<Args\
    \ ...>(N);\n  }\n}\n#line 10 \"test/aoj/1549/main.test.cpp\"\n\nnamespace hl =\
    \ haar_lib;\n\nint main(){\n  int N; std::cin >> N;\n\n  auto a = hl::input_vector<uint32_t>(N);\n\
    \n  auto wm = hl::make_wavelet_matrix_int(a);\n\n  int Q; std::cin >> Q;\n\n \
    \ for(auto [l, r, d] : hl::input_tuples<uint32_t, uint32_t, uint32_t>(Q)){\n \
    \   ++r;\n\n    int ans = INT_MAX;\n\n    {\n      auto x = wm.prev_value(l, r,\
    \ d);\n      if(x) ans = std::min(ans, std::abs((int)*x - (int)d));\n    }\n\n\
    \    {\n      auto x = wm.next_value(l, r, d);\n      if(x) ans = std::min(ans,\
    \ std::abs((int)*x - (int)d));\n    }\n\n    std::cout << ans << std::endl;\n\
    \  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1549\"\
    \n\n#include <iostream>\n#include <vector>\n#include <climits>\n#include <algorithm>\n\
    #include \"Mylib/DataStructure/WaveletMatrix/wavelet_matrix.cpp\"\n#include \"\
    Mylib/IO/input_vector.cpp\"\n#include \"Mylib/IO/input_tuples.cpp\"\n\nnamespace\
    \ hl = haar_lib;\n\nint main(){\n  int N; std::cin >> N;\n\n  auto a = hl::input_vector<uint32_t>(N);\n\
    \n  auto wm = hl::make_wavelet_matrix_int(a);\n\n  int Q; std::cin >> Q;\n\n \
    \ for(auto [l, r, d] : hl::input_tuples<uint32_t, uint32_t, uint32_t>(Q)){\n \
    \   ++r;\n\n    int ans = INT_MAX;\n\n    {\n      auto x = wm.prev_value(l, r,\
    \ d);\n      if(x) ans = std::min(ans, std::abs((int)*x - (int)d));\n    }\n\n\
    \    {\n      auto x = wm.next_value(l, r, d);\n      if(x) ans = std::min(ans,\
    \ std::abs((int)*x - (int)d));\n    }\n\n    std::cout << ans << std::endl;\n\
    \  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/DataStructure/WaveletMatrix/wavelet_matrix.cpp
  - Mylib/DataStructure/WaveletMatrix/succinct_dictionary.cpp
  - Mylib/IO/input_vector.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  isVerificationFile: true
  path: test/aoj/1549/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/1549/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/1549/main.test.cpp
- /verify/test/aoj/1549/main.test.cpp.html
title: test/aoj/1549/main.test.cpp
---
