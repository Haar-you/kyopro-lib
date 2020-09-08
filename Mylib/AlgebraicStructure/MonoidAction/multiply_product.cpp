#pragma once
#include "Mylib/AlgebraicStructure/Monoid/product.cpp"
#include "Mylib/AlgebraicStructure/Monoid/monoid_utils.cpp"

/**
 * @title Range multiply / Range product
 * @docs multiply_product.md
 */
namespace haar_lib {
  template <typename T, typename U>
  struct multiply_product {
    using monoid_get = product_monoid<T>;
    using monoid_update = product_monoid<U>;
    using value_type_get = typename monoid_get::value_type;
    using value_type_update = typename monoid_update::value_type;
    monoid_get M1;
    monoid_update M2;

    value_type_get id_get() const {return M1.id();}
    value_type_update id_update() const {return M2.id();}

    value_type_get op_get(value_type_get a, value_type_get b) const {return M1.op(a, b);}
    value_type_update op_update(value_type_update a, value_type_update b) const {return M2.op(a, b);}

    value_type_get op(value_type_get a, value_type_update b, int len) const {
      return a * times<monoid_update>(b, len);
    }
  };
}
