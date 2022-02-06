#include <iostream>
#include <sstream>
#include "iter.hpp"

void printHeader(std::string header) {
  std::cout << "\n---" << header << "---\n" << std::endl;
}

int main() {

  std::size_t array_size = 10;
  {
    printHeader("Test for char");
    char array[10];
    for (std::size_t i = 0; i < array_size; ++i) {
      array[i] = '!' + static_cast<char>(i);
    }
    std::cout << "Original array: ";
    ::iter(array, array_size, ::printValue);
    std::cout << std::endl;
    ::iter(array, array_size, doubleValue);
    std::cout << "After doubled: ";
    ::iter(array, array_size, ::printValue);
    std::cout << std::endl;
  }
  {
    printHeader("Test for int");
    int array[10];
    for (std::size_t i = 0; i < array_size; ++i) {
      array[i] = i + 1;
    }
    std::cout << "Original array: ";
    ::iter(array, array_size, ::printValue);
    std::cout << std::endl;
    ::iter(array, array_size, doubleValue);
    std::cout << "After doubled: ";
    ::iter(array, array_size, ::printValue);
    std::cout << std::endl;
  }
  {
    printHeader("Test for float");
    float array[10];
    for (std::size_t i = 0; i < array_size; ++i) {
      array[i] = static_cast<float>(i) + 0.2f;
    }
    std::cout << "Original array: ";
    ::iter(array, array_size, ::printValue);
    std::cout << std::endl;
    ::iter(array, array_size, doubleValue);
    std::cout << "After doubled: ";
    ::iter(array, array_size, ::printValue);
    std::cout << std::endl;
  }
  {
    printHeader("Test for string");
    std::string array[10];
    for (std::size_t i = 0; i < array_size; ++i) {
      std::stringstream ss;
      ss << i;
      array[i] = ss.str();
    }
    std::cout << "Original array: ";
    ::iter(array, array_size, ::printValue);
    std::cout << std::endl;
    ::iter(array, array_size, doubleValue);
    std::cout << "After doubled: ";
    ::iter(array, array_size, ::printValue);
    std::cout << std::endl;
  }
  std::cout << std::endl;
}
