//######################################//
//                                      //
//    Jan Kwinta          23.04.2024    //
//                                      //
//    Obiektowy C++                     //
//    Zestaw 7, zadanie  1              //
//                                      //
//######################################//

#include <iostream>

template <int N>
struct Silnia
{
    enum {val = N * Silnia<N - 1>::val};
};

template<>
struct Silnia<1>
{
    enum {val = 1};
};

int main()
{
    std::cout << "5! = " << Silnia<5>::val << std::endl;
}
