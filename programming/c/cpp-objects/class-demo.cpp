#include <cstdio>
#include <iostream>

class democlass {
public:
  // Two member variables, a and b
  int a, b;

  // TODO: add here the member function
  //       described in the exercise
  void print_members() {
    std::cout << "a=" << a << std::endl;
    std::cout << "b=" << b << std::endl;
  }
};

int main(void)
{
  democlass demo;
  demo.a = 10;
  demo.b = 20;

  // TODO: add here a call to the member
  //       function
  demo.print_members();

  return 0;
}
