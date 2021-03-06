#pragma once
#include <iostream>
#include <variant>

namespace haar_lib {
  namespace dihedral_group_impl {
    struct R {
      int value = 0;
      friend std::ostream &operator<<(std::ostream &s, const R &a) {
        s << "R(" << a.value << ")";
        return s;
      }
      R() {}
      R(int value) : value(value) {}
    };

    struct S {
      int value = 0;
      friend std::ostream &operator<<(std::ostream &s, const S &a) {
        s << "S(" << a.value << ")";
        return s;
      }
      S() {}
      S(int value) : value(value) {}
    };
  }  // namespace dihedral_group_impl

  template <const int &K>
  struct dihedral_group {
    using R          = dihedral_group_impl::R;
    using S          = dihedral_group_impl::S;
    using value_type = std::variant<R, S>;

    value_type operator()() const {
      return R(0);
    }

    value_type operator()(const value_type &a, const value_type &b) const {
      if (std::holds_alternative<R>(a)) {
        if (std::holds_alternative<R>(b)) {
          return R((std::get<R>(a).value + std::get<R>(b).value) % K);
        } else {
          return S((std::get<S>(b).value - std::get<R>(a).value + K) % K);
        }
      } else {
        if (std::holds_alternative<R>(b)) {
          return S((std::get<S>(a).value + std::get<R>(b).value) % K);
        } else {
          return R((std::get<S>(b).value - std::get<S>(a).value + K) % K);
        }
      }
    }

    value_type inv(const value_type &a) const {
      if (std::holds_alternative<R>(a)) {
        const int i = std::get<R>(a).value;
        return R(i == 0 ? 0 : K - i);
      } else {
        return a;
      }
    }
  };
}  // namespace haar_lib
