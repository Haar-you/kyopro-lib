#pragma once
#include <cmath>
#include <iostream>
#include <vector>

namespace haar_lib {
  template <typename T>
  struct vec {
    T x, y;
    vec() {}
    vec(T x, T y) : x(x), y(y) {}

    friend auto operator+(const vec &a, const vec &b) { return vec(a.x + b.x, a.y + b.y); }
    friend auto operator-(const vec &a, const vec &b) { return vec(a.x - b.x, a.y - b.y); }
    friend auto operator-(const vec &a) { return vec(-a.x, -a.y); }

    friend bool operator==(const vec &a, const vec &b) { return a.x == b.x and a.y == b.y; }
    friend bool operator!=(const vec &a, const vec &b) { return !(a == b); }
    friend bool operator<(const vec &a, const vec &b) { return a.x < b.x or (a.x == b.x and a.y < b.y); }

    friend std::istream &operator>>(std::istream &s, vec &a) {
      s >> a.x >> a.y;
      return s;
    }
  };

  template <typename T, typename U>
  auto operator*(const vec<T> &a, const U &k) { return vec<T>(a.x * k, a.y * k); }
  template <typename T, typename U>
  auto operator*(const U &k, const vec<T> &a) { return vec<T>(a.x * k, a.y * k); }
  template <typename T, typename U>
  auto operator/(const vec<T> &a, const U &k) { return vec<T>(a.x / k, a.y / k); }

  template <typename T>
  using point = vec<T>;

  template <typename T>
  T abs(const vec<T> &a) { return sqrt(a.x * a.x + a.y * a.y); }
  template <typename T>
  T abs_sq(const vec<T> &a) { return a.x * a.x + a.y * a.y; }

  template <typename T>
  T dot(const vec<T> &a, const vec<T> &b) { return a.x * b.x + a.y * b.y; }
  template <typename T>
  T cross(const vec<T> &a, const vec<T> &b) { return a.x * b.y - a.y * b.x; }

  template <typename T>
  auto unit(const vec<T> &a) { return a / abs(a); }
  template <typename T>
  auto normal(const vec<T> &p) { return vec<T>(-p.y, p.x); }

  template <typename T>
  auto polar(const T &r, const T &ang) { return vec<T>(r * cos(ang), r * sin(ang)); }

  template <typename T>
  T angle(const vec<T> &a, const vec<T> &b) { return atan2(b.y - a.y, b.x - a.x); }
  template <typename T>
  T phase(const vec<T> &a) { return atan2(a.y, a.x); }

  template <typename T>
  T angle_diff(const vec<T> &a, const vec<T> &b) {
    T r = phase(b) - phase(a);

    if (r < -M_PI)
      return r + 2 * M_PI;
    else if (r > M_PI)
      return r - 2 * M_PI;
    return r;
  }

  template <typename T>
  struct line {
    point<T> from, to;
    line() : from(), to() {}
    line(const point<T> &from, const point<T> &to) : from(from), to(to) {}
  };

  template <typename T>
  using segment = line<T>;

  template <typename T>
  auto unit(const line<T> &a) { return unit(a.to - a.from); }
  template <typename T>
  auto normal(const line<T> &a) { return normal(a.to - a.from); }

  template <typename T>
  auto diff(const segment<T> &a) { return a.to - a.from; }

  template <typename T>
  T abs(const segment<T> &a) { return abs(diff(a)); }

  template <typename T>
  T dot(const line<T> &a, const line<T> &b) { return dot(diff(a), diff(b)); }
  template <typename T>
  T cross(const line<T> &a, const line<T> &b) { return cross(diff(a), diff(b)); }

  template <typename T>
  using polygon = std::vector<point<T>>;

  template <typename T>
  struct circle {
    point<T> center;
    T radius;
    circle() : center(), radius(0) {}
    circle(const point<T> &center, T radius) : center(center), radius(radius) {}
  };

  template <typename T>
  std::ostream &operator<<(std::ostream &s, const vec<T> &a) {
    s << "(" << a.x << ", " << a.y << ")";
    return s;
  }

  template <typename T>
  std::ostream &operator<<(std::ostream &s, const line<T> &a) {
    s << "(" << a.from << " -> " << a.to << ")";
    return s;
  }

  template <typename T>
  std::ostream &operator<<(std::ostream &s, const circle<T> &a) {
    s << "("
      << "center: " << a.center << ", "
      << "radius: " << a.radius << ")";
    return s;
  }
}  // namespace haar_lib
