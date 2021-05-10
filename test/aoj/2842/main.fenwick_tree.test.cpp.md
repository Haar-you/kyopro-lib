---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/AlgebraicStructure/Group/sum.cpp
    title: Sum group
  - icon: ':heavy_check_mark:'
    path: Mylib/DataStructure/FenwickTree/fenwick_tree_2d.cpp
    title: Fenwick tree (2D)
  - icon: ':question:'
    path: Mylib/IO/input_tuple.cpp
    title: Input tuple
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2842
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2842
  bundledCode: "#line 1 \"test/aoj/2842/main.fenwick_tree.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2842\"\n\n#include\
    \ <iostream>\n#include <queue>\n#include <tuple>\n#line 2 \"Mylib/AlgebraicStructure/Group/sum.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  struct sum_group {\n    using\
    \ value_type = T;\n\n    value_type operator()() const { return 0; }\n    value_type\
    \ operator()(const value_type &a, const value_type &b) const { return a + b; }\n\
    \    value_type inv(const value_type &a) const { return -a; }\n  };\n}  // namespace\
    \ haar_lib\n#line 2 \"Mylib/DataStructure/FenwickTree/fenwick_tree_2d.cpp\"\n\
    #include <cassert>\n#include <vector>\n\nnamespace haar_lib {\n  template <typename\
    \ AbelianGroup>\n  class fenwick_tree_2d {\n  public:\n    using value_type =\
    \ typename AbelianGroup::value_type;\n\n  private:\n    AbelianGroup G_;\n\n \
    \   int w_, h_;\n    std::vector<std::vector<value_type>> data_;\n\n  private:\n\
    \    value_type get_w(int i, int y) const {\n      value_type ret = G_();\n  \
    \    while (i > 0) {\n        ret = G_(ret, data_[i][y]);\n        i -= i & (-i);\n\
    \      }\n      return ret;\n    }\n\n    value_type get_w(int l, int r, int y)\
    \ const {\n      return G_(get_w(r, y), G_.inv(get_w(l, y)));\n    }\n\n    value_type\
    \ get(int x1, int x2, int y) const {\n      value_type ret = G_();\n      while\
    \ (y > 0) {\n        ret = G_(ret, get_w(x1, x2, y));\n        y -= y & (-y);\n\
    \      }\n      return ret;\n    }\n\n  public:\n    fenwick_tree_2d() {}\n  \
    \  fenwick_tree_2d(int width, int height) : w_(width), h_(height), data_(w_ +\
    \ 1, std::vector<value_type>(h_ + 1, G_())) {}\n\n    value_type fold(std::pair<int,\
    \ int> p1, std::pair<int, int> p2) const {\n      const auto [x1, y1] = p1;\n\
    \      const auto [x2, y2] = p2;\n      assert(0 <= x1 and x1 <= x2 and x2 <=\
    \ w_);\n      assert(0 <= y1 and y1 <= y2 and y2 <= h_);\n      return G_(get(x1,\
    \ x2, y2), G_.inv(get(x1, x2, y1)));\n    }\n\n    value_type operator[](std::pair<int,\
    \ int> p) const {\n      const auto [x, y] = p;\n      return fold({x, y}, {x\
    \ + 1, y + 1});\n    }\n\n    void update(std::pair<int, int> p, const value_type\
    \ &val) {\n      auto [x, y] = p;\n      assert(0 <= x and x < w_);\n      assert(0\
    \ <= y and y < h_);\n      x += 1;\n      y += 1;\n\n      for (int i = x; i <=\
    \ w_; i += i & (-i)) {\n        for (int j = y; j <= h_; j += j & (-j)) {\n  \
    \        data_[i][j] = G_(data_[i][j], val);\n        }\n      }\n    }\n  };\n\
    }  // namespace haar_lib\n#line 2 \"Mylib/IO/input_tuples.cpp\"\n#include <initializer_list>\n\
    #line 5 \"Mylib/IO/input_tuples.cpp\"\n#include <utility>\n#line 6 \"Mylib/IO/input_tuple.cpp\"\
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
    \  }\n}  // namespace haar_lib\n#line 9 \"test/aoj/2842/main.fenwick_tree.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main() {\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int H, W, T, Q;\n  std::cin >> H >> W >> T >> Q;\n\n  hl::fenwick_tree_2d<hl::sum_group<int>>\
    \ seg1(H, W), seg2(H, W);\n\n  std::queue<std::tuple<int, int, int>> q;\n\n  for\
    \ (auto [t, c] : hl::input_tuples<int, int>(Q)) {\n    while (q.size()) {\n  \
    \    auto &a = q.front();\n\n      if (t >= std::get<2>(a) + T) {\n        int\
    \ x = std::get<0>(a), y = std::get<1>(a);\n\n        seg1.update({x, y}, 1);\n\
    \        seg2.update({x, y}, -1);\n\n        q.pop();\n      } else {\n      \
    \  break;\n      }\n    }\n\n    if (c == 0) {\n      int h, w;\n      std::cin\
    \ >> h >> w;\n      --h, --w;\n\n      seg2.update({h, w}, 1);\n      q.emplace(h,\
    \ w, t);\n    } else if (c == 1) {\n      int h, w;\n      std::cin >> h >> w;\n\
    \      --h, --w;\n\n      if (seg1[{h, w}] == 1) seg1.update({h, w}, -1);\n  \
    \  } else {\n      int h1, w1, h2, w2;\n      std::cin >> h1 >> w1 >> h2 >> w2;\n\
    \      --h1, --w1;\n\n      std::cout << seg1.fold({h1, w1}, {h2, w2}) << \" \"\
    \ << seg2.fold({h1, w1}, {h2, w2}) << std::endl;\n    }\n  }\n\n  return 0;\n\
    }\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2842\"\
    \n\n#include <iostream>\n#include <queue>\n#include <tuple>\n#include \"Mylib/AlgebraicStructure/Group/sum.cpp\"\
    \n#include \"Mylib/DataStructure/FenwickTree/fenwick_tree_2d.cpp\"\n#include \"\
    Mylib/IO/input_tuples.cpp\"\n\nnamespace hl = haar_lib;\n\nint main() {\n  std::cin.tie(0);\n\
    \  std::ios::sync_with_stdio(false);\n\n  int H, W, T, Q;\n  std::cin >> H >>\
    \ W >> T >> Q;\n\n  hl::fenwick_tree_2d<hl::sum_group<int>> seg1(H, W), seg2(H,\
    \ W);\n\n  std::queue<std::tuple<int, int, int>> q;\n\n  for (auto [t, c] : hl::input_tuples<int,\
    \ int>(Q)) {\n    while (q.size()) {\n      auto &a = q.front();\n\n      if (t\
    \ >= std::get<2>(a) + T) {\n        int x = std::get<0>(a), y = std::get<1>(a);\n\
    \n        seg1.update({x, y}, 1);\n        seg2.update({x, y}, -1);\n\n      \
    \  q.pop();\n      } else {\n        break;\n      }\n    }\n\n    if (c == 0)\
    \ {\n      int h, w;\n      std::cin >> h >> w;\n      --h, --w;\n\n      seg2.update({h,\
    \ w}, 1);\n      q.emplace(h, w, t);\n    } else if (c == 1) {\n      int h, w;\n\
    \      std::cin >> h >> w;\n      --h, --w;\n\n      if (seg1[{h, w}] == 1) seg1.update({h,\
    \ w}, -1);\n    } else {\n      int h1, w1, h2, w2;\n      std::cin >> h1 >> w1\
    \ >> h2 >> w2;\n      --h1, --w1;\n\n      std::cout << seg1.fold({h1, w1}, {h2,\
    \ w2}) << \" \" << seg2.fold({h1, w1}, {h2, w2}) << std::endl;\n    }\n  }\n\n\
    \  return 0;\n}\n"
  dependsOn:
  - Mylib/AlgebraicStructure/Group/sum.cpp
  - Mylib/DataStructure/FenwickTree/fenwick_tree_2d.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  isVerificationFile: true
  path: test/aoj/2842/main.fenwick_tree.test.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/2842/main.fenwick_tree.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/2842/main.fenwick_tree.test.cpp
- /verify/test/aoj/2842/main.fenwick_tree.test.cpp.html
title: test/aoj/2842/main.fenwick_tree.test.cpp
---