---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/AlgebraicStructure/Monoid/sum.cpp
    title: Sum monoid
  - icon: ':heavy_check_mark:'
    path: Mylib/AlgebraicStructure/MonoidAction/add_square_sum.cpp
    title: Range add / Range square sum
  - icon: ':heavy_check_mark:'
    path: Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp
    title: Lazy segment tree
  - icon: ':heavy_check_mark:'
    path: Mylib/IO/input_tuple.cpp
    title: Input tuple
  - icon: ':heavy_check_mark:'
    path: Mylib/IO/input_tuples.cpp
    title: Input tuples
  - icon: ':question:'
    path: Mylib/IO/input_vector.cpp
    title: Input vector
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/1099
    links:
    - https://yukicoder.me/problems/no/1099
  bundledCode: "#line 1 \"test/yukicoder/1099/main.test.cpp\"\n#define PROBLEM \"\
    https://yukicoder.me/problems/no/1099\"\n\n#include <iostream>\n#line 2 \"Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp\"\
    \n#include <vector>\n#include <cassert>\n\nnamespace haar_lib {\n  template <typename\
    \ Monoid>\n  class lazy_segment_tree {\n  public:\n    using monoid_get = typename\
    \ Monoid::monoid_get;\n    using monoid_update = typename Monoid::monoid_update;\n\
    \    using value_type_get = typename monoid_get::value_type;\n    using value_type_update\
    \ = typename monoid_update::value_type;\n\n  private:\n    Monoid M_;\n    monoid_get\
    \ M_get_;\n    monoid_update M_update_;\n\n    int depth_, size_, hsize_;\n  \
    \  std::vector<value_type_get> data_;\n    std::vector<value_type_update> lazy_;\n\
    \n    void propagate(int i){\n      if(lazy_[i] == M_update_()) return;\n    \
    \  if(i < hsize_){\n        lazy_[i << 1 | 0] = M_update_(lazy_[i], lazy_[i <<\
    \ 1 | 0]);\n        lazy_[i << 1 | 1] = M_update_(lazy_[i], lazy_[i << 1 | 1]);\n\
    \      }\n      const int len = hsize_ >> (31 - __builtin_clz(i));\n      data_[i]\
    \ = M_(data_[i], lazy_[i], len);\n      lazy_[i] = M_update_();\n    }\n\n   \
    \ void propagate_top_down(int i){\n      std::vector<int> temp;\n      while(i\
    \ > 1){\n        i >>= 1;\n        temp.push_back(i);\n      }\n\n      for(auto\
    \ it = temp.rbegin(); it != temp.rend(); ++it) propagate(*it);\n    }\n\n    void\
    \ bottom_up(int i){\n      while(i > 1){\n        i >>= 1;\n        propagate(i\
    \ << 1 | 0);\n        propagate(i << 1 | 1);\n        data_[i] = M_get_(data_[i\
    \ << 1 | 0], data_[i << 1 | 1]);\n      }\n    }\n\n  public:\n    lazy_segment_tree(){}\n\
    \    lazy_segment_tree(int n):\n      depth_(n > 1 ? 32 - __builtin_clz(n - 1)\
    \ + 1 : 1),\n      size_(1 << depth_),\n      hsize_(size_ / 2),\n      data_(size_,\
    \ M_get_()),\n      lazy_(size_, M_update_())\n    {}\n\n    void update(int l,\
    \ int r, const value_type_update &x){\n      assert(0 <= l and l <= r and r <=\
    \ hsize_);\n      propagate_top_down(l + hsize_);\n      if(r < hsize_) propagate_top_down(r\
    \ + hsize_);\n\n      int L = l + hsize_, R = r + hsize_;\n\n      while(L < R){\n\
    \        if(R & 1){\n          --R;\n          lazy_[R] = M_update_(x, lazy_[R]);\n\
    \          propagate(R);\n        }\n        if(L & 1){\n          lazy_[L] =\
    \ M_update_(x, lazy_[L]);\n          propagate(L);\n          ++L;\n        }\n\
    \        L >>= 1;\n        R >>= 1;\n      }\n\n      bottom_up(l + hsize_);\n\
    \      if(r < hsize_) bottom_up(r + hsize_);\n    }\n\n    void update(int i,\
    \ const value_type_update &x){update(i, i + 1, x);}\n\n    value_type_get fold(int\
    \ l, int r){\n      assert(0 <= l and l <= r and r <= hsize_);\n      propagate_top_down(l\
    \ + hsize_);\n      if(r < hsize_) propagate_top_down(r + hsize_);\n\n      value_type_get\
    \ ret_left = M_get_(), ret_right = M_get_();\n\n      int L = l + hsize_, R =\
    \ r + hsize_;\n\n      while(L < R){\n        if(R & 1){\n          --R;\n   \
    \       propagate(R);\n          ret_right = M_get_(data_[R], ret_right);\n  \
    \      }\n        if(L & 1){\n          propagate(L);\n          ret_left = M_get_(ret_left,\
    \ data_[L]);\n          ++L;\n        }\n        L >>= 1;\n        R >>= 1;\n\
    \      }\n\n      return M_get_(ret_left, ret_right);\n    }\n\n    value_type_get\
    \ fold_all(){\n      return fold(0, hsize_);\n    }\n\n    value_type_get operator[](int\
    \ i){return fold(i, i + 1);}\n\n    template <typename T>\n    void init(const\
    \ T &val){\n      init_with_vector(std::vector<T>(hsize_, val));\n    }\n\n  \
    \  template <typename T>\n    void init_with_vector(const std::vector<T> &val){\n\
    \      data_.assign(size_, M_get_());\n      lazy_.assign(size_, M_update_());\n\
    \      for(int i = 0; i < (int)val.size(); ++i) data_[hsize_ + i] = (value_type_get)val[i];\n\
    \      for(int i = hsize_; --i > 0;) data_[i] = M_get_(data_[i << 1 | 0], data_[i\
    \ << 1 | 1]);\n    }\n  };\n}\n#line 2 \"Mylib/AlgebraicStructure/Monoid/sum.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  struct sum_monoid {\n   \
    \ using value_type = T;\n    value_type operator()() const {return 0;}\n    value_type\
    \ operator()(value_type a, value_type b) const {return a + b;}\n  };\n}\n#line\
    \ 2 \"Mylib/AlgebraicStructure/MonoidAction/add_square_sum.cpp\"\n#include <utility>\n\
    \nnamespace haar_lib {\n  template <typename MonoidUpdate>\n  struct add_square_sum\
    \ {\n    struct internal_type {\n      using value_type = typename MonoidUpdate::value_type;\n\
    \      value_type sum, square_sum;\n      internal_type(value_type value): sum(value),\
    \ square_sum(value * value){}\n      internal_type(value_type sum, value_type\
    \ square_sum): sum(sum), square_sum(square_sum){}\n    };\n\n    struct monoid_get\
    \ {\n      using value_type = internal_type;\n      value_type operator()() const\
    \ {return {0, 0};};\n      value_type operator()(const value_type &a, const value_type\
    \ &b){return {a.sum + b.sum, a.square_sum + b.square_sum};}\n    };\n\n    using\
    \ monoid_update = MonoidUpdate;\n    using value_type_get = typename monoid_get::value_type;\n\
    \    using value_type_update = typename MonoidUpdate::value_type;\n\n    value_type_get\
    \ operator()(const value_type_get &a, const value_type_update &b, int len) const\
    \ {\n      return {\n              a.sum + b * len,\n              a.square_sum\
    \ + b * (2 * a.sum + b * len)\n      };\n    }\n  };\n}\n#line 4 \"Mylib/IO/input_vector.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  std::vector<T> input_vector(int\
    \ N){\n    std::vector<T> ret(N);\n    for(int i = 0; i < N; ++i) std::cin >>\
    \ ret[i];\n    return ret;\n  }\n\n  template <typename T>\n  std::vector<std::vector<T>>\
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
    \ 9 \"test/yukicoder/1099/main.test.cpp\"\n\nnamespace hl = haar_lib;\n\nusing\
    \ sum = hl::sum_monoid<int64_t>;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int N; std::cin >> N;\n\n  auto A = hl::input_vector<int64_t>(N);\n\n  hl::lazy_segment_tree<hl::add_square_sum<sum>>\
    \ seg(N);\n  seg.init_with_vector(A);\n\n  int Q; std::cin >> Q;\n\n  for(auto\
    \ [type] : hl::input_tuples<int>(Q)){\n    if(type == 1){\n      int l, r, x;\
    \ std::cin >> l >> r >> x;\n      seg.update(l - 1, r, x);\n    }else{\n     \
    \ int l, r; std::cin >> l >> r;\n      std::cout << seg.fold(l - 1, r).square_sum\
    \ << \"\\n\";\n    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/1099\"\n\n#include <iostream>\n\
    #include \"Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp\"\n#include \"\
    Mylib/AlgebraicStructure/Monoid/sum.cpp\"\n#include \"Mylib/AlgebraicStructure/MonoidAction/add_square_sum.cpp\"\
    \n#include \"Mylib/IO/input_vector.cpp\"\n#include \"Mylib/IO/input_tuples.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nusing sum = hl::sum_monoid<int64_t>;\n\nint main(){\n\
    \  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  int N; std::cin\
    \ >> N;\n\n  auto A = hl::input_vector<int64_t>(N);\n\n  hl::lazy_segment_tree<hl::add_square_sum<sum>>\
    \ seg(N);\n  seg.init_with_vector(A);\n\n  int Q; std::cin >> Q;\n\n  for(auto\
    \ [type] : hl::input_tuples<int>(Q)){\n    if(type == 1){\n      int l, r, x;\
    \ std::cin >> l >> r >> x;\n      seg.update(l - 1, r, x);\n    }else{\n     \
    \ int l, r; std::cin >> l >> r;\n      std::cout << seg.fold(l - 1, r).square_sum\
    \ << \"\\n\";\n    }\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp
  - Mylib/AlgebraicStructure/Monoid/sum.cpp
  - Mylib/AlgebraicStructure/MonoidAction/add_square_sum.cpp
  - Mylib/IO/input_vector.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  isVerificationFile: true
  path: test/yukicoder/1099/main.test.cpp
  requiredBy: []
  timestamp: '2020-10-15 01:51:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yukicoder/1099/main.test.cpp
layout: document
redirect_from:
- /verify/test/yukicoder/1099/main.test.cpp
- /verify/test/yukicoder/1099/main.test.cpp.html
title: test/yukicoder/1099/main.test.cpp
---
