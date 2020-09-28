- class名、関数名はsnake_case
- private member variableはunderscoreを後置する。
- template parameterはCamelCase

- `segment_tree`等の関数名 (`+`は適当な二項演算)
  - `set(i, x)`: a[i] $\leftarrow$ x
  - `update(i, x)`: a[i] $\leftarrow$ a[i] + x
  - `update(l, r, x)`: a[i] $\leftarrow$ a[i] + x ($l \le i \lt r$)
  - `fold(l, r)`: $\sum_{l \le i \lt r}$ a[i]
  - `[i]`: a[i]

- `graph`関連ライブラリの関数名
  - `add_edge(u, v, ...)`: `u`, `v`間に辺を追加する。
  - `max_flow(s, t)`: `s`から`t`への最大流を計算する。
  - `min_cost_flow(s, t)`: `s`から`t`への最小費用流を計算する。
  - `edges()`: 辺集合を返す。
  - `match()`: マッチングを計算する。
  - `get_matching()`: マッチング辺集合を返す。

- 代数的構造ライブラリの関数名
  - `()`: 単位元を返す。
  - `(a, b)`: `a`、`b`に二項演算を適用する。
  - `inv(a)`: `a`の逆元を返す。

- general
  - `count_***`: 個数の数え上げ
  - `enumerate_***`: 列挙

