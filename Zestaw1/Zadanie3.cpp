//######################################//
//                                      //
//    Jan Kwinta          03.03.2024    //
//                                      //
//    Obiektowy C++                     //
//    Zestaw 1, zadanie 3               //
//                                      //
//######################################//

#include <iostream>

template <size_t N, class T>
T dot_product(T *a, T *b)
{
    T result = 0;
    for(size_t i = 0; i < N; i++)
        result += a[i] * b[i];
    
    return result;
}

int main(int argc, char **argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    const int dim = 6;
    std::cout << "Wymiar wektora: " << dim << std::endl;

    double vecA[dim] = {0, 0, 1.2, 4.3, 0.2, 1};
    double vecB[dim] = {1.1, 6.9, 0, 2, 1, 0.5};

    std::cout << "Wektor A: ";
    for(int i = 0; i < dim; i++)
        std::cout << vecA[i] << ", ";
    std::cout << std::endl;

    std::cout << "Wektor B: ";
    for(int i = 0; i < dim; i++)
        std::cout << vecB[i] << ", ";
    std::cout << std::endl;

    std::cout << "A dot B = " << dot_product<dim>(vecA, vecB) << std::endl;
}
