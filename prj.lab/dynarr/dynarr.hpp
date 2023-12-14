#pragma once
#ifndef DYNARR_DYNARR_HPP
#define DYNARR_DYNARR_HPP

#include <cstddef>

class DynArr {
public:
	[[nodiscard]] DynArr() = default;
	[[nodiscard]] DynArr(const DynArr&) = default;
	[[nodiscard]] DynArr(const std::ptrdiff_t size) : size_(size) { }
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


#endif // !DYNARR_DYNARR_HPP