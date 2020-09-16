#pragma once

namespace haar_lib {
#ifdef __SIZEOF_INT128__
  using uint128_t = __uint128_t;
  using int128_t = __int128_t;
#else
#include <boost/multiprecision/cpp_int.hpp>
  using uint128_t = boost::multiprecision::uint128_t;
  using int128_t = boost::multiprecision::int128_t;
#endif
}
