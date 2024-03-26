//######################################//
//                                      //
//    Jan Kwinta          26.03.2024    //
//                                      //
//    Obiektowy C++                     //
//    Zestaw 4, zadanie 1               //
//                                      //
//######################################//

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

#include <iostream>

int main(int argc, char **argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
}