#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <cstddef>

class DynArr {
  public:
    DynArr() = default;
    DynArr(const DynArr&) = default;
    DynArr(const std::ptrdiff_t size) : size_(size) { }
    ~DynArr() = default;
    [[nodiscard]] DynArr& operator=(const DynArr&) = default;
  
    [[nodiscard]] std::ptrdiff_t Size() const noexcept { return size_; }
    void Resize(const std::ptrdiff_t size) { size_ = size; }
    [[nodiscard]] float& operator[](const std::ptrdiff_t idx) { return data_; }
    [[nodiscard]] const float& operator[](const std::ptrdiff_t idx) const { return data_; }
private:
    std::ptrdiff_t size_ = 0;
    float data_ = 0;
};

TEST_CASE("dynarr ctor") {
  DynArr arr_def;
  CHECK_EQ(arr_def.Size(), 0);

  const int size = 5;
  DynArr arr_s(size);
  CHECK_EQ(arr_s.Size(), size);
}

TEST_CASE("dynarr op[]") {
  const int size = 5;
  DynArr arr(size);
  CHECK_EQ(arr[0], 0);
  CHECK_EQ(arr[arr.Size() - 1], 0);
}