---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Mylib/Graph/ShortestPath/warshall_floyd_for_matrix_graph.cpp
    title: Warshall-Floyd algorithm (For adjacency matrix graph)
  - icon: ':question:'
    path: Mylib/IO/input_vector.cpp
    title: Input vector
  - icon: ':heavy_check_mark:'
    path: Mylib/LinearAlgebra/simultaneous_linear_equations_float.cpp
    title: Simultaneous linear equations (Floating point number)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: 1e-8
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2171
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2171
  bundledCode: "#line 1 \"test/aoj/2171/main.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2171\"\
    \n#define ERROR 1e-8\n\n#include <iostream>\n#include <vector>\n#include <iomanip>\n\
    #line 3 \"Mylib/Graph/ShortestPath/warshall_floyd_for_matrix_graph.cpp\"\n#include\
    \ <optional>\n\nnamespace haar_lib {\n  namespace warshall_floyd_for_matrix_impl\
    \ {\n    template <typename T>\n    struct result {\n      std::vector<std::vector<std::optional<T>>>\
    \ dist;\n      bool has_negative_cycle;\n      const auto& operator[](int i) const\
    \ {return dist[i];}\n    };\n  }\n\n  template <typename T, T INVALID>\n  auto\
    \ warshall_floyd_for_matrix(const std::vector<std::vector<T>> &g){\n    const\
    \ int n = g.size();\n    auto dist = std::vector(n, std::vector<std::optional<T>>(n));\n\
    \n    for(int i = 0; i < n; ++i) dist[i][i] = 0;\n\n    for(int i = 0; i < n;\
    \ ++i){\n      for(int j = 0; j < n; ++j){\n        if(g[i][j] != INVALID){\n\
    \          dist[i][j] = g[i][j];\n        }\n      }\n    }\n\n    for(int k =\
    \ 0; k < n; ++k){\n      for(int i = 0; i < n; ++i){\n        for(int j = 0; j\
    \ < n; ++j){\n          if(dist[i][k] and dist[k][j]){\n            if(not dist[i][j]){\n\
    \              dist[i][j] = *dist[i][k] + *dist[k][j];\n            }else{\n \
    \             dist[i][j] = std::min(*dist[i][j], *dist[i][k] + *dist[k][j]);\n\
    \            }\n          }\n        }\n      }\n    }\n\n    bool has_negative_cycle\
    \ = false;\n    for(int i = 0; i < n; ++i) if(*dist[i][i] < 0) has_negative_cycle\
    \ = true;\n\n    return warshall_floyd_for_matrix_impl::result<T>{dist, has_negative_cycle};\n\
    \  }\n}\n#line 4 \"Mylib/LinearAlgebra/simultaneous_linear_equations_float.cpp\"\
    \n#include <utility>\n\nnamespace haar_lib {\n  namespace float_simultaneous_linear_equations_impl\
    \ {\n    template <typename T>\n    struct result {\n      int rank, dim;\n  \
    \    std::vector<T> solution;\n    };\n  }\n\n  template <typename T>\n  auto\
    \ float_simultaneous_linear_equations(std::vector<std::vector<T>> a, std::vector<T>\
    \ b, T eps){\n    using result = float_simultaneous_linear_equations_impl::result<T>;\n\
    \    std::optional<result> ret;\n\n    const int n = a.size(), m = a[0].size();\n\
    \    int rank = 0;\n\n    for(int j = 0; j < m; ++j){\n      int pivot = -1;\n\
    \n      double M = eps;\n      for(int i = rank; i < n; ++i){\n        if(std::abs(a[i][j])\
    \ > M){\n          M = std::abs(a[i][j]);\n          pivot = i;\n        }\n \
    \     }\n\n      if(pivot == -1) continue;\n\n      std::swap(a[pivot], a[rank]);\n\
    \      std::swap(b[pivot], b[rank]);\n\n      {\n        double d = a[rank][j];\n\
    \        for(int k = 0; k < m; ++k) a[rank][k] /= d;\n        b[rank] /= d;\n\
    \      }\n\n      for(int i = 0; i < n; ++i){\n        if(i == rank or std::abs(a[i][j])\
    \ <= eps) continue;\n        double d = a[i][j];\n        for(int k = 0; k < m;\
    \ ++k){\n          a[i][k] -= a[rank][k] * d;\n        }\n        b[i] -= b[rank]\
    \ * d;\n      }\n\n      ++rank;\n    }\n\n    for(int i = rank; i < n; ++i){\n\
    \      if(std::abs(b[i]) > eps){\n        return ret;\n      }\n    }\n\n    const\
    \ int dim = m - rank;\n\n    std::vector<T> solution(m);\n    for(int i = 0; i\
    \ < rank; ++i) solution[i] = b[i];\n\n    ret = result({rank, dim, solution});\n\
    \    return ret;\n  }\n}\n#line 4 \"Mylib/IO/input_vector.cpp\"\n\nnamespace haar_lib\
    \ {\n  template <typename T>\n  std::vector<T> input_vector(int N){\n    std::vector<T>\
    \ ret(N);\n    for(int i = 0; i < N; ++i) std::cin >> ret[i];\n    return ret;\n\
    \  }\n\n  template <typename T>\n  std::vector<std::vector<T>> input_vector(int\
    \ N, int M){\n    std::vector<std::vector<T>> ret(N);\n    for(int i = 0; i <\
    \ N; ++i) ret[i] = input_vector<T>(M);\n    return ret;\n  }\n}\n#line 10 \"test/aoj/2171/main.test.cpp\"\
    \n\nnamespace hl = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n  std::ios::sync_with_stdio(false);\n\
    \n  int n, s, t;\n  while(std::cin >> n >> s >> t, n){\n    --s, --t;\n\n    auto\
    \ q = hl::input_vector<int>(n);\n    auto g = hl::input_vector<int>(n, n);\n\n\
    \    auto dist = hl::warshall_floyd_for_matrix<int, 0>(g);\n\n    if(not dist[s][t]){\n\
    \      std::cout << \"impossible\" << std::endl;\n      continue;\n    }\n\n \
    \   std::vector<std::vector<double>> a(n, std::vector<double>(n));\n    std::vector<double>\
    \ b(n);\n\n    for(int i = 0; i < n; ++i){\n      if(i == t){\n        a[i][i]\
    \ = 1;\n        b[i] = 0;\n        continue;\n      }\n\n      if(q[i]){\n   \
    \     int d = *dist[i][t];\n\n        int k = 0;\n        for(int j = 0; j < n;\
    \ ++j){\n          if(g[i][j] > 0 and g[i][j] + *dist[j][t] == d){\n         \
    \   ++k;\n          }\n        }\n\n        for(int j = 0; j < n; ++j){\n    \
    \      if(g[i][j] > 0 and g[i][j] + *dist[j][t] == d){\n            a[i][j] =\
    \ -1;\n            b[i] += g[i][j];\n          }\n        }\n\n        a[i][i]\
    \ += k;\n      }else{\n        int k = 0;\n        for(int j = 0; j < n; ++j){\n\
    \          if(g[i][j] > 0){\n            ++k;\n          }\n        }\n\n    \
    \    for(int j = 0; j < n; ++j){\n          if(g[i][j] > 0){\n            a[i][j]\
    \ = -1;\n            b[i] += g[i][j];\n          }\n        }\n\n        a[i][i]\
    \ += k;\n      }\n    }\n\n    auto res = hl::float_simultaneous_linear_equations(a,\
    \ b, ERROR);\n\n    double ans = (*res).solution[s];\n    std::cout << std::setprecision(12)\
    \ << std::fixed << ans << std::endl;\n  }\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2171\"\
    \n#define ERROR 1e-8\n\n#include <iostream>\n#include <vector>\n#include <iomanip>\n\
    #include \"Mylib/Graph/ShortestPath/warshall_floyd_for_matrix_graph.cpp\"\n#include\
    \ \"Mylib/LinearAlgebra/simultaneous_linear_equations_float.cpp\"\n#include \"\
    Mylib/IO/input_vector.cpp\"\n\nnamespace hl = haar_lib;\n\nint main(){\n  std::cin.tie(0);\n\
    \  std::ios::sync_with_stdio(false);\n\n  int n, s, t;\n  while(std::cin >> n\
    \ >> s >> t, n){\n    --s, --t;\n\n    auto q = hl::input_vector<int>(n);\n  \
    \  auto g = hl::input_vector<int>(n, n);\n\n    auto dist = hl::warshall_floyd_for_matrix<int,\
    \ 0>(g);\n\n    if(not dist[s][t]){\n      std::cout << \"impossible\" << std::endl;\n\
    \      continue;\n    }\n\n    std::vector<std::vector<double>> a(n, std::vector<double>(n));\n\
    \    std::vector<double> b(n);\n\n    for(int i = 0; i < n; ++i){\n      if(i\
    \ == t){\n        a[i][i] = 1;\n        b[i] = 0;\n        continue;\n      }\n\
    \n      if(q[i]){\n        int d = *dist[i][t];\n\n        int k = 0;\n      \
    \  for(int j = 0; j < n; ++j){\n          if(g[i][j] > 0 and g[i][j] + *dist[j][t]\
    \ == d){\n            ++k;\n          }\n        }\n\n        for(int j = 0; j\
    \ < n; ++j){\n          if(g[i][j] > 0 and g[i][j] + *dist[j][t] == d){\n    \
    \        a[i][j] = -1;\n            b[i] += g[i][j];\n          }\n        }\n\
    \n        a[i][i] += k;\n      }else{\n        int k = 0;\n        for(int j =\
    \ 0; j < n; ++j){\n          if(g[i][j] > 0){\n            ++k;\n          }\n\
    \        }\n\n        for(int j = 0; j < n; ++j){\n          if(g[i][j] > 0){\n\
    \            a[i][j] = -1;\n            b[i] += g[i][j];\n          }\n      \
    \  }\n\n        a[i][i] += k;\n      }\n    }\n\n    auto res = hl::float_simultaneous_linear_equations(a,\
    \ b, ERROR);\n\n    double ans = (*res).solution[s];\n    std::cout << std::setprecision(12)\
    \ << std::fixed << ans << std::endl;\n  }\n\n  return 0;\n}\n"
  dependsOn:
  - Mylib/Graph/ShortestPath/warshall_floyd_for_matrix_graph.cpp
  - Mylib/LinearAlgebra/simultaneous_linear_equations_float.cpp
  - Mylib/IO/input_vector.cpp
  isVerificationFile: true
  path: test/aoj/2171/main.test.cpp
  requiredBy: []
  timestamp: '2020-12-09 11:11:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/2171/main.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/2171/main.test.cpp
- /verify/test/aoj/2171/main.test.cpp.html
title: test/aoj/2171/main.test.cpp
---
