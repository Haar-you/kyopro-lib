---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Mylib/DataStructure/FenwickTree/fenwick_tree.cpp
    title: Fenwick tree
  - icon: ':question:'
    path: Mylib/AlgebraicStructure/Group/sum.cpp
    title: Sum group
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
  bundledCode: "#line 1 \"test/aoj/DSL_2_B/main.fenwick_tree.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\n\n#include\
    \ <iostream>\n#line 2 \"Mylib/DataStructure/FenwickTree/fenwick_tree.cpp\"\n#include\
    \ <vector>\n\nnamespace haar_lib {\n  template <typename AbelianGroup>\n  class\
    \ fenwick_tree {\n    using value_type = typename AbelianGroup::value_type;\n\
    \    const static AbelianGroup G;\n\n    int size;\n    std::vector<value_type>\
    \ data;\n\n  public:\n    fenwick_tree(){}\n    fenwick_tree(int size):\n    \
    \  size(size), data(size + 1, G())\n    {}\n\n    void update(int i, const value_type\
    \ &val){\n      i += 1; // 1-index\n\n      while(i <= size){\n        data[i]\
    \ = G(data[i], val);\n        i += i & (-i);\n      }\n    }\n\n    value_type\
    \ get(int i) const { // [0, i)\n      value_type ret = G();\n      i += 1; //\
    \ 1-index\n\n      while(i > 0){\n        ret = G(ret, data[i]);\n        i -=\
    \ i & (-i);\n      }\n\n      return ret;\n    }\n\n    value_type get(int l,\
    \ int r) const { // [l, r)\n      return G(get(r - 1), G.inv(get(l - 1)));\n \
    \   }\n\n    value_type operator[](int x) const {\n      return get(x, x + 1);\n\
    \    }\n  };\n}\n#line 2 \"Mylib/AlgebraicStructure/Group/sum.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename T>\n  struct sum_group {\n    using value_type\
    \ = T;\n\n    value_type operator()() const {return 0;}\n    value_type operator()(const\
    \ value_type &a, const value_type &b) const {return a + b;}\n    value_type inv(const\
    \ value_type &a) const {return -a;}\n  };\n}\n#line 4 \"Mylib/IO/input_tuples.cpp\"\
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
    \ ...>(N);\n  }\n}\n#line 7 \"test/aoj/DSL_2_B/main.fenwick_tree.test.cpp\"\n\n\
    namespace hl = haar_lib;\n\nint main(){\n  int n, q; std::cin >> n >> q;\n\n \
    \ auto fen = hl::fenwick_tree<hl::sum_group<int>>(n);\n\n  for(auto [type, x,\
    \ y] : hl::input_tuples<int, int, int>(q)){\n    if(type == 0){\n      fen.update(x\
    \ - 1, y);\n    }else{\n      std::cout << fen.get(x - 1, y) << std::endl;\n \
    \   }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\
    \n\n#include <iostream>\n#include \"Mylib/DataStructure/FenwickTree/fenwick_tree.cpp\"\
    \n#include \"Mylib/AlgebraicStructure/Group/sum.cpp\"\n#include \"Mylib/IO/input_tuples.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  int n, q; std::cin >> n >> q;\n\
    \n  auto fen = hl::fenwick_tree<hl::sum_group<int>>(n);\n\n  for(auto [type, x,\
    \ y] : hl::input_tuples<int, int, int>(q)){\n    if(type == 0){\n      fen.update(x\
    \ - 1, y);\n    }else{\n      std::cout << fen.get(x - 1, y) << std::endl;\n \
    \   }\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/DataStructure/FenwickTree/fenwick_tree.cpp
  - Mylib/AlgebraicStructure/Group/sum.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  isVerificationFile: true
  path: test/aoj/DSL_2_B/main.fenwick_tree.test.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/DSL_2_B/main.fenwick_tree.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_B/main.fenwick_tree.test.cpp
- /verify/test/aoj/DSL_2_B/main.fenwick_tree.test.cpp.html
title: test/aoj/DSL_2_B/main.fenwick_tree.test.cpp
---
