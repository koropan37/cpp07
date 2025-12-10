#include "iter.hpp"
#include <iostream>

#define BLACK   "\033[0;30m"
#define RED     "\033[0;31m"
#define GREEN   "\033[0;32m"
#define YELLOW  "\033[0;33m"
#define BLUE    "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN    "\033[0;36m"
#define WHITE   "\033[0;37m"
#define RESET   "\033[0m"
#define B_RED	"\033[1;31m"
#define B_GREEN "\033[1;32m"
#define B_CYAN  "\033[1;36m"

void printColor(std::string const& str, std::string const& color) {
    std::cout
	<< RESET << "======="
	<< color << str
	<< RESET << "=======" << color << std::endl;
}

template <typename T> void print_T(T t) {
  std::cout << t << " ";
}

template <typename T> void print_const_T(T const t) {
  std::cout << t << " ";
}

template <typename T> void print_ref_T(T &t) {
  std::cout << t << " ";
}
template <typename T> void print_const_ref_T(T const &t) {
  std::cout << t << " ";
}

int main(void) {
	printColor("Int", CYAN);
	{
		int arr[] = {0,1,2,3,4};
		::iter(arr, 5, print_T<int>);
		std::cout << std::endl;
		::iter(arr, 5, print_const_T<int>);
		std::cout << std::endl;
		::iter(arr, 5, print_ref_T<int>);
		std::cout << std::endl;
		::iter(arr, 5, print_const_ref_T<int>);
		std::cout << std::endl;
	}
	printColor("char", YELLOW);
	{
		char arr[] = {'a','b','c','d','e'};
		::iter(arr, 5, print_T<char>);
		std::cout << std::endl;
		::iter(arr, 5, print_const_T<char>);
		std::cout << std::endl;
		::iter(arr, 5, print_ref_T<char>);
		std::cout << std::endl;
		::iter(arr, 5, print_const_ref_T<char>);
		std::cout << std::endl;
	}
	printColor("Const int", BLUE);
	{
		int const arr[] = {5,6,7,8,9};
		::iter(arr, 5, print_T<const int>);
		std::cout << std::endl;
		::iter(arr, 5, print_const_T<const int>);
		std::cout << std::endl;
		::iter(arr, 5, print_ref_T<const int>);
		std::cout << std::endl;
		::iter(arr, 5, print_const_ref_T<const int>);
		std::cout << std::endl;
	}
	printColor("Const char", MAGENTA);
	{
		char const *arr[] = {"aaa","bbb","ccc","ddd","eee"};
		::iter(arr, 5, print_T<const char *>);
		std::cout << std::endl;
		::iter(arr, 5, print_const_T<const char *>);
		std::cout << std::endl;
		::iter(arr, 5, print_ref_T<const char *>);
		std::cout << std::endl;
		::iter(arr, 5, print_const_ref_T<const char *>);
		std::cout << std::endl;
	}
	printColor("Mix", RED);
	{
		int arr[] = {5,6,7,8,9};
		int const *carr = arr;
		::iter(carr, 5, print_T<const int>);
		std::cout << std::endl;
		::iter(carr, 5, print_const_T<const int>);
		std::cout << std::endl;
		::iter(carr, 5, print_ref_T<const int>);
		std::cout << std::endl;
		::iter(carr, 5, print_const_ref_T<const int>);
		std::cout << std::endl;
	}

}
