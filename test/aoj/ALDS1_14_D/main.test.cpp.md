---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/IO/input_tuple.cpp
    title: Input tuple
  - icon: ':question:'
    path: Mylib/IO/input_tuples.cpp
    title: Input tuples
  - icon: ':question:'
    path: Mylib/String/suffix_array.cpp
    title: Suffix array
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_D
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_D
  bundledCode: "#line 1 \"test/aoj/ALDS1_14_D/main.test.cpp\"\n#define PROBLEM \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_D\"\n\n#include\
    \ <iostream>\n#include <string>\n#line 3 \"Mylib/IO/input_tuples.cpp\"\n#include\
    \ <vector>\n#include <tuple>\n#include <utility>\n#include <initializer_list>\n\
    #line 6 \"Mylib/IO/input_tuple.cpp\"\n\nnamespace haar_lib {\n  template <typename\
    \ T, size_t ... I>\n  static void input_tuple_helper(std::istream &s, T &val,\
    \ std::index_sequence<I ...>){\n    (void)std::initializer_list<int>{(void(s >>\
    \ std::get<I>(val)), 0) ...};\n  }\n\n  template <typename T, typename U>\n  std::istream&\
    \ operator>>(std::istream &s, std::pair<T, U> &value){\n    s >> value.first >>\
    \ value.second;\n    return s;\n  }\n\n  template <typename ... Args>\n  std::istream&\
    \ operator>>(std::istream &s, std::tuple<Args ...> &value){\n    input_tuple_helper(s,\
    \ value, std::make_index_sequence<sizeof ... (Args)>());\n    return s;\n  }\n\
    }\n#line 8 \"Mylib/IO/input_tuples.cpp\"\n\nnamespace haar_lib {\n  template <typename\
    \ ... Args>\n  class InputTuples {\n    struct iter {\n      using value_type\
    \ = std::tuple<Args ...>;\n      value_type value;\n      bool fetched = false;\n\
    \      int N, c = 0;\n\n      value_type operator*(){\n        if(not fetched){\n\
    \          std::cin >> value;\n        }\n        return value;\n      }\n\n \
    \     void operator++(){\n        ++c;\n        fetched = false;\n      }\n\n\
    \      bool operator!=(iter &) const {\n        return c < N;\n      }\n\n   \
    \   iter(int N): N(N){}\n    };\n\n    int N;\n\n  public:\n    InputTuples(int\
    \ N): N(N){}\n\n    iter begin() const {return iter(N);}\n    iter end() const\
    \ {return iter(N);}\n  };\n\n  template <typename ... Args>\n  auto input_tuples(int\
    \ N){\n    return InputTuples<Args ...>(N);\n  }\n}\n#line 4 \"Mylib/String/suffix_array.cpp\"\
    \n#include <algorithm>\n#include <deque>\n\nnamespace haar_lib {\n  template <typename\
    \ Container>\n  class suffix_array {\n    Container s_;\n    int N_;\n    std::vector<int>\
    \ data_;\n\n  public:\n    suffix_array(){}\n    suffix_array(Container s): s_(s),\
    \ N_(s_.size()), data_(N_){\n      if(N_ == 1){\n        data_ = {1, 0};\n   \
    \     return;\n      }\n\n      s_.resize(N_ + 1);\n\n      std::string LS(N_\
    \ + 1, 'S');\n      for(int i = N_; --i >= 0;){\n        if(s_[i] < s_[i + 1])\
    \ LS[i] = 'S';\n        else if(s_[i] > s_[i + 1]) LS[i] = 'L';\n        else\
    \ LS[i] = LS[i + 1];\n      }\n\n      const int bucket_count = *std::max_element(s_.begin(),\
    \ s_.end());\n      std::vector<int> bucket_size(bucket_count + 1);\n      for(auto\
    \ x : s_) bucket_size[x] += 1;\n\n      auto induced_sort =\n        [&](std::vector<int>\
    \ LMS){\n          std::vector<int> bucket(N_ + 1, -1);\n          std::vector<bool>\
    \ is_lms(N_ + 1);\n\n          std::vector<std::deque<int>> empty(bucket_count\
    \ + 1);\n\n          for(int i = 0, k = 0; i <= bucket_count; ++i){\n        \
    \    for(int j = 0; j < bucket_size[i]; ++j){\n              empty[i].push_back(k);\n\
    \              ++k;\n            }\n          }\n\n          std::reverse(LMS.begin(),\
    \ LMS.end());\n          for(auto x : LMS){\n            int i = empty[s_[x]].back();\
    \ empty[s_[x]].pop_back();\n\n            bucket[i] = x;\n            is_lms[i]\
    \ = true;\n          }\n\n          for(int i = 0; i <= N_; ++i){\n          \
    \  if(bucket[i] >= 1 and LS[bucket[i] - 1] == 'L'){\n              auto x = s_[bucket[i]\
    \ - 1];\n              int j = empty[x].front(); empty[x].pop_front();\n     \
    \         bucket[j] = bucket[i] - 1;\n            }\n          }\n\n         \
    \ for(int i = 0; i <= N_; ++i){\n            if(is_lms[i]){\n              bucket[i]\
    \ = -1;\n            }\n          }\n\n          for(int i = 0, k = 0; i <= bucket_count;\
    \ ++i){\n            empty[i].clear();\n\n            for(int j = 0; j < bucket_size[i];\
    \ ++j){\n              empty[i].push_back(k);\n              ++k;\n          \
    \  }\n          }\n\n          for(int i = N_; i >= 0; --i){\n            if(bucket[i]\
    \ >= 1 and LS[bucket[i] - 1] == 'S'){\n              auto x = s_[bucket[i] - 1];\n\
    \              int j = empty[x].back(); empty[x].pop_back();\n              bucket[j]\
    \ = bucket[i] - 1;\n            }\n          }\n\n          bucket[0] = N_;\n\
    \          return bucket;\n        };\n\n      std::vector<int> LMS;\n      for(int\
    \ i = 1; i <= N_; ++i){\n        if(LS[i] == 'S' and LS[i - 1] == 'L'){\n    \
    \      LMS.push_back(i);\n        }\n      }\n\n      std::vector<int> LMS_bucket_length(N_\
    \ + 1, 1);\n      for(int i = 0; i < (int)LMS.size() - 1; ++i){\n        LMS_bucket_length[LMS[i]]\
    \ = LMS[i + 1] - LMS[i] + 1;\n      }\n\n      auto bucket = induced_sort(LMS);\n\
    \n      std::vector<int> LMS_substr_sorted;\n      for(int i : bucket){\n    \
    \    if(i > 0 and LS[i - 1] == 'L' and LS[i] == 'S'){\n          LMS_substr_sorted.push_back(i);\n\
    \        }\n      }\n\n      std::vector<int> rank(N_ + 1);\n      rank[LMS_substr_sorted[0]]\
    \ = 1;\n\n      for(int i = 1, k = 1; i < (int)LMS_substr_sorted.size(); ++i){\n\
    \        const int x = LMS_substr_sorted[i - 1], y = LMS_substr_sorted[i];\n\n\
    \        bool eq = true;\n        if(LMS_bucket_length[x] != LMS_bucket_length[y])\
    \ eq = false;\n        else{\n          for(int j = 0; j < LMS_bucket_length[x];\
    \ ++j){\n            if(s_[x + j] != s_[y + j]) eq = false;\n          }\n   \
    \     }\n\n        if(not eq) ++k;\n        rank[y] = k;\n      }\n\n      std::vector<int>\
    \ t;\n      for(int i = 0; i <= N_; ++i){\n        if(rank[i] != 0) t.push_back(rank[i]);\n\
    \      }\n\n      auto sa = suffix_array<std::vector<int>>(t);\n\n      std::vector<int>\
    \ LMS_sorted;\n      for(int i = 1; i < (int)sa.size(); ++i){\n        LMS_sorted.push_back(LMS[sa[i]]);\n\
    \      }\n\n      data_ = induced_sort(LMS_sorted);\n    }\n\n    int operator[](size_t\
    \ i) const {return data_[i];}\n    auto begin() const {return data_.begin();}\n\
    \    auto end() const {return data_.end();}\n    size_t size() const {return data_.size();}\n\
    \    const auto& data() const {return data_;}\n    const auto& str() const {return\
    \ s_;}\n\n    int lower_bound(const Container &a) const {\n      auto check =\n\
    \        [&](int x){\n          for(int i = 0; i < (int)a.size(); ++i){\n    \
    \        if(data_[x] + i >= (int)s_.size()) return false;\n            if(a[i]\
    \ < s_[data_[x] + i]) return true;\n            if(a[i] > s_[data_[x] + i]) return\
    \ false;\n          }\n          return true;\n        };\n\n      int lb = -1,\
    \ ub = size();\n      while(std::abs(lb - ub) > 1){\n        int mid = (lb + ub)\
    \ / 2;\n        if(check(mid)) ub = mid;\n        else lb = mid;\n      }\n\n\
    \      return ub;\n    }\n\n    int upper_bound(const Container &s) const {\n\
    \      Container t(s);\n\n      ++t.back();\n      int ret = lower_bound(t);\n\
    \n      return ret;\n    }\n  };\n}\n#line 7 \"test/aoj/ALDS1_14_D/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  std::string T; std::cin >> T;\n  int Q; std::cin >> Q;\n\n  auto sa = hl::suffix_array(T);\n\
    \n  for(auto [P] : hl::input_tuples<std::string>(Q)){\n    bool ans = sa.upper_bound(P)\
    \ - sa.lower_bound(P) > 0;\n    std::cout << ans << \"\\n\";\n  }\n\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_D\"\
    \n\n#include <iostream>\n#include <string>\n#include \"Mylib/IO/input_tuples.cpp\"\
    \n#include \"Mylib/String/suffix_array.cpp\"\n\nnamespace hl = haar_lib;\n\nint\
    \ main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  std::string\
    \ T; std::cin >> T;\n  int Q; std::cin >> Q;\n\n  auto sa = hl::suffix_array(T);\n\
    \n  for(auto [P] : hl::input_tuples<std::string>(Q)){\n    bool ans = sa.upper_bound(P)\
    \ - sa.lower_bound(P) > 0;\n    std::cout << ans << \"\\n\";\n  }\n\n  return\
    \ 0;\n}\n"
  dependsOn:
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  - Mylib/String/suffix_array.cpp
  isVerificationFile: true
  path: test/aoj/ALDS1_14_D/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-28 09:27:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ALDS1_14_D/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1_14_D/main.test.cpp
- /verify/test/aoj/ALDS1_14_D/main.test.cpp.html
title: test/aoj/ALDS1_14_D/main.test.cpp
---
