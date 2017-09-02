//
// Created by xz on 8/30/17.
//

#include "my_thread.h"

#include <type_traits>
#include <typeinfo>
#include <iostream>

template<typename T>
class TD;

decltype(auto) f() {
  int x = 0;
  return (x);
}

int foo(int a, int b, int c) {
  return a + b + c;
}

int main(int argc, const char * argv[]) {
  // insert code here...
  std::cout << "Hello, World!\n";
  // TD<decltype(f())> f_type;
  std::cout << typeid(f()).name() << std::endl;

  auto bindFoo = std::bind(foo, std::placeholders::_1, 1, 2);
  std::cout << bindFoo(3) << std::endl;

  MyThread::RunInThread();

  return 0;
}

