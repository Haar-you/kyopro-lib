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

#ifdef DEBUG
#include <Mylib/Debug/debug.cpp>
#else
#define dump(...) ((void)0)
#endif

template <typename T, typename U>
bool chmin(T &a, const U &b){
  return (a > b ? a = b, true : false);
}

template <typename T, typename U>
bool chmax(T &a, const U &b){
  return (a < b ? a = b, true : false);
}

template <typename T, size_t N, typename U>
void fill_array(T (&a)[N], const U &v){
  std::fill((U*)a, (U*)(a + N), v);
}

template <typename T, size_t N, size_t I = N>
auto make_vector(const std::array<int, N> &a, T value = T()){
  static_assert(I >= 1);
  static_assert(N >= 1);
  if constexpr (I == 1){
    return std::vector<T>(a[N - I], value);
  }else{
    return std::vector(a[N - I], make_vector<T, N, I - 1>(a, value));
  }
}

template <typename T>
std::ostream& operator<<(std::ostream &s, const std::vector<T> &a){
  for(auto it = a.begin(); it != a.end(); ++it){
    if(it != a.begin()) s << " ";
    s << *it;
  }
  return s;
}

template <typename T>
std::istream& operator>>(std::istream &s, std::vector<T> &a){
  for(auto &x : a) s >> x;
  return s;
}


namespace haar_lib {}

namespace solver {
  using namespace haar_lib;

  void init(){
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    std::cerr << std::fixed << std::setprecision(12);
    std::cin.exceptions(std::ios_base::failbit);
  }

  void solve(){
    $0
  }
}

int main(){
  solver::init();
  while(true){
    try{
      solver::solve();
    }catch(const std::istream::failure &e){
      break;
    }
  }
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
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 287, in update
    uncommented_lines = get_uncommented_code(path, iquotes=self.iquotes, compiler=self.compiler).splitlines(keepends=True)
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 195, in get_uncommented_code
    code = _get_uncommented_code(path.resolve(), iquotes_options=tuple(iquotes_options), compiler=compiler)
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 188, in _get_uncommented_code
    return subprocess.check_output(command)
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/subprocess.py", line 411, in check_output
    return run(*popenargs, stdout=PIPE, timeout=timeout, check=True,
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/subprocess.py", line 512, in run
    raise CalledProcessError(retcode, process.args,
subprocess.CalledProcessError: Command '['g++', '-I', '/home/runner/work/kyopro-lib/kyopro-lib', '-fpreprocessed', '-dD', '-E', '/home/runner/work/kyopro-lib/kyopro-lib/snippets/mytemplate.cpp']' returned non-zero exit status 1.

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

