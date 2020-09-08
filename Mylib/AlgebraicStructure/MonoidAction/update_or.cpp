#pragma once
#include <optional>

/**
 * @title Range update / Range bitor
 * @docs update_or.md
 */
namespace haar_lib {
  template <typename T, typename U>
  struct UpdateOr {
    using value_type_get = T;
    using value_type_update = std::optional<U>;

    value_type_get id_get() const {return 0;}
    value_type_update id_update() const {return {};}

    value_type_get op_get(value_type_get a, value_type_get b) const {return a | b;}
    value_type_update op_update(value_type_update a, value_type_update b) const {return (a ? a : b );}

    value_type_get op(value_type_get a, value_type_update b, int len) const {
      return b ? *b : a;
    }
  };
}
