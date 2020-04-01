#pragma once
#include <vector>
#include <functional>
#include <cassert>

template <typename T, typename Add = std::plus<T>, typename Minus = std::minus<T>>
class CumulativeSum2D{
  std::vector<std::vector<T>> data;
  const int N, M;
  const Add add;
  const Minus minus;
  bool is_built = false;

public:
  CumulativeSum2D(const std::vector<std::vector<T>> &a, const T &e = 0, const Add &add = Add(), const Minus &minus = Minus()):
    N(a.size()), M(a[0].size()), add(add), minus(minus)
  {
    data.assign(N+1, std::vector<T>(M+1, e));
    for(int i = 0; i < N; ++i){
      for(int j = 0; j < M; ++j){
        data[i+1][j+1] = a[i][j];
      }
    }
  }

  CumulativeSum2D(int N, int M, const T &e = 0, const Add &add = Add(), const Minus &minus = Minus()):
    N(N), M(M), add(add), minus(minus)
  {
    data.assign(N+1, std::vector<T>(M+1, e));
  }

  inline void update(int i, int j, const T &val){
    assert(not is_built);
    data[i+1][j+1] = add(data[i+1][j+1], val);
  }

  inline void build(){
    assert(not is_built);
    for(int i = 1; i <= N; ++i) for(int j = 0; j <= M; ++j) data[i][j] = add(data[i][j], data[i-1][j]);
    for(int i = 0; i <= N; ++i) for(int j = 1; j <= M; ++j) data[i][j] = add(data[i][j], data[i][j-1]);
    is_built = true;
  }

  inline T get(int x1, int y1, int x2, int y2) const { // [x1,x2), [y1,y2)
    assert(is_built);
    return add(minus(data[x2][y2], add(data[x1][y2], data[x2][y1])), data[x1][y1]);
  }
};