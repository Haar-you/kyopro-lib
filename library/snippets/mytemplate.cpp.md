---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: snippets/mytemplate.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#67be68a348da3b850fb7daa10b034528">snippets</a>
* <a href="{{ site.github.repository_url }}/blob/master/snippets/mytemplate.cpp">View this file on GitHub</a>
    - Last commit date: 1970-01-01 00:00:00+00:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
# -*- mode: snippet -*-
# name: mytemplate
# key: mytemplate
# --
#include <bits/stdc++.h>

using i32 = int_fast32_t;
using i64 = int_fast64_t;
using u32 = uint_fast32_t;
using u64 = uint_fast64_t;
using f64 = double;
using f80 = long double;

#define FOR(v, a, b) for(i64 v = (a); v < (b); ++v)
#define FORE(v, a, b) for(i64 v = (a); v <= (b); ++v)
#define REP(v, n) FOR(v, 0, n)
#define REPE(v, n) FORE(v, 0, n)
#define REV(v, a, b) for(i64 v = (a); v >= (b); --v)
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define ITR(it, c) for(auto it = (c).begin(); it != (c).end(); ++it)
#define RITR(it, c) for(auto it = (c).rbegin(); it != (c).rend(); ++it)
#define EXIST(c,x) ((c).find(x) != (c).end())
#define fst first
#define snd second
#define UNIQ(v) (v).erase(unique(ALL(v)), (v).end())
#define bit(i) (1LL<<(i))

#ifdef DEBUG
#include <Mylib/Debug/debug.cpp>
#else
#define dump(...) ((void)0)
#endif

using namespace std;

template <typename I> void join(ostream &ost, I s, I t, string d=" "){for(auto i=s; i!=t; ++i){if(i!=s)ost<<d; ost<<*i;}ost<<endl;}
template <typename T> istream& operator>>(istream &is, vector<T> &v){for(auto &a : v) is >> a; return is;}

template <typename T, typename U> bool chmin(T &a, const U &b){return (a>b ? a=b, true : false);}
template <typename T, typename U> bool chmax(T &a, const U &b){return (a<b ? a=b, true : false);}

template <typename T, size_t N, typename U> void fill_array(T (&a)[N], const U &v){fill((U*)a, (U*)(a+N), v);}
template <typename T> auto make_vector(int n, int m, const T &value){return vector<vector<T>>(n, vector<T>(m, value));}

template <typename T> void print(const T &value){std::cout << value << "\n";}
template <typename T, typename ...Args> void print(const T &value, const Args&... args){std::cout << value << " ";print(args...);}


struct Init{
  Init(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(12);
    cerr << fixed << setprecision(12);
  }
}init;



int main(){
  $0

  return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 349, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=pathlib.Path.cwd())
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 185, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 216, in update
    uncommented_lines = get_uncommented_code(path, iquotes=self.iquotes, compiler=self.compiler).splitlines(keepends=True)
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 126, in get_uncommented_code
    code = _get_uncommented_code(path.resolve(), iquotes_options=tuple(iquotes_options), compiler=compiler)
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 119, in _get_uncommented_code
    return subprocess.check_output(command)
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/subprocess.py", line 411, in check_output
    return run(*popenargs, stdout=PIPE, timeout=timeout, check=True,
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/subprocess.py", line 512, in run
    raise CalledProcessError(retcode, process.args,
subprocess.CalledProcessError: Command '['g++', '-I', '/home/runner/work/kyopro-lib/kyopro-lib', '-fpreprocessed', '-dD', '-E', '/home/runner/work/kyopro-lib/kyopro-lib/snippets/mytemplate.cpp']' returned non-zero exit status 1.

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

