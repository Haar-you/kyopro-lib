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
  - icon: ':x:'
    path: Mylib/Typical/InversionNumber/range_inversions_query.cpp
    title: Range inversions query
  - icon: ':x:'
    path: Mylib/DataStructure/FenwickTree/fenwick_tree_add.cpp
    title: Fenwick tree (Add)
  - icon: ':question:'
    path: Mylib/Algorithm/Mo/mo_algorithm.cpp
    title: Mo's algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_inversions_query
    links:
    - https://judge.yosupo.jp/problem/static_range_inversions_query
  bundledCode: "#line 1 \"test/yosupo-judge/static_range_inversions_query/main.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\
    \n\n#include <iostream>\n#include <vector>\n#line 4 \"Mylib/IO/input_vector.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  std::vector<T> input_vector(int\
    \ N){\n    std::vector<T> ret(N);\n    for(int i = 0; i < N; ++i) std::cin >>\
    \ ret[i];\n    return ret;\n  }\n\n  template <typename T>\n  std::vector<std::vector<T>>\
    \ input_vector(int N, int M){\n    std::vector<std::vector<T>> ret(N);\n    for(int\
    \ i = 0; i < N; ++i) ret[i] = input_vector<T>(M);\n    return ret;\n  }\n}\n#line\
    \ 4 \"Mylib/IO/input_tuples.cpp\"\n#include <tuple>\n#include <utility>\n#include\
    \ <initializer_list>\n#line 6 \"Mylib/IO/input_tuple.cpp\"\n\nnamespace haar_lib\
    \ {\n  template <typename T, size_t ... I>\n  static void input_tuple_helper(std::istream\
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
    \ 4 \"Mylib/Typical/InversionNumber/range_inversions_query.cpp\"\n#include <algorithm>\n\
    #line 3 \"Mylib/DataStructure/FenwickTree/fenwick_tree_add.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename T>\n  class fenwick_tree_add {\n    using value_type\
    \ = T;\n\n    int size;\n    std::vector<value_type> data;\n\n  public:\n    fenwick_tree_add(){}\n\
    \    fenwick_tree_add(int size): size(size), data(size + 1, 0){}\n\n    void update(int\
    \ i, value_type val){\n      i += 1; // 1-index\n\n      while(i <= size){\n \
    \       data[i] = data[i] + val;\n        i += i & (-i);\n      }\n    }\n\n \
    \   value_type fold(int i) const { // [0, i)\n      value_type ret = 0;\n\n  \
    \    while(i > 0){\n        ret = ret + data[i];\n        i -= i & (-i);\n   \
    \   }\n\n      return ret;\n    }\n\n    value_type fold(int l, int r) const {\
    \ // [l, r)\n      return fold(r) - fold(l);\n    }\n\n    value_type operator[](int\
    \ x) const {\n      return fold(x, x + 1);\n    }\n  };\n}\n#line 4 \"Mylib/Algorithm/Mo/mo_algorithm.cpp\"\
    \n#include <cassert>\n#include <cmath>\n\nnamespace haar_lib {\n  template <typename\
    \ AppendLeft, typename AppendRight, typename RemoveLeft, typename RemoveRight,\
    \ typename Query>\n  class mo_algorithm {\n    int N, Q, index, width;\n    std::vector<int>\
    \ left, right, ord;\n\n    const AppendLeft append_left;\n    const AppendRight\
    \ append_right;\n    const RemoveLeft remove_left;\n    const RemoveRight remove_right;\n\
    \    const Query query;\n\n    bool is_built = false;\n\n  public:\n    mo_algorithm(\n\
    \      int N, int Q,\n      const AppendLeft &append_left, const AppendRight &append_right,\n\
    \      const RemoveLeft &remove_left, const RemoveRight &remove_right,\n     \
    \ const Query &query\n    ):\n      N(N), Q(Q), index(0), width(std::sqrt(N)),\n\
    \      left(Q), right(Q), ord(Q),\n      append_left(append_left), append_right(append_right),\n\
    \      remove_left(remove_left), remove_right(remove_right),\n      query(query)\n\
    \    {}\n\n    // [l, r)\n    void add(int l, int r){\n      left[index] = l;\n\
    \      right[index] = r;\n      ord[index] = index;\n      ++index;\n    }\n\n\
    \    void run(){\n      std::sort(\n        ord.begin(), ord.end(),\n        [&](int\
    \ i, int j){\n          const int a = left[i] / width, b = left[j] / width;\n\
    \          if(a == b){\n            if(a & 1) return right[i] < right[j];\n  \
    \          else return right[i] > right[j];\n          }else{\n            return\
    \ a < b;\n          }\n        }\n      );\n\n      int q = 0;\n      int l =\
    \ left[ord[0]], r = left[ord[0]];\n\n      for(int i = 0; i < Q; ++i){\n     \
    \   int id = ord[q++];\n\n        while(l != left[id] or r != right[id]){\n  \
    \        if(l > left[id]) append_left(--l);\n          if(l < left[id]) remove_left(l++);\n\
    \          if(r < right[id]) append_right(r++);\n          if(r > right[id]) remove_right(--r);\n\
    \        }\n\n        query(id);\n      }\n    }\n  };\n}\n#line 7 \"Mylib/Typical/InversionNumber/range_inversions_query.cpp\"\
    \n\nnamespace haar_lib {\n  template <typename T>\n  class range_inversions_query\
    \ {\n    std::vector<int> a;\n    int N;\n    std::vector<std::pair<int, int>>\
    \ qs;\n\n  public:\n    range_inversions_query(std::vector<T> a_): N(a_.size()){\n\
    \      auto b = a_;\n      std::sort(b.begin(), b.end());\n      b.erase(std::unique(b.begin(),\
    \ b.end()), b.end());\n\n      for(auto x : a_){\n        const int i = std::lower_bound(b.begin(),\
    \ b.end(), x) - b.begin();\n        a.push_back(i);\n      }\n    }\n\n    void\
    \ add(int l, int r){ // [l, r)\n      qs.emplace_back(l, r);\n    }\n\n    auto\
    \ solve(){\n      const int Q = qs.size();\n      fenwick_tree_add<int64_t> b(N);\n\
    \n      int64_t t = 0;\n      std::vector<int64_t> ans(Q);\n\n      auto append_left\
    \ =\n        [&](int i){\n          t += b.fold(0, a[i]);\n          b.update(a[i],\
    \ 1);\n        };\n\n      auto append_right =\n        [&](int i){\n        \
    \  t += b.fold(a[i] + 1, N);\n          b.update(a[i], 1);\n        };\n\n   \
    \   auto remove_left =\n        [&](int i){\n          t -= b.fold(0, a[i]);\n\
    \          b.update(a[i], -1);\n        };\n\n      auto remove_right =\n    \
    \    [&](int i){\n          t -= b.fold(a[i] + 1, N);\n          b.update(a[i],\
    \ -1);\n        };\n\n      auto query = [&](int i){ans[i] = t;};\n\n      auto\
    \ mo =\n        mo_algorithm(\n          N, Q, append_left, append_right, remove_left,\
    \ remove_right, query\n        );\n\n      for(auto [l, r] : qs){\n        mo.add(l,\
    \ r);\n      }\n\n      mo.run();\n\n      return ans;\n    }\n  };\n}\n#line\
    \ 8 \"test/yosupo-judge/static_range_inversions_query/main.test.cpp\"\n\nnamespace\
    \ hl = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int N, Q; std::cin >> N >> Q;\n  auto A = hl::input_vector<int>(N);\n\n  hl::range_inversions_query\
    \ riq(A);\n\n  for(auto [l, r] : hl::input_tuples<int, int>(Q)){\n    riq.add(l,\
    \ r);\n  }\n\n  auto ans = riq.solve();\n\n  for(auto x : ans){\n    std::cout\
    \ << x << \"\\n\";\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\
    \n\n#include <iostream>\n#include <vector>\n#include \"Mylib/IO/input_vector.cpp\"\
    \n#include \"Mylib/IO/input_tuples.cpp\"\n#include \"Mylib/Typical/InversionNumber/range_inversions_query.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int N, Q; std::cin >> N >> Q;\n  auto A = hl::input_vector<int>(N);\n\n  hl::range_inversions_query\
    \ riq(A);\n\n  for(auto [l, r] : hl::input_tuples<int, int>(Q)){\n    riq.add(l,\
    \ r);\n  }\n\n  auto ans = riq.solve();\n\n  for(auto x : ans){\n    std::cout\
    \ << x << \"\\n\";\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/IO/input_vector.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  - Mylib/Typical/InversionNumber/range_inversions_query.cpp
  - Mylib/DataStructure/FenwickTree/fenwick_tree_add.cpp
  - Mylib/Algorithm/Mo/mo_algorithm.cpp
  isVerificationFile: true
  path: test/yosupo-judge/static_range_inversions_query/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-26 08:06:35+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo-judge/static_range_inversions_query/main.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-judge/static_range_inversions_query/main.test.cpp
- /verify/test/yosupo-judge/static_range_inversions_query/main.test.cpp.html
title: test/yosupo-judge/static_range_inversions_query/main.test.cpp
---
