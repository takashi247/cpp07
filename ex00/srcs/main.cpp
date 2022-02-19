#include <iostream>
#include <string>

#include "whatever.hpp"

void printHeader(std::string header) {
  std::cout << "\n---" << header << "---\n" << std::endl;
}

void testAdditional() {
  printHeader("Start char tests");
  tester<char>('a', 'b');
  printHeader("Start float tests");
  tester<float>(-4.2f, 4.2f);
  printHeader("Start double tests");
  tester<double>(-4.2e-200, 4.2e200);
  printHeader("Start const string tests");
  tester<std::string>("abcde", "fghij");
  printHeader("Start boolean tests");
  tester<bool>(false, true);
}

void testSubject() {
  printHeader("Start subject test");

  int a = 2;
  int b = 3;

  ::swap(a, b);
  std::cout << "a = " << a << ", b = " << b << std::endl;
  std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
  std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;

  std::string c = "chaine1";
  std::string d = "chaine2";

  ::swap(c, d);
  std::cout << "c = " << c << ", d = " << d << std::endl;
  std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
  std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
}

int main() {
  testSubject();
#ifdef TEST
  testAdditional();
#endif
  std::cout << std::endl;
}

#ifdef LEAKS
void	detect_leak(void)__attribute__((destructor));

void	detect_leak(void) {
  system("leaks -q a.out");
}
#endif
