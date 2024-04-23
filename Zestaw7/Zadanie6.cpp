//######################################//
//                                      //
//    Jan Kwinta          23.04.2024    //
//                                      //
//    Obiektowy C++                     //
//    Zestaw 7, zadanie 6               //
//                                      //
//######################################//

#include <iostream>

template<size_t N, typename T = double>
struct Inner
{
    static T dot(T *a, T *b)
    {
        return (*a) * (*b) + Inner<N - 1, T>::dot(++a, ++b);
    }
};

template<typename T>  
struct Inner<1,T> 
{
    static T dot(T *a, T *b)
    {
        return (*a) * (*b);
    }
};

                 
template<size_t N, typename T> 
T dot(T *a, T *b)
{
    return Inner<N, T>::dot(a, b);
};


int main()
{
    double X[3] = {1.1, 2.2, 3.3};
    double Y[3] = {2.0, 2.0, 2.0};

    std::cout << "X = [ " << X[0] << ", " << X[1] << ", " << X[2] << " ]" << std::endl;
    std::cout << "Y = [ " << Y[0] << ", " << Y[1] << ", " << Y[2] << " ]" << std::endl;

    double product = Inner<3, double>::dot(X, Y);
    std::cout << "X * Y = " << product << std::endl;
}
