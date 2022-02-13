#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stddef.h>

#include <exception>

template <typename T>
class Array {
 public:
  explicit Array(unsigned int n = 0) : size_(n) {
    array_ = new T[size_];
  }

  Array(const Array<T> &other) : size_(other.size()) {
    array_ = new T[size_];
    *this = other;
  }

  Array &operator=(const Array<T> &other) {
    if (this != &other) {
      if (size_ != other.size()) {
        delete[] array_;
        size_ = other.size();
        array_ = new T[size_];
      }
    }
    for (unsigned int i = 0; i < size_; ++i) {
      array_[i] = other.array_[i];
    }
    return *this;
  }

  virtual ~Array(){ delete[] array_; }

  unsigned int size() const { return size_; }

  T& operator[](unsigned int i) {
    if (!is_valid_index(i)) {
      throw std::exception();
    }
    return array_[i];
  }

  const T& operator[](unsigned int i) const {
    if (!is_valid_index(i)) {
      throw std::exception();
    }
    return array_[i];
  }

 private:
  bool is_valid_index(unsigned int idx) { return idx < size_; }
  unsigned int size_;
  T* array_;

};

#endif
