---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/AlgebraicStructure/Group/sum.cpp
    title: Sum group
  - icon: ':heavy_check_mark:'
    path: Mylib/DataStructure/FenwickTree/fenwick_tree.cpp
    title: Fenwick tree
  - icon: ':heavy_check_mark:'
    path: Mylib/DataStructure/FenwickTree/fenwick_tree_on_fenwick_tree.cpp
    title: Fenwick tree (On Fenwick tree)
  - icon: ':question:'
    path: Mylib/IO/input_tuple.cpp
    title: Input tuple
  - icon: ':heavy_check_mark:'
    path: Mylib/IO/input_tuple_vector.cpp
    title: Input tuple vector
  - icon: ':question:'
    path: Mylib/IO/input_tuples.cpp
    title: Input tuples
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/rectangle_sum
  bundledCode: "#line 1 \"test/yosupo-judge/rectangle_sum/main.fenwick_tree.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\n\n#include\
    \ <iostream>\n#include <vector>\n#line 2 \"Mylib/AlgebraicStructure/Group/sum.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  struct sum_group {\n    using\
    \ value_type = T;\n\n    value_type operator()() const {return 0;}\n    value_type\
    \ operator()(const value_type &a, const value_type &b) const {return a + b;}\n\
    \    value_type inv(const value_type &a) const {return -a;}\n  };\n}\n#line 3\
    \ \"Mylib/DataStructure/FenwickTree/fenwick_tree.cpp\"\n#include <cassert>\n\n\
    namespace haar_lib {\n  template <typename AbelianGroup>\n  class fenwick_tree\
    \ {\n  public:\n    using value_type = typename AbelianGroup::value_type;\n\n\
    \  private:\n    AbelianGroup G_;\n    int size_;\n    std::vector<value_type>\
    \ data_;\n\n  public:\n    fenwick_tree(){}\n    fenwick_tree(int size):\n   \
    \   size_(size), data_(size + 1, G_()){}\n\n    void update(int i, const value_type\
    \ &val){\n      assert(0 <= i and i < size_);\n      i += 1; // 1-index\n\n  \
    \    while(i <= size_){\n        data_[i] = G_(data_[i], val);\n        i += i\
    \ & (-i);\n      }\n    }\n\n    value_type fold(int i) const { // [0, i)\n  \
    \    assert(0 <= i and i <= size_);\n      value_type ret = G_();\n\n      while(i\
    \ > 0){\n        ret = G_(ret, data_[i]);\n        i -= i & (-i);\n      }\n\n\
    \      return ret;\n    }\n\n    value_type fold(int l, int r) const { // [l,\
    \ r)\n      assert(0 <= l and l <= r and r <= size_);\n      return G_(fold(r),\
    \ G_.inv(fold(l)));\n    }\n\n    value_type operator[](int x) const {\n     \
    \ return fold(x, x + 1);\n    }\n  };\n}\n#line 3 \"Mylib/DataStructure/FenwickTree/fenwick_tree_on_fenwick_tree.cpp\"\
    \n#include <numeric>\n#include <algorithm>\n#line 6 \"Mylib/DataStructure/FenwickTree/fenwick_tree_on_fenwick_tree.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename AbelianGroup>\n  class fenwick_tree_on_fenwick_tree\
    \ {\n  public:\n    using value_type = typename AbelianGroup::value_type;\n\n\
    \  private:\n    AbelianGroup G_;\n\n    int N_ = 0;\n    std::vector<int64_t>\
    \ xs_, ys_;\n    std::vector<int> c_xs_;\n    std::vector<std::vector<int>> c_ys_;\n\
    \    int x_size_;\n    std::vector<fenwick_tree<AbelianGroup>> segs_;\n\n  public:\n\
    \    fenwick_tree_on_fenwick_tree(){}\n\n    void add(int64_t x, int64_t y){\n\
    \      xs_.push_back(x);\n      ys_.push_back(y);\n      ++N_;\n    }\n\n    void\
    \ build(){\n      c_xs_.insert(c_xs_.end(), xs_.begin(), xs_.end());\n\n     \
    \ std::sort(c_xs_.begin(), c_xs_.end());\n      c_xs_.erase(std::unique(c_xs_.begin(),\
    \ c_xs_.end()), c_xs_.end());\n\n      x_size_ = c_xs_.size();\n\n      c_ys_.resize(x_size_\
    \ + 1);\n      segs_.resize(x_size_ + 1);\n\n      std::vector<int> ord(N_);\n\
    \      std::iota(ord.begin(), ord.end(), 0);\n      std::sort(ord.begin(), ord.end(),\
    \ [&](int i, int j){return ys_[i] < ys_[j];});\n      for(auto i : ord){\n   \
    \     int x = std::lower_bound(c_xs_.begin(), c_xs_.end(), xs_[i]) - c_xs_.begin();\n\
    \n        for(x += 1; x <= x_size_; x += x & (-x)){\n          c_ys_[x].emplace_back(ys_[i]);\n\
    \        }\n      }\n\n      for(int i = 1; i <= x_size_; ++i){\n        auto\
    \ &a = c_ys_[i];\n        a.erase(std::unique(a.begin(), a.end()), a.end());\n\
    \n        segs_[i] = fenwick_tree<AbelianGroup>(c_ys_[i].size());\n      }\n \
    \   }\n\n    void update(std::pair<int, int> p, const value_type &val){\n    \
    \  const auto [x, y] = p;\n      int i = std::lower_bound(c_xs_.begin(), c_xs_.end(),\
    \ x) - c_xs_.begin();\n\n      for(i += 1; i <= x_size_; i += i & (-i)){\n   \
    \     int j = std::lower_bound(c_ys_[i].begin(), c_ys_[i].end(), y) - c_ys_[i].begin();\n\
    \        segs_[i].update(j, val);\n      }\n    }\n\n  private:\n    value_type\
    \ get(int i, int64_t y1, int64_t y2) const {\n      value_type ret = G_();\n \
    \     for(; i > 0; i -= i & (-i)){\n        int l = std::lower_bound(c_ys_[i].begin(),\
    \ c_ys_[i].end(), y1) - c_ys_[i].begin();\n        int r = std::lower_bound(c_ys_[i].begin(),\
    \ c_ys_[i].end(), y2) - c_ys_[i].begin();\n        ret = G_(ret, segs_[i].fold(l,\
    \ r));\n      }\n      return ret;\n    }\n\n  public:\n    // [x1, x2), [y1,\
    \ y2)\n    value_type fold(std::pair<int64_t, int64_t> p1, std::pair<int64_t,\
    \ int64_t> p2) const {\n      const auto [x1, y1] = p1;\n      const auto [x2,\
    \ y2] = p2;\n      int l = std::lower_bound(c_xs_.begin(), c_xs_.end(), x1) -\
    \ c_xs_.begin();\n      int r = std::lower_bound(c_xs_.begin(), c_xs_.end(), x2)\
    \ - c_xs_.begin();\n      return G_(get(r, y1, y2), G_.inv(get(l, y1, y2)));\n\
    \    }\n  };\n}\n#line 4 \"Mylib/IO/input_tuple_vector.cpp\"\n#include <tuple>\n\
    #include <utility>\n#include <initializer_list>\n\nnamespace haar_lib {\n  template\
    \ <typename T, size_t ... I>\n  void input_tuple_vector_init(T &val, int N, std::index_sequence<I\
    \ ...>){\n    (void)std::initializer_list<int>{(void(std::get<I>(val).resize(N)),\
    \ 0) ...};\n  }\n\n  template <typename T, size_t ... I>\n  void input_tuple_vector_helper(T\
    \ &val, int i, std::index_sequence<I ...>){\n    (void)std::initializer_list<int>{(void(std::cin\
    \ >> std::get<I>(val)[i]), 0) ...};\n  }\n\n  template <typename ... Args>\n \
    \ auto input_tuple_vector(int N){\n    std::tuple<std::vector<Args> ...> ret;\n\
    \n    input_tuple_vector_init(ret, N, std::make_index_sequence<sizeof ... (Args)>());\n\
    \    for(int i = 0; i < N; ++i){\n      input_tuple_vector_helper(ret, i, std::make_index_sequence<sizeof\
    \ ... (Args)>());\n    }\n\n    return ret;\n  }\n}\n#line 6 \"Mylib/IO/input_tuple.cpp\"\
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
    \ ...>(N);\n  }\n}\n#line 10 \"test/yosupo-judge/rectangle_sum/main.fenwick_tree.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int N, Q; std::cin >> N >> Q;\n\n  auto [x, y, w] = hl::input_tuple_vector<int64_t,\
    \ int64_t, int64_t>(N);\n\n  hl::fenwick_tree_on_fenwick_tree<hl::sum_group<int64_t>>\
    \ seg;\n\n  for(int i = 0; i < N; ++i){\n    seg.add(x[i], y[i]);\n  }\n\n  seg.build();\n\
    \n  for(int i = 0; i < N; ++i){\n    seg.update({x[i], y[i]}, w[i]);\n  }\n\n\
    \  for(auto [l, d, r, u] : hl::input_tuples<int64_t, int64_t, int64_t, int64_t>(Q)){\n\
    \    auto ans = seg.fold({l, d}, {r, u});\n    std::cout << ans << std::endl;\n\
    \  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\n\n#include\
    \ <iostream>\n#include <vector>\n#include \"Mylib/AlgebraicStructure/Group/sum.cpp\"\
    \n#include \"Mylib/DataStructure/FenwickTree/fenwick_tree.cpp\"\n#include \"Mylib/DataStructure/FenwickTree/fenwick_tree_on_fenwick_tree.cpp\"\
    \n#include \"Mylib/IO/input_tuple_vector.cpp\"\n#include \"Mylib/IO/input_tuples.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int N, Q; std::cin >> N >> Q;\n\n  auto [x, y, w] = hl::input_tuple_vector<int64_t,\
    \ int64_t, int64_t>(N);\n\n  hl::fenwick_tree_on_fenwick_tree<hl::sum_group<int64_t>>\
    \ seg;\n\n  for(int i = 0; i < N; ++i){\n    seg.add(x[i], y[i]);\n  }\n\n  seg.build();\n\
    \n  for(int i = 0; i < N; ++i){\n    seg.update({x[i], y[i]}, w[i]);\n  }\n\n\
    \  for(auto [l, d, r, u] : hl::input_tuples<int64_t, int64_t, int64_t, int64_t>(Q)){\n\
    \    auto ans = seg.fold({l, d}, {r, u});\n    std::cout << ans << std::endl;\n\
    \  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/AlgebraicStructure/Group/sum.cpp
  - Mylib/DataStructure/FenwickTree/fenwick_tree.cpp
  - Mylib/DataStructure/FenwickTree/fenwick_tree_on_fenwick_tree.cpp
  - Mylib/IO/input_tuple_vector.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  isVerificationFile: true
  path: test/yosupo-judge/rectangle_sum/main.fenwick_tree.test.cpp
  requiredBy: []
  timestamp: '2020-10-10 11:12:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo-judge/rectangle_sum/main.fenwick_tree.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-judge/rectangle_sum/main.fenwick_tree.test.cpp
- /verify/test/yosupo-judge/rectangle_sum/main.fenwick_tree.test.cpp.html
title: test/yosupo-judge/rectangle_sum/main.fenwick_tree.test.cpp
---
