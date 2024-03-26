//######################################//
//                                      //
//    Jan Kwinta          26.03.2024    //
//                                      //
//    Obiektowy C++                     //
//    Zestaw 4, zadanie 1               //
//                                      //
//######################################//

#include <iostream>

template<typename T>
struct sum_traits;

template<>
struct sum_traits<char>
{
    typedef int sum_type; 
};
template<>
struct sum_traits<int>
{
    typedef long int sum_type; 
};
template<>
struct sum_traits<float>
{
    typedef double sum_type; 
};
template<>
struct sum_traits<double>
{
    typedef double sum_type; 
};

template<typename T> 
typename sum_traits<T>::sum_type sum(T *beg,T *end)
{
    typedef typename sum_traits<T>::sum_type sum_type;
    sum_type total = sum_type(); 
    while(beg != end)
    { 
        total += *beg;
        beg++; 
    }
    return total; 
}

int main(int argc, char **argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    int ints[] = {1, 2, 3, 4, 5};
    std::cout << "Suma int: " << sum(ints, ints + 5) << std::endl;

    char chars[] = {'a', 'b', 'c'};
    std::cout << "Suma char: " << sum(chars, chars + 3) << std::endl;

    float floats[] = {1.1, 2.2, 3.3};
    std::cout << "Suma float: " << sum(floats, floats + 3) << std::endl;

    double doubles[] = {1.1, 2.2, 3.3};
    std::cout << "Suma double: " << sum(doubles, doubles + 3) << std::endl;
}