---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Mylib/DataStructure/SegmentTree/dynamic_dual_segment_tree.cpp
    title: Dynamic dual segment tree
  - icon: ':question:'
    path: Mylib/AlgebraicStructure/Monoid/sum.cpp
    title: Sum monoid
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E
  bundledCode: "#line 1 \"test/aoj/DSL_2_E/main.dynamic.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E\"\n\n#include\
    \ <iostream>\n#line 2 \"Mylib/DataStructure/SegmentTree/dynamic_dual_segment_tree.cpp\"\
    \n#include <unordered_map>\n\nnamespace haar_lib {\n  template <typename Monoid>\n\
    \  class dynamic_dual_segment_tree {\n    using value_type = typename Monoid::value_type;\n\
    \    const static Monoid M;\n\n    struct node {\n      value_type val;\n    \
    \  node *left = nullptr, *right = nullptr;\n      node(const value_type &val):\
    \ val(val) {}\n    };\n\n    const int64_t depth, size, hsize;\n    node *root\
    \ = nullptr;\n    std::unordered_map<int64_t, node*> umap;\n\n    void propagate(node\
    \ *t, int64_t l, int64_t r){\n      if(r - l > 1){\n        if(not t->left) t->left\
    \ = new node(M());\n        t->left->val = M(t->val, t->left->val);\n\n      \
    \  if(not t->right) t->right = new node(M());\n        t->right->val = M(t->val,\
    \ t->right->val);\n\n        t->val = M();\n      }\n    }\n\n    void update(node\
    \ *t, int64_t l, int64_t r, int64_t x, int64_t y, const value_type &val){\n  \
    \    if(r - l == 1){\n        if(x <= l && r <= y) t->val = M(t->val, val);\n\
    \        umap[l] = t;\n        return;\n      }\n      if(r < x || y < l) return;\n\
    \      else if(x <= l && r <= y) t->val = M(t->val, val);\n      else{\n     \
    \   const int64_t m = (l + r) / 2;\n        propagate(t, l, r);\n        update(t->left,\
    \ l, m, x, y, val);\n        update(t->right, m, r, x, y, val);\n      }\n   \
    \ }\n\n    void get(node* t, int64_t l, int64_t r, int64_t x){\n      if(r - l\
    \ == 1){\n        umap[l] = t;\n        return;\n      }\n      propagate(t, l,\
    \ r);\n      int m = (l + r) / 2;\n      if(x < m) get(t->left, l, m, x);\n  \
    \    else get(t->right, m, r, x);\n    }\n\n  public:\n    dynamic_dual_segment_tree(int64_t\
    \ n):\n      depth(n > 1 ? 64 - __builtin_clzll(n - 1) + 1 : 1),\n      size(1LL\
    \ << depth),\n      hsize(size / 2)\n    {\n      root = new node(M());\n    }\n\
    \n    void update(int64_t s, int64_t t, value_type &x){\n      update(root, 0,\
    \ hsize, s, t, x);\n    }\n\n    value_type operator[](int64_t x){\n      get(root,\
    \ 0, hsize, x);\n      return umap[x]->val;\n    }\n  };\n}\n#line 2 \"Mylib/AlgebraicStructure/Monoid/sum.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  struct sum_monoid {\n   \
    \ using value_type = T;\n    value_type operator()() const {return 0;}\n    value_type\
    \ operator()(value_type a, value_type b) const {return a + b;}\n  };\n}\n#line\
    \ 3 \"Mylib/IO/input_tuples.cpp\"\n#include <vector>\n#include <tuple>\n#include\
    \ <utility>\n#include <initializer_list>\n#line 6 \"Mylib/IO/input_tuple.cpp\"\
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
    \ ...>(N);\n  }\n}\n#line 7 \"test/aoj/DSL_2_E/main.dynamic.test.cpp\"\n\nnamespace\
    \ hl = haar_lib;\n\nint main(){\n  int n, q; std::cin >> n >> q;\n\n  auto seg\
    \ = hl::dynamic_dual_segment_tree<hl::sum_monoid<int>>(n);\n\n  for(auto [type]\
    \ : hl::input_tuples<int>(q)){\n    if(type == 0){\n      int s, t, x; std::cin\
    \ >> s >> t >> x;\n      seg.update(s - 1, t, x);\n    }else{\n      int t; std::cin\
    \ >> t;\n      std::cout << seg[t - 1] << std::endl;\n    }\n  }\n\n  return 0;\n\
    }\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E\"\
    \n\n#include <iostream>\n#include \"Mylib/DataStructure/SegmentTree/dynamic_dual_segment_tree.cpp\"\
    \n#include \"Mylib/AlgebraicStructure/Monoid/sum.cpp\"\n#include \"Mylib/IO/input_tuples.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  int n, q; std::cin >> n >> q;\n\
    \n  auto seg = hl::dynamic_dual_segment_tree<hl::sum_monoid<int>>(n);\n\n  for(auto\
    \ [type] : hl::input_tuples<int>(q)){\n    if(type == 0){\n      int s, t, x;\
    \ std::cin >> s >> t >> x;\n      seg.update(s - 1, t, x);\n    }else{\n     \
    \ int t; std::cin >> t;\n      std::cout << seg[t - 1] << std::endl;\n    }\n\
    \  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/DataStructure/SegmentTree/dynamic_dual_segment_tree.cpp
  - Mylib/AlgebraicStructure/Monoid/sum.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  isVerificationFile: true
  path: test/aoj/DSL_2_E/main.dynamic.test.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/DSL_2_E/main.dynamic.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_E/main.dynamic.test.cpp
- /verify/test/aoj/DSL_2_E/main.dynamic.test.cpp.html
title: test/aoj/DSL_2_E/main.dynamic.test.cpp
---
