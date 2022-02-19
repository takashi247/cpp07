#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T* array, const std::size_t len, void(*func)(T&)) {
  for (std::size_t i = 0; i < len; ++i) {
    (*func)(array[i]);
  }
}

template <typename T>
void iter(const T* array, const std::size_t len, void(*func)(const T&)) {
  for (std::size_t i = 0; i < len; ++i) {
    (*func)(array[i]);
  }
}

template <typename T>
void doubleValue(T& val) {
  val += val;
}

template <typename T>
void printValue(const T& value) {
  std::cout << value << " ";
}

#endif // ITER_HPP
