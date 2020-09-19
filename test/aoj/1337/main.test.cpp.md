---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: Mylib/Utils/compressor.cpp
    title: Compressor
  - icon: ':question:'
    path: Mylib/DataStructure/UnionFind/unionfind.cpp
    title: Union-find
  - icon: ':question:'
    path: Mylib/IO/input_tuple_vector.cpp
    title: Mylib/IO/input_tuple_vector.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1337
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1337
  bundledCode: "#line 1 \"test/aoj/1337/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1337\"\
    \n\n#include <iostream>\n#include <vector>\n#line 3 \"Mylib/Utils/compressor.cpp\"\
    \n#include <algorithm>\n\nnamespace haar_lib {\n  template <typename T>\n  class\
    \ compressor {\n    std::vector<T> data;\n\n  public:\n    auto& add(const T &val){\n\
    \      data.push_back(val);\n      return *this;\n    }\n\n    auto& add(const\
    \ std::vector<T> &vals){\n      data.insert(data.end(), vals.begin(), vals.end());\n\
    \      return *this;\n    }\n\n    template <typename U, typename ... Args>\n\
    \    auto& add(const U &val, const Args &... args){\n      add(val);\n      return\
    \ add(args ...);\n    }\n\n    auto& build(){\n      std::sort(data.begin(), data.end());\n\
    \      data.erase(std::unique(data.begin(), data.end()), data.end());\n      return\
    \ *this;\n    }\n\n    int get_index(const T &val) const {\n      return std::lower_bound(data.begin(),\
    \ data.end(), val) - data.begin();\n    }\n\n    auto& compress(std::vector<T>\
    \ &vals) const {\n      for(auto &x : vals) x = get_index(x);\n      return *this;\n\
    \    }\n\n    auto& compress(T &val) const {\n      val = get_index(val);\n  \
    \    return *this;\n    }\n\n    template <typename U, typename ... Args>\n  \
    \  auto& compress(U &val, Args &... args) const {\n      compress(val);\n    \
    \  return compress(args ...);\n    }\n\n    auto& decompress(std::vector<T> &vals)\
    \ const {\n      for(auto &x : vals) x = data[x];\n      return *this;\n    }\n\
    \n    auto& decompress(T &val) const {\n      val = data[val];\n      return *this;\n\
    \    }\n\n    template <typename U, typename ... Args>\n    auto& decompress(U\
    \ &val, Args &... args) const {\n      decompress(val);\n      return decompress(args\
    \ ...);\n    }\n\n    int size() const {return data.size();}\n    T operator[](int\
    \ index) const {return data[index];}\n  };\n}\n#line 3 \"Mylib/DataStructure/UnionFind/unionfind.cpp\"\
    \n#include <numeric>\n#line 5 \"Mylib/DataStructure/UnionFind/unionfind.cpp\"\n\
    \nnamespace haar_lib {\n  class unionfind {\n    int n;\n    mutable std::vector<int>\
    \ parent;\n    std::vector<int> depth, size;\n    int count;\n\n  public:\n  \
    \  unionfind(){}\n    unionfind(int n): n(n), parent(n), depth(n, 1), size(n,\
    \ 1), count(n){\n      std::iota(parent.begin(), parent.end(), 0);\n    }\n\n\
    \    int root_of(int i) const {\n      if(parent[i] == i) return i;\n      else\
    \ return parent[i] = root_of(parent[i]);\n    }\n\n    bool is_same(int i, int\
    \ j) const {return root_of(i) == root_of(j);}\n\n    int merge(int i, int j){\n\
    \      const int ri = root_of(i), rj = root_of(j);\n      if(ri == rj) return\
    \ ri;\n      else{\n        --count;\n        if(depth[ri] < depth[rj]){\n   \
    \       parent[ri] = rj;\n          size[rj] += size[ri];\n          return rj;\n\
    \        }else{\n          parent[rj] = ri;\n          size[ri] += size[rj];\n\
    \          if(depth[ri] == depth[rj]) ++depth[ri];\n          return ri;\n   \
    \     }\n      }\n    }\n\n    int size_of(int i) const {return size[root_of(i)];}\n\
    \n    int count_groups() const {return count;}\n\n    auto get_groups() const\
    \ {\n      std::vector<std::vector<int>> ret(n);\n\n      for(int i = 0; i < n;\
    \ ++i){\n        ret[root_of(i)].push_back(i);\n      }\n\n      ret.erase(\n\
    \        std::remove_if(\n          ret.begin(), ret.end(),\n          [](const\
    \ auto &a){return a.empty();}\n        ),\n        ret.end()\n      );\n\n   \
    \   return ret;\n    }\n  };\n}\n#line 4 \"Mylib/IO/input_tuple_vector.cpp\"\n\
    #include <tuple>\n#include <utility>\n#include <initializer_list>\n\nnamespace\
    \ haar_lib {\n  template <typename T, size_t ... I>\n  void input_tuple_vector_init(T\
    \ &val, int N, std::index_sequence<I ...>){\n    (void)std::initializer_list<int>{(void(std::get<I>(val).resize(N)),\
    \ 0) ...};\n  }\n\n  template <typename T, size_t ... I>\n  void input_tuple_vector_helper(T\
    \ &val, int i, std::index_sequence<I ...>){\n    (void)std::initializer_list<int>{(void(std::cin\
    \ >> std::get<I>(val)[i]), 0) ...};\n  }\n\n  template <typename ... Args>\n \
    \ auto input_tuple_vector(int N){\n    std::tuple<std::vector<Args> ...> ret;\n\
    \n    input_tuple_vector_init(ret, N, std::make_index_sequence<sizeof ... (Args)>());\n\
    \    for(int i = 0; i < N; ++i){\n      input_tuple_vector_helper(ret, i, std::make_index_sequence<sizeof\
    \ ... (Args)>());\n    }\n\n    return ret;\n  }\n}\n#line 8 \"test/aoj/1337/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nconst int H = 200;\nconst int W = 200;\n\nint\
    \ main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  int n;\n\
    \n  while(std::cin >> n, n){\n    auto [l, t, r, b] = hl::input_tuple_vector<int,\
    \ int, int, int>(n);\n\n    int64_t a[H][W] = {};\n\n    hl::compressor<int>().add(l,\
    \ r, -1).build().compress(l, r);\n    hl::compressor<int>().add(t, b, -1).build().compress(t,\
    \ b);\n\n    for(int i = 0; i < n; ++i){\n      for(int x = l[i]; x < r[i]; ++x){\n\
    \        for(int y = b[i]; y < t[i]; ++y){\n          a[x][y] |= (1LL << i);\n\
    \        }\n      }\n    }\n\n    hl::unionfind uf(H * W);\n    int index[H][W];\n\
    \    {\n      int k = 0;\n      for(int i = 0; i < H; ++i){\n        for(int j\
    \ = 0; j < W; ++j){\n          index[i][j] = k;\n          ++k;\n        }\n \
    \     }\n    }\n\n    for(int i = 0; i < H; ++i){\n      for(int j = 0; j < W;\
    \ ++j){\n        if(i + 1 < H and a[i][j] == a[i + 1][j]) uf.merge(index[i][j],\
    \ index[i + 1][j]);\n        if(j + 1 < W and a[i][j] == a[i][j + 1]) uf.merge(index[i][j],\
    \ index[i][j + 1]);\n      }\n    }\n\n    int ans = uf.count_groups();\n\n  \
    \  std::cout << ans << \"\\n\";\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1337\"\
    \n\n#include <iostream>\n#include <vector>\n#include \"Mylib/Utils/compressor.cpp\"\
    \n#include \"Mylib/DataStructure/UnionFind/unionfind.cpp\"\n#include \"Mylib/IO/input_tuple_vector.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nconst int H = 200;\nconst int W = 200;\n\nint\
    \ main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\n  int n;\n\
    \n  while(std::cin >> n, n){\n    auto [l, t, r, b] = hl::input_tuple_vector<int,\
    \ int, int, int>(n);\n\n    int64_t a[H][W] = {};\n\n    hl::compressor<int>().add(l,\
    \ r, -1).build().compress(l, r);\n    hl::compressor<int>().add(t, b, -1).build().compress(t,\
    \ b);\n\n    for(int i = 0; i < n; ++i){\n      for(int x = l[i]; x < r[i]; ++x){\n\
    \        for(int y = b[i]; y < t[i]; ++y){\n          a[x][y] |= (1LL << i);\n\
    \        }\n      }\n    }\n\n    hl::unionfind uf(H * W);\n    int index[H][W];\n\
    \    {\n      int k = 0;\n      for(int i = 0; i < H; ++i){\n        for(int j\
    \ = 0; j < W; ++j){\n          index[i][j] = k;\n          ++k;\n        }\n \
    \     }\n    }\n\n    for(int i = 0; i < H; ++i){\n      for(int j = 0; j < W;\
    \ ++j){\n        if(i + 1 < H and a[i][j] == a[i + 1][j]) uf.merge(index[i][j],\
    \ index[i + 1][j]);\n        if(j + 1 < W and a[i][j] == a[i][j + 1]) uf.merge(index[i][j],\
    \ index[i][j + 1]);\n      }\n    }\n\n    int ans = uf.count_groups();\n\n  \
    \  std::cout << ans << \"\\n\";\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Utils/compressor.cpp
  - Mylib/DataStructure/UnionFind/unionfind.cpp
  - Mylib/IO/input_tuple_vector.cpp
  isVerificationFile: true
  path: test/aoj/1337/main.test.cpp
  requiredBy: []
  timestamp: '2020-09-16 17:10:42+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/1337/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/1337/main.test.cpp
- /verify/test/aoj/1337/main.test.cpp.html
title: test/aoj/1337/main.test.cpp
---
