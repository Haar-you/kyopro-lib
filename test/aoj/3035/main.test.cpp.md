---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/IO/input_vector.cpp
    title: Mylib/IO/input_vector.cpp
  - icon: ':question:'
    path: Mylib/IO/input_tuples.cpp
    title: Mylib/IO/input_tuples.cpp
  - icon: ':question:'
    path: Mylib/IO/input_tuple.cpp
    title: Mylib/IO/input_tuple.cpp
  - icon: ':question:'
    path: Mylib/AlgebraicStructure/Monoid/sum.cpp
    title: Sum monoid
  - icon: ':question:'
    path: Mylib/AlgebraicStructure/Monoid/max.cpp
    title: Max monoid
  - icon: ':question:'
    path: Mylib/AlgebraicStructure/Monoid/min.cpp
    title: Min monoid
  - icon: ':heavy_check_mark:'
    path: Mylib/AlgebraicStructure/Monoid/with_count.cpp
    title: Mylib/AlgebraicStructure/Monoid/with_count.cpp
  - icon: ':heavy_check_mark:'
    path: Mylib/AlgebraicStructure/MonoidAction/add_max_with_count.cpp
    title: Range add / Range max with count
  - icon: ':heavy_check_mark:'
    path: Mylib/AlgebraicStructure/MonoidAction/add_min_with_count.cpp
    title: Range add / Range min with count
  - icon: ':question:'
    path: Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp
    title: Lazy segment tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3035
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3035
  bundledCode: "#line 1 \"test/aoj/3035/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3035\"\
    \n\n#include <iostream>\n#include <algorithm>\n#include <map>\n#include <climits>\n\
    #line 3 \"Mylib/IO/input_vector.cpp\"\n#include <vector>\n\nnamespace haar_lib\
    \ {\n  template <typename T>\n  std::vector<T> input_vector(int N){\n    std::vector<T>\
    \ ret(N);\n    for(int i = 0; i < N; ++i) std::cin >> ret[i];\n    return ret;\n\
    \  }\n\n  template <typename T>\n  std::vector<std::vector<T>> input_vector(int\
    \ N, int M){\n    std::vector<std::vector<T>> ret(N);\n    for(int i = 0; i <\
    \ N; ++i) ret[i] = input_vector<T>(M);\n    return ret;\n  }\n}\n#line 4 \"Mylib/IO/input_tuples.cpp\"\
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
    \ ...>(N);\n  }\n}\n#line 2 \"Mylib/AlgebraicStructure/Monoid/sum.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename T>\n  struct sum_monoid {\n    using value_type\
    \ = T;\n    value_type operator()() const {return 0;}\n    value_type operator()(value_type\
    \ a, value_type b) const {return a + b;}\n  };\n}\n#line 3 \"Mylib/AlgebraicStructure/Monoid/max.cpp\"\
    \n#include <optional>\n\nnamespace haar_lib {\n  template <typename T>\n  struct\
    \ max_monoid {\n    using value_type = std::optional<T>;\n\n    value_type operator()()\
    \ const {return {};}\n    value_type operator()(const value_type &a, const value_type\
    \ &b) const {\n      if(not a) return b;\n      if(not b) return a;\n      return\
    \ {std::max(*a, *b)};\n    }\n  };\n}\n#line 4 \"Mylib/AlgebraicStructure/Monoid/min.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  struct min_monoid {\n   \
    \ using value_type = std::optional<T>;\n\n    value_type operator()() const {return\
    \ {};}\n    value_type operator()(const value_type &a, const value_type &b) const\
    \ {\n      if(not a) return b;\n      if(not b) return a;\n      return {std::min(*a,\
    \ *b)};\n    }\n  };\n}\n#line 3 \"Mylib/AlgebraicStructure/Monoid/with_count.cpp\"\
    \n#include <cstdint>\n\nnamespace haar_lib {\n  namespace with_count_impl {\n\
    \    template <typename T>\n    struct inner_value {\n      T value;\n      int64_t\
    \ count;\n      inner_value(): value(T()), count(0){}\n      inner_value(T value):\
    \ value(value), count(1){}\n      inner_value(T value, int64_t count): value(value),\
    \ count(count){}\n    };\n  }\n\n  template <typename Monoid>\n  struct with_count\
    \ {\n    using value_type = with_count_impl::inner_value<typename Monoid::value_type>;\n\
    \    const static Monoid M;\n\n    value_type operator()() const {\n      return\
    \ {M(), 0};\n    }\n\n    value_type operator()(const value_type &a, const value_type\
    \ &b) const {\n      if(a.value == b.value) return {a.value, a.count + b.count};\n\
    \      if(M(a.value, b.value) == a.value) return a;\n      return b;\n    }\n\
    \  };\n}\n#line 2 \"Mylib/AlgebraicStructure/MonoidAction/add_max_with_count.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename MonoidGet, typename MonoidUpdate>\n\
    \  struct add_max_with_count {\n    using value_type_get = typename MonoidGet::value_type;\n\
    \    using value_type_update = typename MonoidUpdate::value_type;\n\n    value_type_get\
    \ operator()(const value_type_get &a, const value_type_update &b, int) const {\n\
    \      return {a.value ? a.value.value() + b : a.value, a.count};\n    }\n  };\n\
    }\n#line 2 \"Mylib/AlgebraicStructure/MonoidAction/add_min_with_count.cpp\"\n\n\
    namespace haar_lib {\n  template <typename MonoidGet, typename MonoidUpdate>\n\
    \  struct add_min_with_count {\n    using value_type_get = typename MonoidGet::value_type;\n\
    \    using value_type_update = typename MonoidUpdate::value_type;\n\n    value_type_get\
    \ operator()(const value_type_get &a, const value_type_update &b, int) const {\n\
    \      return {a.value ? a.value.value() + b : a.value, a.count};\n    }\n  };\n\
    }\n#line 3 \"Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename MonoidGet, typename MonoidUpdate, template\
    \ <typename, typename> typename Connector>\n  class lazy_segment_tree {\n    using\
    \ value_type_get = typename MonoidGet::value_type;\n    using value_type_update\
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
    \ << 1 | 1]);\n    }\n  };\n}\n#line 16 \"test/aoj/3035/main.test.cpp\"\n\nnamespace\
    \ hl = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int H, W, Q; std::cin >> H >> W >> Q;\n  auto A = hl::input_vector<int64_t>(H);\n\
    \  auto B = hl::input_vector<int64_t>(W);\n\n  auto seg_h_max = hl::lazy_segment_tree<hl::with_count<hl::max_monoid<int64_t>>,\
    \ hl::sum_monoid<int64_t>, hl::add_max_with_count>(H);\n  auto seg_h_min = hl::lazy_segment_tree<hl::with_count<hl::min_monoid<int64_t>>,\
    \ hl::sum_monoid<int64_t>, hl::add_min_with_count>(H);\n  auto seg_w_max = hl::lazy_segment_tree<hl::with_count<hl::max_monoid<int64_t>>,\
    \ hl::sum_monoid<int64_t>, hl::add_max_with_count>(W);\n  auto seg_w_min = hl::lazy_segment_tree<hl::with_count<hl::min_monoid<int64_t>>,\
    \ hl::sum_monoid<int64_t>, hl::add_min_with_count>(W);\n\n  seg_h_max.init_with_vector(A);\n\
    \  seg_h_min.init_with_vector(A);\n  seg_w_max.init_with_vector(B);\n  seg_w_min.init_with_vector(B);\n\
    \n  for(auto [type] : hl::input_tuples<int>(Q)){\n    switch(type){\n    case\
    \ 1: {\n      int a, b, v; std::cin >> a >> b >> v;\n      --a;\n      seg_h_max.update(a,\
    \ b, v);\n      seg_h_min.update(a, b, v);\n      break;\n    }\n\n    case 2:\
    \ {\n      int c, d, v; std::cin >> c >> d >> v;\n      --c;\n      seg_w_max.update(c,\
    \ d, v);\n      seg_w_min.update(c, d, v);\n      break;\n    }\n\n    case 3:\
    \ {\n      int64_t a, b, c, d; std::cin >> a >> b >> c >> d;\n      --a, --c;\n\
    \n      std::map<int64_t, int64_t> m;\n\n      auto x = std::vector{seg_h_max.get(a,\
    \ b), seg_h_min.get(a, b)};\n      auto y = std::vector{seg_w_max.get(c, d), seg_w_min.get(c,\
    \ d)};\n\n      if(x[0].value == x[1].value) x.pop_back();\n      if(y[0].value\
    \ == y[1].value) y.pop_back();\n\n      int64_t M = LLONG_MAX;\n      for(auto\
    \ p : x){\n        for(auto q : y){\n          M = std::min(M, *p.value * *q.value);\n\
    \        }\n      }\n\n      if(M == 0){\n        int64_t p = 0;\n        for(auto\
    \ e : x) if(e.value == 0) p += e.count;\n        int64_t q = 0;\n        for(auto\
    \ e : y) if(e.value == 0) q += e.count;\n        m[0] = (b - a) * q + (d - c)\
    \ * p - p * q;\n      }else{\n        for(auto p : x){\n          for(auto q :\
    \ y){\n            m[*p.value * *q.value] += p.count * q.count;\n          }\n\
    \        }\n      }\n\n      std::cout << m.begin()->first << \" \" << m.begin()->second\
    \ << \"\\n\";\n\n      break;\n    }\n\n    case 4: {\n      int64_t a, b, c,\
    \ d; std::cin >> a >> b >> c >> d;\n      --a, --c;\n\n      std::map<int64_t,\
    \ int64_t> m;\n\n      auto x = std::vector{seg_h_max.get(a, b), seg_h_min.get(a,\
    \ b)};\n      auto y = std::vector{seg_w_max.get(c, d), seg_w_min.get(c, d)};\n\
    \n      if(x[0].value == x[1].value) x.pop_back();\n      if(y[0].value == y[1].value)\
    \ y.pop_back();\n\n      int64_t M = LLONG_MIN;\n      for(auto p : x){\n    \
    \    for(auto q : y){\n          M = std::max(M, *p.value * *q.value);\n     \
    \   }\n      }\n\n      if(M == 0){\n        int64_t p = 0;\n        for(auto\
    \ e : x) if(e.value == 0) p += e.count;\n        int64_t q = 0;\n        for(auto\
    \ e : y) if(e.value == 0) q += e.count;\n        m[0] = (b - a) * q + (d - c)\
    \ * p - p * q;\n      }else{\n        for(auto p : x){\n          for(auto q :\
    \ y){\n            m[*p.value * *q.value] += p.count * q.count;\n          }\n\
    \        }\n      }\n\n      std::cout << m.rbegin()->first << \" \" << m.rbegin()->second\
    \ << \"\\n\";\n\n      break;\n    }\n    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3035\"\
    \n\n#include <iostream>\n#include <algorithm>\n#include <map>\n#include <climits>\n\
    #include \"Mylib/IO/input_vector.cpp\"\n#include \"Mylib/IO/input_tuples.cpp\"\
    \n#include \"Mylib/AlgebraicStructure/Monoid/sum.cpp\"\n#include \"Mylib/AlgebraicStructure/Monoid/max.cpp\"\
    \n#include \"Mylib/AlgebraicStructure/Monoid/min.cpp\"\n#include \"Mylib/AlgebraicStructure/Monoid/with_count.cpp\"\
    \n#include \"Mylib/AlgebraicStructure/MonoidAction/add_max_with_count.cpp\"\n\
    #include \"Mylib/AlgebraicStructure/MonoidAction/add_min_with_count.cpp\"\n#include\
    \ \"Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp\"\n\nnamespace hl =\
    \ haar_lib;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int H, W, Q; std::cin >> H >> W >> Q;\n  auto A = hl::input_vector<int64_t>(H);\n\
    \  auto B = hl::input_vector<int64_t>(W);\n\n  auto seg_h_max = hl::lazy_segment_tree<hl::with_count<hl::max_monoid<int64_t>>,\
    \ hl::sum_monoid<int64_t>, hl::add_max_with_count>(H);\n  auto seg_h_min = hl::lazy_segment_tree<hl::with_count<hl::min_monoid<int64_t>>,\
    \ hl::sum_monoid<int64_t>, hl::add_min_with_count>(H);\n  auto seg_w_max = hl::lazy_segment_tree<hl::with_count<hl::max_monoid<int64_t>>,\
    \ hl::sum_monoid<int64_t>, hl::add_max_with_count>(W);\n  auto seg_w_min = hl::lazy_segment_tree<hl::with_count<hl::min_monoid<int64_t>>,\
    \ hl::sum_monoid<int64_t>, hl::add_min_with_count>(W);\n\n  seg_h_max.init_with_vector(A);\n\
    \  seg_h_min.init_with_vector(A);\n  seg_w_max.init_with_vector(B);\n  seg_w_min.init_with_vector(B);\n\
    \n  for(auto [type] : hl::input_tuples<int>(Q)){\n    switch(type){\n    case\
    \ 1: {\n      int a, b, v; std::cin >> a >> b >> v;\n      --a;\n      seg_h_max.update(a,\
    \ b, v);\n      seg_h_min.update(a, b, v);\n      break;\n    }\n\n    case 2:\
    \ {\n      int c, d, v; std::cin >> c >> d >> v;\n      --c;\n      seg_w_max.update(c,\
    \ d, v);\n      seg_w_min.update(c, d, v);\n      break;\n    }\n\n    case 3:\
    \ {\n      int64_t a, b, c, d; std::cin >> a >> b >> c >> d;\n      --a, --c;\n\
    \n      std::map<int64_t, int64_t> m;\n\n      auto x = std::vector{seg_h_max.get(a,\
    \ b), seg_h_min.get(a, b)};\n      auto y = std::vector{seg_w_max.get(c, d), seg_w_min.get(c,\
    \ d)};\n\n      if(x[0].value == x[1].value) x.pop_back();\n      if(y[0].value\
    \ == y[1].value) y.pop_back();\n\n      int64_t M = LLONG_MAX;\n      for(auto\
    \ p : x){\n        for(auto q : y){\n          M = std::min(M, *p.value * *q.value);\n\
    \        }\n      }\n\n      if(M == 0){\n        int64_t p = 0;\n        for(auto\
    \ e : x) if(e.value == 0) p += e.count;\n        int64_t q = 0;\n        for(auto\
    \ e : y) if(e.value == 0) q += e.count;\n        m[0] = (b - a) * q + (d - c)\
    \ * p - p * q;\n      }else{\n        for(auto p : x){\n          for(auto q :\
    \ y){\n            m[*p.value * *q.value] += p.count * q.count;\n          }\n\
    \        }\n      }\n\n      std::cout << m.begin()->first << \" \" << m.begin()->second\
    \ << \"\\n\";\n\n      break;\n    }\n\n    case 4: {\n      int64_t a, b, c,\
    \ d; std::cin >> a >> b >> c >> d;\n      --a, --c;\n\n      std::map<int64_t,\
    \ int64_t> m;\n\n      auto x = std::vector{seg_h_max.get(a, b), seg_h_min.get(a,\
    \ b)};\n      auto y = std::vector{seg_w_max.get(c, d), seg_w_min.get(c, d)};\n\
    \n      if(x[0].value == x[1].value) x.pop_back();\n      if(y[0].value == y[1].value)\
    \ y.pop_back();\n\n      int64_t M = LLONG_MIN;\n      for(auto p : x){\n    \
    \    for(auto q : y){\n          M = std::max(M, *p.value * *q.value);\n     \
    \   }\n      }\n\n      if(M == 0){\n        int64_t p = 0;\n        for(auto\
    \ e : x) if(e.value == 0) p += e.count;\n        int64_t q = 0;\n        for(auto\
    \ e : y) if(e.value == 0) q += e.count;\n        m[0] = (b - a) * q + (d - c)\
    \ * p - p * q;\n      }else{\n        for(auto p : x){\n          for(auto q :\
    \ y){\n            m[*p.value * *q.value] += p.count * q.count;\n          }\n\
    \        }\n      }\n\n      std::cout << m.rbegin()->first << \" \" << m.rbegin()->second\
    \ << \"\\n\";\n\n      break;\n    }\n    }\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/IO/input_vector.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  - Mylib/AlgebraicStructure/Monoid/sum.cpp
  - Mylib/AlgebraicStructure/Monoid/max.cpp
  - Mylib/AlgebraicStructure/Monoid/min.cpp
  - Mylib/AlgebraicStructure/Monoid/with_count.cpp
  - Mylib/AlgebraicStructure/MonoidAction/add_max_with_count.cpp
  - Mylib/AlgebraicStructure/MonoidAction/add_min_with_count.cpp
  - Mylib/DataStructure/SegmentTree/lazy_segment_tree.cpp
  isVerificationFile: true
  path: test/aoj/3035/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-18 18:43:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/3035/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/3035/main.test.cpp
- /verify/test/aoj/3035/main.test.cpp.html
title: test/aoj/3035/main.test.cpp
---
