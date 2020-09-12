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


# :warning: Persistent stack

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#12526f91d29b13109723e3d0cc6a4265">Mylib/DataStructure/Stack</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/DataStructure/Stack/persistent_stack.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 02:56:29+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <iostream>

/**
 * @title Persistent stack
 * @docs persistent_stack.md
 */
namespace haar_lib {
  template <typename T>
  struct persistent_stack {
  protected:
    struct node {
      T value;
      node *next = nullptr;
    };

    node *root;

    persistent_stack(node *root): root(root){}

  public:
    persistent_stack(): root(nullptr){}

    bool empty() const {
      return not root;
    }

    const T& top() const {
      return root->value;
    }

    persistent_stack push(const T &value) const {
      node *t = new node({value, root});
      return persistent_stack(t);
    }

    persistent_stack pop() const {
      node *t = root->next;
      return persistent_stack(t);
    }

    friend std::ostream& operator<<(std::ostream &s, const persistent_stack &a){
      s << "{";
      node *t = a.root;
      while(t){
        if(t != a.root) s << ", ";
        s << t->value;
        t = t->next;
      }

      s << "}";
      return s;
    }
  };
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/DataStructure/Stack/persistent_stack.cpp"
#include <iostream>

/**
 * @title Persistent stack
 * @docs persistent_stack.md
 */
namespace haar_lib {
  template <typename T>
  struct persistent_stack {
  protected:
    struct node {
      T value;
      node *next = nullptr;
    };

    node *root;

    persistent_stack(node *root): root(root){}

  public:
    persistent_stack(): root(nullptr){}

    bool empty() const {
      return not root;
    }

    const T& top() const {
      return root->value;
    }

    persistent_stack push(const T &value) const {
      node *t = new node({value, root});
      return persistent_stack(t);
    }

    persistent_stack pop() const {
      node *t = root->next;
      return persistent_stack(t);
    }

    friend std::ostream& operator<<(std::ostream &s, const persistent_stack &a){
      s << "{";
      node *t = a.root;
      while(t){
        if(t != a.root) s << ", ";
        s << t->value;
        t = t->next;
      }

      s << "}";
      return s;
    }
  };
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

