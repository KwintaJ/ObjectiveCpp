//######################################//
//                                      //
//    Jan Kwinta          23.04.2024    //
//                                      //
//    Obiektowy C++                     //
//    Zestaw 7, zadanie  2              //
//                                      //
//######################################//

#include <iostream>

template <int N, int M>
struct Pow
{
    enum {val = N * Pow<N, M - 1>::val};
};

template<int N>
struct Pow<N, 0>
{
    enum {val = 1};
};


int main()
{
    std::cout << "7 ^ 3 = " << Pow<7, 3>::val << std::endl;
    std::cout << "2 ^ 10 = " << Pow<2, 10>::val << std::endl;
    std::cout << "3 ^ 0 = " << Pow<3, 0>::val << std::endl;
}
