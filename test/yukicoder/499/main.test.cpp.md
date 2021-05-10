---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/IO/join.cpp
    title: join function
  - icon: ':x:'
    path: Mylib/Misc/convert_base.cpp
    title: Convert base
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/499
    links:
    - https://yukicoder.me/problems/no/499
  bundledCode: "#line 1 \"test/yukicoder/499/main.test.cpp\"\n#define PROBLEM \"https://yukicoder.me/problems/no/499\"\
    \n\n#include <algorithm>\n#include <iostream>\n#line 3 \"Mylib/IO/join.cpp\"\n\
    #include <sstream>\n#include <string>\n\nnamespace haar_lib {\n  template <typename\
    \ Iter>\n  std::string join(Iter first, Iter last, std::string delim = \" \")\
    \ {\n    std::stringstream s;\n\n    for (auto it = first; it != last; ++it) {\n\
    \      if (it != first) s << delim;\n      s << *it;\n    }\n\n    return s.str();\n\
    \  }\n}  // namespace haar_lib\n#line 3 \"Mylib/Misc/convert_base.cpp\"\n#include\
    \ <vector>\n\nnamespace haar_lib {\n  std::vector<int64_t> convert_base_to(int64_t\
    \ val, int64_t base) {\n    if (val == 0) return {0};\n\n    int b = std::abs(base);\n\
    \n    std::vector<int64_t> ret;\n    while (val != 0) {\n      int r = val % b;\n\
    \      if (r < 0) r += b;\n      val = (val - r) / base;\n      ret.push_back(r);\n\
    \    }\n\n    std::reverse(ret.begin(), ret.end());\n\n    return ret;\n  }\n\n\
    \  int64_t convert_base_from(const std::vector<int64_t> &val, int64_t base) {\n\
    \    int64_t ret = 0;\n    for (auto it = val.begin(); it != val.end(); ++it)\
    \ {\n      (ret *= base) += *it;\n    }\n\n    return ret;\n  }\n}  // namespace\
    \ haar_lib\n#line 7 \"test/yukicoder/499/main.test.cpp\"\n\nnamespace hl = haar_lib;\n\
    \nint main() {\n  int N;\n  std::cin >> N;\n\n  auto res = hl::convert_base_to(N,\
    \ 7);\n\n  std::cout << hl::join(res.begin(), res.end(), \"\") << \"\\n\";\n\n\
    \  return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/499\"\n\n#include <algorithm>\n\
    #include <iostream>\n#include \"Mylib/IO/join.cpp\"\n#include \"Mylib/Misc/convert_base.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main() {\n  int N;\n  std::cin >> N;\n\n \
    \ auto res = hl::convert_base_to(N, 7);\n\n  std::cout << hl::join(res.begin(),\
    \ res.end(), \"\") << \"\\n\";\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/IO/join.cpp
  - Mylib/Misc/convert_base.cpp
  isVerificationFile: true
  path: test/yukicoder/499/main.test.cpp
  requiredBy: []
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yukicoder/499/main.test.cpp
layout: document
redirect_from:
- /verify/test/yukicoder/499/main.test.cpp
- /verify/test/yukicoder/499/main.test.cpp.html
title: test/yukicoder/499/main.test.cpp
---