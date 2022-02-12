#include "Array.hpp"

#include <iostream>

int main() {

  // test empty array
  std::cout << "\n---empty array test---\n" << std::endl;

  Array<int> arr_empty;
  Array<int> arr_empty_cpy(arr_empty);
  Array<int> arr_empty_assign;
  arr_empty_assign = arr_empty;

  try {
    std::cout << "size of arr_empty: " << arr_empty.size() << std::endl;
    std::cout << "size of arr_empty_cpy: " << arr_empty_cpy.size() << std::endl;
    std::cout << "size of arr_empty_assign: " << arr_empty_assign.size() << std::endl;
    arr_empty[0] = 0;
  } catch (const std::exception&) {
    std::cout << "invalid index" << std::endl;
  }

  {
    // test integer case
    std::cout << "\n---int array test---\n" << std::endl;

    Array<int> arr(10);
    Array<int> arr_cpy(arr);
    Array<int> arr_assign;
    arr_assign = arr;

    std::cout << "size of arr: " << arr.size() << std::endl;
    std::cout << "size of arr_cpy: " << arr_cpy.size() << std::endl;
    std::cout << "size of arr_assign: " << arr_assign.size() << std::endl;

    try {
      for (unsigned int i = 0; i < arr.size() + 1; ++i) {
        arr[i] = i;
        arr_cpy[i] = i + 10;
        arr_assign[i] = i + 100;
        std::cout << "arr["  << i << "] = " << arr[i] << "  "
                  << "arr_cpy[" << i << "] = " << arr_cpy[i] << "   "
                  << "arr_assign[" << i << "] = " << arr_assign[i] << std::endl;
      }
    } catch (const std::exception&) {
      std::cout << "invalid index" << std::endl;
    }
  }
  {
    // test floating point case
    std::cout << "\n---double array test---\n" << std::endl;

    Array<double> arr(10);
    Array<double> arr_cpy(arr);
    Array<double> arr_assign;
    arr_assign = arr;

    std::cout << "size of arr: " << arr.size() << std::endl;
    std::cout << "size of arr_cpy: " << arr_cpy.size() << std::endl;
    std::cout << "size of arr_assign: " << arr_assign.size() << std::endl;

    try {
      for (unsigned int i = 0; i < arr.size() + 1; ++i) {
        arr[i] = i + 0.1;
        arr_cpy[i] = i + 10.1;
        arr_assign[i] = i + 100.1;
        std::cout << "arr["  << i << "] = " << arr[i] << "  "
                  << "arr_cpy[" << i << "] = " << arr_cpy[i] << "   "
                  << "arr_assign[" << i << "] = " << arr_assign[i] << std::endl;
      }
    } catch (const std::exception&) {
      std::cout << "invalid index" << std::endl;
    }
  }
  // test array of string class
  std::cout << "\n---string array test---\n" << std::endl;

  Array<std::string> arr_str(5);
  Array<std::string> arr_str_cpy(arr_str);
  Array<std::string> arr_str_assign;
  arr_str_assign = arr_str;

  std::cout << "size of arr_str: " << arr_str.size() << std::endl;
  std::cout << "size of arr_str_cpy: " << arr_str_cpy.size() << std::endl;
  std::cout << "size of arr_str_assign: " << arr_str_assign.size() << std::endl;

  try {
    for (unsigned int i = 0; i < arr_str.size() + 1; ++i) {
      arr_str[i] = static_cast<char>(i + 42);
      arr_str_cpy[i] = static_cast<char>(i + 52);
      arr_str_assign[i] = static_cast<char>(i + 62);
      std::cout << "arr["  << i << "] = " << arr_str[i] << "  "
                << "arr_cpy[" << i << "] = " << arr_str_cpy[i] << "   "
                << "arr_assign[" << i << "] = " << arr_str_assign[i] << std::endl;
    }
  } catch (const std::exception&) {
    std::cout << "invalid index" << std::endl;
  }
}

#ifdef LEAKS
void	detect_leak(void)__attribute__((destructor));

void	detect_leak(void) {
  system("leaks -q a.out");
}
#endif
