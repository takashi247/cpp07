#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array {
 public:
  Array() : size_() {
    array_ = NULL:
  }

  explicit Array(unsigned int n) : size_(n) {
    array_ = new T[size_];
  }

  Array(const Array<T> &other) : size_(other.size_) {
    array_ = new T[size_];
    *this = other;
  }

  Array &operator=(const Array<T> &other) {
    if (this != &other) {
      delete[] array_;
      size_ = other.size_;
      array_ = new T[size_];
    }
    for (unsigned int i = 0; i < size_; ++i) {
      array_[i] = other.array_[i];
    }
    return *this;
  }

  virtual ~Array(){ delete[] array_; }

 private:
  unsigned int size_;
  T* array_;

};

#endif
