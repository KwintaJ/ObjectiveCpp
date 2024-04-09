//######################################//
//                                      //
//    Jan Kwinta          09.04.2024    //
//                                      //
//    Obiektowy C++                     //
//    Zestaw 5, zadanie 2               //
//                                      //
//######################################//

#include <iostream>
#include <vector>

template<class T>
class has_value_type
{
private:
    typedef char one;
    typedef struct{char arr[2];} two;

    template<class U> static one test(typename U::value_type);
    template<class U> static two test(...);

public:
    enum {yes = (sizeof(test<T>(0)) == sizeof(one))};
};

struct X {};

int main(int argc, char **argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    std::cout << has_value_type<int>::yes << std::endl;
    std::cout << has_value_type<X>::yes << std::endl;
    std::cout << has_value_type<std::vector<double>>::yes << std::endl;
}
