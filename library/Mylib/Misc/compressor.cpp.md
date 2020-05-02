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


# :warning: 座標圧縮

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#3aaad417c82174440088b5eea559262a">Mylib/Misc</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Misc/compressor.cpp">View this file on GitHub</a>
    - Last commit date: 2020-05-02 14:18:42+09:00




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
  inline void add(const T &val) {data.push_back(val);}
  inline void add(const std::vector<T> &vals) {data.insert(data.end(), vals.begin(), vals.end());}
  template <typename U> inline void add_all(const U &val) {add(val);}
  template <typename U, typename ...Args> inline void add_all(const U &val, const Args&... args) {add(val); add_all(args...);}

  inline void build(){
    std::sort(data.begin(), data.end());
    data.erase(std::unique(data.begin(), data.end()), data.end());
  }

  inline int get_index(const T &val) const {return std::lower_bound(data.begin(), data.end(), val) - data.begin();}

  inline void compress(std::vector<T> &vals) const {for(auto &x : vals) x = get_index(x);}
  inline void compress(T &val) const {val = get_index(val);}
  template <typename U> inline void compress_all(U &val) const {compress(val);}
  template <typename U, typename ...Args> inline void compress_all(U &val, Args&... args) const {compress(val); compress_all(args...);}

  inline void decompress(std::vector<T> &vals) const {for(auto &x : vals) x = data[x];}
  inline void decompress(T &val) const {val = data[val];}
  template <typename U> inline void decompress_all(U &val) const {decompress(val);}
  template <typename U, typename ...Args> inline void decompress_all(U &val, Args&... args) const {decompress(val); decompress_all(args...);}
  
  inline int size() const {return data.size();}
  inline T operator[](int index) const {return data[index];}
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
  inline void add(const T &val) {data.push_back(val);}
  inline void add(const std::vector<T> &vals) {data.insert(data.end(), vals.begin(), vals.end());}
  template <typename U> inline void add_all(const U &val) {add(val);}
  template <typename U, typename ...Args> inline void add_all(const U &val, const Args&... args) {add(val); add_all(args...);}

  inline void build(){
    std::sort(data.begin(), data.end());
    data.erase(std::unique(data.begin(), data.end()), data.end());
  }

  inline int get_index(const T &val) const {return std::lower_bound(data.begin(), data.end(), val) - data.begin();}

  inline void compress(std::vector<T> &vals) const {for(auto &x : vals) x = get_index(x);}
  inline void compress(T &val) const {val = get_index(val);}
  template <typename U> inline void compress_all(U &val) const {compress(val);}
  template <typename U, typename ...Args> inline void compress_all(U &val, Args&... args) const {compress(val); compress_all(args...);}

  inline void decompress(std::vector<T> &vals) const {for(auto &x : vals) x = data[x];}
  inline void decompress(T &val) const {val = data[val];}
  template <typename U> inline void decompress_all(U &val) const {decompress(val);}
  template <typename U, typename ...Args> inline void decompress_all(U &val, Args&... args) const {decompress(val); decompress_all(args...);}
  
  inline int size() const {return data.size();}
  inline T operator[](int index) const {return data[index];}
};

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

