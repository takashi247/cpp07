#include "Array.hpp"

#include <iostream>

int main() {

  // test empty array
  Array<int> arr_empty;
  Array<int> arr_empty_cpy(arr_empty);
  Array<int> arr_empty_assign;
  arr_empty_assign = arr_empty;

  std::cout << "size of arr_empty: " << arr_empty.size() << std::endl;
  std::cout << "size of arr_empty_cpy: " << arr_empty_cpy.size() << std::endl;
  std::cout << "size of arr_empty_assign: " << arr_empty_assign.size() << std::endl;

  try {
    arr_empty[0] = 0;
  } catch (const std::exception&) {
    std::cout << "invalid index" << std::endl;
  }

  // test normal case
  Array<int> arr(10);
  Array<int> arr_cpy(arr);
  Array<int> arr_assign;
  arr_assign = arr;

  std::cout << "size of arr: " << arr.size() << std::endl;
  std::cout << "size of arr_cpy: " << arr_cpy.size() << std::endl;
  std::cout << "size of arr_assign: " << arr_assign.size() << std::endl;

  for (unsigned int i = 0; i < arr.size(); ++i) {
    arr[i] = i;
    arr_cpy[i] = i + 10;
    arr_assign[i] = i + 100;
    std::cout << "arr["  << i << "] = " << arr[i] << "  "
              << "arr_cpy[" << i << "] = " << arr_cpy[i] << "   "
              << "arr_assign[" << i << "] = " << arr_assign[i] << std::endl;
  }

  try {
    arr[arr.size()] = 100;
  } catch (const std::exception&) {
    std::cout << "invalid index" << std::endl;
  }

  // test array of string class
  Array<std::string> arr_str(5);
  Array<std::string> arr_str_cpy(arr_str);
  Array<std::string> arr_str_assign;
  arr_str_assign = arr_str;

  std::cout << "size of arr_str: " << arr_str.size() << std::endl;
  std::cout << "size of arr_str_cpy: " << arr_str_cpy.size() << std::endl;
  std::cout << "size of arr_str_assign: " << arr_str_assign.size() << std::endl;

  for (unsigned int i = 0; i < arr_str.size(); ++i) {
    arr_str[i] = static_cast<char>(i + 42);
    arr_str_cpy[i] = static_cast<char>(i + 52);
    arr_str_assign[i] = static_cast<char>(i + 62);
    std::cout << "arr["  << i << "] = " << arr_str[i] << "  "
              << "arr_cpy[" << i << "] = " << arr_str_cpy[i] << "   "
              << "arr_assign[" << i << "] = " << arr_str_assign[i] << std::endl;
  }

  try {
    arr_str[arr_str.size()] = "hoge";
  } catch (const std::exception&) {
    std::cout << "invalid index" << std::endl;
  }
}
