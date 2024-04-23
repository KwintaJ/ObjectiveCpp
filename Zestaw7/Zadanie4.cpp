//######################################//
//                                      //
//    Jan Kwinta          23.04.2024    //
//                                      //
//    Obiektowy C++                     //
//    Zestaw 7, zadanie 4               //
//                                      //
//######################################//

#include <iostream>

template <long long int N>
struct Silnia
{
    enum {val = N * Silnia<N - 1>::val};
};

template<>
struct Silnia<1>
{
    enum {val = 1};
};

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

template<int N> 
double inner(double *a,double *b)
{
    return (*a) * (*b) + inner<N - 1>(++a, ++b);
}

template<>
double inner<1>(double *a, double *b)
{
    return (*a) * (*b);
}

template<int N>
double sin(double x)
{
    return sin<N - 1>(x) + (N % 2 ? 1 : -1) * pow<(2 * N - 1)>(x) / Silnia<(2 * N - 1)>::val;
}

template<>
double sin<0>(double x)
{
    return 0.0;
}

int main()
{
    std::cout << "sin<1>(1) = " << sin<1>(1) << std::endl;
    std::cout << "sin<2>(1) = " << sin<2>(1) << std::endl;
    std::cout << "sin<3>(1) = " << sin<3>(1) << std::endl;
    std::cout << "sin<6>(1) = " << sin<6>(1) << std::endl;
}
