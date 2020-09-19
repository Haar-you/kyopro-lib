---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/IO/input_tuples.cpp
    title: Mylib/IO/input_tuples.cpp
  - icon: ':question:'
    path: Mylib/IO/input_tuple.cpp
    title: Mylib/IO/input_tuple.cpp
  - icon: ':heavy_check_mark:'
    path: Mylib/AlgebraicStructure/Monoid/rolling_hash.cpp
    title: Rolling hash monoid
  - icon: ':heavy_check_mark:'
    path: Mylib/AlgebraicStructure/Monoid/pair.cpp
    title: Pair monoid
  - icon: ':question:'
    path: Mylib/DataStructure/SegmentTree/segment_tree.cpp
    title: Segment tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2444
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2444
  bundledCode: "#line 1 \"test/aoj/2444/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2444\"\
    \n\n#include <iostream>\n#include <string>\n#include <set>\n#include <array>\n\
    #line 3 \"Mylib/IO/input_tuples.cpp\"\n#include <vector>\n#include <tuple>\n#include\
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
    \ ...>(N);\n  }\n}\n#line 4 \"Mylib/AlgebraicStructure/Monoid/rolling_hash.cpp\"\
    \n\nnamespace haar_lib {\n  namespace rolling_hash_monoid_impl {\n    template\
    \ <int64_t Mod, int64_t Base>\n    struct inner_value {\n      int64_t hash, power;\n\
    \      inner_value(){}\n      inner_value(int64_t hash, int64_t power): hash(hash),\
    \ power(power){}\n      inner_value(int64_t a): hash(a % Mod), power(Base){}\n\
    \    };\n  }\n\n  template <int64_t Mod, int Base>\n  struct rolling_hash_monoid\
    \ {\n    using value_type = rolling_hash_monoid_impl::inner_value<Mod, Base>;\n\
    \n    value_type operator()() const {\n      value_type ret(0, 1);\n      return\
    \ ret;\n    }\n\n    value_type operator()(const value_type &a, const value_type\
    \ &b) const {\n      value_type ret;\n      ret.hash = (a.hash + b.hash * a.power\
    \ % Mod) % Mod;\n      ret.power = a.power * b.power % Mod;\n      return ret;\n\
    \    }\n  };\n}\n#line 3 \"Mylib/AlgebraicStructure/Monoid/pair.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename Monoid1, typename Monoid2>\n  struct pair_monoid\
    \ {\n    using value_type = std::pair<typename Monoid1::value_type, typename Monoid2::value_type>;\n\
    \    const static Monoid1 M1;\n    const static Monoid2 M2;\n\n    value_type\
    \ operator()() const {\n      return {M1(), M2()};\n    }\n\n    value_type operator()(const\
    \ value_type &a, const value_type &b) const {\n      return {M1(a.first, b.first),\
    \ M2(a.second, b.second)};\n    }\n  };\n}\n#line 3 \"Mylib/DataStructure/SegmentTree/segment_tree.cpp\"\
    \n#include <algorithm>\n#include <functional>\n\nnamespace haar_lib {\n  template\
    \ <typename Monoid>\n  class segment_tree {\n    using value_type = typename Monoid::value_type;\n\
    \    const static Monoid M;\n\n    int depth, size, hsize;\n    std::vector<value_type>\
    \ data;\n\n  public:\n    segment_tree(){}\n    segment_tree(int n):\n      depth(n\
    \ > 1 ? 32 - __builtin_clz(n - 1) + 1 : 1),\n      size(1 << depth), hsize(size\
    \ / 2),\n      data(size, M())\n    {}\n\n    auto operator[](int i) const {return\
    \ data[hsize + i];}\n\n    auto get(int x, int y) const {\n      value_type ret_left\
    \ = M();\n      value_type ret_right = M();\n\n      int l = x + hsize, r = y\
    \ + hsize;\n      while(l < r){\n        if(r & 1) ret_right = M(data[--r], ret_right);\n\
    \        if(l & 1) ret_left = M(ret_left, data[l++]);\n        l >>= 1, r >>=\
    \ 1;\n      }\n\n      return M(ret_left, ret_right);\n    }\n\n    void update(int\
    \ i, const value_type &x){\n      i += hsize;\n      data[i] = x;\n      while(i\
    \ > 1) i >>= 1, data[i] = M(data[i << 1 | 0], data[i << 1 | 1]);\n    }\n\n  \
    \  template <typename T>\n    void init_with_vector(const std::vector<T> &val){\n\
    \      data.assign(size, M());\n      for(int i = 0; i < (int)val.size(); ++i)\
    \ data[hsize + i] = val[i];\n      for(int i = hsize - 1; i >= 1; --i) data[i]\
    \ = M(data[i << 1 | 0], data[i << 1 | 1]);\n    }\n\n    template <typename T>\n\
    \    void init(const T &val){\n      init_with_vector(std::vector<value_type>(hsize,\
    \ val));\n    }\n\n  private:\n    template <bool Lower, typename F>\n    int\
    \ bound(const int l, const int r, value_type x, F f) const {\n      std::vector<int>\
    \ pl, pr;\n      int L = l + hsize;\n      int R = r + hsize;\n      while(L <\
    \ R){\n        if(R & 1) pr.push_back(--R);\n        if(L & 1) pl.push_back(L++);\n\
    \        L >>= 1, R >>= 1;\n      }\n\n      std::reverse(pr.begin(), pr.end());\n\
    \      pl.insert(pl.end(), pr.begin(), pr.end());\n\n      value_type a = M();\n\
    \n      for(int i : pl){\n        auto b = M(a, data[i]);\n\n        if((Lower\
    \ and not f(b, x)) or (not Lower and f(x, b))){\n          while(i < hsize){\n\
    \            if(auto c = M(a, data[i << 1 | 0]); (Lower and not f(c, x)) or (not\
    \ Lower and f(x, c))){\n              i = i << 1 | 0;\n            }else{\n  \
    \            a = c;\n              i = i << 1 | 1;\n            }\n          }\n\
    \n          return i - hsize;\n        }\n\n        a = b;\n      }\n\n      return\
    \ r;\n    }\n\n  public:\n    template <typename F = std::less<value_type>>\n\
    \    int lower_bound(int l, int r, value_type x, F f = F()) const {\n      return\
    \ bound<true>(l, r, x, f);\n    }\n\n    template <typename F = std::less<value_type>>\n\
    \    int upper_bound(int l, int r, value_type x, F f = F()) const {\n      return\
    \ bound<false>(l, r, x, f);\n    }\n  };\n}\n#line 11 \"test/aoj/2444/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  using Monoid1 = hl::rolling_hash_monoid<1000000007,\
    \ 33>;\n  using Monoid2 = hl::rolling_hash_monoid<1000000007, 100>;\n\n  int n,\
    \ m; std::cin >> n >> m;\n  std::string s; std::cin >> s;\n\n  hl::segment_tree<hl::pair_monoid<Monoid1,\
    \ Monoid2>> seg(n);\n  for(int i = 0; i < n; ++i){\n    seg.update(i, {Monoid1::value_type(s[i]),\
    \ Monoid2::value_type(s[i])});\n  }\n\n  std::set<std::pair<int64_t, int64_t>>\
    \ set;\n  int l = 0, r = 1;\n\n  for(int i = 0; i < m; ++i){\n    std::string\
    \ q; std::cin >> q;\n\n    if(q[0] == 'L'){\n      if(q[1] == '+') ++l;\n    \
    \  else --l;\n    }else{\n      if(q[1] == '+') ++r;\n      else --r;\n    }\n\
    \n    auto t = seg.get(l, r);\n    set.emplace(t.first.hash, t.second.hash);\n\
    \  }\n\n  std::cout << set.size() << \"\\n\";\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2444\"\
    \n\n#include <iostream>\n#include <string>\n#include <set>\n#include <array>\n\
    #include \"Mylib/IO/input_tuples.cpp\"\n#include \"Mylib/AlgebraicStructure/Monoid/rolling_hash.cpp\"\
    \n#include \"Mylib/AlgebraicStructure/Monoid/pair.cpp\"\n#include \"Mylib/DataStructure/SegmentTree/segment_tree.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  using Monoid1 = hl::rolling_hash_monoid<1000000007,\
    \ 33>;\n  using Monoid2 = hl::rolling_hash_monoid<1000000007, 100>;\n\n  int n,\
    \ m; std::cin >> n >> m;\n  std::string s; std::cin >> s;\n\n  hl::segment_tree<hl::pair_monoid<Monoid1,\
    \ Monoid2>> seg(n);\n  for(int i = 0; i < n; ++i){\n    seg.update(i, {Monoid1::value_type(s[i]),\
    \ Monoid2::value_type(s[i])});\n  }\n\n  std::set<std::pair<int64_t, int64_t>>\
    \ set;\n  int l = 0, r = 1;\n\n  for(int i = 0; i < m; ++i){\n    std::string\
    \ q; std::cin >> q;\n\n    if(q[0] == 'L'){\n      if(q[1] == '+') ++l;\n    \
    \  else --l;\n    }else{\n      if(q[1] == '+') ++r;\n      else --r;\n    }\n\
    \n    auto t = seg.get(l, r);\n    set.emplace(t.first.hash, t.second.hash);\n\
    \  }\n\n  std::cout << set.size() << \"\\n\";\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  - Mylib/AlgebraicStructure/Monoid/rolling_hash.cpp
  - Mylib/AlgebraicStructure/Monoid/pair.cpp
  - Mylib/DataStructure/SegmentTree/segment_tree.cpp
  isVerificationFile: true
  path: test/aoj/2444/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-18 01:14:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/2444/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/2444/main.test.cpp
- /verify/test/aoj/2444/main.test.cpp.html
title: test/aoj/2444/main.test.cpp
---
