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
    path: test/yosupo-judge/number_of_substrings/main.test.cpp
    title: test/yosupo-judge/number_of_substrings/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/suffixarray/main.test.cpp
    title: test/yosupo-judge/suffixarray/main.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"Mylib/String/suffix_array.cpp\"\n#include <algorithm>\n\
    #include <deque>\n#include <string>\n#include <vector>\n\nnamespace haar_lib {\n\
    \  template <typename Container>\n  class suffix_array {\n    Container s_;\n\
    \    int N_;\n    std::vector<int> data_;\n\n  public:\n    suffix_array() {}\n\
    \    suffix_array(Container s) : s_(s), N_(s_.size()), data_(N_) {\n      if (N_\
    \ == 1) {\n        data_ = {1, 0};\n        return;\n      }\n\n      s_.resize(N_\
    \ + 1);\n\n      std::string LS(N_ + 1, 'S');\n      for (int i = N_; --i >= 0;)\
    \ {\n        if (s_[i] < s_[i + 1])\n          LS[i] = 'S';\n        else if (s_[i]\
    \ > s_[i + 1])\n          LS[i] = 'L';\n        else\n          LS[i] = LS[i +\
    \ 1];\n      }\n\n      const int bucket_count = *std::max_element(s_.begin(),\
    \ s_.end());\n      std::vector<int> bucket_size(bucket_count + 1);\n      for\
    \ (auto x : s_) bucket_size[x] += 1;\n\n      auto induced_sort =\n          [&](std::vector<int>\
    \ LMS) {\n            std::vector<int> bucket(N_ + 1, -1);\n            std::vector<bool>\
    \ is_lms(N_ + 1);\n\n            std::vector<std::deque<int>> empty(bucket_count\
    \ + 1);\n\n            for (int i = 0, k = 0; i <= bucket_count; ++i) {\n    \
    \          for (int j = 0; j < bucket_size[i]; ++j) {\n                empty[i].push_back(k);\n\
    \                ++k;\n              }\n            }\n\n            std::reverse(LMS.begin(),\
    \ LMS.end());\n            for (auto x : LMS) {\n              int i = empty[s_[x]].back();\n\
    \              empty[s_[x]].pop_back();\n\n              bucket[i] = x;\n    \
    \          is_lms[i] = true;\n            }\n\n            for (int i = 0; i <=\
    \ N_; ++i) {\n              if (bucket[i] >= 1 and LS[bucket[i] - 1] == 'L') {\n\
    \                auto x = s_[bucket[i] - 1];\n                int j  = empty[x].front();\n\
    \                empty[x].pop_front();\n                bucket[j] = bucket[i]\
    \ - 1;\n              }\n            }\n\n            for (int i = 0; i <= N_;\
    \ ++i) {\n              if (is_lms[i]) {\n                bucket[i] = -1;\n  \
    \            }\n            }\n\n            for (int i = 0, k = 0; i <= bucket_count;\
    \ ++i) {\n              empty[i].clear();\n\n              for (int j = 0; j <\
    \ bucket_size[i]; ++j) {\n                empty[i].push_back(k);\n           \
    \     ++k;\n              }\n            }\n\n            for (int i = N_; i >=\
    \ 0; --i) {\n              if (bucket[i] >= 1 and LS[bucket[i] - 1] == 'S') {\n\
    \                auto x = s_[bucket[i] - 1];\n                int j  = empty[x].back();\n\
    \                empty[x].pop_back();\n                bucket[j] = bucket[i] -\
    \ 1;\n              }\n            }\n\n            bucket[0] = N_;\n        \
    \    return bucket;\n          };\n\n      std::vector<int> LMS;\n      for (int\
    \ i = 1; i <= N_; ++i) {\n        if (LS[i] == 'S' and LS[i - 1] == 'L') {\n \
    \         LMS.push_back(i);\n        }\n      }\n\n      std::vector<int> LMS_bucket_length(N_\
    \ + 1, 1);\n      for (int i = 0; i < (int) LMS.size() - 1; ++i) {\n        LMS_bucket_length[LMS[i]]\
    \ = LMS[i + 1] - LMS[i] + 1;\n      }\n\n      auto bucket = induced_sort(LMS);\n\
    \n      std::vector<int> LMS_substr_sorted;\n      for (int i : bucket) {\n  \
    \      if (i > 0 and LS[i - 1] == 'L' and LS[i] == 'S') {\n          LMS_substr_sorted.push_back(i);\n\
    \        }\n      }\n\n      std::vector<int> rank(N_ + 1);\n      rank[LMS_substr_sorted[0]]\
    \ = 1;\n\n      for (int i = 1, k = 1; i < (int) LMS_substr_sorted.size(); ++i)\
    \ {\n        const int x = LMS_substr_sorted[i - 1], y = LMS_substr_sorted[i];\n\
    \n        bool eq = true;\n        if (LMS_bucket_length[x] != LMS_bucket_length[y])\n\
    \          eq = false;\n        else {\n          for (int j = 0; j < LMS_bucket_length[x];\
    \ ++j) {\n            if (s_[x + j] != s_[y + j]) eq = false;\n          }\n \
    \       }\n\n        if (not eq) ++k;\n        rank[y] = k;\n      }\n\n     \
    \ std::vector<int> t;\n      for (int i = 0; i <= N_; ++i) {\n        if (rank[i]\
    \ != 0) t.push_back(rank[i]);\n      }\n\n      auto sa = suffix_array<std::vector<int>>(t);\n\
    \n      std::vector<int> LMS_sorted;\n      for (int i = 1; i < (int) sa.size();\
    \ ++i) {\n        LMS_sorted.push_back(LMS[sa[i]]);\n      }\n\n      data_ =\
    \ induced_sort(LMS_sorted);\n    }\n\n    int operator[](size_t i) const { return\
    \ data_[i]; }\n    auto begin() const { return data_.begin(); }\n    auto end()\
    \ const { return data_.end(); }\n    size_t size() const { return data_.size();\
    \ }\n    const auto& data() const { return data_; }\n    const auto& str() const\
    \ { return s_; }\n\n    int lower_bound(const Container& a) const {\n      auto\
    \ check =\n          [&](int x) {\n            for (int i = 0; i < (int) a.size();\
    \ ++i) {\n              if (data_[x] + i >= (int) s_.size()) return false;\n \
    \             if (a[i] < s_[data_[x] + i]) return true;\n              if (a[i]\
    \ > s_[data_[x] + i]) return false;\n            }\n            return true;\n\
    \          };\n\n      int lb = -1, ub = size();\n      while (std::abs(lb - ub)\
    \ > 1) {\n        int mid = (lb + ub) / 2;\n        if (check(mid))\n        \
    \  ub = mid;\n        else\n          lb = mid;\n      }\n\n      return ub;\n\
    \    }\n\n    int upper_bound(const Container& s) const {\n      Container t(s);\n\
    \n      ++t.back();\n      int ret = lower_bound(t);\n\n      return ret;\n  \
    \  }\n  };\n}  // namespace haar_lib\n"
  code: "#pragma once\n#include <algorithm>\n#include <deque>\n#include <string>\n\
    #include <vector>\n\nnamespace haar_lib {\n  template <typename Container>\n \
    \ class suffix_array {\n    Container s_;\n    int N_;\n    std::vector<int> data_;\n\
    \n  public:\n    suffix_array() {}\n    suffix_array(Container s) : s_(s), N_(s_.size()),\
    \ data_(N_) {\n      if (N_ == 1) {\n        data_ = {1, 0};\n        return;\n\
    \      }\n\n      s_.resize(N_ + 1);\n\n      std::string LS(N_ + 1, 'S');\n \
    \     for (int i = N_; --i >= 0;) {\n        if (s_[i] < s_[i + 1])\n        \
    \  LS[i] = 'S';\n        else if (s_[i] > s_[i + 1])\n          LS[i] = 'L';\n\
    \        else\n          LS[i] = LS[i + 1];\n      }\n\n      const int bucket_count\
    \ = *std::max_element(s_.begin(), s_.end());\n      std::vector<int> bucket_size(bucket_count\
    \ + 1);\n      for (auto x : s_) bucket_size[x] += 1;\n\n      auto induced_sort\
    \ =\n          [&](std::vector<int> LMS) {\n            std::vector<int> bucket(N_\
    \ + 1, -1);\n            std::vector<bool> is_lms(N_ + 1);\n\n            std::vector<std::deque<int>>\
    \ empty(bucket_count + 1);\n\n            for (int i = 0, k = 0; i <= bucket_count;\
    \ ++i) {\n              for (int j = 0; j < bucket_size[i]; ++j) {\n         \
    \       empty[i].push_back(k);\n                ++k;\n              }\n      \
    \      }\n\n            std::reverse(LMS.begin(), LMS.end());\n            for\
    \ (auto x : LMS) {\n              int i = empty[s_[x]].back();\n             \
    \ empty[s_[x]].pop_back();\n\n              bucket[i] = x;\n              is_lms[i]\
    \ = true;\n            }\n\n            for (int i = 0; i <= N_; ++i) {\n    \
    \          if (bucket[i] >= 1 and LS[bucket[i] - 1] == 'L') {\n              \
    \  auto x = s_[bucket[i] - 1];\n                int j  = empty[x].front();\n \
    \               empty[x].pop_front();\n                bucket[j] = bucket[i] -\
    \ 1;\n              }\n            }\n\n            for (int i = 0; i <= N_; ++i)\
    \ {\n              if (is_lms[i]) {\n                bucket[i] = -1;\n       \
    \       }\n            }\n\n            for (int i = 0, k = 0; i <= bucket_count;\
    \ ++i) {\n              empty[i].clear();\n\n              for (int j = 0; j <\
    \ bucket_size[i]; ++j) {\n                empty[i].push_back(k);\n           \
    \     ++k;\n              }\n            }\n\n            for (int i = N_; i >=\
    \ 0; --i) {\n              if (bucket[i] >= 1 and LS[bucket[i] - 1] == 'S') {\n\
    \                auto x = s_[bucket[i] - 1];\n                int j  = empty[x].back();\n\
    \                empty[x].pop_back();\n                bucket[j] = bucket[i] -\
    \ 1;\n              }\n            }\n\n            bucket[0] = N_;\n        \
    \    return bucket;\n          };\n\n      std::vector<int> LMS;\n      for (int\
    \ i = 1; i <= N_; ++i) {\n        if (LS[i] == 'S' and LS[i - 1] == 'L') {\n \
    \         LMS.push_back(i);\n        }\n      }\n\n      std::vector<int> LMS_bucket_length(N_\
    \ + 1, 1);\n      for (int i = 0; i < (int) LMS.size() - 1; ++i) {\n        LMS_bucket_length[LMS[i]]\
    \ = LMS[i + 1] - LMS[i] + 1;\n      }\n\n      auto bucket = induced_sort(LMS);\n\
    \n      std::vector<int> LMS_substr_sorted;\n      for (int i : bucket) {\n  \
    \      if (i > 0 and LS[i - 1] == 'L' and LS[i] == 'S') {\n          LMS_substr_sorted.push_back(i);\n\
    \        }\n      }\n\n      std::vector<int> rank(N_ + 1);\n      rank[LMS_substr_sorted[0]]\
    \ = 1;\n\n      for (int i = 1, k = 1; i < (int) LMS_substr_sorted.size(); ++i)\
    \ {\n        const int x = LMS_substr_sorted[i - 1], y = LMS_substr_sorted[i];\n\
    \n        bool eq = true;\n        if (LMS_bucket_length[x] != LMS_bucket_length[y])\n\
    \          eq = false;\n        else {\n          for (int j = 0; j < LMS_bucket_length[x];\
    \ ++j) {\n            if (s_[x + j] != s_[y + j]) eq = false;\n          }\n \
    \       }\n\n        if (not eq) ++k;\n        rank[y] = k;\n      }\n\n     \
    \ std::vector<int> t;\n      for (int i = 0; i <= N_; ++i) {\n        if (rank[i]\
    \ != 0) t.push_back(rank[i]);\n      }\n\n      auto sa = suffix_array<std::vector<int>>(t);\n\
    \n      std::vector<int> LMS_sorted;\n      for (int i = 1; i < (int) sa.size();\
    \ ++i) {\n        LMS_sorted.push_back(LMS[sa[i]]);\n      }\n\n      data_ =\
    \ induced_sort(LMS_sorted);\n    }\n\n    int operator[](size_t i) const { return\
    \ data_[i]; }\n    auto begin() const { return data_.begin(); }\n    auto end()\
    \ const { return data_.end(); }\n    size_t size() const { return data_.size();\
    \ }\n    const auto& data() const { return data_; }\n    const auto& str() const\
    \ { return s_; }\n\n    int lower_bound(const Container& a) const {\n      auto\
    \ check =\n          [&](int x) {\n            for (int i = 0; i < (int) a.size();\
    \ ++i) {\n              if (data_[x] + i >= (int) s_.size()) return false;\n \
    \             if (a[i] < s_[data_[x] + i]) return true;\n              if (a[i]\
    \ > s_[data_[x] + i]) return false;\n            }\n            return true;\n\
    \          };\n\n      int lb = -1, ub = size();\n      while (std::abs(lb - ub)\
    \ > 1) {\n        int mid = (lb + ub) / 2;\n        if (check(mid))\n        \
    \  ub = mid;\n        else\n          lb = mid;\n      }\n\n      return ub;\n\
    \    }\n\n    int upper_bound(const Container& s) const {\n      Container t(s);\n\
    \n      ++t.back();\n      int ret = lower_bound(t);\n\n      return ret;\n  \
    \  }\n  };\n}  // namespace haar_lib\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/String/suffix_array.cpp
  requiredBy:
  - Mylib/String/lcp_array.cpp
  timestamp: '2021-04-23 23:44:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo-judge/number_of_substrings/main.test.cpp
  - test/yosupo-judge/suffixarray/main.test.cpp
  - test/aoj/ALDS1_14_D/main.test.cpp
documentation_of: Mylib/String/suffix_array.cpp
layout: document
title: Suffix array
---

## Operations

## Requirements

## Notes

## Problems

## References
