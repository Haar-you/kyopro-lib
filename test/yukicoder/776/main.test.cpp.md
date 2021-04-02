---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/AlgebraicStructure/Monoid/max_partial_sum.cpp
    title: Max partial sum monoid
  - icon: ':heavy_check_mark:'
    path: Mylib/DataStructure/SegmentTree/segment_tree.cpp
    title: Segment tree
  - icon: ':heavy_check_mark:'
    path: Mylib/IO/input_tuple.cpp
    title: Input tuple
  - icon: ':heavy_check_mark:'
    path: Mylib/IO/input_tuples.cpp
    title: Input tuples
  - icon: ':heavy_check_mark:'
    path: Mylib/IO/input_vector.cpp
    title: Input vector
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/776
    links:
    - https://yukicoder.me/problems/no/776
  bundledCode: "#line 1 \"test/yukicoder/776/main.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/776\"\
    \n\n#include <iostream>\n#include <vector>\n#include <string>\n#include <algorithm>\n\
    #include <climits>\n#line 2 \"Mylib/AlgebraicStructure/Monoid/max_partial_sum.cpp\"\
    \n#include <optional>\n#line 5 \"Mylib/AlgebraicStructure/Monoid/max_partial_sum.cpp\"\
    \n\nnamespace haar_lib {\n  namespace max_partial_sum_monoid_impl {\n    template\
    \ <typename T>\n    struct max_partial_sum {\n      T sum, left_max, right_max,\
    \ partial_max;\n      max_partial_sum(){}\n      max_partial_sum(T x): sum(x),\
    \ left_max(x), right_max(x), partial_max(x){}\n      max_partial_sum(T sum, T\
    \ left_max, T right_max, T partial_max):\n        sum(sum), left_max(left_max),\
    \ right_max(right_max), partial_max(partial_max){}\n\n      friend std::ostream&\
    \ operator<<(std::ostream &s, const max_partial_sum &a){\n        s << \"(\" <<\
    \ \"sum: \" << a.sum << \", \"\n          << \"left_max: \" << a.left_max << \"\
    , \"\n          << \"right_max: \" << a.right_max << \", \"\n          << \"partial_max:\
    \ \" << a.partial_max << \")\";\n        return s;\n      }\n    };\n  }\n\n \
    \ template <typename T>\n  struct max_partial_sum_monoid {\n    using max_partial_sum\
    \ = max_partial_sum_monoid_impl::max_partial_sum<T>;\n    using value_type = std::optional<max_partial_sum>;\n\
    \n    value_type operator()() const {\n      return std::nullopt;\n    }\n\n \
    \   value_type operator()(const value_type &a, const value_type &b) const {\n\
    \      if(not a) return b;\n      if(not b) return a;\n\n      return max_partial_sum(\n\
    \        a->sum + b->sum,\n        std::max(a->left_max, a->sum + std::max(b->left_max,\
    \ b->sum)),\n        std::max(b->right_max, b->sum + std::max(a->right_max, a->sum)),\n\
    \        std::max({a->partial_max, b->partial_max, a->right_max + b->left_max})\n\
    \      );\n    }\n  };\n}\n#line 4 \"Mylib/DataStructure/SegmentTree/segment_tree.cpp\"\
    \n#include <functional>\n#include <cassert>\n\nnamespace haar_lib {\n  template\
    \ <typename Monoid>\n  class segment_tree {\n  public:\n    using value_type =\
    \ typename Monoid::value_type;\n\n  private:\n    Monoid M_;\n    int depth_,\
    \ size_, hsize_;\n    std::vector<value_type> data_;\n\n  public:\n    segment_tree(){}\n\
    \    segment_tree(int n):\n      depth_(n > 1 ? 32 - __builtin_clz(n - 1) + 1\
    \ : 1),\n      size_(1 << depth_), hsize_(size_ / 2),\n      data_(size_, M_())\n\
    \    {}\n\n    auto operator[](int i) const {\n      assert(0 <= i and i < hsize_);\n\
    \      return data_[hsize_ + i];\n    }\n\n    auto fold(int l, int r) const {\n\
    \      assert(0 <= l and l <= r and r <= hsize_);\n      value_type ret_left =\
    \ M_();\n      value_type ret_right = M_();\n\n      int L = l + hsize_, R = r\
    \ + hsize_;\n      while(L < R){\n        if(R & 1) ret_right = M_(data_[--R],\
    \ ret_right);\n        if(L & 1) ret_left = M_(ret_left, data_[L++]);\n      \
    \  L >>= 1, R >>= 1;\n      }\n\n      return M_(ret_left, ret_right);\n    }\n\
    \n    auto fold_all() const {\n      return data_[1];\n    }\n\n    void set(int\
    \ i, const value_type &x){\n      assert(0 <= i and i < hsize_);\n      i += hsize_;\n\
    \      data_[i] = x;\n      while(i > 1) i >>= 1, data_[i] = M_(data_[i << 1 |\
    \ 0], data_[i << 1 | 1]);\n    }\n\n    void update(int i, const value_type &x){\n\
    \      assert(0 <= i and i < hsize_);\n      i += hsize_;\n      data_[i] = M_(data_[i],\
    \ x);\n      while(i > 1) i >>= 1, data_[i] = M_(data_[i << 1 | 0], data_[i <<\
    \ 1 | 1]);\n    }\n\n    template <typename T>\n    void init_with_vector(const\
    \ std::vector<T> &val){\n      data_.assign(size_, M_());\n      for(int i = 0;\
    \ i < (int)val.size(); ++i) data_[hsize_ + i] = val[i];\n      for(int i = hsize_;\
    \ --i >= 1;) data_[i] = M_(data_[i << 1 | 0], data_[i << 1 | 1]);\n    }\n\n \
    \   template <typename T>\n    void init(const T &val){\n      init_with_vector(std::vector<value_type>(hsize_,\
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
    }\n#line 4 \"Mylib/IO/input_tuples.cpp\"\n#include <tuple>\n#include <utility>\n\
    #include <initializer_list>\n#line 6 \"Mylib/IO/input_tuple.cpp\"\n\nnamespace\
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
    \ 4 \"Mylib/IO/input_vector.cpp\"\n\nnamespace haar_lib {\n  template <typename\
    \ T>\n  std::vector<T> input_vector(int N){\n    std::vector<T> ret(N);\n    for(int\
    \ i = 0; i < N; ++i) std::cin >> ret[i];\n    return ret;\n  }\n\n  template <typename\
    \ T>\n  std::vector<std::vector<T>> input_vector(int N, int M){\n    std::vector<std::vector<T>>\
    \ ret(N);\n    for(int i = 0; i < N; ++i) ret[i] = input_vector<T>(M);\n    return\
    \ ret;\n  }\n}\n#line 12 \"test/yukicoder/776/main.test.cpp\"\n\nnamespace hl\
    \ = haar_lib;\n\nusing M = hl::max_partial_sum_monoid<int64_t>;\n\nint main(){\n\
    \  int N, Q; std::cin >> N >> Q;\n\n  hl::segment_tree<M> seg(N);\n\n  auto a\
    \ = hl::input_vector<int64_t>(N);\n  for(int i = 0; i < N; ++i){\n    seg.set(i,\
    \ M::max_partial_sum(a[i]));\n  }\n\n  for(auto [type] : hl::input_tuples<std::string>(Q)){\n\
    \    if(type == \"set\"){\n      int i, x; std::cin >> i >> x;\n      --i;\n \
    \     seg.set(i, M::max_partial_sum(x));\n      a[i] = x;\n    }else{\n      int\
    \ l1, l2, r1, r2; std::cin >> l1 >> l2 >> r1 >> r2;\n      --l1, --l2, --r1, --r2;\n\
    \n      r1 = std::max(l1, r1);\n      l2 = std::min(l2, r2);\n\n      int64_t\
    \ ans = LLONG_MIN;\n\n      auto f =\n        [&](int L1, int L2, int R1, int\
    \ R2){\n          auto ret =\n            seg.fold(L1, L2 + 1).value_or(M::max_partial_sum(0)).right_max\
    \ +\n            seg.fold(std::min(L2 + 1, R1), R1).value_or(M::max_partial_sum(0)).sum\
    \ +\n            seg.fold(R1, R2 + 1).value_or(M::max_partial_sum(0)).left_max;\n\
    \n          if(L2 == R1) ret -= a[L2];\n\n          return ret;\n        };\n\n\
    \      if(l2 <= r1){\n        ans = f(l1, l2, r1, r2);\n      }else{\n       \
    \ if(l1 <= r1) ans = std::max(ans, f(l1, r1, r1, r2));\n        if(l2 <= r2) ans\
    \ = std::max(ans, f(l1, l2, l2, r2));\n        if(r1 <= l2) ans = std::max(ans,\
    \ seg.fold(r1, l2 + 1)->partial_max);\n      }\n\n      std::cout << ans << \"\
    \\n\";\n    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/776\"\n\n#include <iostream>\n\
    #include <vector>\n#include <string>\n#include <algorithm>\n#include <climits>\n\
    #include \"Mylib/AlgebraicStructure/Monoid/max_partial_sum.cpp\"\n#include \"\
    Mylib/DataStructure/SegmentTree/segment_tree.cpp\"\n#include \"Mylib/IO/input_tuples.cpp\"\
    \n#include \"Mylib/IO/input_vector.cpp\"\n\nnamespace hl = haar_lib;\n\nusing\
    \ M = hl::max_partial_sum_monoid<int64_t>;\n\nint main(){\n  int N, Q; std::cin\
    \ >> N >> Q;\n\n  hl::segment_tree<M> seg(N);\n\n  auto a = hl::input_vector<int64_t>(N);\n\
    \  for(int i = 0; i < N; ++i){\n    seg.set(i, M::max_partial_sum(a[i]));\n  }\n\
    \n  for(auto [type] : hl::input_tuples<std::string>(Q)){\n    if(type == \"set\"\
    ){\n      int i, x; std::cin >> i >> x;\n      --i;\n      seg.set(i, M::max_partial_sum(x));\n\
    \      a[i] = x;\n    }else{\n      int l1, l2, r1, r2; std::cin >> l1 >> l2 >>\
    \ r1 >> r2;\n      --l1, --l2, --r1, --r2;\n\n      r1 = std::max(l1, r1);\n \
    \     l2 = std::min(l2, r2);\n\n      int64_t ans = LLONG_MIN;\n\n      auto f\
    \ =\n        [&](int L1, int L2, int R1, int R2){\n          auto ret =\n    \
    \        seg.fold(L1, L2 + 1).value_or(M::max_partial_sum(0)).right_max +\n  \
    \          seg.fold(std::min(L2 + 1, R1), R1).value_or(M::max_partial_sum(0)).sum\
    \ +\n            seg.fold(R1, R2 + 1).value_or(M::max_partial_sum(0)).left_max;\n\
    \n          if(L2 == R1) ret -= a[L2];\n\n          return ret;\n        };\n\n\
    \      if(l2 <= r1){\n        ans = f(l1, l2, r1, r2);\n      }else{\n       \
    \ if(l1 <= r1) ans = std::max(ans, f(l1, r1, r1, r2));\n        if(l2 <= r2) ans\
    \ = std::max(ans, f(l1, l2, l2, r2));\n        if(r1 <= l2) ans = std::max(ans,\
    \ seg.fold(r1, l2 + 1)->partial_max);\n      }\n\n      std::cout << ans << \"\
    \\n\";\n    }\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/AlgebraicStructure/Monoid/max_partial_sum.cpp
  - Mylib/DataStructure/SegmentTree/segment_tree.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  - Mylib/IO/input_vector.cpp
  isVerificationFile: true
  path: test/yukicoder/776/main.test.cpp
  requiredBy: []
  timestamp: '2020-10-15 01:51:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yukicoder/776/main.test.cpp
layout: document
redirect_from:
- /verify/test/yukicoder/776/main.test.cpp
- /verify/test/yukicoder/776/main.test.cpp.html
title: test/yukicoder/776/main.test.cpp
---
