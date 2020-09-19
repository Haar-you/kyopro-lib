---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Mylib/String/aho_corasick.cpp
    title: Aho-Corasick algorithm
  - icon: ':question:'
    path: Mylib/IO/input_vector.cpp
    title: Mylib/IO/input_vector.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://yukicoder.me/problems/no/430
    links:
    - https://yukicoder.me/problems/no/430
  bundledCode: "#line 1 \"test/yukicoder/430/main.aho_corasick.test.cpp\"\n#define\
    \ PROBLEM \"https://yukicoder.me/problems/no/430\"\n\n#include <iostream>\n#include\
    \ <string>\n#include <vector>\n#line 3 \"Mylib/String/aho_corasick.cpp\"\n#include\
    \ <unordered_map>\n#line 5 \"Mylib/String/aho_corasick.cpp\"\n#include <queue>\n\
    \nnamespace haar_lib {\n  class aho_corasick {\n  public:\n    int n;\n    std::vector<std::unordered_map<char,\
    \ int>> trie;\n    std::vector<int> failure_edge;\n    std::vector<std::string>\
    \ dict;\n    std::vector<std::vector<int>> dict_index;\n\n    aho_corasick():\
    \ n(1), trie(1), failure_edge(1){}\n\n    void add(const std::string &s){\n  \
    \    dict.push_back(s);\n\n      int cur = 0;\n\n      for(int i = 0; i < (int)s.size();\
    \ ++i){\n        char c = s[i];\n\n        if(trie[cur].find(c) != trie[cur].end()){\n\
    \          cur = trie[cur][c];\n        }else{\n          ++n;\n          trie.resize(n);\n\
    \n          trie[cur][c] = n - 1;\n\n          cur = trie[cur][c];\n        }\n\
    \      }\n\n      dict_index.resize(n);\n      dict_index[cur].push_back(dict.size()\
    \ - 1);\n    }\n\n    void build(){\n      failure_edge.resize(n);\n\n      std::queue<int>\
    \ dq;\n      dq.push(0);\n\n      while(not dq.empty()){\n        int cur = dq.front();\
    \ dq.pop();\n\n        for(auto &kv : trie[cur]){\n          char c = kv.first;\n\
    \          int next = kv.second;\n\n          if(cur == 0){\n            failure_edge[next]\
    \ = 0;\n\n          }else{\n            int i = failure_edge[cur];\n         \
    \   int j = 0;\n\n            while(1){\n              if(trie[i].find(c) != trie[i].end()){\n\
    \                j = trie[i][c];\n                break;\n              }else{\n\
    \                if(i == 0) break;\n                i = failure_edge[i];\n   \
    \           }\n            }\n\n            failure_edge[next] = j;\n\n      \
    \      for(auto k : dict_index[failure_edge[next]]){\n              dict_index[next].push_back(k);\n\
    \            }\n          }\n\n          dq.push(next);\n        }\n      }\n\
    \    }\n\n    template <typename Func> // function<void(int, int)>\n    void match(const\
    \ std::string &s, const Func &f){\n      int cur = 0;\n\n      for(int i = 0;\
    \ i < (int)s.size(); ++i){\n        char c = s[i];\n\n        while(cur != 0 and\
    \ trie[cur].find(c) == trie[cur].end()){\n          cur = failure_edge[cur];\n\
    \        }\n\n        cur = trie[cur][c];\n\n        for(auto j : dict_index[cur]){\n\
    \          int len = dict[j].size();\n          f(i - len + 1, len);\n       \
    \ }\n      }\n    }\n  };\n}\n#line 4 \"Mylib/IO/input_vector.cpp\"\n\nnamespace\
    \ haar_lib {\n  template <typename T>\n  std::vector<T> input_vector(int N){\n\
    \    std::vector<T> ret(N);\n    for(int i = 0; i < N; ++i) std::cin >> ret[i];\n\
    \    return ret;\n  }\n\n  template <typename T>\n  std::vector<std::vector<T>>\
    \ input_vector(int N, int M){\n    std::vector<std::vector<T>> ret(N);\n    for(int\
    \ i = 0; i < N; ++i) ret[i] = input_vector<T>(M);\n    return ret;\n  }\n}\n#line\
    \ 8 \"test/yukicoder/430/main.aho_corasick.test.cpp\"\n\nnamespace hl = haar_lib;\n\
    \nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  std::string\
    \ S; std::cin >> S;\n  int M; std::cin >> M;\n\n  auto C = hl::input_vector<std::string>(M);\n\
    \n  hl::aho_corasick ac;\n  for(int i = 0; i < M; ++i){\n    ac.add(C[i]);\n \
    \ }\n\n  ac.build();\n\n  int ans = 0;\n  ac.match(S, [&](int, int){++ans;});\n\
    \n  std::cout << ans << std::endl;\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://yukicoder.me/problems/no/430\"\n\n#include <iostream>\n\
    #include <string>\n#include <vector>\n#include \"Mylib/String/aho_corasick.cpp\"\
    \n#include \"Mylib/IO/input_vector.cpp\"\n\nnamespace hl = haar_lib;\n\nint main(){\n\
    \  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  std::string S; std::cin\
    \ >> S;\n  int M; std::cin >> M;\n\n  auto C = hl::input_vector<std::string>(M);\n\
    \n  hl::aho_corasick ac;\n  for(int i = 0; i < M; ++i){\n    ac.add(C[i]);\n \
    \ }\n\n  ac.build();\n\n  int ans = 0;\n  ac.match(S, [&](int, int){++ans;});\n\
    \n  std::cout << ans << std::endl;\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/String/aho_corasick.cpp
  - Mylib/IO/input_vector.cpp
  isVerificationFile: true
  path: test/yukicoder/430/main.aho_corasick.test.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yukicoder/430/main.aho_corasick.test.cpp
layout: document
redirect_from:
- /verify/test/yukicoder/430/main.aho_corasick.test.cpp
- /verify/test/yukicoder/430/main.aho_corasick.test.cpp.html
title: test/yukicoder/430/main.aho_corasick.test.cpp
---
