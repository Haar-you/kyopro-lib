#pragma once
#include <utility>

/**
 * @title 不動点コンビネータ
 * @docs fix_point.md
 */
template <typename F>
struct FixPoint : F{
  explicit constexpr FixPoint(F &&f) noexcept : F(std::forward<F>(f)){}

  template <typename... Args>
  constexpr auto operator()(Args &&... args) const {
    return F::operator()(*this, std::forward<Args>(args)...);
  }
};

template <typename F>
inline constexpr auto make_fix_point(F &&f){
  return FixPoint<F>(std::forward<F>(f));
}

template <typename F>
inline constexpr auto make_fix_point(F &f){
  return FixPoint<F>(std::forward<F>(f));
}
