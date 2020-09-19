---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1327/main.test.cpp
    title: test/aoj/1327/main.test.cpp
  - icon: ':x:'
    path: test/aoj/DSL_3_D/main.test.cpp
    title: test/aoj/DSL_3_D/main.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/1300/main.test.cpp
    title: test/aoj/1300/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/inv_of_formal_power_series/main.test.cpp
    title: test/yosupo-judge/inv_of_formal_power_series/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/two_sat/main.test.cpp
    title: test/yosupo-judge/two_sat/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/sharp_p_subset_sum/main.test.cpp
    title: test/yosupo-judge/sharp_p_subset_sum/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/maximum_independent_set/main.test.cpp
    title: test/yosupo-judge/maximum_independent_set/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/tree_diameter/main.test.cpp
    title: test/yosupo-judge/tree_diameter/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/polynomial_taylor_shift/main.test.cpp
    title: test/yosupo-judge/polynomial_taylor_shift/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/stirling_number_of_the_second_kind/main.test.cpp
    title: test/yosupo-judge/stirling_number_of_the_second_kind/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/bernoulli_number/main.test.cpp
    title: test/yosupo-judge/bernoulli_number/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/pow_of_formal_power_series/main.test.cpp
    title: test/yosupo-judge/pow_of_formal_power_series/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/two_edge_connected_components/main.test.cpp
    title: test/yosupo-judge/two_edge_connected_components/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/factorize/main.test.cpp
    title: test/yosupo-judge/factorize/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/system_of_linear_equations/main.test.cpp
    title: test/yosupo-judge/system_of_linear_equations/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/convolution_mod/main.test.cpp
    title: test/yosupo-judge/convolution_mod/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/log_of_formal_power_series/main.test.cpp
    title: test/yosupo-judge/log_of_formal_power_series/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/sqrt_of_formal_power_series/main.test.cpp
    title: test/yosupo-judge/sqrt_of_formal_power_series/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/suffixarray/main.test.cpp
    title: test/yosupo-judge/suffixarray/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/stirling_number_of_the_first_kind/main.test.cpp
    title: test/yosupo-judge/stirling_number_of_the_first_kind/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/montmort_number_mod/main.test.cpp
    title: test/yosupo-judge/montmort_number_mod/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/exp_of_formal_power_series/main.test.cpp
    title: test/yosupo-judge/exp_of_formal_power_series/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/zalgorithm/main.test.cpp
    title: test/yosupo-judge/zalgorithm/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/scc/main.test.cpp
    title: test/yosupo-judge/scc/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/assignment/main.test.cpp
    title: test/yosupo-judge/assignment/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/partition_function/main.test.cpp
    title: test/yosupo-judge/partition_function/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/partition_function/main.fps.test.cpp
    title: test/yosupo-judge/partition_function/main.fps.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/cartesian_tree/main.test.cpp
    title: test/yosupo-judge/cartesian_tree/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/convolution_mod_1000000007/main.test.cpp
    title: test/yosupo-judge/convolution_mod_1000000007/main.test.cpp
  - icon: ':x:'
    path: test/yukicoder/782/main.test.cpp
    title: test/yukicoder/782/main.test.cpp
  - icon: ':x:'
    path: test/yukicoder/499/main.test.cpp
    title: test/yukicoder/499/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/IO/join.cpp\"\n#include <iostream>\n#include <sstream>\n\
    #include <string>\n\nnamespace haar_lib {\n  template <typename Iter>\n  std::string\
    \ join(Iter first, Iter last, std::string delim = \" \"){\n    std::stringstream\
    \ s;\n\n    for(auto it = first; it != last; ++it){\n      if(it != first) s <<\
    \ delim;\n      s << *it;\n    }\n\n    return s.str();\n  }\n}\n"
  code: "#pragma once\n#include <iostream>\n#include <sstream>\n#include <string>\n\
    \nnamespace haar_lib {\n  template <typename Iter>\n  std::string join(Iter first,\
    \ Iter last, std::string delim = \" \"){\n    std::stringstream s;\n\n    for(auto\
    \ it = first; it != last; ++it){\n      if(it != first) s << delim;\n      s <<\
    \ *it;\n    }\n\n    return s.str();\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/IO/join.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/1327/main.test.cpp
  - test/aoj/DSL_3_D/main.test.cpp
  - test/aoj/1300/main.test.cpp
  - test/yosupo-judge/inv_of_formal_power_series/main.test.cpp
  - test/yosupo-judge/two_sat/main.test.cpp
  - test/yosupo-judge/sharp_p_subset_sum/main.test.cpp
  - test/yosupo-judge/maximum_independent_set/main.test.cpp
  - test/yosupo-judge/tree_diameter/main.test.cpp
  - test/yosupo-judge/polynomial_taylor_shift/main.test.cpp
  - test/yosupo-judge/stirling_number_of_the_second_kind/main.test.cpp
  - test/yosupo-judge/bernoulli_number/main.test.cpp
  - test/yosupo-judge/pow_of_formal_power_series/main.test.cpp
  - test/yosupo-judge/two_edge_connected_components/main.test.cpp
  - test/yosupo-judge/factorize/main.test.cpp
  - test/yosupo-judge/system_of_linear_equations/main.test.cpp
  - test/yosupo-judge/convolution_mod/main.test.cpp
  - test/yosupo-judge/log_of_formal_power_series/main.test.cpp
  - test/yosupo-judge/sqrt_of_formal_power_series/main.test.cpp
  - test/yosupo-judge/suffixarray/main.test.cpp
  - test/yosupo-judge/stirling_number_of_the_first_kind/main.test.cpp
  - test/yosupo-judge/montmort_number_mod/main.test.cpp
  - test/yosupo-judge/exp_of_formal_power_series/main.test.cpp
  - test/yosupo-judge/zalgorithm/main.test.cpp
  - test/yosupo-judge/scc/main.test.cpp
  - test/yosupo-judge/assignment/main.test.cpp
  - test/yosupo-judge/partition_function/main.test.cpp
  - test/yosupo-judge/partition_function/main.fps.test.cpp
  - test/yosupo-judge/cartesian_tree/main.test.cpp
  - test/yosupo-judge/convolution_mod_1000000007/main.test.cpp
  - test/yukicoder/782/main.test.cpp
  - test/yukicoder/499/main.test.cpp
documentation_of: Mylib/IO/join.cpp
layout: document
title: null
---

## Operations

## Requirements

## Notes

## Problems

## References
