---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Mylib/DataStructure/SegmentTree/segment_tree_beats.cpp
    title: Segment tree beats
  - icon: ':question:'
    path: Mylib/IO/input_tuple.cpp
    title: Input tuple
  - icon: ':question:'
    path: Mylib/IO/input_tuples.cpp
    title: Input tuples
  - icon: ':question:'
    path: Mylib/IO/input_vector.cpp
    title: Input vector
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
  bundledCode: "#line 1 \"test/yosupo-judge/range_chmin_chmax_add_range_sum/main.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \n\n#include <iostream>\n#include <vector>\n#line 3 \"Mylib/DataStructure/SegmentTree/segment_tree_beats.cpp\"\
    \n#include <limits>\n#include <algorithm>\n\nnamespace haar_lib {\n  class segment_tree_beats\
    \ {\n  public:\n    using value_type = int64_t;\n\n  private:\n    int depth_,\
    \ size_, hsize_;\n\n    std::vector<value_type> fst_max_, snd_max_;\n    std::vector<int>\
    \ max_count_;\n\n    std::vector<value_type> fst_min_, snd_min_;\n    std::vector<int>\
    \ min_count_;\n\n    std::vector<value_type> sum_, lazy_add_;\n\n  public:\n \
    \   segment_tree_beats(){}\n    segment_tree_beats(int n):\n      depth_(n > 1\
    \ ? 32 - __builtin_clz(n - 1) + 1 : 1),\n      size_(1 << depth_),\n      hsize_(size_\
    \ / 2),\n\n      fst_max_(size_, std::numeric_limits<value_type>::min()),\n  \
    \    snd_max_(size_, std::numeric_limits<value_type>::min()),\n      max_count_(size_,\
    \ 0),\n\n      fst_min_(size_, std::numeric_limits<value_type>::max()),\n    \
    \  snd_min_(size_, std::numeric_limits<value_type>::max()),\n      min_count_(size_,\
    \ 0),\n\n      sum_(size_, 0),\n      lazy_add_(size_, 0)\n    {}\n\n  private:\n\
    \    int lc(int i) const {return i << 1 | 0;} // left child\n    int rc(int i)\
    \ const {return i << 1 | 1;} // right child\n\n    void update_node_max(int i,\
    \ value_type x){\n      sum_[i] += (x - fst_max_[i]) * max_count_[i];\n\n    \
    \  if(fst_max_[i] == fst_min_[i]) fst_max_[i] = fst_min_[i] = x;\n      else if(fst_max_[i]\
    \ == snd_min_[i]) fst_max_[i] = snd_min_[i] = x;\n      else fst_max_[i] = x;\n\
    \    }\n\n    void update_node_min(int i, value_type x){\n      sum_[i] += (x\
    \ - fst_min_[i]) * min_count_[i];\n\n      if(fst_max_[i] == fst_min_[i]) fst_max_[i]\
    \ = fst_min_[i] = x;\n      else if(snd_max_[i] == fst_min_[i]) snd_max_[i] =\
    \ fst_min_[i] = x;\n      else fst_min_[i] = x;\n    }\n\n    void update_node_add(int\
    \ i, value_type x){\n      const int len = hsize_ >> (31 - __builtin_clz(i));\n\
    \n      sum_[i] += x * len;\n      fst_max_[i] += x;\n      if(snd_max_[i] !=\
    \ std::numeric_limits<value_type>::min()) snd_max_[i] += x;\n      fst_min_[i]\
    \ += x;\n      if(snd_min_[i] != std::numeric_limits<value_type>::max()) snd_min_[i]\
    \ += x;\n\n      lazy_add_[i] += x;\n    }\n\n    void propagate(int i){\n   \
    \   if(i >= hsize_) return;\n\n      if(lazy_add_[i] != 0){\n        update_node_add(lc(i),\
    \ lazy_add_[i]);\n        update_node_add(rc(i), lazy_add_[i]);\n        lazy_add_[i]\
    \ = 0;\n      }\n\n      if(fst_max_[i] < fst_max_[lc(i)]) update_node_max(lc(i),\
    \ fst_max_[i]);\n      if(fst_min_[i] > fst_min_[lc(i)]) update_node_min(lc(i),\
    \ fst_min_[i]);\n\n      if(fst_max_[i] < fst_max_[rc(i)]) update_node_max(rc(i),\
    \ fst_max_[i]);\n      if(fst_min_[i] > fst_min_[rc(i)]) update_node_min(rc(i),\
    \ fst_min_[i]);\n    }\n\n    void bottom_up(int i){\n      const int L = lc(i);\n\
    \      const int R = rc(i);\n\n      sum_[i] = sum_[L] + sum_[R];\n\n      fst_max_[i]\
    \ = std::max(fst_max_[L], fst_max_[R]);\n\n      if(fst_max_[L] < fst_max_[R]){\n\
    \        max_count_[i] = max_count_[R];\n        snd_max_[i] = std::max(fst_max_[L],\
    \ snd_max_[R]);\n      }else if(fst_max_[L] > fst_max_[R]){\n        max_count_[i]\
    \ = max_count_[L];\n        snd_max_[i] = std::max(snd_max_[L], fst_max_[R]);\n\
    \      }else{\n        max_count_[i] = max_count_[L] + max_count_[R];\n      \
    \  snd_max_[i] = std::max(snd_max_[L], snd_max_[R]);\n      }\n\n      fst_min_[i]\
    \ = std::min(fst_min_[L], fst_min_[R]);\n\n      if(fst_min_[L] > fst_min_[R]){\n\
    \        min_count_[i] = min_count_[R];\n        snd_min_[i] = std::min(fst_min_[L],\
    \ snd_min_[R]);\n      }else if(fst_min_[L] < fst_min_[R]){\n        min_count_[i]\
    \ = min_count_[L];\n        snd_min_[i] = std::min(snd_min_[L], fst_min_[R]);\n\
    \      }else{\n        min_count_[i] = min_count_[L] + min_count_[R];\n      \
    \  snd_min_[i] = std::min(snd_min_[L], snd_min_[R]);\n      }\n    }\n\n  private:\n\
    \    void chmin(int i, int l, int r, int s, int t, value_type x){\n      if(r\
    \ <= s or t <= l or fst_max_[i] <= x) return;\n      if(s <= l and r <= t and\
    \ snd_max_[i] < x){\n        update_node_max(i, x);\n        return;\n      }\n\
    \n      propagate(i);\n      chmin(lc(i), l, (l + r) / 2, s, t, x);\n      chmin(rc(i),\
    \ (l + r) / 2, r, s, t, x);\n      bottom_up(i);\n    }\n\n  public:\n    void\
    \ chmin(int l, int r, value_type x){chmin(1, 0, hsize_, l, r, x);}\n\n  private:\n\
    \    void chmax(int i, int l, int r, int s, int t, value_type x){\n      if(r\
    \ <= s or t <= l or fst_min_[i] >= x) return;\n      if(s <= l and r <= t and\
    \ snd_min_[i] > x){\n        update_node_min(i, x);\n        return;\n      }\n\
    \n      propagate(i);\n      chmax(lc(i), l, (l + r) / 2, s, t, x);\n      chmax(rc(i),\
    \ (l + r) / 2, r, s, t, x);\n      bottom_up(i);\n    }\n\n  public:\n    void\
    \ chmax(int l, int r, value_type x){chmax(1, 0, hsize_, l, r, x);}\n\n  private:\n\
    \    void add(int i, int l, int r, int s, int t, value_type x){\n      if(r <=\
    \ s or t <= l) return;\n      if(s <= l and r <= t){\n        update_node_add(i,\
    \ x);\n        return;\n      }\n\n      propagate(i);\n      add(lc(i), l, (l\
    \ + r) / 2, s, t, x);\n      add(rc(i), (l + r) / 2, r, s, t, x);\n      bottom_up(i);\n\
    \    }\n\n  public:\n    void add(int l, int r, value_type x){add(1, 0, hsize_,\
    \ l, r, x);}\n\n  private:\n    value_type get_sum(int i, int l, int r, int s,\
    \ int t){\n      if(r <= s or t <= l) return 0;\n      if(s <= l and r <= t) return\
    \ sum_[i];\n\n      propagate(i);\n      return get_sum(lc(i), l, (l + r) / 2,\
    \ s, t) + get_sum(rc(i), (l + r) / 2, r, s, t);\n    }\n\n  public:\n    value_type\
    \ get_sum(int l, int r){return get_sum(1, 0, hsize_, l, r);}\n\n  public:\n  \
    \  void init_with_vector(const std::vector<value_type> &v){\n      fst_max_.assign(size_,\
    \ std::numeric_limits<value_type>::min());\n      snd_max_.assign(size_, std::numeric_limits<value_type>::min());\n\
    \      max_count_.assign(size_, 1);\n\n      fst_min_.assign(size_, std::numeric_limits<value_type>::max());\n\
    \      snd_min_.assign(size_, std::numeric_limits<value_type>::max());\n     \
    \ min_count_.assign(size_, 1);\n\n      sum_.assign(size_, 0);\n      lazy_add_.assign(size_,\
    \ 0);\n\n      for(int i = 0; i < (int)v.size(); ++i){\n        fst_max_[hsize_\
    \ + i] = v[i];\n        max_count_[hsize_ + i] = 1;\n        fst_min_[hsize_ +\
    \ i] = v[i];\n        min_count_[hsize_ + i] = 1;\n        sum_[hsize_ + i] =\
    \ v[i];\n      }\n\n      for(int i = hsize_; --i >= 1;) bottom_up(i);\n    }\n\
    \  };\n}\n#line 4 \"Mylib/IO/input_vector.cpp\"\n\nnamespace haar_lib {\n  template\
    \ <typename T>\n  std::vector<T> input_vector(int N){\n    std::vector<T> ret(N);\n\
    \    for(int i = 0; i < N; ++i) std::cin >> ret[i];\n    return ret;\n  }\n\n\
    \  template <typename T>\n  std::vector<std::vector<T>> input_vector(int N, int\
    \ M){\n    std::vector<std::vector<T>> ret(N);\n    for(int i = 0; i < N; ++i)\
    \ ret[i] = input_vector<T>(M);\n    return ret;\n  }\n}\n#line 4 \"Mylib/IO/input_tuples.cpp\"\
    \n#include <tuple>\n#include <utility>\n#include <initializer_list>\n#line 6 \"\
    Mylib/IO/input_tuple.cpp\"\n\nnamespace haar_lib {\n  template <typename T, size_t\
    \ ... I>\n  static void input_tuple_helper(std::istream &s, T &val, std::index_sequence<I\
    \ ...>){\n    (void)std::initializer_list<int>{(void(s >> std::get<I>(val)), 0)\
    \ ...};\n  }\n\n  template <typename T, typename U>\n  std::istream& operator>>(std::istream\
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
    \ ...>(N);\n  }\n}\n#line 8 \"test/yosupo-judge/range_chmin_chmax_add_range_sum/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int N, Q; std::cin >> N >> Q;\n\n  hl::segment_tree_beats seg(N);\n\n  auto\
    \ a = hl::input_vector<int64_t>(N);\n  seg.init_with_vector(a);\n\n  for(auto\
    \ [type, l, r] : hl::input_tuples<int, int, int>(Q)){\n    switch(type){\n   \
    \ case 0: {\n      int64_t b; std::cin >> b;\n      seg.chmin(l, r, b);\n    \
    \  break;\n    }\n    case 1: {\n      int64_t b; std::cin >> b;\n      seg.chmax(l,\
    \ r, b);\n      break;\n    }\n    case 2: {\n      int64_t b; std::cin >> b;\n\
    \      seg.add(l, r, b);\n      break;\n    }\n    case 3: {\n      auto ans =\
    \ seg.get_sum(l, r);\n      std::cout << ans << \"\\n\";\n      break;\n    }\n\
    \    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \n\n#include <iostream>\n#include <vector>\n#include \"Mylib/DataStructure/SegmentTree/segment_tree_beats.cpp\"\
    \n#include \"Mylib/IO/input_vector.cpp\"\n#include \"Mylib/IO/input_tuples.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int N, Q; std::cin >> N >> Q;\n\n  hl::segment_tree_beats seg(N);\n\n  auto\
    \ a = hl::input_vector<int64_t>(N);\n  seg.init_with_vector(a);\n\n  for(auto\
    \ [type, l, r] : hl::input_tuples<int, int, int>(Q)){\n    switch(type){\n   \
    \ case 0: {\n      int64_t b; std::cin >> b;\n      seg.chmin(l, r, b);\n    \
    \  break;\n    }\n    case 1: {\n      int64_t b; std::cin >> b;\n      seg.chmax(l,\
    \ r, b);\n      break;\n    }\n    case 2: {\n      int64_t b; std::cin >> b;\n\
    \      seg.add(l, r, b);\n      break;\n    }\n    case 3: {\n      auto ans =\
    \ seg.get_sum(l, r);\n      std::cout << ans << \"\\n\";\n      break;\n    }\n\
    \    }\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/DataStructure/SegmentTree/segment_tree_beats.cpp
  - Mylib/IO/input_vector.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  isVerificationFile: true
  path: test/yosupo-judge/range_chmin_chmax_add_range_sum/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-28 09:27:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo-judge/range_chmin_chmax_add_range_sum/main.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-judge/range_chmin_chmax_add_range_sum/main.test.cpp
- /verify/test/yosupo-judge/range_chmin_chmax_add_range_sum/main.test.cpp.html
title: test/yosupo-judge/range_chmin_chmax_add_range_sum/main.test.cpp
---
