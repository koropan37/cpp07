#ifndef ARRAY_HPP_
#define ARRAY_HPP_

template<typename T> class Array {
 private:
    unsigned int size_;
    T* array_;

 public:
    Array();
    Array(unsigned int size);
    Array(Array const& other);
    Array& operator=(Array const& other);
    ~Array();
    T& operator[](unsigned int i);
    T const& operator[](unsigned int i) const;
    unsigned int size() const;
    void copyArray(Array const& other);
};

#include "Array.tpp"

#endif
