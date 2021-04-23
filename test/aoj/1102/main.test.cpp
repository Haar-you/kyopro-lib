#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1102"

#include <iostream>
#include <string>
#include "Mylib/Parser/parser.cpp"

namespace hl = haar_lib;

struct complex {
  int real, imag;
  bool overflow;

  complex() : real(0), imag(0), overflow(false) {}
  complex(int real, int imag = 0) : real(real), imag(imag), overflow(false) {
    if (abs(real) > 10000 or abs(imag) > 10000) overflow = true;
  }
  complex(bool overflow) : real(0), imag(0), overflow(true) {}

  friend complex operator+(const complex &a, const complex &b) {
    if (a.overflow or b.overflow) return complex(true);
    return complex(a.real + b.real, a.imag + b.imag);
  }

  friend complex operator-(const complex &a, const complex &b) {
    if (a.overflow or b.overflow) return complex(true);
    return complex(a.real - b.real, a.imag - b.imag);
  }

  friend complex operator-(const complex &a) {
    if (a.overflow) return complex(true);
    return complex(-a.real, -a.imag);
  }

  friend complex operator*(const complex &a, const complex &b) {
    if (a.overflow or b.overflow) return complex(true);
    return complex(a.real * b.real - a.imag * b.imag, a.real * b.imag + a.imag * b.real);
  }

  complex &operator=(const complex &a) {
    this->real     = a.real;
    this->imag     = a.imag;
    this->overflow = a.overflow;
    return *this;
  }

  complex &operator+=(const complex &a) {
    *this = *this + a;
    return *this;
  }

  complex &operator-=(const complex &a) {
    *this = *this - a;
    return *this;
  }

  complex &operator*=(const complex &a) {
    *this = *this * a;
    return *this;
  }
};

std::ostream &operator<<(std::ostream &os, const complex &a) {
  if (a.overflow)
    os << "overflow";
  else {
    if (a.real == 0 and a.imag == 0)
      os << 0;
    else {
      if (a.real) {
        os << a.real;
      }
      if (a.imag) {
        if (a.imag > 0 and a.real) os << "+";
        os << a.imag;
        os << "i";
      }
    }
  }
  return os;
}

struct parser : hl::parser {
  parser(const std::string &s) : hl::parser(s) {}

  complex number() {
    bool neg = false;
    if (check_and_ignore('-')) neg = true;

    complex ret;

    if (digit()) {
      ret = get_number<complex>();

      if (check_and_ignore('i')) {
        ret *= complex(0, 1);
      }
    } else {
      if (check_and_ignore('i')) {
        ret = complex(0, 1);
      }
    }

    if (neg) ret = -ret;

    return ret;
  }

  complex factor() {
    complex ret;

    if (check_and_ignore('(')) {
      ret = expression();
      ignore(')');
    } else {
      ret = number();
    }

    return ret;
  }

  complex term() {
    complex ret = factor();

    while (1) {
      if (check_and_ignore('*')) {
        ret *= factor();
      } else {
        break;
      }
    }

    return ret;
  }

  complex expression() {
    complex ret = term();

    while (1) {
      if (check_and_ignore('+')) {
        ret += term();
      } else if (check_and_ignore('-')) {
        ret -= term();
      } else {
        break;
      }
    }

    return ret;
  }

  complex run() {
    return expression();
  }
};

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);

  std::string s;
  while (std::cin >> s) {
    std::cout << parser(s).run() << "\n";
  }

  return 0;
}
