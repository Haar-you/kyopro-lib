---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo-judge/inv_of_formal_power_series/main.test.cpp
    title: test/yosupo-judge/inv_of_formal_power_series/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/sharp_p_subset_sum/main.test.cpp
    title: test/yosupo-judge/sharp_p_subset_sum/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/bernoulli_number/main.test.cpp
    title: test/yosupo-judge/bernoulli_number/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/pow_of_formal_power_series/main.test.cpp
    title: test/yosupo-judge/pow_of_formal_power_series/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/log_of_formal_power_series/main.test.cpp
    title: test/yosupo-judge/log_of_formal_power_series/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/sqrt_of_formal_power_series/main.test.cpp
    title: test/yosupo-judge/sqrt_of_formal_power_series/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/exp_of_formal_power_series/main.test.cpp
    title: test/yosupo-judge/exp_of_formal_power_series/main.test.cpp
  - icon: ':x:'
    path: test/yosupo-judge/partition_function/main.fps.test.cpp
    title: test/yosupo-judge/partition_function/main.fps.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"Mylib/Math/formal_power_series.cpp\"\n#include <functional>\n\
    #include <vector>\n#include <initializer_list>\n#include <cassert>\n\nnamespace\
    \ haar_lib {\n  template <typename T>\n  struct formal_power_series {\n    using\
    \ value_type = T;\n\n    static std::function<std::vector<T>(std::vector<T>, std::vector<T>)>\
    \ convolve;\n    static std::function<std::optional<T>(T)> get_sqrt;\n\n    std::vector<T>\
    \ data;\n\n    formal_power_series(){}\n    explicit formal_power_series(int N):\
    \ data(N){}\n    formal_power_series(const std::vector<T> &data): data(data){}\n\
    \    formal_power_series(std::initializer_list<T> init): data(init.begin(), init.end()){}\n\
    \    formal_power_series(const formal_power_series &a): data(a.data){}\n    formal_power_series(formal_power_series\
    \ &&a) noexcept {*this = std::move(a);}\n\n    int size() const {\n      return\
    \ data.size();\n    }\n\n    const T& operator[](int i) const {\n      return\
    \ data[i];\n    }\n\n    T& operator[](int i){\n      return data[i];\n    }\n\
    \n    auto begin() {return data.begin();}\n    auto end() {return data.end();}\n\
    \n    void resize(int n){\n      data.resize(n);\n    }\n\n    auto& operator=(formal_power_series\
    \ &&rhs) noexcept {\n      if(this != &rhs){\n        data = std::move(rhs.data);\n\
    \      }\n      return *this;\n    }\n\n    auto& operator+=(const formal_power_series\
    \ &rhs){\n      if(data.size() < rhs.size()) data.resize(rhs.size());\n      for(int\
    \ i = 0; i < rhs.size(); ++i) data[i] += rhs[i];\n      return *this;\n    }\n\
    \n    auto& operator+=(T rhs){\n      data[0] += rhs;\n      return *this;\n \
    \   }\n\n    auto operator+(T rhs) const {\n      auto ret = *this;\n      return\
    \ ret += rhs;\n    }\n\n    auto operator+(const formal_power_series &rhs) const\
    \ {\n      auto ret = *this;\n      return ret += rhs;\n    }\n\n    auto& operator-=(const\
    \ formal_power_series &rhs){\n      if(data.size() < rhs.size()) data.resize(rhs.size());\n\
    \      for(int i = 0; i < rhs.size(); ++i) data[i] -= rhs[i];\n      return *this;\n\
    \    }\n\n    auto& operator-=(T rhs){\n      data[0] -= rhs;\n      return *this;\n\
    \    }\n\n    auto operator-(T rhs) const {\n      auto ret = *this;\n      return\
    \ ret -= rhs;\n    }\n\n    auto operator-(const formal_power_series &rhs) const\
    \ {\n      auto ret = *this;\n      return ret -= rhs;\n    }\n\n    auto operator-()\
    \ const {\n      auto ret = *this;\n      for(auto &x : ret) x = -x;\n      return\
    \ ret;\n    }\n\n    auto& operator*=(const formal_power_series &rhs){\n     \
    \ data = convolve(data, rhs.data);\n      return *this;\n    }\n\n    auto operator*(const\
    \ formal_power_series &rhs) const {\n      auto ret = convolve(data, rhs.data);\n\
    \      return formal_power_series(ret);\n    }\n\n    auto& operator*=(T rhs){\n\
    \      for(auto &x : data) x *= rhs;\n      return *this;\n    }\n\n    auto operator*(T\
    \ rhs) const {\n      auto ret = *this;\n      return ret *= rhs;\n    }\n\n \
    \   auto differentiate() const {\n      const int n = data.size();\n      std::vector<T>\
    \ ret(n - 1);\n      for(int i = 0; i < n - 1; ++i){\n        ret[i] = data[i\
    \ + 1] * (i + 1);\n      }\n\n      return formal_power_series(ret);\n    }\n\n\
    \    auto integrate() const {\n      const int n = data.size();\n      std::vector<T>\
    \ ret(n + 1);\n      for(int i = 0; i < n; ++i){\n        ret[i + 1] = data[i]\
    \ / (i + 1);\n      }\n\n      return formal_power_series(ret);\n    }\n\n   \
    \ auto inv() const {\n      assert(data[0] != 0);\n      const int n = data.size();\n\
    \n      int t = 1;\n      std::vector<T> ret = {data[0].inv()};\n      ret.reserve(n\
    \ * 2);\n\n      while(t <= n * 2){\n        std::vector<T> c(data.begin(), data.begin()\
    \ + std::min(t, n));\n        c = convolve(c, convolve(ret, ret));\n\n       \
    \ c.resize(t);\n        ret.resize(t);\n\n        for(int i = 0; i < t; ++i){\n\
    \          ret[i] = ret[i] * 2 - c[i];\n        }\n\n        t <<= 1;\n      }\n\
    \n      ret.resize(n);\n\n      return formal_power_series(ret);\n    }\n\n  \
    \  auto log() const {\n      assert(data[0] == 1);\n      const int n = data.size();\n\
    \      auto ret = (differentiate() * inv()).integrate();\n      ret.resize(n);\n\
    \      return ret;\n    }\n\n    auto exp() const {\n      const int n = data.size();\n\
    \n      int t = 1;\n      formal_power_series b({1});\n\n      while(t <= n *\
    \ 2){\n        t <<= 1;\n        auto temp = b.log();\n        temp.resize(t);\n\
    \n        for(int i = 0; i < t; ++i) temp[i] = -temp[i];\n        temp[0] += 1;\n\
    \        for(int i = 0; i < std::min(t, n); ++i) temp[i] += data[i];\n\n     \
    \   b = b * temp;\n        b.resize(t);\n      }\n\n      b.resize(n);\n\n   \
    \   return b;\n    }\n\n    auto shift(int64_t k) const {\n      const int64_t\
    \ n = data.size();\n      formal_power_series ret(n);\n\n      if(k >= 0){\n \
    \       for(int64_t i = k; i < n; ++i){\n          ret[i] = data[i - k];\n   \
    \     }\n      }else{\n        for(int64_t i = 0; i < n + k; ++i){\n         \
    \ ret[i] = data[i - k];\n        }\n      }\n\n      return ret;\n    }\n\n  \
    \  auto pow(int64_t M) const {\n      assert(M >= 0);\n\n      const int n = data.size();\n\
    \      int k = 0;\n      for(; k < n; ++k){\n        if(data[k] != 0){\n     \
    \     break;\n        }\n      }\n\n      if(k >= n) return *this;\n\n      T\
    \ a = data[k];\n\n      formal_power_series ret = *this;\n      ret = (ret.shift(-k))\
    \ * a.inv();\n      ret = (ret.log() * (T)M).exp();\n      ret = (ret * a.pow(M)).shift(M\
    \ * k);\n\n      return ret;\n    }\n\n    std::optional<formal_power_series>\
    \ sqrt() const {\n      const int n = data.size();\n      int k = 0;\n      for(;\
    \ k < n; ++k) if(data[k] != 0) break;\n\n      if(k >= n) return *this;\n    \
    \  if(k % 2 != 0) return {};\n\n      int t = 1;\n      auto x = get_sqrt(data[k]);\n\
    \n      if(not x) return {};\n\n      const int m = n - k;\n\n      auto it =\
    \ data.begin() + k;\n      formal_power_series ret({*x});\n\n      while(t <=\
    \ m * 2){\n        formal_power_series f(std::vector(it, it + std::min(t, m)));\n\
    \        ret.resize(t);\n        f.resize(t);\n        ret = (ret + f * ret.inv())\
    \ * T(2).inv();\n        t <<= 1;\n      }\n\n      ret.resize(n);\n      ret\
    \ = ret.shift(k / 2);\n\n      return ret;\n    }\n  };\n\n  template <typename\
    \ T>\n  std::function<std::vector<T>(std::vector<T>, std::vector<T>)> formal_power_series<T>::convolve;\n\
    \n  template <typename T>\n  std::function<std::optional<T>(T)> formal_power_series<T>::get_sqrt;\n\
    }\n"
  code: "#pragma once\n#include <functional>\n#include <vector>\n#include <initializer_list>\n\
    #include <cassert>\n\nnamespace haar_lib {\n  template <typename T>\n  struct\
    \ formal_power_series {\n    using value_type = T;\n\n    static std::function<std::vector<T>(std::vector<T>,\
    \ std::vector<T>)> convolve;\n    static std::function<std::optional<T>(T)> get_sqrt;\n\
    \n    std::vector<T> data;\n\n    formal_power_series(){}\n    explicit formal_power_series(int\
    \ N): data(N){}\n    formal_power_series(const std::vector<T> &data): data(data){}\n\
    \    formal_power_series(std::initializer_list<T> init): data(init.begin(), init.end()){}\n\
    \    formal_power_series(const formal_power_series &a): data(a.data){}\n    formal_power_series(formal_power_series\
    \ &&a) noexcept {*this = std::move(a);}\n\n    int size() const {\n      return\
    \ data.size();\n    }\n\n    const T& operator[](int i) const {\n      return\
    \ data[i];\n    }\n\n    T& operator[](int i){\n      return data[i];\n    }\n\
    \n    auto begin() {return data.begin();}\n    auto end() {return data.end();}\n\
    \n    void resize(int n){\n      data.resize(n);\n    }\n\n    auto& operator=(formal_power_series\
    \ &&rhs) noexcept {\n      if(this != &rhs){\n        data = std::move(rhs.data);\n\
    \      }\n      return *this;\n    }\n\n    auto& operator+=(const formal_power_series\
    \ &rhs){\n      if(data.size() < rhs.size()) data.resize(rhs.size());\n      for(int\
    \ i = 0; i < rhs.size(); ++i) data[i] += rhs[i];\n      return *this;\n    }\n\
    \n    auto& operator+=(T rhs){\n      data[0] += rhs;\n      return *this;\n \
    \   }\n\n    auto operator+(T rhs) const {\n      auto ret = *this;\n      return\
    \ ret += rhs;\n    }\n\n    auto operator+(const formal_power_series &rhs) const\
    \ {\n      auto ret = *this;\n      return ret += rhs;\n    }\n\n    auto& operator-=(const\
    \ formal_power_series &rhs){\n      if(data.size() < rhs.size()) data.resize(rhs.size());\n\
    \      for(int i = 0; i < rhs.size(); ++i) data[i] -= rhs[i];\n      return *this;\n\
    \    }\n\n    auto& operator-=(T rhs){\n      data[0] -= rhs;\n      return *this;\n\
    \    }\n\n    auto operator-(T rhs) const {\n      auto ret = *this;\n      return\
    \ ret -= rhs;\n    }\n\n    auto operator-(const formal_power_series &rhs) const\
    \ {\n      auto ret = *this;\n      return ret -= rhs;\n    }\n\n    auto operator-()\
    \ const {\n      auto ret = *this;\n      for(auto &x : ret) x = -x;\n      return\
    \ ret;\n    }\n\n    auto& operator*=(const formal_power_series &rhs){\n     \
    \ data = convolve(data, rhs.data);\n      return *this;\n    }\n\n    auto operator*(const\
    \ formal_power_series &rhs) const {\n      auto ret = convolve(data, rhs.data);\n\
    \      return formal_power_series(ret);\n    }\n\n    auto& operator*=(T rhs){\n\
    \      for(auto &x : data) x *= rhs;\n      return *this;\n    }\n\n    auto operator*(T\
    \ rhs) const {\n      auto ret = *this;\n      return ret *= rhs;\n    }\n\n \
    \   auto differentiate() const {\n      const int n = data.size();\n      std::vector<T>\
    \ ret(n - 1);\n      for(int i = 0; i < n - 1; ++i){\n        ret[i] = data[i\
    \ + 1] * (i + 1);\n      }\n\n      return formal_power_series(ret);\n    }\n\n\
    \    auto integrate() const {\n      const int n = data.size();\n      std::vector<T>\
    \ ret(n + 1);\n      for(int i = 0; i < n; ++i){\n        ret[i + 1] = data[i]\
    \ / (i + 1);\n      }\n\n      return formal_power_series(ret);\n    }\n\n   \
    \ auto inv() const {\n      assert(data[0] != 0);\n      const int n = data.size();\n\
    \n      int t = 1;\n      std::vector<T> ret = {data[0].inv()};\n      ret.reserve(n\
    \ * 2);\n\n      while(t <= n * 2){\n        std::vector<T> c(data.begin(), data.begin()\
    \ + std::min(t, n));\n        c = convolve(c, convolve(ret, ret));\n\n       \
    \ c.resize(t);\n        ret.resize(t);\n\n        for(int i = 0; i < t; ++i){\n\
    \          ret[i] = ret[i] * 2 - c[i];\n        }\n\n        t <<= 1;\n      }\n\
    \n      ret.resize(n);\n\n      return formal_power_series(ret);\n    }\n\n  \
    \  auto log() const {\n      assert(data[0] == 1);\n      const int n = data.size();\n\
    \      auto ret = (differentiate() * inv()).integrate();\n      ret.resize(n);\n\
    \      return ret;\n    }\n\n    auto exp() const {\n      const int n = data.size();\n\
    \n      int t = 1;\n      formal_power_series b({1});\n\n      while(t <= n *\
    \ 2){\n        t <<= 1;\n        auto temp = b.log();\n        temp.resize(t);\n\
    \n        for(int i = 0; i < t; ++i) temp[i] = -temp[i];\n        temp[0] += 1;\n\
    \        for(int i = 0; i < std::min(t, n); ++i) temp[i] += data[i];\n\n     \
    \   b = b * temp;\n        b.resize(t);\n      }\n\n      b.resize(n);\n\n   \
    \   return b;\n    }\n\n    auto shift(int64_t k) const {\n      const int64_t\
    \ n = data.size();\n      formal_power_series ret(n);\n\n      if(k >= 0){\n \
    \       for(int64_t i = k; i < n; ++i){\n          ret[i] = data[i - k];\n   \
    \     }\n      }else{\n        for(int64_t i = 0; i < n + k; ++i){\n         \
    \ ret[i] = data[i - k];\n        }\n      }\n\n      return ret;\n    }\n\n  \
    \  auto pow(int64_t M) const {\n      assert(M >= 0);\n\n      const int n = data.size();\n\
    \      int k = 0;\n      for(; k < n; ++k){\n        if(data[k] != 0){\n     \
    \     break;\n        }\n      }\n\n      if(k >= n) return *this;\n\n      T\
    \ a = data[k];\n\n      formal_power_series ret = *this;\n      ret = (ret.shift(-k))\
    \ * a.inv();\n      ret = (ret.log() * (T)M).exp();\n      ret = (ret * a.pow(M)).shift(M\
    \ * k);\n\n      return ret;\n    }\n\n    std::optional<formal_power_series>\
    \ sqrt() const {\n      const int n = data.size();\n      int k = 0;\n      for(;\
    \ k < n; ++k) if(data[k] != 0) break;\n\n      if(k >= n) return *this;\n    \
    \  if(k % 2 != 0) return {};\n\n      int t = 1;\n      auto x = get_sqrt(data[k]);\n\
    \n      if(not x) return {};\n\n      const int m = n - k;\n\n      auto it =\
    \ data.begin() + k;\n      formal_power_series ret({*x});\n\n      while(t <=\
    \ m * 2){\n        formal_power_series f(std::vector(it, it + std::min(t, m)));\n\
    \        ret.resize(t);\n        f.resize(t);\n        ret = (ret + f * ret.inv())\
    \ * T(2).inv();\n        t <<= 1;\n      }\n\n      ret.resize(n);\n      ret\
    \ = ret.shift(k / 2);\n\n      return ret;\n    }\n  };\n\n  template <typename\
    \ T>\n  std::function<std::vector<T>(std::vector<T>, std::vector<T>)> formal_power_series<T>::convolve;\n\
    \n  template <typename T>\n  std::function<std::optional<T>(T)> formal_power_series<T>::get_sqrt;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: Mylib/Math/formal_power_series.cpp
  requiredBy: []
  timestamp: '2020-09-23 00:48:51+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo-judge/inv_of_formal_power_series/main.test.cpp
  - test/yosupo-judge/sharp_p_subset_sum/main.test.cpp
  - test/yosupo-judge/bernoulli_number/main.test.cpp
  - test/yosupo-judge/pow_of_formal_power_series/main.test.cpp
  - test/yosupo-judge/log_of_formal_power_series/main.test.cpp
  - test/yosupo-judge/sqrt_of_formal_power_series/main.test.cpp
  - test/yosupo-judge/exp_of_formal_power_series/main.test.cpp
  - test/yosupo-judge/partition_function/main.fps.test.cpp
documentation_of: Mylib/Math/formal_power_series.cpp
layout: document
title: Formal power series
---

## Operations

## Requirements

## Notes

## Problems

## References

- [https://www.hamayanhamayan.com/entry/2019/12/07/000441](https://www.hamayanhamayan.com/entry/2019/12/07/000441)
- [https://www.hamayanhamayan.com/entry/2019/12/14/221205](https://www.hamayanhamayan.com/entry/2019/12/14/221205)
- [https://maspypy.com/多項式・形式的べき級数数え上げとの対応付け](https://maspypy.com/%e5%a4%9a%e9%a0%85%e5%bc%8f%e3%83%bb%e5%bd%a2%e5%bc%8f%e7%9a%84%e3%81%b9%e3%81%8d%e7%b4%9a%e6%95%b0%e6%95%b0%e3%81%88%e4%b8%8a%e3%81%92%e3%81%a8%e3%81%ae%e5%af%be%e5%bf%9c%e4%bb%98%e3%81%91)
- [https://codeforces.com/blog/entry/56422](https://codeforces.com/blog/entry/56422)
- [https://beet-aizu.hatenablog.com/entry/2019/09/27/224701](https://beet-aizu.hatenablog.com/entry/2019/09/27/224701)
- [https://kopricky.github.io/code/FFTs/polynomial_division.html](https://kopricky.github.io/code/FFTs/polynomial_division.html)
- [https://kopricky.github.io/code/FFTs/polynomial_exp.html](https://kopricky.github.io/code/FFTs/polynomial_exp.html)
- [https://kopricky.github.io/code/FFTs/polynomial_inverse.html](https://kopricky.github.io/code/FFTs/polynomial_inverse.html)
- [https://kopricky.github.io/code/FFTs/polynomial_log.html](https://kopricky.github.io/code/FFTs/polynomial_log.html)
- [https://qiita.com/hotman78/items/f0e6d2265badd84d429a](https://qiita.com/hotman78/items/f0e6d2265badd84d429a)
