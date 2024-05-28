//######################################//
//                                      //
//    Jan Kwinta          28.05.2024    //
//                                      //
//    Obiektowy C++                     //
//    Zestaw 11, zadanie 2              //
//                                      //
//######################################//

#include <iostream>
#include <compare>
#include <concepts>

class MyClass {
public:
    int value;
    auto operator<=>(const MyClass&) const = default;
};

template <std::three_way_comparable T>
void compare_objects(const T& a, const T& b) {
    if (a < b) {
        std::cout << "a is less than b\n";
    } else if (a > b) {
        std::cout << "a is greater than b\n";
    } else {
        std::cout << "a is equal to b\n";
    }
}

int main() {
    MyClass obj1{10};
    MyClass obj2{20};

    compare_objects(obj1, obj2);

    return 0;
}