//######################################//
//                                      //
//    Jan Kwinta          03.03.2024    //
//                                      //
//    Obiektowy C++                     //
//    Zestaw 1, zadania 1, 2            //
//                                      //
//######################################//

#include <iostream>

template <class T>
T maksimum(T &&a, T &&b)
{
    return (a > b) ? a : b;
}

int main(int argc, char **argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    std::cout << "maksimum(128, 9) = " << maksimum(128, 9) << std::endl;
    std::cout << "maksimum(\"gruby\", \"durny\") = " << maksimum("gruby", "durny") << std::endl;
}
