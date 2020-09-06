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


# :warning: Memory dump

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0f67555b3039d368e55db69bb4454f7e">Mylib/Debug</a>
* <a href="{{ site.github.repository_url }}/blob/master/Mylib/Debug/memory_dump.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-02 21:08:27+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <cstdio>
#include <cstddef>
#include <cctype>

/**
 * @title Memory dump
 * @docs memory_dump.md
 */
void memory_dump(const void* p, size_t size){
  unsigned char *cur = (unsigned char*)p;

  printf("                 | 00 01 02 03 04 05 06 07 08 09 0a 0b 0c 0d 0e 0f\n");
  printf("__________________________________________________________________\n");

  size_t padding = (size_t)cur % 0x10;
  size += padding;
  cur -= padding;

  char temp[17];

  size_t i = 0;
  for(; i < size; ++i){
    if(i % 16 == 0){
      if(i != 0){
        printf("|%s|\n", temp);
      }
      printf("%16p | ", cur);
      for(size_t j = 0; j < 16; ++j) temp[j] = ' ';
      temp[16] = '\0';
    }

    printf("%02x ", (int)(*cur));

    if(isprint((char)(*cur))){
      temp[i % 16] = (char)(*cur);
    }else{
      temp[i % 16] = '.';
    }

    ++cur;
  }

  for(size_t k = 0; k < (16 - (i % 16)) % 16; ++k) printf("   ");
  printf("|%s|\n", temp);

  printf("\n");
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "Mylib/Debug/memory_dump.cpp"
#include <cstdio>
#include <cstddef>
#include <cctype>

/**
 * @title Memory dump
 * @docs memory_dump.md
 */
void memory_dump(const void* p, size_t size){
  unsigned char *cur = (unsigned char*)p;

  printf("                 | 00 01 02 03 04 05 06 07 08 09 0a 0b 0c 0d 0e 0f\n");
  printf("__________________________________________________________________\n");

  size_t padding = (size_t)cur % 0x10;
  size += padding;
  cur -= padding;

  char temp[17];

  size_t i = 0;
  for(; i < size; ++i){
    if(i % 16 == 0){
      if(i != 0){
        printf("|%s|\n", temp);
      }
      printf("%16p | ", cur);
      for(size_t j = 0; j < 16; ++j) temp[j] = ' ';
      temp[16] = '\0';
    }

    printf("%02x ", (int)(*cur));

    if(isprint((char)(*cur))){
      temp[i % 16] = (char)(*cur);
    }else{
      temp[i % 16] = '.';
    }

    ++cur;
  }

  for(size_t k = 0; k < (16 - (i % 16)) % 16; ++k) printf("   ");
  printf("|%s|\n", temp);

  printf("\n");
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

