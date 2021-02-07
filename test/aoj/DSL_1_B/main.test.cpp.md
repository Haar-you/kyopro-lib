---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/DataStructure/UnionFind/weighted_unionfind.cpp
    title: Weighted union-find
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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B
  bundledCode: "#line 1 \"test/aoj/DSL_1_B/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B\"\
    \n\n#include <iostream>\n#line 2 \"Mylib/DataStructure/UnionFind/weighted_unionfind.cpp\"\
    \n#include <vector>\n#include <numeric>\n\nnamespace haar_lib {\n  template <typename\
    \ T>\n  class weighted_unionfind {\n  public:\n    using value_type = T;\n\n \
    \ private:\n    std::vector<int> parent_, depth_, size_;\n    std::vector<T> weight_;\n\
    \    int count_;\n\n  public:\n    weighted_unionfind(){}\n    weighted_unionfind(int\
    \ n): parent_(n), depth_(n, 1), size_(n, 1), weight_(n, 0){\n      std::iota(parent_.begin(),\
    \ parent_.end(), 0);\n    }\n\n    int root_of(int i){\n      if(parent_[i] ==\
    \ i) return i;\n      else {\n        const int p = root_of(parent_[i]);\n   \
    \     weight_[i] += weight_[parent_[i]];\n        return parent_[i] = p;\n   \
    \   }\n    }\n\n    T weight_of(int i){root_of(i); return weight_[i];}\n    bool\
    \ is_same(int i, int j){return root_of(i) == root_of(j);}\n    T diff(int i, int\
    \ j){return weight_of(i) - weight_of(j);}\n\n    int merge(int i, int j, T w){\n\
    \      const int ri = root_of(i), rj = root_of(j);\n      if(ri == rj) return\
    \ ri;\n      else{\n        if(depth_[ri] < depth_[rj]){\n          parent_[ri]\
    \ = rj; size_[rj] += size_[ri]; weight_[ri] = w - weight_[i] + weight_[j];\n \
    \         return rj;\n        }else{\n          parent_[rj] = ri; size_[ri] +=\
    \ size_[rj]; weight_[rj] = -w + weight_[i] - weight_[j];\n          if(depth_[ri]\
    \ == depth_[rj]) ++depth_[ri];\n          return ri;\n        }\n      }\n   \
    \ }\n\n    int size_of(int i){return size_[root_of(i)];}\n    int count_groups(){return\
    \ count_;}\n  };\n}\n#line 4 \"Mylib/IO/input_tuples.cpp\"\n#include <tuple>\n\
    #include <utility>\n#include <initializer_list>\n#line 6 \"Mylib/IO/input_tuple.cpp\"\
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
    \ ...>(N);\n  }\n}\n#line 6 \"test/aoj/DSL_1_B/main.test.cpp\"\n\nnamespace hl\
    \ = haar_lib;\n\nint main(){\n  int n, q; std::cin >> n >> q;\n\n  hl::weighted_unionfind<int>\
    \ uf(n);\n\n  for(auto [type, x, y] : hl::input_tuples<int, int, int>(q)){\n \
    \   if(type == 0){\n      int z; std::cin >> z;\n      uf.merge(x, y, z);\n  \
    \  }else{\n      if(uf.is_same(x, y)){\n        std::cout << uf.diff(x, y) <<\
    \ std::endl;\n      }else{\n        std::cout << \"?\" << std::endl;\n      }\n\
    \    }\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B\"\
    \n\n#include <iostream>\n#include \"Mylib/DataStructure/UnionFind/weighted_unionfind.cpp\"\
    \n#include \"Mylib/IO/input_tuples.cpp\"\n\nnamespace hl = haar_lib;\n\nint main(){\n\
    \  int n, q; std::cin >> n >> q;\n\n  hl::weighted_unionfind<int> uf(n);\n\n \
    \ for(auto [type, x, y] : hl::input_tuples<int, int, int>(q)){\n    if(type ==\
    \ 0){\n      int z; std::cin >> z;\n      uf.merge(x, y, z);\n    }else{\n   \
    \   if(uf.is_same(x, y)){\n        std::cout << uf.diff(x, y) << std::endl;\n\
    \      }else{\n        std::cout << \"?\" << std::endl;\n      }\n    }\n  }\n\
    \n  return 0;\n}\n"
  dependsOn:
  - Mylib/DataStructure/UnionFind/weighted_unionfind.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  isVerificationFile: true
  path: test/aoj/DSL_1_B/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-28 09:27:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_1_B/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_1_B/main.test.cpp
- /verify/test/aoj/DSL_1_B/main.test.cpp.html
title: test/aoj/DSL_1_B/main.test.cpp
---
