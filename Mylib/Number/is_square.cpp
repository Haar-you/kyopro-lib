#pragma once

/**
 * @title Check square number
 * @docs is_square.md
 */
template <typename T> bool is_square(T n){T rt = sqrt(n); return rt * rt == n;}
