---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/IO/input_tuple_vector.cpp
    title: Input tuple vector
  - icon: ':heavy_check_mark:'
    path: Mylib/Typical/knapsack_branch_and_bound.cpp
    title: 0-1 Knapsack problem (Branch and bound)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_H
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_H
  bundledCode: "#line 1 \"test/aoj/DPL_1_H/main.test.bb.cpp\"\n#define PROBLEM \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_H\"\n\n#include\
    \ <iostream>\n#include <vector>\n#line 2 \"Mylib/Typical/knapsack_branch_and_bound.cpp\"\
    \n\n#line 4 \"Mylib/Typical/knapsack_branch_and_bound.cpp\"\n#include <algorithm>\n\
    #include <numeric>\n\nnamespace haar_lib {\n  template <typename Weight, typename\
    \ Value>\n  Value knapsack_branch_and_bound(\n    int N, Weight cap, const std::vector<Weight>\
    \ &weight, const std::vector<Value> &value\n  ){\n    std::vector<int> ord(N);\n\
    \    std::iota(ord.begin(), ord.end(), 0);\n\n    std::sort(\n      ord.begin(),\
    \ ord.end(),\n      [&](int i, int j){\n        return (double)value[i] / weight[i]\
    \ > (double)value[j] / weight[j];\n      }\n    );\n\n    Value feasible_sol =\
    \ 0;\n\n    auto dfs =\n      [&](auto &dfs, int k, Weight w, Value v) -> Value\
    \ {\n        if(w > cap) return 0;\n        if(k == N){\n          feasible_sol\
    \ = std::max(feasible_sol, v);\n          return v;\n        }\n\n        bool\
    \ is_opt = true;\n        Value sol = 0;\n        Weight w_sum = 0;\n        int\
    \ p = 0;\n\n        for(p = k; p < N; ++p){\n          if(w_sum + weight[ord[p]]\
    \ >= cap - w){\n            if(w_sum + weight[ord[p]] == cap - w){\n         \
    \     w_sum += weight[ord[p]];\n              sol += value[ord[p]];\n        \
    \    }else{\n              is_opt = false;\n            }\n\n            break;\n\
    \          }else{\n            w_sum += weight[ord[p]];\n            sol += value[ord[p]];\n\
    \          }\n        }\n\n        if(is_opt) return feasible_sol = std::max(feasible_sol,\
    \ v + sol);\n\n        double d = (double)value[ord[p]] / weight[ord[p]] * (cap\
    \ - w - w_sum) ;\n        if((double)v + sol + d < feasible_sol){\n          return\
    \ 0;\n        }\n\n        Value ret = 0;\n\n        if(w + weight[ord[k]] <=\
    \ cap){\n          ret = std::max(ret, dfs(dfs, k + 1, w + weight[ord[k]], v +\
    \ value[ord[k]]));\n          feasible_sol = std::max(feasible_sol, ret);\n  \
    \      }\n\n        ret = std::max(ret, dfs(dfs, k + 1, w, v));\n        feasible_sol\
    \ = std::max(feasible_sol, ret);\n\n        return ret;\n      };\n\n    auto\
    \ ret = dfs(dfs, 0, 0, 0);\n    return ret;\n  }\n}\n#line 4 \"Mylib/IO/input_tuple_vector.cpp\"\
    \n#include <tuple>\n#include <utility>\n#include <initializer_list>\n\nnamespace\
    \ haar_lib {\n  template <typename T, size_t ... I>\n  void input_tuple_vector_init(T\
    \ &val, int N, std::index_sequence<I ...>){\n    (void)std::initializer_list<int>{(void(std::get<I>(val).resize(N)),\
    \ 0) ...};\n  }\n\n  template <typename T, size_t ... I>\n  void input_tuple_vector_helper(T\
    \ &val, int i, std::index_sequence<I ...>){\n    (void)std::initializer_list<int>{(void(std::cin\
    \ >> std::get<I>(val)[i]), 0) ...};\n  }\n\n  template <typename ... Args>\n \
    \ auto input_tuple_vector(int N){\n    std::tuple<std::vector<Args> ...> ret;\n\
    \n    input_tuple_vector_init(ret, N, std::make_index_sequence<sizeof ... (Args)>());\n\
    \    for(int i = 0; i < N; ++i){\n      input_tuple_vector_helper(ret, i, std::make_index_sequence<sizeof\
    \ ... (Args)>());\n    }\n\n    return ret;\n  }\n}\n#line 7 \"test/aoj/DPL_1_H/main.test.bb.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  int N; std::cin >> N;\n  int64_t\
    \ W; std::cin >> W;\n\n  auto [v, w] = hl::input_tuple_vector<int64_t, int64_t>(N);\n\
    \n  auto ans = hl::knapsack_branch_and_bound(N, W, w, v);\n\n  std::cout << ans\
    \ << std::endl;\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_H\"\
    \n\n#include <iostream>\n#include <vector>\n#include \"Mylib/Typical/knapsack_branch_and_bound.cpp\"\
    \n#include \"Mylib/IO/input_tuple_vector.cpp\"\n\nnamespace hl = haar_lib;\n\n\
    int main(){\n  int N; std::cin >> N;\n  int64_t W; std::cin >> W;\n\n  auto [v,\
    \ w] = hl::input_tuple_vector<int64_t, int64_t>(N);\n\n  auto ans = hl::knapsack_branch_and_bound(N,\
    \ W, w, v);\n\n  std::cout << ans << std::endl;\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Typical/knapsack_branch_and_bound.cpp
  - Mylib/IO/input_tuple_vector.cpp
  isVerificationFile: true
  path: test/aoj/DPL_1_H/main.test.bb.cpp
  requiredBy: []
  timestamp: '2020-11-24 20:28:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DPL_1_H/main.test.bb.cpp
layout: document
redirect_from:
- /verify/test/aoj/DPL_1_H/main.test.bb.cpp
- /verify/test/aoj/DPL_1_H/main.test.bb.cpp.html
title: test/aoj/DPL_1_H/main.test.bb.cpp
---
