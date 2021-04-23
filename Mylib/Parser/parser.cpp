#pragma once
#include <cassert>
#include <string>

namespace haar_lib {
  struct parser {
    using state = std::string::const_iterator;

    state cur, first, last;

    parser() {}
    parser(const std::string &s) : cur(s.cbegin()), first(s.cbegin()), last(s.cend()) {}

    char peek() const { return *cur; }

    bool check(char c) const {
      return *cur == c;
    }

    bool check(const std::string &s) const {
      state temp = cur;
      for (auto c : s) {
        if (c != *temp) return false;
        ++temp;
      }
      return true;
    }

    void ignore(char c) {
      assert(*cur == c);
      ++cur;
    }

    void ignore() {
      ++cur;
    }

    void ignore(const std::string &s) {
      for (auto c : s) {
        assert(*cur == c);
        ++cur;
      }
    }

    template <class Checker>
    void ignore_if(const Checker &f) {
      assert(f(*cur));
      ++cur;
    }

    bool check_and_ignore(char c) {
      if (*cur != c) return false;
      ++cur;
      return true;
    }

    bool end() const { return cur == last; }
    bool digit() const { return isdigit(*cur); }
    bool alpha() const { return isalpha(*cur); }
    bool lower() const { return islower(*cur); }
    bool upper() const { return isupper(*cur); }

    char get_char() {
      return *(cur++);
    }

    int get_digit() {
      return (int) (*(cur++) - '0');
    }

    template <typename Checker>
    auto get_string(const Checker &f) {
      std::string ret;
      while (f(peek())) {
        ret += peek();
        ignore();
      }
      return ret;
    }

    auto get_string_alpha() {
      std::string ret;
      while (isalpha(*cur)) {
        ret += *cur;
        ++cur;
      }
      return ret;
    }

    auto get_string_alnum() {
      std::string ret;
      while (isalnum(*cur)) {
        ret += *cur;
        ++cur;
      }
      return ret;
    }

    template <typename T>
    T get_number() {
      T ret = get_digit();
      while (digit()) {
        (ret *= 10) += (T)(get_digit());
      }
      return ret;
    }
  };
}  // namespace haar_lib
