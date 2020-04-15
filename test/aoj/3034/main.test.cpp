#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3034"
#define ERROR 1e-3

#include <iostream>
#include <iomanip>
#include <vector>

#include "Mylib/Geometry/Float/geometry_template.cpp"
#include "Mylib/Geometry/Float/double_eps.cpp"
#include "Mylib/Geometry/Float/minimum_covering_circle.cpp"
#include "Mylib/Misc/fix_point.cpp"
#include "Mylib/Bit/for_each_subset_asc.cpp"

using D = DoubleEps<double>;
template <> double D::eps = ERROR;

D dp[15][1<<14];
bool check[15][1<<14];

const D INF = 1e9;

int main(){
  int N, M; std::cin >> N >> M;

  std::vector<Point<D>> ps(N);
  for(int i = 0; i < N; ++i) std::cin >> ps[i];

  const int mask = (1 << N) - 1;

  std::vector<double> memo(1 << N);

  for(int t = 0; t < (1 << N); ++t){  
    std::vector<Point<D>> q;
    for(int i = 0; i < N; ++i){
      if(t & (1 << i)) q.push_back(ps[i]);
    }
    memo[t] = (double)minimum_covering_circle(q).radius;
  }  

  auto rec =
    make_fix_point([&](auto &&rec, int d, int s) -> D{
                     if(d == M){
                       if(s != 0) return dp[d][s] = INF;
                       return dp[d][s] = 0;
                     }

                     if(check[d][s]) return dp[d][s];
                     check[d][s] = true;

                     D ret = INF;

                     for_each_subset_asc(s,
                                         [&](int t){
                                           
                                           D val = std::max((double)rec(d+1, s^t), memo[t]);
                                           ret = std::min((double)ret, (double)val);
                                         });

                     return dp[d][s] = ret;
                   });

  auto ans = rec(0, mask);

  std::cout << std::fixed << std::setprecision(12) << ans << std::endl;

  return 0;
}
