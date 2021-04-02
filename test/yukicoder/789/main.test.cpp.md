---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/AlgebraicStructure/Monoid/sum.cpp
    title: Sum monoid
  - icon: ':heavy_check_mark:'
    path: Mylib/DataStructure/SegmentTree/dynamic_segment_tree.cpp
    title: Dynamic segment tree
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
    PROBLEM: https://yukicoder.me/problems/no/789
    links:
    - https://yukicoder.me/problems/no/789
  bundledCode: "#line 1 \"test/yukicoder/789/main.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/789\"\
    \n\n#include <iostream>\n#line 2 \"Mylib/DataStructure/SegmentTree/dynamic_segment_tree.cpp\"\
    \n#include <cstdint>\n\nnamespace haar_lib {\n  template <typename Monoid>\n \
    \ class dynamic_segment_tree {\n  public:\n    using value_type = typename Monoid::value_type;\n\
    \n  private:\n    struct node {\n      value_type val;\n      node *left = nullptr,\
    \ *right = nullptr;\n      node(const value_type &val): val(val) {}\n    };\n\n\
    \    Monoid M_;\n    int64_t depth_, size_, hsize_;\n    node *root_ = nullptr;\n\
    \n    value_type eval(node *t) const {\n      return t ? t->val : M_();\n    }\n\
    \n    node* update(node *t, int64_t l, int64_t r, int64_t pos, const value_type\
    \ &val){\n      if(r - l == 1){\n        if(t) t->val = val;\n        else t =\
    \ new node(val);\n      }else{\n        const int64_t m = (l + r) / 2;\n     \
    \   if(not t) t = new node(val);\n        if(pos < m) t->left = update(t->left,\
    \ l, m, pos, val);\n        else t->right = update(t->right, m, r, pos, val);\n\
    \        t->val = M_(eval(t->left), eval(t->right));\n      }\n      return t;\n\
    \    }\n\n    value_type get(node* t, int64_t l, int64_t r, int64_t x, int64_t\
    \ y) const {\n      if(not t) return M_();\n      if(x <= l and r <= y) return\
    \ t ? t->val : M_();\n      if(r < x or y < l) return M_();\n      int64_t m =\
    \ (l + r) >> 1;\n      return M_(get(t->left, l, m, x, y), get(t->right, m, r,\
    \ x, y));\n    }\n\n  public:\n    dynamic_segment_tree(){}\n    dynamic_segment_tree(int64_t\
    \ n):\n      depth_(n > 1 ? 64 - __builtin_clzll(n - 1) + 1 : 1),\n      size_(1LL\
    \ << depth_),\n      hsize_(size_ / 2)\n    {\n      root_ = new node(M_());\n\
    \    }\n\n    void set(int64_t i, const value_type &x){\n      update(root_, 0,\
    \ hsize_, i, x);\n    }\n\n    void update(int64_t i, const value_type &x){\n\
    \      set(i, M_((*this)[i], x));\n    }\n\n    value_type fold(int64_t l, int64_t\
    \ r) const {\n      return get(root_, 0, hsize_, l, r);\n    }\n\n    value_type\
    \ operator[](int64_t i) const {\n      return fold(i, i + 1);\n    }\n  };\n}\n\
    #line 2 \"Mylib/AlgebraicStructure/Monoid/sum.cpp\"\n\nnamespace haar_lib {\n\
    \  template <typename T>\n  struct sum_monoid {\n    using value_type = T;\n \
    \   value_type operator()() const {return 0;}\n    value_type operator()(value_type\
    \ a, value_type b) const {return a + b;}\n  };\n}\n#line 3 \"Mylib/IO/input_tuples.cpp\"\
    \n#include <vector>\n#include <tuple>\n#include <utility>\n#include <initializer_list>\n\
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
    \ N){\n    return InputTuples<Args ...>(N);\n  }\n}\n#line 7 \"test/yukicoder/789/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int n; std::cin >> n;\n\n  hl::dynamic_segment_tree<hl::sum_monoid<int64_t>>\
    \ seg(1000000001);\n\n  int64_t ans = 0;\n\n  for(auto [q, x, y] : hl::input_tuples<int,\
    \ int, int>(n)){\n    if(q == 0){\n      seg.update(x, y);\n    }else{\n     \
    \ ans += seg.fold(x, y + 1);\n    }\n  }\n\n  std::cout << ans << \"\\n\";\n\n\
    \  return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/789\"\n\n#include <iostream>\n\
    #include \"Mylib/DataStructure/SegmentTree/dynamic_segment_tree.cpp\"\n#include\
    \ \"Mylib/AlgebraicStructure/Monoid/sum.cpp\"\n#include \"Mylib/IO/input_tuples.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int n; std::cin >> n;\n\n  hl::dynamic_segment_tree<hl::sum_monoid<int64_t>>\
    \ seg(1000000001);\n\n  int64_t ans = 0;\n\n  for(auto [q, x, y] : hl::input_tuples<int,\
    \ int, int>(n)){\n    if(q == 0){\n      seg.update(x, y);\n    }else{\n     \
    \ ans += seg.fold(x, y + 1);\n    }\n  }\n\n  std::cout << ans << \"\\n\";\n\n\
    \  return 0;\n}\n"
  dependsOn:
  - Mylib/DataStructure/SegmentTree/dynamic_segment_tree.cpp
  - Mylib/AlgebraicStructure/Monoid/sum.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  isVerificationFile: true
  path: test/yukicoder/789/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-28 09:27:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yukicoder/789/main.test.cpp
layout: document
redirect_from:
- /verify/test/yukicoder/789/main.test.cpp
- /verify/test/yukicoder/789/main.test.cpp.html
title: test/yukicoder/789/main.test.cpp
---
