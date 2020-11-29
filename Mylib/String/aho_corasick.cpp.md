---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/430/main.aho_corasick.test.cpp
    title: test/yukicoder/430/main.aho_corasick.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/String/aho_corasick.cpp\"\n#include <vector>\n#include\
    \ <unordered_map>\n#include <string>\n#include <queue>\n\nnamespace haar_lib {\n\
    \  class aho_corasick {\n    int n_;\n    std::vector<std::unordered_map<char,\
    \ int>> trie_;\n    std::vector<int> failure_edge_;\n    std::vector<std::string>\
    \ dict_;\n    std::vector<std::vector<int>> dict_index_;\n\n  public:\n    aho_corasick():\
    \ n_(1), trie_(1), failure_edge_(1){}\n\n    void add(const std::string &s){\n\
    \      dict_.push_back(s);\n\n      int cur = 0;\n\n      for(int i = 0; i < (int)s.size();\
    \ ++i){\n        char c = s[i];\n\n        if(trie_[cur].find(c) != trie_[cur].end()){\n\
    \          cur = trie_[cur][c];\n        }else{\n          ++n_;\n          trie_.resize(n_);\n\
    \n          trie_[cur][c] = n_ - 1;\n\n          cur = trie_[cur][c];\n      \
    \  }\n      }\n\n      dict_index_.resize(n_);\n      dict_index_[cur].push_back(dict_.size()\
    \ - 1);\n    }\n\n    void build(){\n      failure_edge_.resize(n_);\n\n     \
    \ std::queue<int> dq;\n      dq.push(0);\n\n      while(not dq.empty()){\n   \
    \     int cur = dq.front(); dq.pop();\n\n        for(auto &kv : trie_[cur]){\n\
    \          char c = kv.first;\n          int next = kv.second;\n\n          if(cur\
    \ == 0){\n            failure_edge_[next] = 0;\n\n          }else{\n         \
    \   int i = failure_edge_[cur];\n            int j = 0;\n\n            while(1){\n\
    \              if(trie_[i].find(c) != trie_[i].end()){\n                j = trie_[i][c];\n\
    \                break;\n              }else{\n                if(i == 0) break;\n\
    \                i = failure_edge_[i];\n              }\n            }\n\n   \
    \         failure_edge_[next] = j;\n\n            for(auto k : dict_index_[failure_edge_[next]]){\n\
    \              dict_index_[next].push_back(k);\n            }\n          }\n\n\
    \          dq.push(next);\n        }\n      }\n    }\n\n    template <typename\
    \ Func> // function<void(int, int)>\n    void match(const std::string &s, const\
    \ Func &f){\n      int cur = 0;\n\n      for(int i = 0; i < (int)s.size(); ++i){\n\
    \        const char c = s[i];\n\n        while(cur != 0 and trie_[cur].find(c)\
    \ == trie_[cur].end()){\n          cur = failure_edge_[cur];\n        }\n\n  \
    \      cur = trie_[cur][c];\n\n        for(auto j : dict_index_[cur]){\n     \
    \     const int len = dict_[j].size();\n          f(i - len + 1, len);\n     \
    \   }\n      }\n    }\n  };\n}\n"
  code: "#pragma once\n#include <vector>\n#include <unordered_map>\n#include <string>\n\
    #include <queue>\n\nnamespace haar_lib {\n  class aho_corasick {\n    int n_;\n\
    \    std::vector<std::unordered_map<char, int>> trie_;\n    std::vector<int> failure_edge_;\n\
    \    std::vector<std::string> dict_;\n    std::vector<std::vector<int>> dict_index_;\n\
    \n  public:\n    aho_corasick(): n_(1), trie_(1), failure_edge_(1){}\n\n    void\
    \ add(const std::string &s){\n      dict_.push_back(s);\n\n      int cur = 0;\n\
    \n      for(int i = 0; i < (int)s.size(); ++i){\n        char c = s[i];\n\n  \
    \      if(trie_[cur].find(c) != trie_[cur].end()){\n          cur = trie_[cur][c];\n\
    \        }else{\n          ++n_;\n          trie_.resize(n_);\n\n          trie_[cur][c]\
    \ = n_ - 1;\n\n          cur = trie_[cur][c];\n        }\n      }\n\n      dict_index_.resize(n_);\n\
    \      dict_index_[cur].push_back(dict_.size() - 1);\n    }\n\n    void build(){\n\
    \      failure_edge_.resize(n_);\n\n      std::queue<int> dq;\n      dq.push(0);\n\
    \n      while(not dq.empty()){\n        int cur = dq.front(); dq.pop();\n\n  \
    \      for(auto &kv : trie_[cur]){\n          char c = kv.first;\n          int\
    \ next = kv.second;\n\n          if(cur == 0){\n            failure_edge_[next]\
    \ = 0;\n\n          }else{\n            int i = failure_edge_[cur];\n        \
    \    int j = 0;\n\n            while(1){\n              if(trie_[i].find(c) !=\
    \ trie_[i].end()){\n                j = trie_[i][c];\n                break;\n\
    \              }else{\n                if(i == 0) break;\n                i =\
    \ failure_edge_[i];\n              }\n            }\n\n            failure_edge_[next]\
    \ = j;\n\n            for(auto k : dict_index_[failure_edge_[next]]){\n      \
    \        dict_index_[next].push_back(k);\n            }\n          }\n\n     \
    \     dq.push(next);\n        }\n      }\n    }\n\n    template <typename Func>\
    \ // function<void(int, int)>\n    void match(const std::string &s, const Func\
    \ &f){\n      int cur = 0;\n\n      for(int i = 0; i < (int)s.size(); ++i){\n\
    \        const char c = s[i];\n\n        while(cur != 0 and trie_[cur].find(c)\
    \ == trie_[cur].end()){\n          cur = failure_edge_[cur];\n        }\n\n  \
    \      cur = trie_[cur][c];\n\n        for(auto j : dict_index_[cur]){\n     \
    \     const int len = dict_[j].size();\n          f(i - len + 1, len);\n     \
    \   }\n      }\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/String/aho_corasick.cpp
  requiredBy: []
  timestamp: '2020-09-28 09:27:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/430/main.aho_corasick.test.cpp
documentation_of: Mylib/String/aho_corasick.cpp
layout: document
title: Aho-Corasick algorithm
---

## Operations

## Requirements

## Notes

## Problems

## References
