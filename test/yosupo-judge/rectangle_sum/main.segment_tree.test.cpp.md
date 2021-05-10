---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/AlgebraicStructure/Monoid/sum.cpp
    title: Sum monoid
  - icon: ':question:'
    path: Mylib/DataStructure/SegmentTree/segment_tree.cpp
    title: Segment tree
  - icon: ':x:'
    path: Mylib/DataStructure/SegmentTree/segment_tree_on_segment_tree.cpp
    title: Segment tree (On segment tree)
  - icon: ':question:'
    path: Mylib/IO/input_tuple.cpp
    title: Input tuple
  - icon: ':question:'
    path: Mylib/IO/input_tuple_vector.cpp
    title: Input tuple vector
  - icon: ':question:'
    path: Mylib/IO/input_tuples.cpp
    title: Input tuples
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/rectangle_sum
  bundledCode: "#line 1 \"test/yosupo-judge/rectangle_sum/main.segment_tree.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\n\n#include\
    \ <iostream>\n#include <vector>\n#line 2 \"Mylib/AlgebraicStructure/Monoid/sum.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  struct sum_monoid {\n   \
    \ using value_type = T;\n    value_type operator()() const { return 0; }\n   \
    \ value_type operator()(value_type a, value_type b) const { return a + b; }\n\
    \  };\n}  // namespace haar_lib\n#line 2 \"Mylib/DataStructure/SegmentTree/segment_tree.cpp\"\
    \n#include <algorithm>\n#include <cassert>\n#include <functional>\n#line 6 \"\
    Mylib/DataStructure/SegmentTree/segment_tree.cpp\"\n\nnamespace haar_lib {\n \
    \ template <typename Monoid>\n  class segment_tree {\n  public:\n    using value_type\
    \ = typename Monoid::value_type;\n\n  private:\n    Monoid M_;\n    int depth_,\
    \ size_, hsize_;\n    std::vector<value_type> data_;\n\n  public:\n    segment_tree()\
    \ {}\n    segment_tree(int n) : depth_(n > 1 ? 32 - __builtin_clz(n - 1) + 1 :\
    \ 1),\n                          size_(1 << depth_),\n                       \
    \   hsize_(size_ / 2),\n                          data_(size_, M_()) {}\n\n  \
    \  auto operator[](int i) const {\n      assert(0 <= i and i < hsize_);\n    \
    \  return data_[hsize_ + i];\n    }\n\n    auto fold(int l, int r) const {\n \
    \     assert(0 <= l and l <= r and r <= hsize_);\n      value_type ret_left  =\
    \ M_();\n      value_type ret_right = M_();\n\n      int L = l + hsize_, R = r\
    \ + hsize_;\n      while (L < R) {\n        if (R & 1) ret_right = M_(data_[--R],\
    \ ret_right);\n        if (L & 1) ret_left = M_(ret_left, data_[L++]);\n     \
    \   L >>= 1, R >>= 1;\n      }\n\n      return M_(ret_left, ret_right);\n    }\n\
    \n    auto fold_all() const {\n      return data_[1];\n    }\n\n    void set(int\
    \ i, const value_type &x) {\n      assert(0 <= i and i < hsize_);\n      i +=\
    \ hsize_;\n      data_[i] = x;\n      while (i > 1) i >>= 1, data_[i] = M_(data_[i\
    \ << 1 | 0], data_[i << 1 | 1]);\n    }\n\n    void update(int i, const value_type\
    \ &x) {\n      assert(0 <= i and i < hsize_);\n      i += hsize_;\n      data_[i]\
    \ = M_(data_[i], x);\n      while (i > 1) i >>= 1, data_[i] = M_(data_[i << 1\
    \ | 0], data_[i << 1 | 1]);\n    }\n\n    template <typename T>\n    void init_with_vector(const\
    \ std::vector<T> &val) {\n      data_.assign(size_, M_());\n      for (int i =\
    \ 0; i < (int) val.size(); ++i) data_[hsize_ + i] = val[i];\n      for (int i\
    \ = hsize_; --i >= 1;) data_[i] = M_(data_[i << 1 | 0], data_[i << 1 | 1]);\n\
    \    }\n\n    template <typename T>\n    void init(const T &val) {\n      init_with_vector(std::vector<value_type>(hsize_,\
    \ val));\n    }\n\n  private:\n    template <bool Lower, typename F>\n    int\
    \ bound(const int l, const int r, value_type x, F f) const {\n      std::vector<int>\
    \ pl, pr;\n      int L = l + hsize_;\n      int R = r + hsize_;\n      while (L\
    \ < R) {\n        if (R & 1) pr.push_back(--R);\n        if (L & 1) pl.push_back(L++);\n\
    \        L >>= 1, R >>= 1;\n      }\n\n      std::reverse(pr.begin(), pr.end());\n\
    \      pl.insert(pl.end(), pr.begin(), pr.end());\n\n      value_type a = M_();\n\
    \n      for (int i : pl) {\n        auto b = M_(a, data_[i]);\n\n        if ((Lower\
    \ and not f(b, x)) or (not Lower and f(x, b))) {\n          while (i < hsize_)\
    \ {\n            const auto c = M_(a, data_[i << 1 | 0]);\n            if ((Lower\
    \ and not f(c, x)) or (not Lower and f(x, c))) {\n              i = i << 1 | 0;\n\
    \            } else {\n              a = c;\n              i = i << 1 | 1;\n \
    \           }\n          }\n\n          return i - hsize_;\n        }\n\n    \
    \    a = b;\n      }\n\n      return r;\n    }\n\n  public:\n    template <typename\
    \ F = std::less<value_type>>\n    int lower_bound(int l, int r, value_type x,\
    \ F f = F()) const {\n      return bound<true>(l, r, x, f);\n    }\n\n    template\
    \ <typename F = std::less<value_type>>\n    int upper_bound(int l, int r, value_type\
    \ x, F f = F()) const {\n      return bound<false>(l, r, x, f);\n    }\n  };\n\
    }  // namespace haar_lib\n#line 5 \"Mylib/DataStructure/SegmentTree/segment_tree_on_segment_tree.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename Monoid>\n  class segment_tree_on_segment_tree\
    \ {\n  public:\n    using value_type = typename Monoid::value_type;\n\n  private:\n\
    \    Monoid M_;\n    int N_ = 0;\n    std::vector<int64_t> xs_, ys_;\n    std::vector<int>\
    \ c_xs_;\n    std::vector<std::vector<int>> c_ys_;\n    int x_size_;\n    std::vector<segment_tree<Monoid>>\
    \ segs_;\n\n  public:\n    segment_tree_on_segment_tree() {}\n\n    void add(int64_t\
    \ x, int64_t y) {\n      xs_.push_back(x);\n      ys_.push_back(y);\n      ++N_;\n\
    \    }\n\n    void build() {\n      c_xs_.insert(c_xs_.end(), xs_.begin(), xs_.end());\n\
    \n      std::sort(c_xs_.begin(), c_xs_.end());\n      c_xs_.erase(std::unique(c_xs_.begin(),\
    \ c_xs_.end()), c_xs_.end());\n\n      x_size_ = 1;\n      while (x_size_ < (int)\
    \ c_xs_.size()) x_size_ *= 2;\n      x_size_ *= 2;\n\n      c_ys_.resize(x_size_);\n\
    \      segs_.resize(x_size_);\n\n      for (int i = 0; i < N_; ++i) {\n      \
    \  int j = std::lower_bound(c_xs_.begin(), c_xs_.end(), xs_[i]) - c_xs_.begin();\n\
    \        c_ys_[j + x_size_ / 2].push_back(ys_[i]);\n      }\n\n      for (int\
    \ i = 0; i < x_size_ / 2; ++i) {\n        auto &v = c_ys_[i + x_size_ / 2];\n\
    \        std::sort(v.begin(), v.end());\n        v.erase(std::unique(v.begin(),\
    \ v.end()), v.end());\n      }\n\n      for (int i = x_size_ / 2 - 1; i >= 1;\
    \ --i) {\n        const auto &a = c_ys_[i << 1 | 0];\n        const auto &b =\
    \ c_ys_[i << 1 | 1];\n        auto &c       = c_ys_[i];\n        c.resize(a.size()\
    \ + b.size());\n\n        std::merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());\n\
    \        c.erase(std::unique(c.begin(), c.end()), c.end());\n      }\n\n     \
    \ for (int i = 1; i < x_size_; ++i) {\n        segs_[i] = segment_tree<Monoid>(c_ys_[i].size());\n\
    \      }\n    }\n\n    void update(std::pair<int64_t, int64_t> p, const value_type\
    \ &val) {\n      const auto [x, y] = p;\n      int i             = std::lower_bound(c_xs_.begin(),\
    \ c_xs_.end(), x) - c_xs_.begin() + x_size_ / 2;\n\n      while (i >= 1) {\n \
    \       int j = std::lower_bound(c_ys_[i].begin(), c_ys_[i].end(), y) - c_ys_[i].begin();\n\
    \        segs_[i].update(j, val);\n\n        i >>= 1;\n      }\n    }\n\n  private:\n\
    \    value_type get_sub(int i, int64_t y1, int64_t y2) const {\n      int l =\
    \ std::lower_bound(c_ys_[i].begin(), c_ys_[i].end(), y1) - c_ys_[i].begin();\n\
    \      int r = std::lower_bound(c_ys_[i].begin(), c_ys_[i].end(), y2) - c_ys_[i].begin();\n\
    \n      return segs_[i].fold(l, r);\n    }\n\n  public:\n    value_type fold(std::pair<int64_t,\
    \ int64_t> p1, std::pair<int64_t, int64_t> p2) const {\n      const auto [x1,\
    \ y1] = p1;\n      const auto [x2, y2] = p2;\n      int l               = std::lower_bound(c_xs_.begin(),\
    \ c_xs_.end(), x1) - c_xs_.begin() + x_size_ / 2;\n      int r               =\
    \ std::lower_bound(c_xs_.begin(), c_xs_.end(), x2) - c_xs_.begin() + x_size_ /\
    \ 2;\n\n      value_type ret = M_();\n\n      while (l < r) {\n        if (r &\
    \ 1) ret = M_(ret, get_sub(--r, y1, y2));\n        if (l & 1) ret = M_(ret, get_sub(l++,\
    \ y1, y2));\n        l >>= 1;\n        r >>= 1;\n      }\n\n      return ret;\n\
    \    }\n  };\n}  // namespace haar_lib\n#line 2 \"Mylib/IO/input_tuple_vector.cpp\"\
    \n#include <initializer_list>\n#line 4 \"Mylib/IO/input_tuple_vector.cpp\"\n#include\
    \ <tuple>\n#include <utility>\n#line 7 \"Mylib/IO/input_tuple_vector.cpp\"\n\n\
    namespace haar_lib {\n  template <typename T, size_t... I>\n  void input_tuple_vector_init(T\
    \ &val, int N, std::index_sequence<I...>) {\n    (void) std::initializer_list<int>{(void(std::get<I>(val).resize(N)),\
    \ 0)...};\n  }\n\n  template <typename T, size_t... I>\n  void input_tuple_vector_helper(T\
    \ &val, int i, std::index_sequence<I...>) {\n    (void) std::initializer_list<int>{(void(std::cin\
    \ >> std::get<I>(val)[i]), 0)...};\n  }\n\n  template <typename... Args>\n  auto\
    \ input_tuple_vector(int N) {\n    std::tuple<std::vector<Args>...> ret;\n\n \
    \   input_tuple_vector_init(ret, N, std::make_index_sequence<sizeof...(Args)>());\n\
    \    for (int i = 0; i < N; ++i) {\n      input_tuple_vector_helper(ret, i, std::make_index_sequence<sizeof...(Args)>());\n\
    \    }\n\n    return ret;\n  }\n}  // namespace haar_lib\n#line 6 \"Mylib/IO/input_tuple.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T, size_t... I>\n  static void\
    \ input_tuple_helper(std::istream &s, T &val, std::index_sequence<I...>) {\n \
    \   (void) std::initializer_list<int>{(void(s >> std::get<I>(val)), 0)...};\n\
    \  }\n\n  template <typename T, typename U>\n  std::istream &operator>>(std::istream\
    \ &s, std::pair<T, U> &value) {\n    s >> value.first >> value.second;\n    return\
    \ s;\n  }\n\n  template <typename... Args>\n  std::istream &operator>>(std::istream\
    \ &s, std::tuple<Args...> &value) {\n    input_tuple_helper(s, value, std::make_index_sequence<sizeof...(Args)>());\n\
    \    return s;\n  }\n}  // namespace haar_lib\n#line 8 \"Mylib/IO/input_tuples.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename... Args>\n  class InputTuples {\n\
    \    struct iter {\n      using value_type = std::tuple<Args...>;\n      value_type\
    \ value;\n      bool fetched = false;\n      int N, c = 0;\n\n      value_type\
    \ operator*() {\n        if (not fetched) {\n          std::cin >> value;\n  \
    \      }\n        return value;\n      }\n\n      void operator++() {\n      \
    \  ++c;\n        fetched = false;\n      }\n\n      bool operator!=(iter &) const\
    \ {\n        return c < N;\n      }\n\n      iter(int N) : N(N) {}\n    };\n\n\
    \    int N;\n\n  public:\n    InputTuples(int N) : N(N) {}\n\n    iter begin()\
    \ const { return iter(N); }\n    iter end() const { return iter(N); }\n  };\n\n\
    \  template <typename... Args>\n  auto input_tuples(int N) {\n    return InputTuples<Args...>(N);\n\
    \  }\n}  // namespace haar_lib\n#line 9 \"test/yosupo-judge/rectangle_sum/main.segment_tree.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main() {\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int N, Q;\n  std::cin >> N >> Q;\n\n  auto [x, y, w] = hl::input_tuple_vector<int64_t,\
    \ int64_t, int64_t>(N);\n\n  hl::segment_tree_on_segment_tree<hl::sum_monoid<int64_t>>\
    \ seg;\n\n  for (int i = 0; i < N; ++i) {\n    seg.add(x[i], y[i]);\n  }\n\n \
    \ seg.build();\n\n  for (int i = 0; i < N; ++i) {\n    seg.update({x[i], y[i]},\
    \ w[i]);\n  }\n\n  for (auto [l, d, r, u] : hl::input_tuples<int64_t, int64_t,\
    \ int64_t, int64_t>(Q)) {\n    auto ans = seg.fold({l, d}, {r, u});\n    std::cout\
    \ << ans << std::endl;\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\n\n#include\
    \ <iostream>\n#include <vector>\n#include \"Mylib/AlgebraicStructure/Monoid/sum.cpp\"\
    \n#include \"Mylib/DataStructure/SegmentTree/segment_tree_on_segment_tree.cpp\"\
    \n#include \"Mylib/IO/input_tuple_vector.cpp\"\n#include \"Mylib/IO/input_tuples.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main() {\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int N, Q;\n  std::cin >> N >> Q;\n\n  auto [x, y, w] = hl::input_tuple_vector<int64_t,\
    \ int64_t, int64_t>(N);\n\n  hl::segment_tree_on_segment_tree<hl::sum_monoid<int64_t>>\
    \ seg;\n\n  for (int i = 0; i < N; ++i) {\n    seg.add(x[i], y[i]);\n  }\n\n \
    \ seg.build();\n\n  for (int i = 0; i < N; ++i) {\n    seg.update({x[i], y[i]},\
    \ w[i]);\n  }\n\n  for (auto [l, d, r, u] : hl::input_tuples<int64_t, int64_t,\
    \ int64_t, int64_t>(Q)) {\n    auto ans = seg.fold({l, d}, {r, u});\n    std::cout\
    \ << ans << std::endl;\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/AlgebraicStructure/Monoid/sum.cpp
  - Mylib/DataStructure/SegmentTree/segment_tree_on_segment_tree.cpp
  - Mylib/DataStructure/SegmentTree/segment_tree.cpp
  - Mylib/IO/input_tuple_vector.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  isVerificationFile: true
  path: test/yosupo-judge/rectangle_sum/main.segment_tree.test.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo-judge/rectangle_sum/main.segment_tree.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-judge/rectangle_sum/main.segment_tree.test.cpp
- /verify/test/yosupo-judge/rectangle_sum/main.segment_tree.test.cpp.html
title: test/yosupo-judge/rectangle_sum/main.segment_tree.test.cpp
---