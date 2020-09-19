---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp
    title: Lazy segment tree
  - icon: ':x:'
    path: Mylib/AlgebraicStructure/Monoid/array.cpp
    title: Array monoid
  - icon: ':question:'
    path: Mylib/AlgebraicStructure/Monoid/sum.cpp
    title: Sum monoid
  - icon: ':x:'
    path: Mylib/AlgebraicStructure/MonoidAction/add_square_sum.cpp
    title: Range add / Range square sum
  - icon: ':question:'
    path: Mylib/IO/input_vector.cpp
    title: Mylib/IO/input_vector.cpp
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
    PROBLEM: https://yukicoder.me/problems/no/1099
    links:
    - https://yukicoder.me/problems/no/1099
  bundledCode: "#line 1 \"test/yukicoder/1099/main.test.cpp\"\n#define PROBLEM \"\
    https://yukicoder.me/problems/no/1099\"\n\n#include <iostream>\n#line 2 \"Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp\"\
    \n#include <vector>\n\nnamespace haar_lib {\n  template <typename MonoidGet, typename\
    \ MonoidUpdate, template <typename, typename> typename Connector>\n  class lazy_segment_tree\
    \ {\n    using value_type_get = typename MonoidGet::value_type;\n    using value_type_update\
    \ = typename MonoidUpdate::value_type;\n    Connector<MonoidGet, MonoidUpdate>\
    \ M;\n    MonoidGet M_get;\n    MonoidUpdate M_update;\n\n    const int depth,\
    \ size, hsize;\n    std::vector<value_type_get> data;\n    std::vector<value_type_update>\
    \ lazy;\n\n    void propagate(int i){\n      if(lazy[i] == M_update()) return;\n\
    \      if(i < hsize){\n        lazy[i << 1 | 0] = M_update(lazy[i], lazy[i <<\
    \ 1 | 0]);\n        lazy[i << 1 | 1] = M_update(lazy[i], lazy[i << 1 | 1]);\n\
    \      }\n      int len = hsize >> (31 - __builtin_clz(i));\n      data[i] = M(data[i],\
    \ lazy[i], len);\n      lazy[i] = M_update();\n    }\n\n    void propagate_top_down(int\
    \ i){\n      std::vector<int> temp;\n      while(i > 1){\n        i >>= 1;\n \
    \       temp.push_back(i);\n      }\n\n      for(auto it = temp.rbegin(); it !=\
    \ temp.rend(); ++it) propagate(*it);\n    }\n\n    void bottom_up(int i){\n  \
    \    while(i > 1){\n        i >>= 1;\n        propagate(i << 1 | 0);\n       \
    \ propagate(i << 1 | 1);\n        data[i] = M_get(data[i << 1 | 0], data[i <<\
    \ 1 | 1]);\n      }\n    }\n\n  public:\n    lazy_segment_tree(){}\n    lazy_segment_tree(int\
    \ n):\n      depth(n > 1 ? 32 - __builtin_clz(n - 1) + 1 : 1),\n      size(1 <<\
    \ depth),\n      hsize(size / 2),\n      data(size, M_get()),\n      lazy(size,\
    \ M_update())\n    {}\n\n    void update(int l, int r, const value_type_update\
    \ &x){\n      propagate_top_down(l + hsize);\n      if(r < hsize) propagate_top_down(r\
    \ + hsize);\n\n      int L = l + hsize, R = r + hsize;\n\n      while(L < R){\n\
    \        if(R & 1){\n          --R;\n          lazy[R] = M_update(x, lazy[R]);\n\
    \          propagate(R);\n        }\n        if(L & 1){\n          lazy[L] = M_update(x,\
    \ lazy[L]);\n          propagate(L);\n          ++L;\n        }\n        L >>=\
    \ 1;\n        R >>= 1;\n      }\n\n      bottom_up(l + hsize);\n      if(r < hsize)\
    \ bottom_up(r + hsize);\n    }\n\n    void update_at(int i, const value_type_update\
    \ &x){update(i, i + 1, x);}\n\n    value_type_get get(int l, int r){\n      propagate_top_down(l\
    \ + hsize);\n      if(r < hsize) propagate_top_down(r + hsize);\n\n      value_type_get\
    \ ret_left = M_get(), ret_right = M_get();\n\n      int L = l + hsize, R = r +\
    \ hsize;\n\n      while(L < R){\n        if(R & 1){\n          --R;\n        \
    \  propagate(R);\n          ret_right = M_get(data[R], ret_right);\n        }\n\
    \        if(L & 1){\n          propagate(L);\n          ret_left = M_get(ret_left,\
    \ data[L]);\n          ++L;\n        }\n        L >>= 1;\n        R >>= 1;\n \
    \     }\n\n      return M_get(ret_left, ret_right);\n    }\n\n    value_type_get\
    \ operator[](int i){return get(i, i + 1);}\n\n    template <typename T>\n    void\
    \ init(const T &val){\n      init_with_vector(std::vector<T>(hsize, val));\n \
    \   }\n\n    template <typename T>\n    void init_with_vector(const std::vector<T>\
    \ &val){\n      data.assign(size, M_get());\n      lazy.assign(size, M_update());\n\
    \      for(int i = 0; i < (int)val.size(); ++i) data[hsize + i] = (value_type_get)val[i];\n\
    \      for(int i = hsize - 1; i > 0; --i) data[i] = M_get(data[i << 1 | 0], data[i\
    \ << 1 | 1]);\n    }\n  };\n}\n#line 2 \"Mylib/AlgebraicStructure/Monoid/array.cpp\"\
    \n#include <array>\n\nnamespace haar_lib {\n  template <typename Monoid, int B>\n\
    \  struct array_monoid {\n    using value_type = std::array<typename Monoid::value_type,\
    \ B>;\n    const static Monoid M;\n\n    value_type operator()() const {\n   \
    \   value_type ret;\n      ret.fill(M());\n      return ret;\n    }\n\n    value_type\
    \ operator()(const value_type &a, const value_type &b) const {\n      value_type\
    \ ret;\n      for(int i = 0; i < B; ++i) ret[i] = M(a[i], b[i]);\n      return\
    \ ret;\n    }\n  };\n}\n#line 2 \"Mylib/AlgebraicStructure/Monoid/sum.cpp\"\n\n\
    namespace haar_lib {\n  template <typename T>\n  struct sum_monoid {\n    using\
    \ value_type = T;\n    value_type operator()() const {return 0;}\n    value_type\
    \ operator()(value_type a, value_type b) const {return a + b;}\n  };\n}\n#line\
    \ 2 \"Mylib/AlgebraicStructure/MonoidAction/add_square_sum.cpp\"\n#include <utility>\n\
    \nnamespace haar_lib {\n  template <typename MonoidGet, typename MonoidUpdate>\n\
    \  struct add_square_sum {\n    using value_type_get = typename MonoidGet::value_type;\n\
    \    using value_type_update = typename MonoidUpdate::value_type;\n\n    value_type_get\
    \ operator()(const value_type_get &a, const value_type_update &b, int len) const\
    \ {\n      return {std::get<0>(a) + b * len, std::get<1>(a) + b * (2 * std::get<0>(a)\
    \ + b * len)};\n    }\n  };\n}\n#line 4 \"Mylib/IO/input_vector.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename T>\n  std::vector<T> input_vector(int N){\n\
    \    std::vector<T> ret(N);\n    for(int i = 0; i < N; ++i) std::cin >> ret[i];\n\
    \    return ret;\n  }\n\n  template <typename T>\n  std::vector<std::vector<T>>\
    \ input_vector(int N, int M){\n    std::vector<std::vector<T>> ret(N);\n    for(int\
    \ i = 0; i < N; ++i) ret[i] = input_vector<T>(M);\n    return ret;\n  }\n}\n#line\
    \ 4 \"Mylib/IO/input_tuples.cpp\"\n#include <tuple>\n#line 6 \"Mylib/IO/input_tuples.cpp\"\
    \n#include <initializer_list>\n#line 6 \"Mylib/IO/input_tuple.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename T, size_t ... I>\n  static void input_tuple_helper(std::istream\
    \ &s, T &val, std::index_sequence<I ...>){\n    (void)std::initializer_list<int>{(void(s\
    \ >> std::get<I>(val)), 0) ...};\n  }\n\n  template <typename T, typename U>\n\
    \  std::istream& operator>>(std::istream &s, std::pair<T, U> &value){\n    s >>\
    \ value.first >> value.second;\n    return s;\n  }\n\n  template <typename ...\
    \ Args>\n  std::istream& operator>>(std::istream &s, std::tuple<Args ...> &value){\n\
    \    input_tuple_helper(s, value, std::make_index_sequence<sizeof ... (Args)>());\n\
    \    return s;\n  }\n}\n#line 8 \"Mylib/IO/input_tuples.cpp\"\n\nnamespace haar_lib\
    \ {\n  template <typename ... Args>\n  class InputTuples {\n    struct iter {\n\
    \      using value_type = std::tuple<Args ...>;\n      value_type value;\n   \
    \   bool fetched = false;\n      int N, c = 0;\n\n      value_type operator*(){\n\
    \        if(not fetched){\n          std::cin >> value;\n        }\n        return\
    \ value;\n      }\n\n      void operator++(){\n        ++c;\n        fetched =\
    \ false;\n      }\n\n      bool operator!=(iter &) const {\n        return c <\
    \ N;\n      }\n\n      iter(int N): N(N){}\n    };\n\n    int N;\n\n  public:\n\
    \    InputTuples(int N): N(N){}\n\n    iter begin() const {return iter(N);}\n\
    \    iter end() const {return iter(N);}\n  };\n\n  template <typename ... Args>\n\
    \  auto input_tuples(int N){\n    return InputTuples<Args ...>(N);\n  }\n}\n#line\
    \ 10 \"test/yukicoder/1099/main.test.cpp\"\n\nnamespace hl = haar_lib;\n\nint\
    \ main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  int N;\
    \ std::cin >> N;\n\n  auto A = hl::input_vector<int64_t>(N);\n\n  hl::lazy_segment_tree<\n\
    \    hl::array_monoid<hl::sum_monoid<int64_t>, 2>,\n    hl::sum_monoid<int64_t>,\n\
    \    hl::add_square_sum> seg(N);\n\n  for(int i = 0; i < N; ++i) seg.update_at(i,\
    \ A[i]);\n\n  int Q; std::cin >> Q;\n\n  for(auto [type] : hl::input_tuples<int>(Q)){\n\
    \    if(type == 1){\n      int l, r, x; std::cin >> l >> r >> x;\n      seg.update(l\
    \ - 1, r, x);\n    }else{\n      int l, r; std::cin >> l >> r;\n      std::cout\
    \ << std::get<1>(seg.get(l - 1, r)) << \"\\n\";\n    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1099\"\n\n#include <iostream>\n\
    #include \"Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp\"\n#include \"\
    Mylib/AlgebraicStructure/Monoid/array.cpp\"\n#include \"Mylib/AlgebraicStructure/Monoid/sum.cpp\"\
    \n#include \"Mylib/AlgebraicStructure/MonoidAction/add_square_sum.cpp\"\n#include\
    \ \"Mylib/IO/input_vector.cpp\"\n#include \"Mylib/IO/input_tuples.cpp\"\n\nnamespace\
    \ hl = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int N; std::cin >> N;\n\n  auto A = hl::input_vector<int64_t>(N);\n\n  hl::lazy_segment_tree<\n\
    \    hl::array_monoid<hl::sum_monoid<int64_t>, 2>,\n    hl::sum_monoid<int64_t>,\n\
    \    hl::add_square_sum> seg(N);\n\n  for(int i = 0; i < N; ++i) seg.update_at(i,\
    \ A[i]);\n\n  int Q; std::cin >> Q;\n\n  for(auto [type] : hl::input_tuples<int>(Q)){\n\
    \    if(type == 1){\n      int l, r, x; std::cin >> l >> r >> x;\n      seg.update(l\
    \ - 1, r, x);\n    }else{\n      int l, r; std::cin >> l >> r;\n      std::cout\
    \ << std::get<1>(seg.get(l - 1, r)) << \"\\n\";\n    }\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp
  - Mylib/AlgebraicStructure/Monoid/array.cpp
  - Mylib/AlgebraicStructure/Monoid/sum.cpp
  - Mylib/AlgebraicStructure/MonoidAction/add_square_sum.cpp
  - Mylib/IO/input_vector.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  isVerificationFile: true
  path: test/yukicoder/1099/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-18 18:43:57+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yukicoder/1099/main.test.cpp
layout: document
redirect_from:
- /verify/test/yukicoder/1099/main.test.cpp
- /verify/test/yukicoder/1099/main.test.cpp.html
title: test/yukicoder/1099/main.test.cpp
---
