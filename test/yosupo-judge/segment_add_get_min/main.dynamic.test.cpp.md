---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/DataStructure/ConvexHullTrick/dynamic_lichao_segment_tree.cpp
    title: Dynamic LiChao segment tree
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
    PROBLEM: https://judge.yosupo.jp/problem/segment_add_get_min
    links:
    - https://judge.yosupo.jp/problem/segment_add_get_min
  bundledCode: "#line 1 \"test/yosupo-judge/segment_add_get_min/main.dynamic.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/segment_add_get_min\"\n\n\
    #include <iostream>\n#include <climits>\n#line 2 \"Mylib/DataStructure/ConvexHullTrick/dynamic_lichao_segment_tree.cpp\"\
    \n#include <utility>\n#include <optional>\n\nnamespace haar_lib {\n  template\
    \ <typename T, typename Comparator>\n  class dynamic_lichao_segment_tree {\n \
    \ public:\n    using value_type = T;\n\n  private:\n    using line = std::pair<T,\
    \ T>;\n\n    struct node {\n      std::optional<line> value;\n      int64_t l,\
    \ r;\n      node *l_child = nullptr, *r_child = nullptr;\n      node(std::optional<line>\
    \ value, int64_t l, int64_t r): value(value), l(l), r(r){}\n    };\n\n    Comparator\
    \ cmp_ = Comparator();\n    int64_t MIN_, MAX_;\n    node *root_ = nullptr;\n\n\
    \    T chm(const T &a, const T &b) const {\n      return cmp_(a, b) ? a : b;\n\
    \    }\n\n  public:\n    dynamic_lichao_segment_tree(){}\n    dynamic_lichao_segment_tree(int64_t\
    \ MIN, int64_t MAX): MIN_(MIN), MAX_(MAX){}\n\n    T apply(const line &l, const\
    \ T &x) const {\n      return l.first * x + l.second;\n    }\n\n  private:\n \
    \   node* update(node *t, line new_line, int64_t l, int64_t r){\n      if(not\
    \ t){\n        return t = new node(new_line, l, r);\n      }\n\n      if(not t->value){\n\
    \        t->value = new_line;\n        return t;\n      }\n\n      if(l + 1 ==\
    \ r){\n        if(cmp_(apply(new_line, l), apply(*(t->value), l))){\n        \
    \  t->value = new_line;\n        }\n        return t;\n      }\n\n      const\
    \ auto m = (l + r) / 2;\n\n      bool left = cmp_(apply(new_line, l), apply(*(t->value),\
    \ l));\n      bool mid = cmp_(apply(new_line, m), apply(*(t->value), m));\n  \
    \    bool right = cmp_(apply(new_line, r), apply(*(t->value), r));\n\n      if(left\
    \ and right){\n        t->value = new_line;\n        return t;\n      }\n\n  \
    \    if(not left and not right){\n        return t;\n      }\n\n      if(mid){\n\
    \        std::swap(*(t->value), new_line);\n      }\n\n      if(left != mid){\n\
    \        t->l_child = update(t->l_child, new_line, l, m);\n      }else{\n    \
    \    t->r_child = update(t->r_child, new_line, m, r);\n      }\n\n      return\
    \ t;\n    }\n\n    node* update_segment(node *t, line new_line, int64_t l, int64_t\
    \ r, int64_t sl, int64_t sr){\n      if(r < sl or sr < l) return t;\n      if(sl\
    \ <= l and r <= sr){\n        return t = update(t, new_line, l, r);\n      }\n\
    \n      if(l + 1 == r){\n        return t;\n      }\n\n      if(not t) t = new\
    \ node(std::nullopt, l, r);\n      else{\n        if(t->value){\n          if(\n\
    \            cmp_(apply(*(t->value), l), apply(new_line, l)) and\n           \
    \ cmp_(apply(*(t->value), r), apply(new_line, r))\n          ){\n            return\
    \ t;\n          }\n        }\n      }\n\n      const auto m = (l + r) / 2;\n\n\
    \      t->l_child = update_segment(t->l_child, new_line, l, m, sl, sr);\n    \
    \  t->r_child = update_segment(t->r_child, new_line, m, r, sl, sr);\n\n      return\
    \ t;\n    }\n\n  public:\n    void add_line(T a, T b){\n      root_ = update(root_,\
    \ std::make_pair(a, b), MIN_, MAX_);\n    }\n\n    void add_segment(int64_t l,\
    \ int64_t r, T a, T b){\n      root_ = update_segment(root_, std::make_pair(a,\
    \ b), MIN_, MAX_, l, r);\n    }\n\n    auto operator()(const int64_t &x) const\
    \ {\n      std::optional<T> ret;\n      node *cur = root_;\n\n      while(cur){\n\
    \        if(cur->value){\n          if(not ret) ret = apply(*(cur->value), x);\n\
    \          else ret = chm(*ret, apply(*(cur->value), x));\n        }\n\n     \
    \   const auto m = (cur->l + cur->r) / 2;\n        if(x < m) cur = cur->l_child;\n\
    \        else cur = cur->r_child;\n      }\n\n      return ret;\n    }\n  };\n\
    }\n#line 3 \"Mylib/IO/input_tuples.cpp\"\n#include <vector>\n#include <tuple>\n\
    #line 6 \"Mylib/IO/input_tuples.cpp\"\n#include <initializer_list>\n#line 6 \"\
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
    \ ...>(N);\n  }\n}\n#line 7 \"test/yosupo-judge/segment_add_get_min/main.dynamic.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int N, Q; std::cin >> N >> Q;\n\n  auto lc = hl::dynamic_lichao_segment_tree<int64_t,\
    \ std::less<>>(INT_MIN, INT_MAX);\n\n  for(auto [l, r, a, b] : hl::input_tuples<int64_t,\
    \ int64_t, int64_t, int64_t>(N)){\n    lc.add_segment(l, r, a, b);\n  }\n\n  for(auto\
    \ [type] : hl::input_tuples<int>(Q)){\n    if(type == 0){\n      int64_t l, r,\
    \ a, b; std::cin >> l >> r >> a >> b;\n      lc.add_segment(l, r, a, b);\n   \
    \ }else{\n      int64_t p; std::cin >> p;\n      auto ans = lc(p);\n      if(ans)\
    \ std::cout << *ans << \"\\n\";\n      else std::cout << \"INFINITY\" << \"\\\
    n\";\n    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/segment_add_get_min\"\n\
    \n#include <iostream>\n#include <climits>\n#include \"Mylib/DataStructure/ConvexHullTrick/dynamic_lichao_segment_tree.cpp\"\
    \n#include \"Mylib/IO/input_tuples.cpp\"\n\nnamespace hl = haar_lib;\n\nint main(){\n\
    \  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  int N, Q; std::cin\
    \ >> N >> Q;\n\n  auto lc = hl::dynamic_lichao_segment_tree<int64_t, std::less<>>(INT_MIN,\
    \ INT_MAX);\n\n  for(auto [l, r, a, b] : hl::input_tuples<int64_t, int64_t, int64_t,\
    \ int64_t>(N)){\n    lc.add_segment(l, r, a, b);\n  }\n\n  for(auto [type] : hl::input_tuples<int>(Q)){\n\
    \    if(type == 0){\n      int64_t l, r, a, b; std::cin >> l >> r >> a >> b;\n\
    \      lc.add_segment(l, r, a, b);\n    }else{\n      int64_t p; std::cin >> p;\n\
    \      auto ans = lc(p);\n      if(ans) std::cout << *ans << \"\\n\";\n      else\
    \ std::cout << \"INFINITY\" << \"\\n\";\n    }\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/DataStructure/ConvexHullTrick/dynamic_lichao_segment_tree.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  isVerificationFile: true
  path: test/yosupo-judge/segment_add_get_min/main.dynamic.test.cpp
  requiredBy: []
  timestamp: '2020-09-28 09:27:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo-judge/segment_add_get_min/main.dynamic.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-judge/segment_add_get_min/main.dynamic.test.cpp
- /verify/test/yosupo-judge/segment_add_get_min/main.dynamic.test.cpp.html
title: test/yosupo-judge/segment_add_get_min/main.dynamic.test.cpp
---
