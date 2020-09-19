---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 70, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 287, in update\n    uncommented_lines = get_uncommented_code(path, iquotes=self.iquotes,\
    \ compiler=self.compiler).splitlines(keepends=True)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 195, in get_uncommented_code\n    code = _get_uncommented_code(path.resolve(),\
    \ iquotes_options=tuple(iquotes_options), compiler=compiler)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 188, in _get_uncommented_code\n    return subprocess.check_output(command)\n\
    \  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/subprocess.py\"\
    , line 411, in check_output\n    return run(*popenargs, stdout=PIPE, timeout=timeout,\
    \ check=True,\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/subprocess.py\"\
    , line 512, in run\n    raise CalledProcessError(retcode, process.args,\nsubprocess.CalledProcessError:\
    \ Command '['g++', '-I', '/home/runner/work/kyopro-lib/kyopro-lib', '-fpreprocessed',\
    \ '-dD', '-E', '/home/runner/work/kyopro-lib/kyopro-lib/snippets/mytemplate.cpp']'\
    \ returned non-zero exit status 1.\n"
  code: "# -*- mode: snippet -*-\n# name: mytemplate\n# key: mytemplate\n# --\n#include\
    \ <bits/stdc++.h>\n\n#ifdef DEBUG\n#include <Mylib/Debug/debug.cpp>\n#else\n#define\
    \ dump(...) ((void)0)\n#endif\n\ntemplate <typename T, typename U>\nbool chmin(T\
    \ &a, const U &b){\n  return (a > b ? a = b, true : false);\n}\n\ntemplate <typename\
    \ T, typename U>\nbool chmax(T &a, const U &b){\n  return (a < b ? a = b, true\
    \ : false);\n}\n\ntemplate <typename T, size_t N, typename U>\nvoid fill_array(T\
    \ (&a)[N], const U &v){\n  std::fill((U*)a, (U*)(a + N), v);\n}\n\ntemplate <typename\
    \ T, size_t N, size_t I = N>\nauto make_vector(const std::array<int, N> &a, T\
    \ value = T()){\n  static_assert(I >= 1);\n  static_assert(N >= 1);\n  if constexpr\
    \ (I == 1){\n    return std::vector<T>(a[N - I], value);\n  }else{\n    return\
    \ std::vector(a[N - I], make_vector<T, N, I - 1>(a, value));\n  }\n}\n\ntemplate\
    \ <typename T>\nstd::ostream& operator<<(std::ostream &s, const std::vector<T>\
    \ &a){\n  for(auto it = a.begin(); it != a.end(); ++it){\n    if(it != a.begin())\
    \ s << \" \";\n    s << *it;\n  }\n  return s;\n}\n\ntemplate <typename T>\nstd::istream&\
    \ operator>>(std::istream &s, std::vector<T> &a){\n  for(auto &x : a) s >> x;\n\
    \  return s;\n}\n\n\nnamespace haar_lib {}\n\nnamespace solver {\n  using namespace\
    \ haar_lib;\n\n  constexpr int m1000000007 = 1000000007;\n  constexpr int m998244353\
    \ = 998244353;\n\n  void init(){\n    std::cin.tie(0);\n    std::ios::sync_with_stdio(false);\n\
    \    std::cout << std::fixed << std::setprecision(12);\n    std::cerr << std::fixed\
    \ << std::setprecision(12);\n    std::cin.exceptions(std::ios_base::failbit);\n\
    \  }\n\n  void solve(){\n    $0\n  }\n}\n\nint main(){\n  solver::init();\n  while(true){\n\
    \    try{\n      solver::solve();\n    }catch(const std::istream::failure &e){\n\
    \      break;\n    }\n  }\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: snippets/mytemplate.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: snippets/mytemplate.cpp
layout: document
redirect_from:
- /library/snippets/mytemplate.cpp
- /library/snippets/mytemplate.cpp.html
title: snippets/mytemplate.cpp
---
