#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
//class vector
template  <typename T>
class Vector
{
private:
    T* arr_;
    size_t size_{};
    size_t capacity_{};
public:
    Vector() {
        arr_ = new T[1];
        capacity_ = 1;
    }
    bool is_Empty() const {
        return size_ == 0;
    }
    size_t size() const {
        return size_;
    }
    size_t capacity() const {
        return capacity_;
    }
    void addMemory() {
        capacity_ *= 2;
        T* tmp = arr_;
        arr_ = new T[capacity_];
        for (size_t i = 0; i < size_; ++i) arr_[i] = tmp[i];
        delete[] tmp;
    }
    void push_back(const T value) {
        if (size_ >= capacity_) addMemory();
        arr_[size_++] = value;
    }
};