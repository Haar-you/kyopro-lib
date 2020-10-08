---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/DataStructure/SegmentTree/segment_tree_linear_add.cpp
    title: Segment tree (Add $ai + b$)
  - icon: ':question:'
    path: Mylib/IO/input_tuple.cpp
    title: Input tuple
  - icon: ':question:'
    path: Mylib/IO/input_tuples.cpp
    title: Input tuples
  - icon: ':question:'
    path: Mylib/IO/join.cpp
    title: join function
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3165
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3165
  bundledCode: "#line 1 \"test/aoj/3165/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3165\"\
    \n\n#include <iostream>\n#line 2 \"Mylib/DataStructure/SegmentTree/segment_tree_linear_add.cpp\"\
    \n#include <vector>\n#include <utility>\n\nnamespace haar_lib {\n  template <typename\
    \ T>\n  class segment_tree_linear_add {\n  public:\n    using value_type = T;\n\
    \n  private:\n    using P = std::pair<T, T>;\n\n    int depth_, size_, hsize_;\n\
    \    std::vector<P> data_;\n    std::vector<int> from_;\n\n    P add(P a, P b){\n\
    \      return {a.first + b.first, a.second + b.second};\n    }\n\n    void propagate(int\
    \ i){\n      if(i < hsize_){\n        data_[i << 1 | 0] = add(data_[i << 1 | 0],\
    \ data_[i]);\n\n        const int len = hsize_ >> (31 - __builtin_clz(i) + 1);\n\
    \        data_[i].first += data_[i].second * len;\n        data_[i << 1 | 1] =\
    \ add(data_[i << 1 | 1], data_[i]);\n\n        data_[i] = P();\n      }\n    }\n\
    \n    void propagate_top_down(int i){\n      std::vector<int> temp;\n      while(i\
    \ > 1){\n        i >>= 1;\n        temp.push_back(i);\n      }\n\n      for(auto\
    \ it = temp.rbegin(); it != temp.rend(); ++it) propagate(*it);\n    }\n\n  public:\n\
    \    segment_tree_linear_add(){}\n    segment_tree_linear_add(int n):\n      depth_(n\
    \ > 1 ? 32 - __builtin_clz(n - 1) + 1 : 1),\n      size_(1 << depth_), hsize_(size_\
    \ / 2),\n      data_(size_, P()),\n      from_(size_)\n    {\n      int s = 0;\n\
    \      for(int i = 1; i < size_; ++i){\n        from_[i] = s;\n        int l =\
    \ hsize_ >> (31 - __builtin_clz(i));\n        s += l;\n        if(s == hsize_)\
    \ s = 0;\n      }\n    }\n\n    void update(int l, int r, T a, T b){\n      int\
    \ L = l + hsize_;\n      int R = r + hsize_;\n\n      while(L < R){\n        if(R\
    \ & 1){\n          --R;\n          data_[R] = add(std::make_pair(b + a * (from_[R]\
    \ - l), a), data_[R]);\n        }\n        if(L & 1){\n          data_[L] = add(std::make_pair(b\
    \ + a * (from_[L] - l), a), data_[L]);\n          ++L;\n        }\n        L >>=\
    \ 1;\n        R >>= 1;\n      }\n    }\n\n    T operator[](int i){\n      propagate_top_down(i\
    \ + hsize_);\n      return data_[i + hsize_].first;\n    }\n\n    std::vector<T>\
    \ get_all(int n){\n      std::vector<T> ret(n);\n      for(int i = 1; i < hsize_;\
    \ ++i) propagate(i);\n      for(int i = hsize_; i < hsize_ + n; ++i) ret[i - hsize_]\
    \ = data_[i].first;\n      return ret;\n    }\n  };\n}\n#line 4 \"Mylib/IO/input_tuples.cpp\"\
    \n#include <tuple>\n#line 6 \"Mylib/IO/input_tuples.cpp\"\n#include <initializer_list>\n\
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
    \ N){\n    return InputTuples<Args ...>(N);\n  }\n}\n#line 3 \"Mylib/IO/join.cpp\"\
    \n#include <sstream>\n#include <string>\n\nnamespace haar_lib {\n  template <typename\
    \ Iter>\n  std::string join(Iter first, Iter last, std::string delim = \" \"){\n\
    \    std::stringstream s;\n\n    for(auto it = first; it != last; ++it){\n   \
    \   if(it != first) s << delim;\n      s << *it;\n    }\n\n    return s.str();\n\
    \  }\n}\n#line 7 \"test/aoj/3165/main.test.cpp\"\n\nnamespace hl = haar_lib;\n\
    \nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  int\
    \ N, Q; std::cin >> N >> Q;\n\n  auto seg = hl::segment_tree_linear_add<int64_t>(N);\n\
    \n  for(auto [l, k] : hl::input_tuples<int, int>(Q)){\n    --l;\n    seg.update(l,\
    \ l + k, 1, 1);\n  }\n\n  auto ans = seg.get_all(N);\n  std::cout << hl::join(ans.begin(),\
    \ ans.end()) << \"\\n\";\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3165\"\
    \n\n#include <iostream>\n#include \"Mylib/DataStructure/SegmentTree/segment_tree_linear_add.cpp\"\
    \n#include \"Mylib/IO/input_tuples.cpp\"\n#include \"Mylib/IO/join.cpp\"\n\nnamespace\
    \ hl = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int N, Q; std::cin >> N >> Q;\n\n  auto seg = hl::segment_tree_linear_add<int64_t>(N);\n\
    \n  for(auto [l, k] : hl::input_tuples<int, int>(Q)){\n    --l;\n    seg.update(l,\
    \ l + k, 1, 1);\n  }\n\n  auto ans = seg.get_all(N);\n  std::cout << hl::join(ans.begin(),\
    \ ans.end()) << \"\\n\";\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/DataStructure/SegmentTree/segment_tree_linear_add.cpp
  - Mylib/IO/input_tuples.cpp
  - Mylib/IO/input_tuple.cpp
  - Mylib/IO/join.cpp
  isVerificationFile: true
  path: test/aoj/3165/main.test.cpp
  requiredBy: []
  timestamp: '2020-10-01 05:16:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/3165/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/3165/main.test.cpp
- /verify/test/aoj/3165/main.test.cpp.html
title: test/aoj/3165/main.test.cpp
---
