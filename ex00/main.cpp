#include "whatever.hpp"
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

// template<typename T, typename U>
// void swap_diff(T& a, U& b) {
//     T tmp = a;
//     a = static_cast<T>(b);
//     b = static_cast<U>(tmp);
// }

int main( void ) {
	printColor("Subject", CYAN);
	{
		int a = 2;
		int b = 3;
		std::cout << "a = " << a << ", b = " << b << std::endl;
		::swap( a, b );
		std::cout << "swap" << std::endl;
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	std::cout << std::endl;
	printColor("Float", GREEN);
	{
		float a(2.9);
		float b(3.1);
		std::cout << "a = " << a << ", b = " << b << std::endl;
		::swap(a, b);
		std::cout << "swap" << std::endl;
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min = " << ::min(a, b)
				  << ", max = " << ::max(a, b) << std::endl;
  	}
	std::cout << std::endl;
	// {
	// 	int a(1);
	// 	float b(1.1);
	// 	std::cout << "a = " << a << ", b = " << b << std::endl;
	// 	::swap_diff(a, b);
	// 	std::cout << "swap" << std::endl;
	// 	std::cout << "a = " << a << ", b = " << b << std::endl;
	// }
	return 0;
}
