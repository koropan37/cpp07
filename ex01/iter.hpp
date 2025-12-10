#ifndef ITER_HPP_
#define ITER_HPP_

#include <cstddef>

template <typename T, typename F>
void iter(T* array, size_t len, const F& func) {
    for (size_t i = 0; i < len; ++i)
        func(array[i]);
}

template <typename T, typename F>
void iter(const T* array, size_t len, const F& func) {
    for (size_t i = 0; i < len; ++i)
        func(array[i]);
}

#endif
