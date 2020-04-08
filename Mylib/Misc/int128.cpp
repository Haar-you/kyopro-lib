#pragma once

/**
 * @title 128bit整数型
 */
#ifdef __SIZEOF_INT128__
using uint128_t = __uint128_t;
#else
#include <boost/multiprecision/cpp_int.hpp>
using uint128_t = boost::multiprecision::uint128_t;
#endif
