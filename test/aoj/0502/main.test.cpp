#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0502"

#include <iostream>
#include <string>
#include "Mylib/Misc/dice.cpp"

int main(){
  int N;
  while(std::cin >> N, N){
    auto d = Dice(1, 6, 2, 5, 3, 4);

    int ans = 1;

    while(N--){
      std::string s; std::cin >> s;

      if(s == "North") d = d.rot_back(), ans += d.top;
      if(s == "East") d = d.rot_right(), ans += d.top;
      if(s == "West") d = d.rot_left(), ans += d.top;
      if(s == "South") d = d.rot_front(), ans += d.top;
      if(s == "Right") d = d.rot_clockwise(), ans += d.top;
      if(s == "Left") d = d.rot_counterclockwise(), ans += d.top;
    }
    
    std::cout << ans << "\n";
  }

  return 0;
}
