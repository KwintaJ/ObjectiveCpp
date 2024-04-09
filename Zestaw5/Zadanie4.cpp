//######################################//
//                                      //
//    Jan Kwinta          09.04.2024    //
//                                      //
//    Obiektowy C++                     //
//    Zestaw 5, zadanie 3               //
//                                      //
//######################################//

#include <iostream>
#include <type_traits>

template <class T>
struct __strip
{
    using type = T;
};

template <class T>
struct __strip<const T>
{
    using type = T;
};

template <class T>
struct __strip<T&>
{
    using type = T;
};

template <class T>
struct __strip<const T&>
{
    using type = T;
};

template <class T>
using Strip = typename __strip<T>::type;

int main(int argc, char **argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    Strip<const int> a;


}
