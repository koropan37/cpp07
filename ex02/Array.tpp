#include "Array.hpp"
#include <cstdlib>

template<typename T> 
Array<T>::Array() : size_(0), array_(NULL) {}

template<typename T>
Array<T>::Array(unsigned int size)
: size_(size), array_(new T[size]) {}

template<typename T>
Array<T>::Array(Array const& other)
: size_(0), array_(NULL) {
    copyArray(other);
}

template<typename T>
Array<T>& Array<T>::operator=(Array const& other) {
    if(this != &other){
        delete[] array_;
        array_ = NULL;
        copyArray(other);
    }
    return *this;
}

template<typename T>
void Array<T>::copyArray(Array const& other) {
    if (other.size_ == 0) {
        array_ = NULL;
        size_ = 0;
        return;
    }
    array_ = new T[other.size_];
    for(unsigned int i = 0; i < other.size_; ++i)
        array_[i] = other.array_[i];
    size_ = other.size_;
    
}

template<typename T>
Array<T>::~Array() {
    delete[] array_;
}

template<typename T>
T& Array<T>::operator[](unsigned int i) {
    if(i >= size_)
        throw std::out_of_range("Index: out of range");
    return array_[i];
}

template<typename T>
T const& Array<T>::operator[](unsigned int i)  const{
    if(i >= size_)
        throw std::out_of_range("Index: out of range");
    return array_[i];
}

template<typename T>
unsigned int Array<T>::size() const { return size_; }
