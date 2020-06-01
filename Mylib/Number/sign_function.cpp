#pragma once

/**
 * @title Sign function
 * @docs sign_function.md
 */
template <typename T> int sign(T n){return (n > 0) - (n < 0);}
