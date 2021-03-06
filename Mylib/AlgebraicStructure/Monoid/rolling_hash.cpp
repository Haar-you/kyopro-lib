#pragma once
#include <array>
#include <utility>

namespace haar_lib {
  namespace rolling_hash_monoid_impl {
    template <int64_t Mod, int64_t Base>
    struct internal_value {
      int64_t hash, power;
      internal_value() {}
      internal_value(int64_t hash, int64_t power) : hash(hash), power(power) {}
      internal_value(int64_t a) : hash(a % Mod), power(Base) {}
    };
  }  // namespace rolling_hash_monoid_impl

  template <int64_t Mod, int Base>
  struct rolling_hash_monoid {
    using value_type = rolling_hash_monoid_impl::internal_value<Mod, Base>;

    value_type operator()() const {
      value_type ret(0, 1);
      return ret;
    }

    value_type operator()(const value_type &a, const value_type &b) const {
      value_type ret;
      ret.hash  = (a.hash + b.hash * a.power % Mod) % Mod;
      ret.power = a.power * b.power % Mod;
      return ret;
    }
  };
}  // namespace haar_lib
