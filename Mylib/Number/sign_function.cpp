#pragma once

/**
 * @title 符号関数
 * @docs sign_function.md
 */
template <typename T> int sign(T n){return (n > 0) - (n < 0);}
