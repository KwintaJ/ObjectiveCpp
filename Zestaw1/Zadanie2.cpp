//######################################//
//                                      //
//    Jan Kwinta          03.03.2024    //
//                                      //
//    Obiektowy C++                     //
//    Zestaw 1, zadanie 2               //
//                                      //
//######################################//

#include <iostream>

template <class T, class U>
T convert(U x)
{
    return (T)x;
}

int main(int argc, char **argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    std::cout << convert<int, double>(10.55) << std::endl;  
    std::cout << convert<int, char>('a') << std::endl;  
}
