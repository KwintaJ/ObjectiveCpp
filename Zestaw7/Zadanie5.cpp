//######################################//
//                                      //
//    Jan Kwinta          23.04.2024    //
//                                      //
//    Obiektowy C++                     //
//    Zestaw 7, zadanie 5               //
//                                      //
//######################################//

#include <iostream>

template<size_t N> 
double inner(double *a, double *b)
{
    return (*a) * (*b) + inner<N - 1>(++a, ++b);
}

template<>
double inner<1>(double *a, double *b)
{
    return (*a) * (*b);
}

int main()
{
    double X[3] = {1.1, 2.2, 3.3};
    double Y[3] = {2.0, 2.0, 2.0};

    std::cout << "X = [ " << X[0] << ", " << X[1] << ", " << X[2] << " ]" << std::endl;
    std::cout << "Y = [ " << Y[0] << ", " << Y[1] << ", " << Y[2] << " ]" << std::endl;

    double dot = inner<3>(X, Y);
    std::cout << "X * Y = " << dot << std::endl;

}
