#define PROBLEM "https://judge.yosupo.jp/problem/persistent_queue"

#include <iostream>
#include <vector>
#include "Mylib/DataStructure/Queue/persistent_queue.cpp"
#include "Mylib/IO/input_tuples.cpp"

int main(){
  int Q; std::cin >> Q;

  std::vector<PersistentQueue<int>> S;

  for(auto [type, t] : input_tuples<int, int>(Q)){
    if(type == 0){
      int x; std::cin >> x;
      if(t == -1){
        PersistentQueue<int> a(x);
        S.push_back(a);
      }else{
        auto res = S[t].push(x);
        S.push_back(res);
      }
    }else{
      std::cout << S[t].front() << std::endl;
      auto res = S[t].pop();
      S.push_back(res);
    }
  }

  return 0;
}
