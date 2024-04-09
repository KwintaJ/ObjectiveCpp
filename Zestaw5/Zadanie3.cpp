//######################################//
//                                      //
//    Jan Kwinta          09.04.2024    //
//                                      //
//    Obiektowy C++                     //
//    Zestaw 5, zadanie 3               //
//                                      //
//######################################//

#include <iostream>
#include <vector>

template<class T, class U>
class is_convertible
{
private:
    typedef char one;
    typedef struct{char arr[2];} two;

    static one test(U);
    static two test(...);
    static T makeT();

public:
    enum {yes = sizeof(test(makeT())) == sizeof(one), same_type = false};
};

template<class T>
class is_convertible<T, T>
{
public:
    enum {yes = true, same_type = true};
};

int main(int argc, char **argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    std::cout << is_convertible<int, double>::yes << std::endl;
    std::cout << is_convertible<double, int>::yes << std::endl;

    std::cout << is_convertible<double, int>::same_type << std::endl;

    std::cout << is_convertible<size_t, unsigned int>::same_type << std::endl;

    std::cout << is_convertible<std::vector<double>::value_type, double>::same_type << std::endl;

    std::cout << is_convertible<std::vector<double>::iterator, double*>::same_type << std::endl;
}
