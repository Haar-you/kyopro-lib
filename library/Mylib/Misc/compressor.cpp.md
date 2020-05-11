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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: 座標圧縮

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#3aaad417c82174440088b5eea559262a">Mylib/Misc</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Misc/compressor.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-10 06:32:26+09:00




## Verified with

* :heavy_check_mark: <a href="../../../verify/test/aoj/1337/main.test.cpp.html">test/aoj/1337/main.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <vector>
#include <algorithm>

/**
 * @title 座標圧縮
 * @docs compressor.md
 */
template <typename T>
class Compressor{
  std::vector<T> data;

public:
  auto& add(const T &val) {data.push_back(val); return *this;}
  auto& add(const std::vector<T> &vals) {data.insert(data.end(), vals.begin(), vals.end()); return *this;}
  template <typename U, typename ...Args> auto& add(const U &val, const Args&... args) {add(val); return add(args...);}

  auto& build(){
    std::sort(data.begin(), data.end());
    data.erase(std::unique(data.begin(), data.end()), data.end());
    return *this;
  }

  int get_index(const T &val) const {return std::lower_bound(data.begin(), data.end(), val) - data.begin();}

  auto& compress(std::vector<T> &vals) const {for(auto &x : vals) x = get_index(x); return *this;}
  auto& compress(T &val) const {val = get_index(val);return *this;}
  template <typename U, typename ...Args> auto& compress(U &val, Args&... args) const {compress(val); return compress(args...);}

  auto& decompress(std::vector<T> &vals) const {for(auto &x : vals) x = data[x]; return *this;}
  auto& decompress(T &val) const {val = data[val]; return *this;}
  template <typename U, typename ...Args> auto& decompress(U &val, Args&... args) const {decompress(val); return decompress(args...);}
  
  int size() const {return data.size();}
  T operator[](int index) const {return data[index];}
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Misc/compressor.cpp"
#include <vector>
#include <algorithm>

/**
 * @title 座標圧縮
 * @docs compressor.md
 */
template <typename T>
class Compressor{
  std::vector<T> data;

public:
  auto& add(const T &val) {data.push_back(val); return *this;}
  auto& add(const std::vector<T> &vals) {data.insert(data.end(), vals.begin(), vals.end()); return *this;}
  template <typename U, typename ...Args> auto& add(const U &val, const Args&... args) {add(val); return add(args...);}

  auto& build(){
    std::sort(data.begin(), data.end());
    data.erase(std::unique(data.begin(), data.end()), data.end());
    return *this;
  }

  int get_index(const T &val) const {return std::lower_bound(data.begin(), data.end(), val) - data.begin();}

  auto& compress(std::vector<T> &vals) const {for(auto &x : vals) x = get_index(x); return *this;}
  auto& compress(T &val) const {val = get_index(val);return *this;}
  template <typename U, typename ...Args> auto& compress(U &val, Args&... args) const {compress(val); return compress(args...);}

  auto& decompress(std::vector<T> &vals) const {for(auto &x : vals) x = data[x]; return *this;}
  auto& decompress(T &val) const {val = data[val]; return *this;}
  template <typename U, typename ...Args> auto& decompress(U &val, Args&... args) const {decompress(val); return decompress(args...);}
  
  int size() const {return data.size();}
  T operator[](int index) const {return data[index];}
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

