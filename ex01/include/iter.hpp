#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <iostream>

template <typename T>
void printValue(T& value) {
  std::cout << value << " ";
}

template <typename T>
void iter(T* array, std::size_t len, void(*func)(T&)) {
  for (std::size_t i = 0; i < len; ++i) {
    (*func)(array[i]);
  }
}

template <typename T>
void doubleValue(T& val) {
  val += val;
}

#endif // ITER_HPP
