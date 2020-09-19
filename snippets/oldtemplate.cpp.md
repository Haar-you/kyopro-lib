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
    \ '-dD', '-E', '/home/runner/work/kyopro-lib/kyopro-lib/snippets/oldtemplate.cpp']'\
    \ returned non-zero exit status 1.\n"
  code: "# -*- mode: snippet -*-\n# name: oldtemplate\n# key: oldtemplate\n# --\n\
    #include <bits/stdc++.h>\n\nusing i32 = int_fast32_t;\nusing i64 = int_fast64_t;\n\
    using u32 = uint_fast32_t;\nusing u64 = uint_fast64_t;\nusing f64 = double;\n\
    using f80 = long double;\n\n#define FOR(v, a, b) for(i64 v = (a); v < (b); ++v)\n\
    #define FORE(v, a, b) for(i64 v = (a); v <= (b); ++v)\n#define REP(v, n) FOR(v,\
    \ 0, n)\n#define REPE(v, n) FORE(v, 0, n)\n#define REV(v, a, b) for(i64 v = (a);\
    \ v >= (b); --v)\n#define ALL(x) (x).begin(), (x).end()\n#define RALL(x) (x).rbegin(),\
    \ (x).rend()\n#define ITR(it, c) for(auto it = (c).begin(); it != (c).end(); ++it)\n\
    #define RITR(it, c) for(auto it = (c).rbegin(); it != (c).rend(); ++it)\n#define\
    \ EXIST(c,x) ((c).find(x) != (c).end())\n#define fst first\n#define snd second\n\
    #define UNIQ(v) (v).erase(unique(ALL(v)), (v).end())\n#define bit(i) (1LL<<(i))\n\
    \n#ifdef DEBUG\n#include <Mylib/Debug/debug.cpp>\n#else\n#define dump(...) ((void)0)\n\
    #endif\n\nusing namespace std;\n\ntemplate <typename I> void join(ostream &ost,\
    \ I s, I t, string d=\" \"){for(auto i=s; i!=t; ++i){if(i!=s)ost<<d; ost<<*i;}ost<<endl;}\n\
    template <typename T> istream& operator>>(istream &is, vector<T> &v){for(auto\
    \ &a : v) is >> a; return is;}\n\ntemplate <typename T, typename U> bool chmin(T\
    \ &a, const U &b){return (a>b ? a=b, true : false);}\ntemplate <typename T, typename\
    \ U> bool chmax(T &a, const U &b){return (a<b ? a=b, true : false);}\n\ntemplate\
    \ <typename T, size_t N, typename U> void fill_array(T (&a)[N], const U &v){fill((U*)a,\
    \ (U*)(a+N), v);}\ntemplate <typename T> auto make_vector(int n, int m, const\
    \ T &value){return vector<vector<T>>(n, vector<T>(m, value));}\n\ntemplate <typename\
    \ T> void print(const T &value){std::cout << value << \"\\n\";}\ntemplate <typename\
    \ T, typename ...Args> void print(const T &value, const Args&... args){std::cout\
    \ << value << \" \";print(args...);}\n\n\nstruct Init{\n  Init(){\n    cin.tie(0);\n\
    \    ios::sync_with_stdio(false);\n    cout << fixed << setprecision(12);\n  \
    \  cerr << fixed << setprecision(12);\n  }\n}init;\n\n\n\nint main(){\n  $0\n\n\
    \  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: snippets/oldtemplate.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: snippets/oldtemplate.cpp
layout: document
redirect_from:
- /library/snippets/oldtemplate.cpp
- /library/snippets/oldtemplate.cpp.html
title: snippets/oldtemplate.cpp
---
