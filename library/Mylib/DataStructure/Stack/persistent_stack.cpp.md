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
    - Last commit date: 2020-06-02 05:58:35+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

/**
 * @title Persistent stack
 * @docs persistent_stack.md
 */
template <typename T> struct PersistentStack{
protected:
  struct node{
    T value;
    node *next = nullptr;
  };

  node *root;

  PersistentStack(node *root): root(root){}

public:
  PersistentStack(): root(nullptr){}
  
  bool empty() const {
    return root == nullptr;
  }
  
  const T& top() const {
    return root->value;
  }

  PersistentStack push(const T &value) const {
    node *t = new node({value, root});
    return PersistentStack(t);
  }

  PersistentStack pop() const {
    node *t = root->next;
    return PersistentStack(t);
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/DataStructure/Stack/persistent_stack.cpp"

/**
 * @title Persistent stack
 * @docs persistent_stack.md
 */
template <typename T> struct PersistentStack{
protected:
  struct node{
    T value;
    node *next = nullptr;
  };

  node *root;

  PersistentStack(node *root): root(root){}

public:
  PersistentStack(): root(nullptr){}
  
  bool empty() const {
    return root == nullptr;
  }
  
  const T& top() const {
    return root->value;
  }

  PersistentStack push(const T &value) const {
    node *t = new node({value, root});
    return PersistentStack(t);
  }

  PersistentStack pop() const {
    node *t = root->next;
    return PersistentStack(t);
  }
};

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

