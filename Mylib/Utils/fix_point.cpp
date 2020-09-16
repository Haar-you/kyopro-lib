#pragma once
#include <utility>

namespace haar_lib {
  template <typename F>
  struct fix_point : F {
    explicit constexpr fix_point(F &&f) noexcept : F(std::forward<F>(f)){}

    template <typename ... Args>
    constexpr auto operator()(Args &&... args) const {
      return F::operator()(*this, std::forward<Args>(args) ...);
    }
  };

  template <typename F>
  inline constexpr auto make_fix_point(F &&f){
    return fix_point<F>(std::forward<F>(f));
  }

  template <typename F>
  inline constexpr auto make_fix_point(F &f){
    return fix_point<F>(std::forward<F>(f));
  }
}
