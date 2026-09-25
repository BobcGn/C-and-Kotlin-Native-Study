#include "../includes/buffer.hpp"

#include <algorithm>
#include <iostream>
#include <utility>

Buffer::Buffer(std::size_t size)
    : size_(size), data_(size > 0 ? new int[size]{} : nullptr) {

  std::cout << "construct: " << data_ << '\n';
}

Buffer::~Buffer() {

  std::cout << "destroy: " << data_ << '\n';

  delete[] data_;
}

Buffer::Buffer(const Buffer &other)
    : size_(other.size_),
      data_(other.size_ > 0 ? new int[other.size_] : nullptr) {

  std::copy(other.data_, other.data_ + other.size_, data_);

  std::cout << "copy construct\n";
}

Buffer &Buffer::operator=(const Buffer &other) {

  std::cout << "copy assign\n";

  if (this == &other) {
    return *this;
  }

  int *new_data = other.size_ > 0 ? new int[other.size_] : nullptr;

  std::copy(other.data_, other.data_ + other.size_, new_data);

  delete[] data_;

  data_ = new_data;
  size_ = other.size_;

  return *this;
}

Buffer::Buffer(Buffer &&other) noexcept
    : size_(std::exchange(other.size_, 0)),
      data_(std::exchange(other.data_, nullptr)) {

  std::cout << "move construct\n";
}

Buffer &Buffer::operator=(Buffer &&other) noexcept {

  std::cout << "move assign\n";

  if (this == &other) {
    return *this;
  }

  delete[] data_;

  size_ = std::exchange(other.size_, 0);

  data_ = std::exchange(other.data_, nullptr);

  return *this;
}

std::size_t Buffer::size() const noexcept { return size_; }

bool Buffer::empty() const noexcept { return size_ == 0; }

int *Buffer::data() noexcept { return data_; }

const int *Buffer::data() const noexcept { return data_; }