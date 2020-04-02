#pragma once

/**
 * @title 平方数判定
 */
template <typename T> bool is_square(T n){T rt = sqrt(n); return rt * rt == n;}
