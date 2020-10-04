---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Mylib/DataStructure/ConvexHullTrick/lichao_segment_tree.cpp
    title: LiChao segment tree
  - icon: ':question:'
    path: Mylib/IO/input_tuple.cpp
    title: Input tuple
  - icon: ':question:'
    path: Mylib/IO/input_tuples.cpp
    title: Input tuples
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/line_add_get_min
    links:
    - https://judge.yosupo.jp/problem/line_add_get_min
  bundledCode: "#line 1 \"test/yosupo-judge/line_add_get_min/main.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n\n#include <iostream>\n\
    #include <vector>\n#include <utility>\n#include <variant>\n#include <tuple>\n\
    #line 4 \"Mylib/DataStructure/ConvexHullTrick/lichao_segment_tree.cpp\"\n#include\
    \ <algorithm>\n#include <optional>\n\nnamespace haar_lib {\n  template <typename\
    \ T, typename Comparator>\n  class lichao_segment_tree {\n  public:\n    using\
    \ value_type = T;\n\n  private:\n    using line = std::pair<T, T>;\n\n    Comparator\
    \ cmp_ = Comparator();\n    std::vector<T> xs_;\n    int n_;\n    std::vector<std::optional<line>>\
    \ data_;\n    std::vector<std::pair<int, int>> range_;\n\n    T chm(const T &a,\
    \ const T &b) const {\n      return cmp_(a, b) ? a : b;\n    }\n\n    void init_range_(int\
    \ i, int left, int right){\n      if(i >= 2 * n_) return;\n\n      range_[i] =\
    \ std::make_pair(left, right);\n      const int mid = (left + right) / 2;\n  \
    \    init_range_(i << 1 | 0, left, mid);\n      init_range_(i << 1 | 1, mid, right);\n\
    \    }\n\n  public:\n    lichao_segment_tree(){}\n    lichao_segment_tree(std::vector<T>\
    \ xs): xs_(xs){\n      std::sort(xs_.begin(), xs_.end());\n      xs_.erase(std::unique(xs_.begin(),\
    \ xs_.end()), xs_.end());\n\n      n_ = 1;\n      while(n_ < (int)xs_.size())\
    \ n_ *= 2;\n\n      const auto m = xs_.back();\n      xs_.resize(n_, m);\n\n \
    \     data_.assign(2 * n_, std::nullopt);\n\n      range_.resize(2 * n_);\n  \
    \    init_range_(1, 0, n_);\n    }\n\n    T apply(const line &l, const T &x) const\
    \ {\n      return l.first * x + l.second;\n    }\n\n  private:\n    void update(int\
    \ i, line new_line, int l, int r){\n      if(not data_[i]){\n        data_[i]\
    \ = new_line;\n        return;\n      }\n\n      const int m = (l + r) / 2;\n\n\
    \      auto lx = xs_[l], mx = xs_[m], rx = xs_[r - 1];\n\n      bool left = cmp_(apply(new_line,\
    \ lx), apply(*data_[i], lx));\n      bool mid = cmp_(apply(new_line, mx), apply(*data_[i],\
    \ mx));\n      bool right = cmp_(apply(new_line, rx), apply(*data_[i], rx));\n\
    \n      if(left and right){\n        data_[i] = new_line;\n        return;\n \
    \     }\n\n      if(not left and not right){\n        return;\n      }\n\n   \
    \   if(mid){\n        std::swap(*data_[i], new_line);\n      }\n\n      if(left\
    \ != mid){\n        update(i << 1 | 0, new_line, l, m);\n      }else{\n      \
    \  update(i << 1 | 1, new_line, m, r);\n      }\n    }\n\n  public:\n    void\
    \ add_line(T a, T b){\n      update(1, std::make_pair(a, b), 0, n_);\n    }\n\n\
    \    // [l, r)\n    void add_segment(T l, T r, T a, T b){\n      int left = std::lower_bound(xs_.begin(),\
    \ xs_.end(), l) - xs_.begin();\n      int right = std::lower_bound(xs_.begin(),\
    \ xs_.end(), r) - xs_.begin();\n\n      int L = left + n_;\n      int R = right\
    \ + n_;\n\n      while(L < R){\n        if(R & 1){\n          --R;\n         \
    \ update(R, std::make_pair(a, b), range_[R].first, range_[R].second);\n      \
    \  }\n\n        if(L & 1){\n          update(L, std::make_pair(a, b), range_[L].first,\
    \ range_[L].second);\n          ++L;\n        }\n\n        L >>= 1;\n        R\
    \ >>= 1;\n      }\n    }\n\n  public:\n    auto operator()(const T &x) const {\n\
    \      const int i = std::lower_bound(xs_.begin(), xs_.end(), x) - xs_.begin();\n\
    \      int k = i + n_;\n\n      std::optional<T> ret;\n\n      while(k > 0){\n\
    \        if(data_[k]){\n          if(not ret) ret = apply(*data_[k], xs_[i]);\n\
    \          else ret = chm(*ret, apply(*data_[k], xs_[i]));\n        }\n      \
    \  k >>= 1;\n      }\n\n      return ret;\n    }\n  };\n\n  template <typename\
    \ T>\n  auto make_lichao_min(const std::vector<T> &xs){\n    return lichao_segment_tree<T,\
    \ std::less<T>>(xs);\n  }\n\n  template <typename T>\n  auto make_lichao_max(const\
    \ std::vector<T> &xs){\n    return lichao_segment_tree<T, std::greater<T>>(xs);\n\
    \  }\n}\n#line 6 \"Mylib/IO/input_tuples.cpp\"\n#include <initializer_list>\n\
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
    \ N){\n    return InputTuples<Args ...>(N);\n  }\n}\n#line 10 \"test/yosupo-judge/line_add_get_min/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nusing Query = std::variant<std::pair<int64_t,\
    \ int64_t>, int64_t>;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int N, Q; std::cin >> N >> Q;\n\n  std::vector<int64_t> xs;\n\n  std::vector<std::pair<int64_t,\
    \ int64_t>> lines;\n\n  for(auto [a, b] : hl::input_tuples<int64_t, int64_t>(N)){\n\
    \    lines.emplace_back(a, b);\n  }\n\n  std::vector<Query> query;\n\n  for(auto\
    \ [type] : hl::input_tuples<int>(Q)){\n    switch(type){\n    case 0: {\n    \
    \  int64_t a, b; std::cin >> a >> b;\n      query.push_back(std::make_pair(a,\
    \ b));\n      break;\n    }\n    case 1: {\n      int64_t p; std::cin >> p;\n\
    \      query.push_back(p);\n      xs.push_back(p);\n      break;\n    }\n    }\n\
    \  }\n\n  auto lc = hl::make_lichao_min(xs);\n\n  for(auto [a, b] : lines){\n\
    \    lc.add_line(a, b);\n  }\n\n  for(auto &q : query){\n    if(q.index() == 0){\n\
    \      auto [a, b] = std::get<0>(q);\n      lc.add_line(a, b);\n    }else{\n \
    \     auto p = std::get<1>(q);\n      auto res = lc(p);\n\n      std::cout <<\
    \ *res << \"\\n\";\n    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n\n\
    #include <iostream>\n#include <vector>\n#include <utility>\n#include <variant>\n\
    #include <tuple>\n#include \"Mylib/DataStructure/ConvexHullTrick/lichao_segment_tree.cpp\"\
    \n#include \"Mylib/IO/input_tuples.cpp\"\n\nnamespace hl = haar_lib;\n\nusing\
    \ Query = std::variant<std::pair<int64_t, int64_t>, int64_t>;\n\nint main(){\n\
    \  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  int N, Q; std::cin\
    \ >> N >> Q;\n\n  std::vector<int64_t> xs;\n\n  std::vector<std::pair<int64_t,\
    \ int64_t>> lines;\n\n  for(auto [a, b] : hl::input_tuples<int64_t, int64_t>(N)){\n\
    \    lines.emplace_back(a, b);\n  }\n\n  std::vector<Query> query;\n\n  for(auto\
    \ [type] : hl::input_tuples<int>(Q)){\n    switch(type){\n    case 0: {\n    \
    \  int64_t a, b; std::cin >> a >> b;\n      query.push_back(std::make_pair(a,\
    \ b));\n      break;\n    }\n    case 1: {\n      int64_t p; std::cin >> p;\n\
    \      query.push_back(p);\n      xs.push_back(p);\n      break;\n    }\n    }\n\
    \  }\n\n  auto lc = hl::make_lichao_min(xs);\n\n  for(auto [a, b] : lines){\n\
    \    lc.add_line(a, b);\n  }\n\n  for(auto &q : query){\n    if(q.index() == 0){\n\
    \      auto [a, b] = std::get<0>(q);\n      lc.add_line(a, b);\n    }else{\n \
    \     auto p = std::get<1>(q);\n      auto res = lc(p);\n\n      std::cout <<\
    \ *res << \"\\n\";\n    }\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/DataStructure/ConvexHullTrick/lichao_segment_tree.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  isVerificationFile: true
  path: test/yosupo-judge/line_add_get_min/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-28 09:27:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo-judge/line_add_get_min/main.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-judge/line_add_get_min/main.test.cpp
- /verify/test/yosupo-judge/line_add_get_min/main.test.cpp.html
title: test/yosupo-judge/line_add_get_min/main.test.cpp
---
