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

  // test normal case
  Array<int> arr(10);
  Array<int> arr_cpy(arr);
  Array<int> arr_assign;
  arr_assign = arr;

  std::cout << "size of arr: " << arr.size() << std::endl;
  std::cout << "size of arr_cpy: " << arr_cpy.size() << std::endl;
  std::cout << "size of arr_assign: " << arr_assign.size() << std::endl;

}
