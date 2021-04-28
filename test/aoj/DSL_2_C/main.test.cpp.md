---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Mylib/DataStructure/RangeTree/range_tree.cpp
    title: Range tree
  - icon: ':question:'
    path: Mylib/IO/input_tuple.cpp
    title: Input tuple
  - icon: ':question:'
    path: Mylib/IO/input_tuples.cpp
    title: Input tuples
  - icon: ':question:'
    path: Mylib/IO/input_tuples_with_index.cpp
    title: Input tuples with index
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_C
  bundledCode: "#line 1 \"test/aoj/DSL_2_C/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_C\"\
    \n\n#include <iostream>\n#include <map>\n#include <utility>\n#include <vector>\n\
    #line 2 \"Mylib/DataStructure/RangeTree/range_tree.cpp\"\n#include <algorithm>\n\
    #include <iterator>\n#line 6 \"Mylib/DataStructure/RangeTree/range_tree.cpp\"\n\
    \nnamespace haar_lib {\n  class range_tree {\n    using pll = std::pair<int64_t,\
    \ int64_t>;\n    friend class range_tree_builder;\n\n    int size_;\n    std::vector<int64_t>\
    \ c_xs_;\n    std::vector<std::vector<std::pair<int64_t, int>>> data_;\n\n  public:\n\
    \    auto get(pll s, pll t) const {\n      const auto [sx, sy] = s;\n      const\
    \ auto [tx, ty] = t;\n\n      std::vector<pll> ret;\n\n      int L = std::lower_bound(c_xs_.begin(),\
    \ c_xs_.end(), sx) - c_xs_.begin();\n      int R = std::lower_bound(c_xs_.begin(),\
    \ c_xs_.end(), tx) - c_xs_.begin();\n\n      L += size_ / 2;\n      R += size_\
    \ / 2;\n\n      while (L < R) {\n        if (R & 1) {\n          auto &a = data_[--R];\n\
    \n          auto it = std::lower_bound(a.begin(), a.end(), std::make_pair(sy,\
    \ 0));\n\n          while (it != a.end()) {\n            if (it->first >= ty)\
    \ break;\n\n            ret.emplace_back(c_xs_[it->second], it->first);\n\n  \
    \          ++it;\n          }\n        }\n\n        if (L & 1) {\n          auto\
    \ &a = data_[L++];\n\n          auto it = std::lower_bound(a.begin(), a.end(),\
    \ std::make_pair(sy, 0));\n\n          while (it != a.end()) {\n            if\
    \ (it->first >= ty) break;\n\n            ret.emplace_back(c_xs_[it->second],\
    \ it->first);\n\n            ++it;\n          }\n        }\n\n        L >>= 1;\n\
    \        R >>= 1;\n      }\n\n      return ret;\n    }\n  };\n\n  class range_tree_builder\
    \ {\n    int N_ = 0;\n    std::vector<int64_t> xs_, ys_;\n\n  public:\n    range_tree_builder()\
    \ {}\n\n    void add(int64_t x, int64_t y) {\n      ++N_;\n      xs_.push_back(x);\n\
    \      ys_.push_back(y);\n    }\n\n    auto build() const {\n      range_tree\
    \ ret;\n      ret.c_xs_ = xs_;\n      std::sort(ret.c_xs_.begin(), ret.c_xs_.end());\n\
    \      ret.c_xs_.erase(std::unique(ret.c_xs_.begin(), ret.c_xs_.end()), ret.c_xs_.end());\n\
    \n      int M     = ret.c_xs_.size();\n      ret.size_ = 1 << (M > 1 ? 32 - __builtin_clz(M\
    \ - 1) + 1 : 1);\n\n      ret.data_.resize(ret.size_);\n\n      for (int i = 0;\
    \ i < N_; ++i) {\n        int j = std::lower_bound(ret.c_xs_.begin(), ret.c_xs_.end(),\
    \ xs_[i]) - ret.c_xs_.begin();\n        ret.data_[ret.size_ / 2 + j].emplace_back(ys_[i],\
    \ j);\n      }\n\n      for (int i = ret.size_ / 2; i < ret.size_; ++i) {\n  \
    \      std::sort(ret.data_[i].begin(), ret.data_[i].end());\n      }\n\n     \
    \ for (int i = ret.size_ / 2 - 1; i > 0; --i) {\n        auto &a = ret.data_[i\
    \ << 1 | 0];\n        auto &b = ret.data_[i << 1 | 1];\n\n        std::merge(a.begin(),\
    \ a.end(), b.begin(), b.end(), std::back_inserter(ret.data_[i]));\n      }\n\n\
    \      return ret;\n    }\n  };\n}  // namespace haar_lib\n#line 2 \"Mylib/IO/input_tuples.cpp\"\
    \n#include <initializer_list>\n#line 4 \"Mylib/IO/input_tuples.cpp\"\n#include\
    \ <tuple>\n#line 6 \"Mylib/IO/input_tuple.cpp\"\n\nnamespace haar_lib {\n  template\
    \ <typename T, size_t... I>\n  static void input_tuple_helper(std::istream &s,\
    \ T &val, std::index_sequence<I...>) {\n    (void) std::initializer_list<int>{(void(s\
    \ >> std::get<I>(val)), 0)...};\n  }\n\n  template <typename T, typename U>\n\
    \  std::istream &operator>>(std::istream &s, std::pair<T, U> &value) {\n    s\
    \ >> value.first >> value.second;\n    return s;\n  }\n\n  template <typename...\
    \ Args>\n  std::istream &operator>>(std::istream &s, std::tuple<Args...> &value)\
    \ {\n    input_tuple_helper(s, value, std::make_index_sequence<sizeof...(Args)>());\n\
    \    return s;\n  }\n}  // namespace haar_lib\n#line 8 \"Mylib/IO/input_tuples.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename... Args>\n  class InputTuples {\n\
    \    struct iter {\n      using value_type = std::tuple<Args...>;\n      value_type\
    \ value;\n      bool fetched = false;\n      int N, c = 0;\n\n      value_type\
    \ operator*() {\n        if (not fetched) {\n          std::cin >> value;\n  \
    \      }\n        return value;\n      }\n\n      void operator++() {\n      \
    \  ++c;\n        fetched = false;\n      }\n\n      bool operator!=(iter &) const\
    \ {\n        return c < N;\n      }\n\n      iter(int N) : N(N) {}\n    };\n\n\
    \    int N;\n\n  public:\n    InputTuples(int N) : N(N) {}\n\n    iter begin()\
    \ const { return iter(N); }\n    iter end() const { return iter(N); }\n  };\n\n\
    \  template <typename... Args>\n  auto input_tuples(int N) {\n    return InputTuples<Args...>(N);\n\
    \  }\n}  // namespace haar_lib\n#line 8 \"Mylib/IO/input_tuples_with_index.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename... Args>\n  class InputTuplesWithIndex\
    \ {\n    struct iter {\n      using value_type = std::tuple<int, Args...>;\n \
    \     value_type value;\n      bool fetched = false;\n      int N;\n      int\
    \ c = 0;\n\n      value_type operator*() {\n        if (not fetched) {\n     \
    \     std::tuple<Args...> temp;\n          std::cin >> temp;\n          value\
    \ = std::tuple_cat(std::make_tuple(c), temp);\n        }\n        return value;\n\
    \      }\n\n      void operator++() {\n        ++c;\n        fetched = false;\n\
    \      }\n\n      bool operator!=(iter &) const {\n        return c < N;\n   \
    \   }\n\n      iter(int N) : N(N) {}\n    };\n\n    int N;\n\n  public:\n    InputTuplesWithIndex(int\
    \ N) : N(N) {}\n\n    iter begin() const { return iter(N); }\n    iter end() const\
    \ { return iter(N); }\n  };\n\n  template <typename... Args>\n  auto input_tuples_with_index(int\
    \ N) {\n    return InputTuplesWithIndex<Args...>(N);\n  }\n}  // namespace haar_lib\n\
    #line 10 \"test/aoj/DSL_2_C/main.test.cpp\"\n\nnamespace hl = haar_lib;\n\nint\
    \ main() {\n  int n;\n  std::cin >> n;\n  hl::range_tree_builder builder;\n\n\
    \  std::map<std::pair<int, int>, int> m;\n\n  for (auto [i, x, y] : hl::input_tuples_with_index<int,\
    \ int>(n)) {\n    builder.add(x, y);\n    m[{x, y}] = i;\n  }\n\n  auto rt = builder.build();\n\
    \n  int q;\n  std::cin >> q;\n\n  for (auto [sx, tx, sy, ty] : hl::input_tuples<int,\
    \ int, int, int>(q)) {\n    auto res = rt.get({sx, sy}, {tx + 1, ty + 1});\n\n\
    \    std::vector<int> ans;\n    for (auto &p : res) ans.push_back(m[p]);\n\n \
    \   std::sort(ans.begin(), ans.end());\n    for (auto &x : ans) {\n      std::cout\
    \ << x << \"\\n\";\n    }\n    std::cout << \"\\n\";\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_C\"\
    \n\n#include <iostream>\n#include <map>\n#include <utility>\n#include <vector>\n\
    #include \"Mylib/DataStructure/RangeTree/range_tree.cpp\"\n#include \"Mylib/IO/input_tuples.cpp\"\
    \n#include \"Mylib/IO/input_tuples_with_index.cpp\"\n\nnamespace hl = haar_lib;\n\
    \nint main() {\n  int n;\n  std::cin >> n;\n  hl::range_tree_builder builder;\n\
    \n  std::map<std::pair<int, int>, int> m;\n\n  for (auto [i, x, y] : hl::input_tuples_with_index<int,\
    \ int>(n)) {\n    builder.add(x, y);\n    m[{x, y}] = i;\n  }\n\n  auto rt = builder.build();\n\
    \n  int q;\n  std::cin >> q;\n\n  for (auto [sx, tx, sy, ty] : hl::input_tuples<int,\
    \ int, int, int>(q)) {\n    auto res = rt.get({sx, sy}, {tx + 1, ty + 1});\n\n\
    \    std::vector<int> ans;\n    for (auto &p : res) ans.push_back(m[p]);\n\n \
    \   std::sort(ans.begin(), ans.end());\n    for (auto &x : ans) {\n      std::cout\
    \ << x << \"\\n\";\n    }\n    std::cout << \"\\n\";\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/DataStructure/RangeTree/range_tree.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  - Mylib/IO/input_tuples_with_index.cpp
  isVerificationFile: true
  path: test/aoj/DSL_2_C/main.test.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/DSL_2_C/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_C/main.test.cpp
- /verify/test/aoj/DSL_2_C/main.test.cpp.html
title: test/aoj/DSL_2_C/main.test.cpp
---
