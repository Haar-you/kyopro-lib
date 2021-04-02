---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/AlgebraicStructure/Monoid/sum.cpp
    title: Sum monoid
  - icon: ':heavy_check_mark:'
    path: Mylib/DataStructure/SegmentTree/segment_tree_2d.cpp
    title: Segment tree (2D)
  - icon: ':heavy_check_mark:'
    path: Mylib/IO/input_tuple.cpp
    title: Input tuple
  - icon: ':heavy_check_mark:'
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
  bundledCode: "#line 1 \"test/aoj/2842/main.segment_tree.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2842\"\n\n#include\
    \ <iostream>\n#include <queue>\n#include <tuple>\n#line 2 \"Mylib/AlgebraicStructure/Monoid/sum.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  struct sum_monoid {\n   \
    \ using value_type = T;\n    value_type operator()() const {return 0;}\n    value_type\
    \ operator()(value_type a, value_type b) const {return a + b;}\n  };\n}\n#line\
    \ 2 \"Mylib/DataStructure/SegmentTree/segment_tree_2d.cpp\"\n#include <vector>\n\
    \nnamespace haar_lib {\n  template <typename Monoid>\n  class segment_tree_2d\
    \ {\n  public:\n    using value_type = typename Monoid::value_type;\n\n  private:\n\
    \    Monoid M_;\n    int w_, h_;\n    std::vector<std::vector<value_type>> data_;\n\
    \n    value_type get_w(int l, int r, int y) const {\n      l += w_ / 2;\n    \
    \  r += w_ / 2;\n\n      value_type ret = M_();\n\n      while(l < r){\n     \
    \   if(r & 1) ret = M_(ret, data_[--r][y]);\n        if(l & 1) ret = M_(ret, data_[l++][y]);\n\
    \        l >>= 1, r >>= 1;\n      }\n\n      return ret;\n    }\n\n  public:\n\
    \    segment_tree_2d(){}\n    segment_tree_2d(int width, int height){\n      w_\
    \ = 1;\n      while(w_ < width) w_ *= 2;\n      w_ = w_ * 2;\n\n      h_ = 1;\n\
    \      while(h_ < height) h_ *= 2;\n      h_ = h_ * 2;\n\n      data_ = std::vector(w_,\
    \ std::vector<value_type>(h_, M_()));\n    }\n\n    value_type fold(std::pair<int,\
    \ int> p1, std::pair<int, int> p2) const {\n      const auto [x1, y1] = p1;\n\
    \      const auto [x2, y2] = p2;\n      int l = y1 + h_ / 2;\n      int r = y2\
    \ + h_ / 2;\n\n      value_type ret = M_();\n\n      while(l < r){\n        if(r\
    \ & 1) ret = M_(ret, get_w(x1, x2, --r));\n        if(l & 1) ret = M_(ret, get_w(x1,\
    \ x2, l++));\n        l >>= 1, r >>= 1;\n      }\n\n      return ret;\n    }\n\
    \n    value_type operator[](std::pair<int, int> p) const {\n      auto [x, y]\
    \ = p;\n      return data_[w_ / 2 + x][h_ / 2 + y];\n    }\n\n    void set(std::pair<int,\
    \ int> p, const value_type &val){\n      const auto [x, y] = p;\n      const int\
    \ i = x + w_ / 2;\n      const int j = y + h_ / 2;\n\n      data_[i][j] = val;\n\
    \n      for(int X = i >> 1, Y = j; X > 0; X >>= 1){\n        data_[X][Y] = M_(data_[X\
    \ << 1 | 0][Y], data_[X << 1 | 1][Y]);\n      }\n\n      for(int Y = j >> 1; Y\
    \ > 0; Y >>= 1){\n        for(int X = i; X > 0; X >>= 1){\n          data_[X][Y]\
    \ = M_(data_[X][Y << 1 | 0], data_[X][Y << 1 | 1]);\n        }\n      }\n    }\n\
    \n    void update(std::pair<int, int> p, const value_type &val){\n      set(p,\
    \ M_((*this)[p], val));\n    }\n  };\n}\n#line 5 \"Mylib/IO/input_tuples.cpp\"\
    \n#include <utility>\n#include <initializer_list>\n#line 6 \"Mylib/IO/input_tuple.cpp\"\
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
    \ ...>(N);\n  }\n}\n#line 9 \"test/aoj/2842/main.segment_tree.test.cpp\"\n\nnamespace\
    \ hl = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int H, W, T, Q; std::cin >> H >> W >> T >> Q;\n\n  hl::segment_tree_2d<hl::sum_monoid<int>>\
    \ seg1(H, W), seg2(H, W);\n\n  std::queue<std::tuple<int, int, int>> q;\n\n  for(auto\
    \ [t, c] : hl::input_tuples<int, int>(Q)){\n    while(q.size()){\n      auto &a\
    \ = q.front();\n\n      if(t >= std::get<2>(a) + T){\n        int x = std::get<0>(a),\
    \ y = std::get<1>(a);\n\n        seg1.update({x, y}, 1);\n        seg2.update({x,\
    \ y}, -1);\n\n        q.pop();\n      }else{\n        break;\n      }\n    }\n\
    \n    if(c == 0){\n      int h, w; std::cin >> h >> w;\n      --h, --w;\n\n  \
    \    seg2.update({h, w}, 1);\n      q.emplace(h, w, t);\n    }else if(c == 1){\n\
    \      int h, w; std::cin >> h >> w;\n      --h, --w;\n\n      if(seg1[{h, w}]\
    \ == 1) seg1.update({h, w}, -1);\n    }else{\n      int h1, w1, h2, w2; std::cin\
    \ >> h1 >> w1 >> h2 >> w2;\n      --h1, --w1;\n\n      std::cout << seg1.fold({h1,\
    \ w1}, {h2, w2}) << \" \" << seg2.fold({h1, w1}, {h2, w2}) << std::endl;\n   \
    \ }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2842\"\
    \n\n#include <iostream>\n#include <queue>\n#include <tuple>\n#include \"Mylib/AlgebraicStructure/Monoid/sum.cpp\"\
    \n#include \"Mylib/DataStructure/SegmentTree/segment_tree_2d.cpp\"\n#include \"\
    Mylib/IO/input_tuples.cpp\"\n\nnamespace hl = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n\
    \  std::ios::sync_with_stdio(false);\n\n  int H, W, T, Q; std::cin >> H >> W >>\
    \ T >> Q;\n\n  hl::segment_tree_2d<hl::sum_monoid<int>> seg1(H, W), seg2(H, W);\n\
    \n  std::queue<std::tuple<int, int, int>> q;\n\n  for(auto [t, c] : hl::input_tuples<int,\
    \ int>(Q)){\n    while(q.size()){\n      auto &a = q.front();\n\n      if(t >=\
    \ std::get<2>(a) + T){\n        int x = std::get<0>(a), y = std::get<1>(a);\n\n\
    \        seg1.update({x, y}, 1);\n        seg2.update({x, y}, -1);\n\n       \
    \ q.pop();\n      }else{\n        break;\n      }\n    }\n\n    if(c == 0){\n\
    \      int h, w; std::cin >> h >> w;\n      --h, --w;\n\n      seg2.update({h,\
    \ w}, 1);\n      q.emplace(h, w, t);\n    }else if(c == 1){\n      int h, w; std::cin\
    \ >> h >> w;\n      --h, --w;\n\n      if(seg1[{h, w}] == 1) seg1.update({h, w},\
    \ -1);\n    }else{\n      int h1, w1, h2, w2; std::cin >> h1 >> w1 >> h2 >> w2;\n\
    \      --h1, --w1;\n\n      std::cout << seg1.fold({h1, w1}, {h2, w2}) << \" \"\
    \ << seg2.fold({h1, w1}, {h2, w2}) << std::endl;\n    }\n  }\n\n  return 0;\n\
    }\n"
  dependsOn:
  - Mylib/AlgebraicStructure/Monoid/sum.cpp
  - Mylib/DataStructure/SegmentTree/segment_tree_2d.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  isVerificationFile: true
  path: test/aoj/2842/main.segment_tree.test.cpp
  requiredBy: []
  timestamp: '2020-09-28 09:27:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/2842/main.segment_tree.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/2842/main.segment_tree.test.cpp
- /verify/test/aoj/2842/main.segment_tree.test.cpp.html
title: test/aoj/2842/main.segment_tree.test.cpp
---
