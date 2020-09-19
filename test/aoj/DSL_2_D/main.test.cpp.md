---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Mylib/DataStructure/SegmentTree/dual_segment_tree.cpp
    title: Dual segment tree
  - icon: ':x:'
    path: Mylib/AlgebraicStructure/Monoid/update.cpp
    title: Update monoid
  - icon: ':question:'
    path: Mylib/IO/input_tuples.cpp
    title: Mylib/IO/input_tuples.cpp
  - icon: ':question:'
    path: Mylib/IO/input_tuple.cpp
    title: Mylib/IO/input_tuple.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D
  bundledCode: "#line 1 \"test/aoj/DSL_2_D/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D\"\
    \n\n#include <iostream>\n#include <climits>\n#line 2 \"Mylib/DataStructure/SegmentTree/dual_segment_tree.cpp\"\
    \n#include <vector>\n\nnamespace haar_lib {\n  template <typename Monoid>\n  class\
    \ dual_segment_tree {\n    using value_type = typename Monoid::value_type;\n \
    \   const static Monoid M;\n\n    const int depth, size, hsize;\n    std::vector<value_type>\
    \ data;\n\n    void propagate(int i){\n      if(i < hsize){\n        data[i <<\
    \ 1 | 0] = M(data[i], data[i << 1 | 0]);\n        data[i << 1 | 1] = M(data[i],\
    \ data[i << 1 | 1]);\n        data[i] = M();\n      }\n    }\n\n    void propagate_top_down(int\
    \ i){\n      std::vector<int> temp;\n      while(i > 1){\n        i >>= 1;\n \
    \       temp.push_back(i);\n      }\n\n      for(auto it = temp.rbegin(); it !=\
    \ temp.rend(); ++it) propagate(*it);\n    }\n\n  public:\n    dual_segment_tree(int\
    \ n):\n      depth(n > 1 ? 32 - __builtin_clz(n - 1) + 1 : 1),\n      size(1 <<\
    \ depth), hsize(size / 2),\n      data(size, M())\n    {}\n\n    void update(int\
    \ l, int r, const value_type &x){\n      propagate_top_down(l + hsize);\n    \
    \  propagate_top_down(r + hsize);\n\n      int L = l + hsize;\n      int R = r\
    \ + hsize;\n\n      while(L < R){\n        if(R & 1) --R, data[R] = M(x, data[R]);\n\
    \        if(L & 1) data[L] = M(x, data[L]), ++L;\n        L >>= 1, R >>= 1;\n\
    \      }\n    }\n\n    value_type operator[](int i){\n      propagate_top_down(i\
    \ + hsize);\n      return data[i + hsize];\n    }\n\n    template <typename T>\n\
    \    void init_with_vector(const std::vector<T> &a){\n      data.assign(size,\
    \ M());\n      for(int i = 0; i < (int)a.size(); ++i) data[hsize + i] = a[i];\n\
    \    }\n\n    template <typename T>\n    void init(const T &val){\n      init_with_vector(std::vector<value_type>(hsize,\
    \ val));\n    }\n  };\n}\n#line 2 \"Mylib/AlgebraicStructure/Monoid/update.cpp\"\
    \n#include <optional>\n\nnamespace haar_lib {\n  template <typename T>\n  struct\
    \ update_monoid {\n    using value_type = std::optional<T>;\n    value_type operator()()\
    \ const {return std::nullopt;}\n    value_type operator()(const value_type &a,\
    \ const value_type &b) const {return (a ? a : b);}\n  };\n}\n#line 4 \"Mylib/IO/input_tuples.cpp\"\
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
    \ ...>(N);\n  }\n}\n#line 8 \"test/aoj/DSL_2_D/main.test.cpp\"\n\nnamespace hl\
    \ = haar_lib;\n\nint main(){\n  int n, q; std::cin >> n >> q;\n\n  auto seg =\
    \ hl::dual_segment_tree<hl::update_monoid<int>>(n);\n  seg.init(INT_MAX);\n\n\
    \  for(auto [type] : hl::input_tuples<int>(q)){\n    if(type == 0){\n      int\
    \ s, t, x; std::cin >> s >> t >> x;\n      seg.update(s, t + 1, x);\n    }else{\n\
    \      int i; std::cin >> i;\n      std::cout << *seg[i] << std::endl;\n    }\n\
    \  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D\"\
    \n\n#include <iostream>\n#include <climits>\n#include \"Mylib/DataStructure/SegmentTree/dual_segment_tree.cpp\"\
    \n#include \"Mylib/AlgebraicStructure/Monoid/update.cpp\"\n#include \"Mylib/IO/input_tuples.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  int n, q; std::cin >> n >> q;\n\
    \n  auto seg = hl::dual_segment_tree<hl::update_monoid<int>>(n);\n  seg.init(INT_MAX);\n\
    \n  for(auto [type] : hl::input_tuples<int>(q)){\n    if(type == 0){\n      int\
    \ s, t, x; std::cin >> s >> t >> x;\n      seg.update(s, t + 1, x);\n    }else{\n\
    \      int i; std::cin >> i;\n      std::cout << *seg[i] << std::endl;\n    }\n\
    \  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/DataStructure/SegmentTree/dual_segment_tree.cpp
  - Mylib/AlgebraicStructure/Monoid/update.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  isVerificationFile: true
  path: test/aoj/DSL_2_D/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/DSL_2_D/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_D/main.test.cpp
- /verify/test/aoj/DSL_2_D/main.test.cpp.html
title: test/aoj/DSL_2_D/main.test.cpp
---
