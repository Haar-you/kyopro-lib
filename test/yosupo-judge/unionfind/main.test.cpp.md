---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/DataStructure/UnionFind/unionfind.cpp
    title: Union-find
  - icon: ':heavy_check_mark:'
    path: Mylib/IO/input_tuple.cpp
    title: Input tuple
  - icon: ':heavy_check_mark:'
    path: Mylib/IO/input_tuples.cpp
    title: Input tuples
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/yosupo-judge/unionfind/main.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include <iostream>\n#line\
    \ 2 \"Mylib/DataStructure/UnionFind/unionfind.cpp\"\n#include <vector>\n#include\
    \ <numeric>\n#include <algorithm>\n\nnamespace haar_lib {\n  class unionfind {\n\
    \    int n_, count_;\n    mutable std::vector<int> parent_;\n    std::vector<int>\
    \ depth_, size_;\n\n  public:\n    unionfind(){}\n    unionfind(int n): n_(n),\
    \ count_(n), parent_(n), depth_(n, 1), size_(n, 1){\n      std::iota(parent_.begin(),\
    \ parent_.end(), 0);\n    }\n\n    int root_of(int i) const {\n      if(parent_[i]\
    \ == i) return i;\n      else return parent_[i] = root_of(parent_[i]);\n    }\n\
    \n    bool is_same(int i, int j) const {return root_of(i) == root_of(j);}\n\n\
    \    int merge(int i, int j){\n      const int ri = root_of(i), rj = root_of(j);\n\
    \      if(ri == rj) return ri;\n      else{\n        --count_;\n        if(depth_[ri]\
    \ < depth_[rj]){\n          parent_[ri] = rj;\n          size_[rj] += size_[ri];\n\
    \          return rj;\n        }else{\n          parent_[rj] = ri;\n         \
    \ size_[ri] += size_[rj];\n          if(depth_[ri] == depth_[rj]) ++depth_[ri];\n\
    \          return ri;\n        }\n      }\n    }\n\n    int size_of(int i) const\
    \ {return size_[root_of(i)];}\n\n    int count_groups() const {return count_;}\n\
    \n    auto get_groups() const {\n      std::vector<std::vector<int>> ret(n_);\n\
    \n      for(int i = 0; i < n_; ++i){\n        ret[root_of(i)].push_back(i);\n\
    \      }\n\n      ret.erase(\n        std::remove_if(\n          ret.begin(),\
    \ ret.end(),\n          [](const auto &a){return a.empty();}\n        ),\n   \
    \     ret.end()\n      );\n\n      return ret;\n    }\n  };\n}\n#line 4 \"Mylib/IO/input_tuples.cpp\"\
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
    \ ...>(N);\n  }\n}\n#line 6 \"test/yosupo-judge/unionfind/main.test.cpp\"\n\n\
    namespace hl = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int N, Q; std::cin >> N >> Q;\n\n  hl::unionfind uf(N);\n\n  for(auto [t,\
    \ u, v] : hl::input_tuples<int, int, int>(Q)){\n    if(t == 0){\n      uf.merge(u,\
    \ v);\n    }else{\n      std::cout << uf.is_same(u, v) << std::endl;\n    }\n\
    \  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ <iostream>\n#include \"Mylib/DataStructure/UnionFind/unionfind.cpp\"\n#include\
    \ \"Mylib/IO/input_tuples.cpp\"\n\nnamespace hl = haar_lib;\n\nint main(){\n \
    \ std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  int N, Q; std::cin\
    \ >> N >> Q;\n\n  hl::unionfind uf(N);\n\n  for(auto [t, u, v] : hl::input_tuples<int,\
    \ int, int>(Q)){\n    if(t == 0){\n      uf.merge(u, v);\n    }else{\n      std::cout\
    \ << uf.is_same(u, v) << std::endl;\n    }\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/DataStructure/UnionFind/unionfind.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  isVerificationFile: true
  path: test/yosupo-judge/unionfind/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-28 09:27:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo-judge/unionfind/main.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-judge/unionfind/main.test.cpp
- /verify/test/yosupo-judge/unionfind/main.test.cpp.html
title: test/yosupo-judge/unionfind/main.test.cpp
---
