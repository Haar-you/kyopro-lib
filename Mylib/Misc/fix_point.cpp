#pragma once
#include <utility>

/**
 * @title 不動点コンビネータ
 */
template <typename F>
struct FixPoint : F{
  explicit constexpr FixPoint(F &&f) noexcept : F(std::forward<F>(f)){}

  template <typename... Args>
  constexpr decltype(auto) operator()(Args &&... args) const {
    return F::operator()(*this, std::forward<Args>(args)...);
  }
};

template <typename F>
static inline constexpr decltype(auto) make_fix_point(F &&f){
  return FixPoint<F>(std::forward<F>(f));
}

template <typename F>
static inline constexpr decltype(auto) make_fix_point(F &f){
  return FixPoint<F>(std::forward<F>(f));
}
