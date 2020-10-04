---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/AlgebraicStructure/Group/dihedral.cpp
    title: Dihedral group
  - icon: ':question:'
    path: Mylib/DataStructure/SegmentTree/segment_tree.cpp
    title: Segment tree
  - icon: ':question:'
    path: Mylib/IO/input_tuple.cpp
    title: Input tuple
  - icon: ':question:'
    path: Mylib/IO/input_tuples.cpp
    title: Input tuples
  - icon: ':question:'
    path: Mylib/IO/input_vector.cpp
    title: Input vector
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0390
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0390
  bundledCode: "#line 1 \"test/aoj/0390/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0390\"\
    \n\n#include <iostream>\n#include <variant>\n#line 3 \"Mylib/IO/input_vector.cpp\"\
    \n#include <vector>\n\nnamespace haar_lib {\n  template <typename T>\n  std::vector<T>\
    \ input_vector(int N){\n    std::vector<T> ret(N);\n    for(int i = 0; i < N;\
    \ ++i) std::cin >> ret[i];\n    return ret;\n  }\n\n  template <typename T>\n\
    \  std::vector<std::vector<T>> input_vector(int N, int M){\n    std::vector<std::vector<T>>\
    \ ret(N);\n    for(int i = 0; i < N; ++i) ret[i] = input_vector<T>(M);\n    return\
    \ ret;\n  }\n}\n#line 4 \"Mylib/IO/input_tuples.cpp\"\n#include <tuple>\n#include\
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
    \ ...>(N);\n  }\n}\n#line 4 \"Mylib/AlgebraicStructure/Group/dihedral.cpp\"\n\n\
    namespace haar_lib {\n  namespace dihedral_group_impl {\n    struct R {\n    \
    \  int value = 0;\n      friend std::ostream& operator<<(std::ostream &s, const\
    \ R &a){\n        s << \"R(\" << a.value << \")\";\n        return s;\n      }\n\
    \      R(){}\n      R(int value): value(value){}\n    };\n\n    struct S {\n \
    \     int value = 0;\n      friend std::ostream& operator<<(std::ostream &s, const\
    \ S &a){\n        s << \"S(\" << a.value << \")\";\n        return s;\n      }\n\
    \      S(){}\n      S(int value): value(value){}\n    };\n  }\n\n  template <const\
    \ int &K>\n  struct dihedral_group {\n    using R = dihedral_group_impl::R;\n\
    \    using S = dihedral_group_impl::S;\n    using value_type = std::variant<R,\
    \ S>;\n\n    value_type operator()() const {\n      return R(0);\n    }\n\n  \
    \  value_type operator()(const value_type &a, const value_type &b) const {\n \
    \     if(std::holds_alternative<R>(a)){\n        if(std::holds_alternative<R>(b)){\n\
    \          return R((std::get<R>(a).value + std::get<R>(b).value) % K);\n    \
    \    }else{\n          return S((std::get<S>(b).value - std::get<R>(a).value +\
    \ K) % K);\n        }\n      }else{\n        if(std::holds_alternative<R>(b)){\n\
    \          return S((std::get<S>(a).value + std::get<R>(b).value) % K);\n    \
    \    }else{\n          return R((std::get<S>(b).value - std::get<S>(a).value +\
    \ K) % K);\n        }\n      }\n    }\n\n    value_type inv(const value_type &a)\
    \ const {\n      if(std::holds_alternative<R>(a)){\n        const int i = std::get<R>(a).value;\n\
    \        return R(i == 0 ? 0 : K - i);\n      }else{\n        return a;\n    \
    \  }\n    }\n  };\n}\n#line 3 \"Mylib/DataStructure/SegmentTree/segment_tree.cpp\"\
    \n#include <algorithm>\n#include <functional>\n\nnamespace haar_lib {\n  template\
    \ <typename Monoid>\n  class segment_tree {\n  public:\n    using value_type =\
    \ typename Monoid::value_type;\n\n  private:\n    Monoid M_;\n    int depth_,\
    \ size_, hsize_;\n    std::vector<value_type> data_;\n\n  public:\n    segment_tree(){}\n\
    \    segment_tree(int n):\n      depth_(n > 1 ? 32 - __builtin_clz(n - 1) + 1\
    \ : 1),\n      size_(1 << depth_), hsize_(size_ / 2),\n      data_(size_, M_())\n\
    \    {}\n\n    auto operator[](int i) const {return data_[hsize_ + i];}\n\n  \
    \  auto fold(int x, int y) const {\n      value_type ret_left = M_();\n      value_type\
    \ ret_right = M_();\n\n      int l = x + hsize_, r = y + hsize_;\n      while(l\
    \ < r){\n        if(r & 1) ret_right = M_(data_[--r], ret_right);\n        if(l\
    \ & 1) ret_left = M_(ret_left, data_[l++]);\n        l >>= 1, r >>= 1;\n     \
    \ }\n\n      return M_(ret_left, ret_right);\n    }\n\n    auto fold_all() const\
    \ {\n      return data_[1];\n    }\n\n    void set(int i, const value_type &x){\n\
    \      i += hsize_;\n      data_[i] = x;\n      while(i > 1) i >>= 1, data_[i]\
    \ = M_(data_[i << 1 | 0], data_[i << 1 | 1]);\n    }\n\n    void update(int i,\
    \ const value_type &x){\n      i += hsize_;\n      data_[i] = M_(data_[i], x);\n\
    \      while(i > 1) i >>= 1, data_[i] = M_(data_[i << 1 | 0], data_[i << 1 | 1]);\n\
    \    }\n\n    template <typename T>\n    void init_with_vector(const std::vector<T>\
    \ &val){\n      data_.assign(size_, M_());\n      for(int i = 0; i < (int)val.size();\
    \ ++i) data_[hsize_ + i] = val[i];\n      for(int i = hsize_; --i >= 1;) data_[i]\
    \ = M_(data_[i << 1 | 0], data_[i << 1 | 1]);\n    }\n\n    template <typename\
    \ T>\n    void init(const T &val){\n      init_with_vector(std::vector<value_type>(hsize_,\
    \ val));\n    }\n\n  private:\n    template <bool Lower, typename F>\n    int\
    \ bound(const int l, const int r, value_type x, F f) const {\n      std::vector<int>\
    \ pl, pr;\n      int L = l + hsize_;\n      int R = r + hsize_;\n      while(L\
    \ < R){\n        if(R & 1) pr.push_back(--R);\n        if(L & 1) pl.push_back(L++);\n\
    \        L >>= 1, R >>= 1;\n      }\n\n      std::reverse(pr.begin(), pr.end());\n\
    \      pl.insert(pl.end(), pr.begin(), pr.end());\n\n      value_type a = M_();\n\
    \n      for(int i : pl){\n        auto b = M_(a, data_[i]);\n\n        if((Lower\
    \ and not f(b, x)) or (not Lower and f(x, b))){\n          while(i < hsize_){\n\
    \            const auto c = M_(a, data_[i << 1 | 0]);\n            if((Lower and\
    \ not f(c, x)) or (not Lower and f(x, c))){\n              i = i << 1 | 0;\n \
    \           }else{\n              a = c;\n              i = i << 1 | 1;\n    \
    \        }\n          }\n\n          return i - hsize_;\n        }\n\n       \
    \ a = b;\n      }\n\n      return r;\n    }\n\n  public:\n    template <typename\
    \ F = std::less<value_type>>\n    int lower_bound(int l, int r, value_type x,\
    \ F f = F()) const {\n      return bound<true>(l, r, x, f);\n    }\n\n    template\
    \ <typename F = std::less<value_type>>\n    int upper_bound(int l, int r, value_type\
    \ x, F f = F()) const {\n      return bound<false>(l, r, x, f);\n    }\n  };\n\
    }\n#line 9 \"test/aoj/0390/main.test.cpp\"\n\nnamespace hl = haar_lib;\n\nstatic\
    \ int K;\nusing M = hl::dihedral_group<K>;\n\nint main(){\n  int N, Q; std::cin\
    \ >> K >> N >> Q;\n  auto A = hl::input_vector<int>(N);\n\n  hl::segment_tree<M>\
    \ seg(N);\n\n  for(int i = 0; i < N; ++i){\n    if(A[i] > 0){\n      seg.set(i,\
    \ M::R({A[i] % K}));\n    }else if(A[i] < 0){\n      seg.set(i, M::R({A[i] % K\
    \ + K}));\n    }else{\n      seg.set(i, M::S({0}));\n    }\n  }\n\n  for(auto\
    \ [L, R] : hl::input_tuples<int, int>(Q)){\n    --L, --R;\n\n    auto x = seg[L];\n\
    \    auto y = seg[R];\n    seg.set(L, y);\n    seg.set(R, x);\n\n    auto res\
    \ = seg.fold_all();\n\n    if(std::holds_alternative<M::R>(res)){\n      int ans\
    \ = (K - std::get<M::R>(res).value) % K + 1;\n      std::cout << ans << \"\\n\"\
    ;\n    }else{\n      int ans = -(std::get<M::S>(res).value + 1);\n      std::cout\
    \ << ans << \"\\n\";\n    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0390\"\
    \n\n#include <iostream>\n#include <variant>\n#include \"Mylib/IO/input_vector.cpp\"\
    \n#include \"Mylib/IO/input_tuples.cpp\"\n#include \"Mylib/AlgebraicStructure/Group/dihedral.cpp\"\
    \n#include \"Mylib/DataStructure/SegmentTree/segment_tree.cpp\"\n\nnamespace hl\
    \ = haar_lib;\n\nstatic int K;\nusing M = hl::dihedral_group<K>;\n\nint main(){\n\
    \  int N, Q; std::cin >> K >> N >> Q;\n  auto A = hl::input_vector<int>(N);\n\n\
    \  hl::segment_tree<M> seg(N);\n\n  for(int i = 0; i < N; ++i){\n    if(A[i] >\
    \ 0){\n      seg.set(i, M::R({A[i] % K}));\n    }else if(A[i] < 0){\n      seg.set(i,\
    \ M::R({A[i] % K + K}));\n    }else{\n      seg.set(i, M::S({0}));\n    }\n  }\n\
    \n  for(auto [L, R] : hl::input_tuples<int, int>(Q)){\n    --L, --R;\n\n    auto\
    \ x = seg[L];\n    auto y = seg[R];\n    seg.set(L, y);\n    seg.set(R, x);\n\n\
    \    auto res = seg.fold_all();\n\n    if(std::holds_alternative<M::R>(res)){\n\
    \      int ans = (K - std::get<M::R>(res).value) % K + 1;\n      std::cout <<\
    \ ans << \"\\n\";\n    }else{\n      int ans = -(std::get<M::S>(res).value + 1);\n\
    \      std::cout << ans << \"\\n\";\n    }\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/IO/input_vector.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  - Mylib/AlgebraicStructure/Group/dihedral.cpp
  - Mylib/DataStructure/SegmentTree/segment_tree.cpp
  isVerificationFile: true
  path: test/aoj/0390/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-28 13:26:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/0390/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/0390/main.test.cpp
- /verify/test/aoj/0390/main.test.cpp.html
title: test/aoj/0390/main.test.cpp
---
