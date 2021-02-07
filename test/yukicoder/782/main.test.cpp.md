---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/IO/input_tuple.cpp
    title: Input tuple
  - icon: ':heavy_check_mark:'
    path: Mylib/IO/input_tuples.cpp
    title: Input tuples
  - icon: ':heavy_check_mark:'
    path: Mylib/IO/join.cpp
    title: join function
  - icon: ':heavy_check_mark:'
    path: Mylib/Misc/convert_base.cpp
    title: Convert base
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/782
    links:
    - https://yukicoder.me/problems/no/782
  bundledCode: "#line 1 \"test/yukicoder/782/main.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/782\"\
    \n\n#include <iostream>\n#line 2 \"Mylib/Misc/convert_base.cpp\"\n#include <vector>\n\
    #include <algorithm>\n\nnamespace haar_lib {\n  std::vector<int64_t> convert_base_to(int64_t\
    \ val, int64_t base){\n    if(val == 0) return {0};\n\n    int b = std::abs(base);\n\
    \n    std::vector<int64_t> ret;\n    while(val != 0){\n      int r = val % b;\n\
    \      if(r < 0) r += b;\n      val = (val - r) / base;\n      ret.push_back(r);\n\
    \    }\n\n    std::reverse(ret.begin(), ret.end());\n\n    return ret;\n  }\n\n\
    \  int64_t convert_base_from(const std::vector<int64_t> &val, int64_t base){\n\
    \    int64_t ret = 0;\n    for(auto it = val.begin(); it != val.end(); ++it){\n\
    \      (ret *= base) += *it;\n    }\n\n    return ret;\n  }\n}\n#line 3 \"Mylib/IO/join.cpp\"\
    \n#include <sstream>\n#include <string>\n\nnamespace haar_lib {\n  template <typename\
    \ Iter>\n  std::string join(Iter first, Iter last, std::string delim = \" \"){\n\
    \    std::stringstream s;\n\n    for(auto it = first; it != last; ++it){\n   \
    \   if(it != first) s << delim;\n      s << *it;\n    }\n\n    return s.str();\n\
    \  }\n}\n#line 4 \"Mylib/IO/input_tuples.cpp\"\n#include <tuple>\n#include <utility>\n\
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
    \ 7 \"test/yukicoder/782/main.test.cpp\"\n\nnamespace hl = haar_lib;\n\nint main(){\n\
    \  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  int T, B; std::cin\
    \ >> T >> B;\n  for(auto [N] : hl::input_tuples<int>(T)){\n    auto ans = hl::convert_base_to(N,\
    \ B);\n\n    std::cout << hl::join(ans.begin(), ans.end(), \"\") << \"\\n\";\n\
    \  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/782\"\n\n#include <iostream>\n\
    #include \"Mylib/Misc/convert_base.cpp\"\n#include \"Mylib/IO/join.cpp\"\n#include\
    \ \"Mylib/IO/input_tuples.cpp\"\n\nnamespace hl = haar_lib;\n\nint main(){\n \
    \ std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  int T, B; std::cin\
    \ >> T >> B;\n  for(auto [N] : hl::input_tuples<int>(T)){\n    auto ans = hl::convert_base_to(N,\
    \ B);\n\n    std::cout << hl::join(ans.begin(), ans.end(), \"\") << \"\\n\";\n\
    \  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Misc/convert_base.cpp
  - Mylib/IO/join.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  isVerificationFile: true
  path: test/yukicoder/782/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yukicoder/782/main.test.cpp
layout: document
redirect_from:
- /verify/test/yukicoder/782/main.test.cpp
- /verify/test/yukicoder/782/main.test.cpp.html
title: test/yukicoder/782/main.test.cpp
---
