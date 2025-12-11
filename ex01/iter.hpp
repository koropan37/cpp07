#ifndef ITER_HPP_
#define ITER_HPP_

template <typename T, typename F>
void iter(T* array, unsigned int len, const F& func) {
    for (unsigned int i = 0; i < len; ++i)
        func(array[i]);
}

template <typename T, typename F>
void iter(const T* array, unsigned int len, const F& func) {
    for (unsigned int i = 0; i < len; ++i)
        func(array[i]);
}

#endif
