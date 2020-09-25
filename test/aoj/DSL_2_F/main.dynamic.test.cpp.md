---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Mylib/DataStructure/SegmentTree/dynamic_lazy_segment_tree.cpp
    title: Dynamic lazy segment tree
  - icon: ':x:'
    path: Mylib/AlgebraicStructure/Monoid/update.cpp
    title: Update monoid
  - icon: ':question:'
    path: Mylib/AlgebraicStructure/Monoid/min.cpp
    title: Min monoid
  - icon: ':x:'
    path: Mylib/AlgebraicStructure/MonoidAction/update_min.cpp
    title: Range update / Range min
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F
  bundledCode: "#line 1 \"test/aoj/DSL_2_F/main.dynamic.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F\"\n\n#include\
    \ <iostream>\n#include <climits>\n#line 2 \"Mylib/DataStructure/SegmentTree/dynamic_lazy_segment_tree.cpp\"\
    \n#include <cstdint>\n\nnamespace haar_lib {\n  template <typename MonoidGet,\
    \ typename MonoidUpdate, template <typename, typename> typename Connector>\n \
    \ class dynamic_lazy_segment_tree {\n    using value_type_get = typename MonoidGet::value_type;\n\
    \    using value_type_update = typename MonoidUpdate::value_type;\n    Connector<MonoidGet,\
    \ MonoidUpdate> M;\n    MonoidGet M_get;\n    MonoidUpdate M_update;\n\n    struct\
    \ node {\n      value_type_get value;\n      value_type_update lazy;\n      node\
    \ *left = nullptr, *right = nullptr;\n      node(){}\n      node(const value_type_get\
    \ &value, const value_type_update &lazy): value(value), lazy(lazy){}\n    };\n\
    \n    int64_t depth, size, hsize;\n    node *root = nullptr;\n\n    void propagate(node\
    \ *t, int64_t l, int64_t r){\n      if(t->lazy == M_update()) return;\n      if(r\
    \ - l > 1){\n        if(not t->left) t->left = new node(M_get(), M_update());\n\
    \        t->left->lazy = M_update(t->lazy, t->left->lazy);\n        if(not t->right)\
    \ t->right = new node(M_get(), M_update());\n        t->right->lazy = M_update(t->lazy,\
    \ t->right->lazy);\n      }\n      int64_t len = r - l;\n      t->value = M(t->value,\
    \ t->lazy, len);\n      t->lazy = M_update();\n    }\n\n    node* update(node\
    \ *t, int64_t l, int64_t r, int64_t x, int64_t y, value_type_update value){\n\
    \      if(not t) t = new node(M_get(), M_update());\n\n      propagate(t, l, r);\n\
    \      if(r - l == 1){\n        if(x <= l and r <= y) t->lazy = M_update(value,\
    \ t->lazy);\n        propagate(t, l, r);\n        return t;\n      }\n\n     \
    \ if(r < x or y < l) return t;\n      if(x <= l and r <= y){\n        t->lazy\
    \ = M_update(value, t->lazy);\n        propagate(t, l, r);\n        return t;\n\
    \      }\n\n      t->left = update(t->left, l, (l + r) / 2, x, y, value);\n  \
    \    t->right = update(t->right, (l + r) / 2, r, x, y, value);\n      t->value\
    \ = M_get(t->left->value, t->right->value);\n\n      return t;\n    }\n\n    value_type_get\
    \ get(node *t, int64_t l, int64_t r, int64_t x, int64_t y){\n      if(not t) return\
    \ M_get();\n\n      propagate(t, l, r);\n      if(r <= x or y <= l) return M_get();\n\
    \      if(x <= l and r <= y) return t->value;\n\n      return M_get(\n       \
    \ get(t->left, l, (l + r) / 2, x, y),\n        get(t->right, (l + r) / 2, r, x,\
    \ y)\n      );\n    }\n\n  public:\n    dynamic_lazy_segment_tree(int64_t n):\n\
    \      depth(n > 1 ? 64 - __builtin_clzll(n - 1) + 1 : 1),\n      size(1LL <<\
    \ depth),\n      hsize(size / 2)\n    {\n      root = new node(M_get(), M_update());\n\
    \    }\n\n    void update(int64_t l, int64_t r, value_type_update value){\n  \
    \    update(root, 0, hsize, l, r, value);\n    }\n\n    value_type_get fold(int64_t\
    \ l, int64_t r){\n      return get(root, 0, hsize, l, r);\n    }\n\n    value_type_get\
    \ operator[](int64_t i){\n      return fold(i, i + 1);\n    }\n  };\n}\n#line\
    \ 2 \"Mylib/AlgebraicStructure/Monoid/update.cpp\"\n#include <optional>\n\nnamespace\
    \ haar_lib {\n  template <typename T>\n  struct update_monoid {\n    using value_type\
    \ = std::optional<T>;\n    value_type operator()() const {return std::nullopt;}\n\
    \    value_type operator()(const value_type &a, const value_type &b) const {return\
    \ (a ? a : b);}\n  };\n}\n#line 2 \"Mylib/AlgebraicStructure/Monoid/min.cpp\"\n\
    #include <algorithm>\n#line 4 \"Mylib/AlgebraicStructure/Monoid/min.cpp\"\n\n\
    namespace haar_lib {\n  template <typename T>\n  struct min_monoid {\n    using\
    \ value_type = std::optional<T>;\n\n    value_type operator()() const {return\
    \ {};}\n    value_type operator()(const value_type &a, const value_type &b) const\
    \ {\n      if(not a) return b;\n      if(not b) return a;\n      return {std::min(*a,\
    \ *b)};\n    }\n  };\n}\n#line 2 \"Mylib/AlgebraicStructure/MonoidAction/update_min.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename MonoidGet, typename MonoidUpdate>\n\
    \  struct update_min {\n    using value_type_get = typename MonoidGet::value_type;\n\
    \    using value_type_update = typename MonoidUpdate::value_type;\n\n    value_type_get\
    \ operator()(value_type_get a, value_type_update b, int) const {\n      return\
    \ b ? *b : a;\n    }\n  };\n}\n#line 3 \"Mylib/IO/input_tuples.cpp\"\n#include\
    \ <vector>\n#include <tuple>\n#include <utility>\n#include <initializer_list>\n\
    #line 6 \"Mylib/IO/input_tuple.cpp\"\n\nnamespace haar_lib {\n  template <typename\
    \ T, size_t ... I>\n  static void input_tuple_helper(std::istream &s, T &val,\
    \ std::index_sequence<I ...>){\n    (void)std::initializer_list<int>{(void(s >>\
    \ std::get<I>(val)), 0) ...};\n  }\n\n  template <typename T, typename U>\n  std::istream&\
    \ operator>>(std::istream &s, std::pair<T, U> &value){\n    s >> value.first >>\
    \ value.second;\n    return s;\n  }\n\n  template <typename ... Args>\n  std::istream&\
    \ operator>>(std::istream &s, std::tuple<Args ...> &value){\n    input_tuple_helper(s,\
    \ value, std::make_index_sequence<sizeof ... (Args)>());\n    return s;\n  }\n\
    }\n#line 8 \"Mylib/IO/input_tuples.cpp\"\n\nnamespace haar_lib {\n  template <typename\
    \ ... Args>\n  class InputTuples {\n    struct iter {\n      using value_type\
    \ = std::tuple<Args ...>;\n      value_type value;\n      bool fetched = false;\n\
    \      int N, c = 0;\n\n      value_type operator*(){\n        if(not fetched){\n\
    \          std::cin >> value;\n        }\n        return value;\n      }\n\n \
    \     void operator++(){\n        ++c;\n        fetched = false;\n      }\n\n\
    \      bool operator!=(iter &) const {\n        return c < N;\n      }\n\n   \
    \   iter(int N): N(N){}\n    };\n\n    int N;\n\n  public:\n    InputTuples(int\
    \ N): N(N){}\n\n    iter begin() const {return iter(N);}\n    iter end() const\
    \ {return iter(N);}\n  };\n\n  template <typename ... Args>\n  auto input_tuples(int\
    \ N){\n    return InputTuples<Args ...>(N);\n  }\n}\n#line 10 \"test/aoj/DSL_2_F/main.dynamic.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  int n, q; std::cin >> n >> q;\n\
    \n  hl::dynamic_lazy_segment_tree<hl::min_monoid<int>, hl::update_monoid<int>,\
    \ hl::update_min> seg(n);\n\n  for(auto [type, s, t] : hl::input_tuples<int, int,\
    \ int>(q)){\n    if(type == 0){\n      int x; std::cin >> x;\n      seg.update(s,\
    \ t + 1, x);\n    }else{\n      std::cout << seg.fold(s, t + 1).value_or(INT_MAX)\
    \ << std::endl;\n    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F\"\
    \n\n#include <iostream>\n#include <climits>\n#include \"Mylib/DataStructure/SegmentTree/dynamic_lazy_segment_tree.cpp\"\
    \n#include \"Mylib/AlgebraicStructure/Monoid/update.cpp\"\n#include \"Mylib/AlgebraicStructure/Monoid/min.cpp\"\
    \n#include \"Mylib/AlgebraicStructure/MonoidAction/update_min.cpp\"\n#include\
    \ \"Mylib/IO/input_tuples.cpp\"\n\nnamespace hl = haar_lib;\n\nint main(){\n \
    \ int n, q; std::cin >> n >> q;\n\n  hl::dynamic_lazy_segment_tree<hl::min_monoid<int>,\
    \ hl::update_monoid<int>, hl::update_min> seg(n);\n\n  for(auto [type, s, t] :\
    \ hl::input_tuples<int, int, int>(q)){\n    if(type == 0){\n      int x; std::cin\
    \ >> x;\n      seg.update(s, t + 1, x);\n    }else{\n      std::cout << seg.fold(s,\
    \ t + 1).value_or(INT_MAX) << std::endl;\n    }\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/DataStructure/SegmentTree/dynamic_lazy_segment_tree.cpp
  - Mylib/AlgebraicStructure/Monoid/update.cpp
  - Mylib/AlgebraicStructure/Monoid/min.cpp
  - Mylib/AlgebraicStructure/MonoidAction/update_min.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  isVerificationFile: true
  path: test/aoj/DSL_2_F/main.dynamic.test.cpp
  requiredBy: []
  timestamp: '2020-09-25 01:38:58+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/DSL_2_F/main.dynamic.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_F/main.dynamic.test.cpp
- /verify/test/aoj/DSL_2_F/main.dynamic.test.cpp.html
title: test/aoj/DSL_2_F/main.dynamic.test.cpp
---
