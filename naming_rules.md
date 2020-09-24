- class名、関数名はsnake_case

- `segment_tree`等の関数名 (`+`は適当な二項演算)
  - `set(i, x)`: a[i] $\leftarrow$ x
  - `update(i, x)`: a[i] $\leftarrow$ a[i] + x
  - `update(l, r, x)`: a[i] $\leftarrow$ a[i] + x ($l \le i \lt r$)
  - `fold(l, r)`: $\sum_{l \le i \lt r}$ a[i]
  - `[i]`: a[i]
