#include <iostream>
#include <iomanip>
#include <vector>
#include <array>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <list>
#include <forward_list>
#include <string>
#include <optional>
#include <variant>
#include <complex>
#include <initializer_list>

template <class T, class Allocator>
void debug_print(std::ostream&, std::vector<T, Allocator>);

template <class T, std::size_t N>
void debug_print(std::ostream&, std::array<T, N>);

template <class T, class Allocator>
void debug_print(std::ostream&, std::deque<T, Allocator>);

template <class T, class Container>
void debug_print(std::ostream&, std::stack<T, Container>);

template <class T, class Container>
void debug_print(std::ostream&, std::queue<T, Container>);

template <class T, class Container, class Compare>
void debug_print(std::ostream&, std::priority_queue<T, Container, Compare>);


template <class Key, class Compare, class Allocator>
void debug_print(std::ostream&, std::set<Key, Compare, Allocator>);

template <class Key, class Hash, class Pred, class Allocator>
void debug_print(std::ostream&, std::unordered_set<Key, Hash, Pred, Allocator>);

template <class Key, class T, class Compare, class Allocator>
void debug_print(std::ostream&, std::map<Key, T, Compare, Allocator>);


template <class Key, class T, class Hash, class Pred, class Allocator>
void debug_print(std::ostream&, std::unordered_map<Key, T, Hash, Pred, Allocator>);

template <class T1, class T2>
void debug_print(std::ostream&, std::pair<T1, T2>);

template <class ... Args>
void debug_print(std::ostream&, std::tuple<Args ...>);

template <class T, class Allocator>
void debug_print(std::ostream&, std::list<T, Allocator>);

template <class T, class Allocator>
void debug_print(std::ostream&, std::forward_list<T, Allocator>);

template <class Key, class Compare, class Allocator>
void debug_print(std::ostream&, std::multiset<Key, Compare, Allocator>);

template <class Key, class Hash, class Pred, class Allocator>
void debug_print(std::ostream&, std::unordered_multiset<Key, Hash, Pred, Allocator>);

template <class Key, class T, class Compare, class Allocator>
void debug_print(std::ostream&, std::multimap<Key, T, Compare, Allocator>);

template <class Key, class T, class Hash, class Pred, class Allocator>
void debug_print(std::ostream&, std::unordered_multimap<Key, T, Hash, Pred, Allocator>);

template <class T>
void debug_print(std::ostream&, std::complex<T>);

template <class T>
void debug_print(std::ostream&, std::optional<T>);

template <class ... Types>
void debug_print(std::ostream&, std::variant<Types ...>);

void debug_print(std::ostream&, bool);
void debug_print(std::ostream&, int);
void debug_print(std::ostream&, double);
void debug_print(std::ostream&, std::string);
void debug_print(std::ostream&, char);

template <size_t N>
void debug_print(std::ostream&, const char (&)[N]);

template <typename T, size_t N>
void debug_print(std::ostream&, const T (&)[N]);

template <typename T>
void debug_print(std::ostream&, T);












#define dump(...) dump_(__LINE__, #__VA_ARGS__, __VA_ARGS__)


template <class T>
void dump_helper(int line, T value){
  std::cerr << "[\e[1;33mL" << std::setw(3) << line << "\e[m] ";
  std::cerr << "\e[1;32m";
  debug_print(std::cerr, value);
  std::cerr << "\e[m" << std::endl;
}

template <class... Args>
void dump_(int line, std::string names, Args &&... args){
  std::cerr << "[\e[1m====\e[m] \e[1m" << names << "\e[m" << "\n";
  (void)std::initializer_list<int>{(void(dump_helper(line, args)), 0) ...};
}



template <typename Iter>
void dump_container(std::ostream& s, Iter first, Iter last){
  s << "{";
  for(auto it = first; it != last; ++it){
    if(it != first) s << ",";
    debug_print(s, *it);
  }
  s << "}";
}

// vector
template <class T, class Allocator>
void debug_print(std::ostream& s, std::vector<T, Allocator> val){
  dump_container(s, val.begin(), val.end());
}

// array
template <class T, std::size_t N>
void debug_print(std::ostream& s, std::array<T, N> val){
  dump_container(s, val.begin(), val.end());
}

// deque
template <class T, class Allocator>
void debug_print(std::ostream& s, std::deque<T, Allocator> val){
  dump_container(s, val.begin(), val.end());
}

// stack
template <class T, class Container>
void debug_print(std::ostream& s, std::stack<T, Container> val){
  int N = val.size();

  s << "{";
  for(int i = 0; i < N; ++i){
    if(i) s << ",";
    auto x = val.top(); val.pop();
    debug_print(s, x);
  }
  s << "}";
}

// queue
template <class T, class Container>
void debug_print(std::ostream& s, std::queue<T, Container> val){
  int N = val.size();

  s << "{";
  for(int i = 0; i < N; ++i){
    if(i) s << ",";
    auto x = val.front(); val.pop();
    debug_print(s, x);
  }
  s << "}";
}

// priority_queue
template <class T, class Container, class Compare>
void debug_print(std::ostream& s, std::priority_queue<T, Container, Compare> val){
  int N = val.size();

  s << "{";
  for(int i = 0; i < N; ++i){
    if(i) s << ",";
    auto x = val.top(); val.pop();
    debug_print(s, x);
  }
  s << "}";
}

// set
template <class Key, class Compare, class Allocator>
void debug_print(std::ostream& s, std::set<Key, Compare, Allocator> val){
  dump_container(s, val.begin(), val.end());
}

// unrodered_set
template <class Key, class Hash, class Pred, class Allocator>
void debug_print(std::ostream& s, std::unordered_set<Key, Hash, Pred, Allocator> val){
  dump_container(s, val.begin(), val.end());
}

// map
template <class Key, class T, class Compare, class Allocator>
void debug_print(std::ostream& s, std::map<Key, T, Compare, Allocator> val){
  dump_container(s, val.begin(), val.end());
}

// unordered_map
template <class Key, class T, class Hash, class Pred, class Allocator>
void debug_print(std::ostream& s, std::unordered_map<Key, T, Hash, Pred, Allocator> val){
  dump_container(s, val.begin(), val.end());
}


// pair
template <class T1, class T2>
void debug_print(std::ostream& s, std::pair<T1, T2> val){
  s << "(";
  debug_print(s, val.first);
  s<< ",";
  debug_print(s, val.second);
  s << ")";
}

// tuple
template <size_t I, class ... Args>
void tuple_dump_helper(std::ostream& s, std::tuple<Args ...> val){
  if constexpr (I == 1){
    debug_print(s, std::get<0>(val));
  }else{
    tuple_dump_helper<I - 1, Args ...>(s, val);
    s << ",";
    debug_print(s, std::get<I - 1>(val));
  }
}

template <class ... Args>
void debug_print(std::ostream& s, std::tuple<Args ...> val){
  s << "(";
  tuple_dump_helper<sizeof ... (Args), Args ...>(s, val);
  s << ")";
}


// list
template <class T, class Allocator>
void debug_print(std::ostream& s, std::list<T, Allocator> val){
  dump_container(s, val.begin(), val.end());
}

// forward_list
template <class T, class Allocator>
void debug_print(std::ostream& s, std::forward_list<T, Allocator> val){
  dump_container(s, val.begin(), val.end());
}

// multiset
template <class Key, class Compare, class Allocator>
void debug_print(std::ostream& s, std::multiset<Key, Compare, Allocator> val){
  dump_container(s, val.begin(), val.end());
}

// unordered_multiset
template <class Key, class Hash, class Pred, class Allocator>
void debug_print(std::ostream& s, std::unordered_multiset<Key, Hash, Pred, Allocator> val){
  dump_container(s, val.begin(), val.end());
}

// multimap
template <class Key, class T, class Compare, class Allocator>
void debug_print(std::ostream& s, std::multimap<Key, T, Compare, Allocator> val){
  dump_container(s, val.begin(), val.end());
}

// unordered_multimap
template <class Key, class T, class Hash, class Pred, class Allocator>
void debug_print(std::ostream& s, std::unordered_multimap<Key, T, Hash, Pred, Allocator> val){
  dump_container(s, val.begin(), val.end());
}

// complex number
template <class T>
void debug_print(std::ostream& s, std::complex<T> val){
  s << val.real() << (val.imag() < 0 ? "" : "+") << val.imag() << "i";
}


// optional
template <class T>
void debug_print(std::ostream& s, std::optional<T> val){
  s << "{";
  if(val.has_value()){
    debug_print(s, val.value());
  }
  s << "}";
}

// variant
template <class ... Types>
void debug_print(std::ostream& s, std::variant<Types ...> val){
  std::visit([&s](const auto &x){debug_print(s, x);}, val);
}


// others
void debug_print(std::ostream& s, bool val){
  if(val){
    s << "true";
  }else{
    s << "false";
  }
}

void debug_print(std::ostream& s, int val){
  s << val;
}

void debug_print(std::ostream& s, double val){
  s << val;
}

void debug_print(std::ostream& s, std::string val){
  s << "\"" << val << "\"";
}

void debug_print(std::ostream& s, char val){
  s << "'" << val << "'";
}

// array

template <size_t N>
void debug_print(std::ostream& s, const char (&val)[N]){
  s << "\"" << val << "\"";
}

template <typename T, size_t N>
void debug_print(std::ostream& s, const T val[N]){
  s << "{";
  for(int i = 0; i < (int)N; ++i){
    if(i) s << ",";
    debug_print(s, val[i]);
  }
  s << "}";
}

template <typename T>
void debug_print(std::ostream& s, T val){
  s << val;
}
