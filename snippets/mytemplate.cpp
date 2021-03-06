# -*- mode: snippet -*-
# name: mytemplate
# key: mytemplate
# --
#include <bits/stdc++.h>

#ifdef DEBUG
#include <Mylib/Debug/debug.cpp>
#else
#define dump(...) ((void)0)
#endif

template <typename T, typename U>
bool chmin(T &a, const U &b) {
  return (a > b ? a = b, true : false);
}

template <typename T, typename U>
bool chmax(T &a, const U &b) {
  return (a < b ? a = b, true : false);
}

template <typename T, size_t N, typename U>
void fill_array(T (&a)[N], const U &v) {
  std::fill((U *) a, (U *) (a + N), v);
}

template <typename T, size_t N, size_t I = N>
auto make_vector(const std::array<int, N> &a, T value = T()) {
  static_assert(I >= 1);
  static_assert(N >= 1);
  if constexpr (I == 1) {
    return std::vector<T>(a[N - I], value);
  } else {
    return std::vector(a[N - I], make_vector<T, N, I - 1>(a, value));
  }
}

template <typename T>
std::ostream &operator<<(std::ostream &s, const std::vector<T> &a) {
  for (auto it = a.begin(); it != a.end(); ++it) {
    if (it != a.begin()) s << " ";
    s << *it;
  }
  return s;
}

template <typename T>
std::istream &operator>>(std::istream &s, std::vector<T> &a) {
  for (auto &x : a) s >> x;
  return s;
}

std::string YesNo(bool value) { return value ? "Yes" : "No"; }
std::string YESNO(bool value) { return value ? "YES" : "NO"; }
std::string yesno(bool value) { return value ? "yes" : "no"; }

template <typename T>
void putl(const T &value) {
  std::cout << value << "\n";
}

template <typename Head, typename... Tail>
void putl(const Head head, const Tail &... tail) {
  std::cout << head << " ";
  putl(tail...);
}

namespace haar_lib {}

namespace solver {
  using namespace haar_lib;

  constexpr int m1000000007 = 1000000007;
  constexpr int m998244353  = 998244353;

  void init() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(12);
    std::cerr << std::fixed << std::setprecision(12);
    std::cin.exceptions(std::ios_base::failbit);
  }

  void solve() {
    $0
  }
}

int main() {
  solver::init();
  while (true) {
    try {
      solver::solve();
      std::cout << std::flush;
      std::cerr << std::flush;
    } catch (const std::istream::failure &e) {
      break;
    } catch (...) {
      break;
    }
  }
  return 0;
}
