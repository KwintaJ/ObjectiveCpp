//######################################//
//                                      //
//    Jan Kwinta          23.04.2024    //
//                                      //
//    Obiektowy C++                     //
//    Zestaw 7, zadanie  3              //
//                                      //
//######################################//

#include <iostream>

template <int N>
inline double pow(double x)
{
    if(N % 2 == 1)
        return x * pow<N / 2>(x*x);
    else
        return pow<N / 2>(x*x);
}

template<>
inline double pow<1>(double x)
{
    return x;
}

template<>
inline double pow<0>(double x)
{
    return 1.0;
}

int main()
{
    std::cout << "7.2 ^ 3 = " << pow<3>(7.2) << std::endl;
    std::cout << "2.0 ^ 10 = " << pow<10>(2.0) << std::endl;
    std::cout << "3.69 ^ 0 = " << pow<0>(3.69) << std::endl;
}
