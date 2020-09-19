---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: Mylib/String/lcp_array.cpp
    title: LCP(Longest Common Prefix) array
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/ALDS1_14_D/main.test.cpp
    title: test/aoj/ALDS1_14_D/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/suffixarray/main.test.cpp
    title: test/yosupo-judge/suffixarray/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/number_of_substrings/main.test.cpp
    title: test/yosupo-judge/number_of_substrings/main.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/String/suffix_array.cpp\"\n#include <string>\n#include\
    \ <vector>\n#include <algorithm>\n#include <deque>\n\nnamespace haar_lib {\n \
    \ template <typename Container>\n  struct suffix_array {\n    Container s;\n \
    \   int N;\n    std::vector<int> data;\n\n    suffix_array(Container s_): s(s_),\
    \ N(s.size()), data(N){\n      if(N == 1){\n        data = {1, 0};\n        return;\n\
    \      }\n\n      s.resize(N + 1);\n\n      std::string LS(N + 1, 'S');\n    \
    \  for(int i = N; --i >= 0;){\n        if(s[i] < s[i + 1]) LS[i] = 'S';\n    \
    \    else if(s[i] > s[i + 1]) LS[i] = 'L';\n        else LS[i] = LS[i + 1];\n\
    \      }\n\n      const int bucket_count = *std::max_element(s.begin(), s.end());\n\
    \      std::vector<int> bucket_size(bucket_count + 1);\n      for(auto x : s)\
    \ bucket_size[x] += 1;\n\n      auto induced_sort =\n        [&](std::vector<int>\
    \ LMS){\n          std::vector<int> bucket(N + 1, -1);\n          std::vector<bool>\
    \ is_lms(N + 1);\n\n          std::vector<std::deque<int>> empty(bucket_count\
    \ + 1);\n\n          for(int i = 0, k = 0; i <= bucket_count; ++i){\n        \
    \    for(int j = 0; j < bucket_size[i]; ++j){\n              empty[i].push_back(k);\n\
    \              ++k;\n            }\n          }\n\n          std::reverse(LMS.begin(),\
    \ LMS.end());\n          for(auto x : LMS){\n            int i = empty[s[x]].back();\
    \ empty[s[x]].pop_back();\n\n            bucket[i] = x;\n            is_lms[i]\
    \ = true;\n          }\n\n          for(int i = 0; i <= N; ++i){\n           \
    \ if(bucket[i] >= 1 and LS[bucket[i] - 1] == 'L'){\n              auto x = s[bucket[i]\
    \ - 1];\n              int j = empty[x].front(); empty[x].pop_front();\n     \
    \         bucket[j] = bucket[i] - 1;\n            }\n          }\n\n         \
    \ for(int i = 0; i <= N; ++i){\n            if(is_lms[i]){\n              bucket[i]\
    \ = -1;\n            }\n          }\n\n          for(int i = 0, k = 0; i <= bucket_count;\
    \ ++i){\n            empty[i].clear();\n\n            for(int j = 0; j < bucket_size[i];\
    \ ++j){\n              empty[i].push_back(k);\n              ++k;\n          \
    \  }\n          }\n\n          for(int i = N; i >= 0; --i){\n            if(bucket[i]\
    \ >= 1 and LS[bucket[i] - 1] == 'S'){\n              auto x = s[bucket[i] - 1];\n\
    \              int j = empty[x].back(); empty[x].pop_back();\n              bucket[j]\
    \ = bucket[i] - 1;\n            }\n          }\n\n          bucket[0] = N;\n \
    \         return bucket;\n        };\n\n      std::vector<int> LMS;\n      for(int\
    \ i = 1; i <= N; ++i){\n        if(LS[i] == 'S' and LS[i - 1] == 'L'){\n     \
    \     LMS.push_back(i);\n        }\n      }\n\n      std::vector<int> LMS_bucket_length(N\
    \ + 1, 1);\n      for(int i = 0; i < (int)LMS.size() - 1; ++i){\n        LMS_bucket_length[LMS[i]]\
    \ = LMS[i + 1] - LMS[i] + 1;\n      }\n\n      auto bucket = induced_sort(LMS);\n\
    \n      std::vector<int> LMS_substr_sorted;\n      for(int i : bucket){\n    \
    \    if(i > 0 and LS[i - 1] == 'L' and LS[i] == 'S'){\n          LMS_substr_sorted.push_back(i);\n\
    \        }\n      }\n\n      std::vector<int> rank(N + 1);\n      rank[LMS_substr_sorted[0]]\
    \ = 1;\n\n      for(int i = 1, k = 1; i < (int)LMS_substr_sorted.size(); ++i){\n\
    \        const int x = LMS_substr_sorted[i - 1], y = LMS_substr_sorted[i];\n\n\
    \        bool eq = true;\n        if(LMS_bucket_length[x] != LMS_bucket_length[y])\
    \ eq = false;\n        else{\n          for(int j = 0; j < LMS_bucket_length[x];\
    \ ++j){\n            if(s[x + j] != s[y + j]) eq = false;\n          }\n     \
    \   }\n\n        if(not eq) ++k;\n        rank[y] = k;\n      }\n\n      std::vector<int>\
    \ t;\n      for(int i = 0; i <= N; ++i){\n        if(rank[i] != 0) t.push_back(rank[i]);\n\
    \      }\n\n      auto sa = suffix_array<std::vector<int>>(t).data;\n\n      std::vector<int>\
    \ LMS_sorted;\n      for(int i = 1; i < (int)sa.size(); ++i){\n        LMS_sorted.push_back(LMS[sa[i]]);\n\
    \      }\n\n      data = induced_sort(LMS_sorted);\n    }\n\n    int operator[](size_t\
    \ i) const {return data[i];}\n    auto begin() const {return data.begin();}\n\
    \    auto end() const {return data.end();}\n    size_t size() const {return data.size();}\n\
    \n    int lower_bound(const Container &s_) const {\n      auto check =\n     \
    \   [&](int x){\n          for(int i = 0; i < (int)s_.size(); ++i){\n        \
    \    if(data[x] + i >= (int)s.size()) return false;\n            if(s_[i] < s[data[x]\
    \ + i]) return true;\n            if(s_[i] > s[data[x] + i]) return false;\n \
    \         }\n          return true;\n        };\n\n      int lb = -1, ub = size();\n\
    \      while(std::abs(lb - ub) > 1){\n        int mid = (lb + ub) / 2;\n     \
    \   if(check(mid)) ub = mid;\n        else lb = mid;\n      }\n\n      return\
    \ ub;\n    }\n\n    int upper_bound(const Container &s_) const {\n      Container\
    \ t(s_);\n\n      ++t.back();\n      int ret = lower_bound(t);\n\n      return\
    \ ret;\n    }\n  };\n}\n"
  code: "#pragma once\n#include <string>\n#include <vector>\n#include <algorithm>\n\
    #include <deque>\n\nnamespace haar_lib {\n  template <typename Container>\n  struct\
    \ suffix_array {\n    Container s;\n    int N;\n    std::vector<int> data;\n\n\
    \    suffix_array(Container s_): s(s_), N(s.size()), data(N){\n      if(N == 1){\n\
    \        data = {1, 0};\n        return;\n      }\n\n      s.resize(N + 1);\n\n\
    \      std::string LS(N + 1, 'S');\n      for(int i = N; --i >= 0;){\n       \
    \ if(s[i] < s[i + 1]) LS[i] = 'S';\n        else if(s[i] > s[i + 1]) LS[i] = 'L';\n\
    \        else LS[i] = LS[i + 1];\n      }\n\n      const int bucket_count = *std::max_element(s.begin(),\
    \ s.end());\n      std::vector<int> bucket_size(bucket_count + 1);\n      for(auto\
    \ x : s) bucket_size[x] += 1;\n\n      auto induced_sort =\n        [&](std::vector<int>\
    \ LMS){\n          std::vector<int> bucket(N + 1, -1);\n          std::vector<bool>\
    \ is_lms(N + 1);\n\n          std::vector<std::deque<int>> empty(bucket_count\
    \ + 1);\n\n          for(int i = 0, k = 0; i <= bucket_count; ++i){\n        \
    \    for(int j = 0; j < bucket_size[i]; ++j){\n              empty[i].push_back(k);\n\
    \              ++k;\n            }\n          }\n\n          std::reverse(LMS.begin(),\
    \ LMS.end());\n          for(auto x : LMS){\n            int i = empty[s[x]].back();\
    \ empty[s[x]].pop_back();\n\n            bucket[i] = x;\n            is_lms[i]\
    \ = true;\n          }\n\n          for(int i = 0; i <= N; ++i){\n           \
    \ if(bucket[i] >= 1 and LS[bucket[i] - 1] == 'L'){\n              auto x = s[bucket[i]\
    \ - 1];\n              int j = empty[x].front(); empty[x].pop_front();\n     \
    \         bucket[j] = bucket[i] - 1;\n            }\n          }\n\n         \
    \ for(int i = 0; i <= N; ++i){\n            if(is_lms[i]){\n              bucket[i]\
    \ = -1;\n            }\n          }\n\n          for(int i = 0, k = 0; i <= bucket_count;\
    \ ++i){\n            empty[i].clear();\n\n            for(int j = 0; j < bucket_size[i];\
    \ ++j){\n              empty[i].push_back(k);\n              ++k;\n          \
    \  }\n          }\n\n          for(int i = N; i >= 0; --i){\n            if(bucket[i]\
    \ >= 1 and LS[bucket[i] - 1] == 'S'){\n              auto x = s[bucket[i] - 1];\n\
    \              int j = empty[x].back(); empty[x].pop_back();\n              bucket[j]\
    \ = bucket[i] - 1;\n            }\n          }\n\n          bucket[0] = N;\n \
    \         return bucket;\n        };\n\n      std::vector<int> LMS;\n      for(int\
    \ i = 1; i <= N; ++i){\n        if(LS[i] == 'S' and LS[i - 1] == 'L'){\n     \
    \     LMS.push_back(i);\n        }\n      }\n\n      std::vector<int> LMS_bucket_length(N\
    \ + 1, 1);\n      for(int i = 0; i < (int)LMS.size() - 1; ++i){\n        LMS_bucket_length[LMS[i]]\
    \ = LMS[i + 1] - LMS[i] + 1;\n      }\n\n      auto bucket = induced_sort(LMS);\n\
    \n      std::vector<int> LMS_substr_sorted;\n      for(int i : bucket){\n    \
    \    if(i > 0 and LS[i - 1] == 'L' and LS[i] == 'S'){\n          LMS_substr_sorted.push_back(i);\n\
    \        }\n      }\n\n      std::vector<int> rank(N + 1);\n      rank[LMS_substr_sorted[0]]\
    \ = 1;\n\n      for(int i = 1, k = 1; i < (int)LMS_substr_sorted.size(); ++i){\n\
    \        const int x = LMS_substr_sorted[i - 1], y = LMS_substr_sorted[i];\n\n\
    \        bool eq = true;\n        if(LMS_bucket_length[x] != LMS_bucket_length[y])\
    \ eq = false;\n        else{\n          for(int j = 0; j < LMS_bucket_length[x];\
    \ ++j){\n            if(s[x + j] != s[y + j]) eq = false;\n          }\n     \
    \   }\n\n        if(not eq) ++k;\n        rank[y] = k;\n      }\n\n      std::vector<int>\
    \ t;\n      for(int i = 0; i <= N; ++i){\n        if(rank[i] != 0) t.push_back(rank[i]);\n\
    \      }\n\n      auto sa = suffix_array<std::vector<int>>(t).data;\n\n      std::vector<int>\
    \ LMS_sorted;\n      for(int i = 1; i < (int)sa.size(); ++i){\n        LMS_sorted.push_back(LMS[sa[i]]);\n\
    \      }\n\n      data = induced_sort(LMS_sorted);\n    }\n\n    int operator[](size_t\
    \ i) const {return data[i];}\n    auto begin() const {return data.begin();}\n\
    \    auto end() const {return data.end();}\n    size_t size() const {return data.size();}\n\
    \n    int lower_bound(const Container &s_) const {\n      auto check =\n     \
    \   [&](int x){\n          for(int i = 0; i < (int)s_.size(); ++i){\n        \
    \    if(data[x] + i >= (int)s.size()) return false;\n            if(s_[i] < s[data[x]\
    \ + i]) return true;\n            if(s_[i] > s[data[x] + i]) return false;\n \
    \         }\n          return true;\n        };\n\n      int lb = -1, ub = size();\n\
    \      while(std::abs(lb - ub) > 1){\n        int mid = (lb + ub) / 2;\n     \
    \   if(check(mid)) ub = mid;\n        else lb = mid;\n      }\n\n      return\
    \ ub;\n    }\n\n    int upper_bound(const Container &s_) const {\n      Container\
    \ t(s_);\n\n      ++t.back();\n      int ret = lower_bound(t);\n\n      return\
    \ ret;\n    }\n  };\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/String/suffix_array.cpp
  requiredBy:
  - Mylib/String/lcp_array.cpp
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/ALDS1_14_D/main.test.cpp
  - test/yosupo-judge/suffixarray/main.test.cpp
  - test/yosupo-judge/number_of_substrings/main.test.cpp
documentation_of: Mylib/String/suffix_array.cpp
layout: document
title: Suffix array
---

## Operations

## Requirements

## Notes

## Problems

## References
