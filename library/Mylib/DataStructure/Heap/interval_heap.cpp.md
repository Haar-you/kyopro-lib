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
<script type="text/javascript" src="../../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../../assets/css/copy-button.css" />


# :warning: Interval heap

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#f151d59e79c7ff7f731ff52cf9b782e4">Mylib/DataStructure/Heap</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/DataStructure/Heap/interval_heap.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00




## Operations

## Requirements

## Notes

## Problems

## References

- [https://natsugiri.hatenablog.com/entry/2016/10/10/035445](https://natsugiri.hatenablog.com/entry/2016/10/10/035445)


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <array>
#include <utility>
#include <functional>

/**
 * @title Interval heap
 * @docs interval_heap.md
 */
namespace haar_lib {
  template <typename T, typename Compare = std::less<T>>
  class interval_heap {
    int left(int i) const {return i * 2 + 1;}
    int right(int i) const {return i * 2 + 2;}
    int parent(int i) const {return (i - 1) >> 1;}
    bool check(int i) const {return i < ((int)data.size() + 1) / 2;}
    int back() const {return ((int)data.size() - 1) / 2;}
    bool is_singleton(int i) const {return i == back() and data.size() % 2 == 1;}
    int get_min_element(int i) const {return is_singleton(i) ? (int)data.size() - 1 : 2 * i;}
    int get_max_element(int i) const {return is_singleton(i) ? (int)data.size() - 1 : 2 * i + 1;}

    bool merge(int &parent, int &child){
      if(is_singleton(child)){
        auto &a = data[get_min_element(parent)];
        auto &b = data[get_max_element(parent)];
        auto &x = data[get_min_element(child)];

        if(compare(x, a)){
          std::swap(x, a);
        }else if(compare(b, x)){
          std::swap(b, x);
        }else{
          return false;
        }
      }else{
        std::array<int, 4> a =
          {
           get_min_element(parent),
           get_min_element(child),
           get_max_element(child),
           get_max_element(parent)
          };

        if(compare(data[a[0]], data[a[1]]) and
           compare(data[a[1]], data[a[2]]) and
           compare(data[a[2]], data[a[3]])) return false;

        for(int i = 0; i < 4; ++i){
          for(int j = i + 1; j < 4; ++j){
            if(not compare(data[a[i]], data[a[j]])) std::swap(data[a[i]], data[a[j]]);
          }
        }
      }

      return true;
    }

    void top_down(int i, bool is_min_modified){
      while(1){
        int l = left(i), r = right(i);

        if(not check(l)) break;

        if(check(r)){
          if(is_min_modified){
            if(compare(data[get_min_element(l)], data[get_min_element(r)])){
              if(not merge(i, l)) break;
              i = l;
            }else{
              if(not merge(i, r)) break;
              i = r;
            }

          }else{
            if(compare(data[get_max_element(l)], data[get_max_element(r)])){
              if(not merge(i, r)) break;
              i = r;
            }else{
              if(not merge(i, l)) break;
              i = l;
            }
          }
        }else{
          if(not merge(i, l)) break;
          i = l;
        }
      }
    }

    void bottom_up(int i){
      while(i > 0){
        int p = parent(i);
        if(not merge(p, i)) break;
        i = p;
      }
    }

    Compare compare;
    std::vector<T> data;

  public:
    interval_heap(): compare(Compare()){}

    const T& get_min() const {
      return data[get_min_element(0)];
    }

    const T& get_max() const {
      return data[get_max_element(0)];
    }

    void push(T value){
      if(data.size() % 2 == 1 and compare(value, data.back())) std::swap(value, data.back());
      data.push_back(value);
      bottom_up(back());
    }

    void pop_min(){
      std::swap(data[get_min_element(0)], data.back());
      data.pop_back();
      top_down(0, true);
    }

    void pop_max(){
      std::swap(data[get_max_element(0)], data.back());
      data.pop_back();
      top_down(0, false);
    }

    bool empty() const {
      return data.empty();
    }

    int size() const {
      return data.size();
    }
  };
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/DataStructure/Heap/interval_heap.cpp"
#include <array>
#include <utility>
#include <functional>

/**
 * @title Interval heap
 * @docs interval_heap.md
 */
namespace haar_lib {
  template <typename T, typename Compare = std::less<T>>
  class interval_heap {
    int left(int i) const {return i * 2 + 1;}
    int right(int i) const {return i * 2 + 2;}
    int parent(int i) const {return (i - 1) >> 1;}
    bool check(int i) const {return i < ((int)data.size() + 1) / 2;}
    int back() const {return ((int)data.size() - 1) / 2;}
    bool is_singleton(int i) const {return i == back() and data.size() % 2 == 1;}
    int get_min_element(int i) const {return is_singleton(i) ? (int)data.size() - 1 : 2 * i;}
    int get_max_element(int i) const {return is_singleton(i) ? (int)data.size() - 1 : 2 * i + 1;}

    bool merge(int &parent, int &child){
      if(is_singleton(child)){
        auto &a = data[get_min_element(parent)];
        auto &b = data[get_max_element(parent)];
        auto &x = data[get_min_element(child)];

        if(compare(x, a)){
          std::swap(x, a);
        }else if(compare(b, x)){
          std::swap(b, x);
        }else{
          return false;
        }
      }else{
        std::array<int, 4> a =
          {
           get_min_element(parent),
           get_min_element(child),
           get_max_element(child),
           get_max_element(parent)
          };

        if(compare(data[a[0]], data[a[1]]) and
           compare(data[a[1]], data[a[2]]) and
           compare(data[a[2]], data[a[3]])) return false;

        for(int i = 0; i < 4; ++i){
          for(int j = i + 1; j < 4; ++j){
            if(not compare(data[a[i]], data[a[j]])) std::swap(data[a[i]], data[a[j]]);
          }
        }
      }

      return true;
    }

    void top_down(int i, bool is_min_modified){
      while(1){
        int l = left(i), r = right(i);

        if(not check(l)) break;

        if(check(r)){
          if(is_min_modified){
            if(compare(data[get_min_element(l)], data[get_min_element(r)])){
              if(not merge(i, l)) break;
              i = l;
            }else{
              if(not merge(i, r)) break;
              i = r;
            }

          }else{
            if(compare(data[get_max_element(l)], data[get_max_element(r)])){
              if(not merge(i, r)) break;
              i = r;
            }else{
              if(not merge(i, l)) break;
              i = l;
            }
          }
        }else{
          if(not merge(i, l)) break;
          i = l;
        }
      }
    }

    void bottom_up(int i){
      while(i > 0){
        int p = parent(i);
        if(not merge(p, i)) break;
        i = p;
      }
    }

    Compare compare;
    std::vector<T> data;

  public:
    interval_heap(): compare(Compare()){}

    const T& get_min() const {
      return data[get_min_element(0)];
    }

    const T& get_max() const {
      return data[get_max_element(0)];
    }

    void push(T value){
      if(data.size() % 2 == 1 and compare(value, data.back())) std::swap(value, data.back());
      data.push_back(value);
      bottom_up(back());
    }

    void pop_min(){
      std::swap(data[get_min_element(0)], data.back());
      data.pop_back();
      top_down(0, true);
    }

    void pop_max(){
      std::swap(data[get_max_element(0)], data.back());
      data.pop_back();
      top_down(0, false);
    }

    bool empty() const {
      return data.empty();
    }

    int size() const {
      return data.size();
    }
  };
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

