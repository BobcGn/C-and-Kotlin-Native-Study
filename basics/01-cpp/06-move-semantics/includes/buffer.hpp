#pragma once

#include <cstddef>

class Buffer {
public:
  explicit Buffer(std::size_t size);

  ~Buffer();

  Buffer(const Buffer &other);

  Buffer &operator=(const Buffer &other);

  Buffer(Buffer &&other) noexcept;

  Buffer &operator=(Buffer &&other) noexcept;

  [[nodiscard]]
  std::size_t size() const noexcept;

  [[nodiscard]]
  bool empty() const noexcept;

  int *data() noexcept;

  const int *data() const noexcept;

private:
  std::size_t size_{0};
  int *data_{nullptr};
};