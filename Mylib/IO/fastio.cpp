#pragma once
#include <cstdio>
#include <cstdlib>

class fastio {
  static const int read_size  = 1 << 26;
  static const int write_size = 1 << 26;

  char *read_data, *write_data;
  char *rb, *wb;
  char temp[100];

public:
  fastio() {
    read_data  = (char *) std::malloc(read_size);
    write_data = (char *) std::malloc(write_size);

    fread(read_data, 1, read_size, stdin);
    rb = read_data;
    wb = write_data;
  }

  ~fastio() {
    fwrite(write_data, 1, wb - write_data, stdout);
    std::free(read_data);
    std::free(write_data);
  }

  template <typename T>
  inline T read_int() {
    T ret    = 0;
    bool neg = false;

    while ((*rb < '0' or *rb > '9') and *rb != '-') ++rb;

    if (*rb == '-') {
      neg = true;
      ++rb;
    }

    while ('0' <= *rb and *rb <= '9') {
      ret = ret * 10 + (*rb - '0');
      ++rb;
    }

    if (neg) ret = -ret;

    return ret;
  }

  template <typename T>
  inline void write_int(T x) {
    if (x == 0) {
      write_char('0');
      return;
    }

    if (x < 0) {
      write_char('-');
      x = -x;
    }

    char *t = temp;

    while (x) {
      auto y = x / 10;
      *t     = (char) ('0' + x - y * 10);
      ++t;
      x = y;
    }

    while (t != temp) write_char(*(--t));
  }

  inline void write_char(char c) {
    *wb = c;
    ++wb;
  }
};
