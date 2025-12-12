#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750

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

#include <cstdio>

void test(void){
    printColor("Int", CYAN);
    {
        Array<int> a1;
        Array<int> a2(3);
        Array<int> a3(a2);
        Array<int> a4(0);
        std::cout << "a1.size() = " << a1.size() << std::endl;
        std::cout << "a2.size() = " << a2.size() << std::endl;
        std::cout << "a3.size() = " << a3.size() << std::endl;
        for (unsigned int i = 0; i < a2.size(); i++) {
        a2[i] = i;
        std::cout << "a2[" << i << "] = " << a2[i] << std::endl;
        }
            for (unsigned int i = 0; i < a3.size(); i++) {
            a3[i] = i + 10;
            std::cout << "a3[" << i << "] = " << a3[i] << std::endl;
        }
        {
            const Array<int> a5 = a2;
            for (unsigned int i = 0; i < a5.size(); i++) {
            std::cout << "a5[" << i << "] = " << a5[i] << std::endl;
            }
        }
    }
    {
        printColor("Std::string", MAGENTA);
        Array<std::string> a1;
        Array<std::string> a2(5);
        Array<std::string> a3(a2);
        Array<std::string> a4(0);
        for (unsigned int i = 0; i < a2.size(); i++) {
            char buf[100];
            sprintf(buf, "hello %u", i);
            a2[i] = std::string(buf);
            std::cout << "a2[" << i << "] = " << a2[i] << std::endl;
        }
        for (unsigned int i = 0; i < a3.size(); i++) {
            char buf[100];
            sprintf(buf, "world %u", i + 10);
            a3[i] = std::string(buf);
            std::cout << "a3[" << i << "] = " << a3[i] << std::endl;
        }
        {
        const Array<std::string> a5 = a2;
        for (unsigned int i = 0; i < a5.size(); i++) {
            std::cout << "a5[" << i << "] = " << a5[i] << std::endl;
        }
        }
    }
}

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    test();
    return 0;
}
