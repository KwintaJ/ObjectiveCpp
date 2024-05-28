//######################################//
//                                      //
//    Jan Kwinta          28.05.2024    //
//                                      //
//    Obiektowy C++                     //
//    Zestaw 11, zadanie 3              //
//                                      //
//######################################//

#include <iostream>
#include <vector>
#include <concepts>
#include <memory> // for std::allocator

template <typename T>
class MyVector {
private:
    std::vector<T> data;
public:
    void push_back(const T& value) requires std::copyable<T> {
        data.push_back(value);
    }

    void print() const {
        for (const auto& item : data) {
            std::cout << item << " ";
        }
        std::cout << "\n";
    }
};

class NonCopyableClass {
public:
    int value;
    NonCopyableClass(int val) : value(val) {}

    // Usuwamy konstruktor kopiujący
    NonCopyableClass(const NonCopyableClass&) = delete;
    NonCopyableClass& operator=(const NonCopyableClass&) = delete;
};

int main() {
    MyVector<int> intVector;
    intVector.push_back(10);
    intVector.push_back(20);
    intVector.print(); // Powinno wydrukować: 10 20

    NonCopyableClass ncc1(10);
    NonCopyableClass ncc2(20);

    MyVector<NonCopyableClass> nccVector;
    // Próba dodania obiektów typu NonCopyableClass do MyVector spowoduje błąd kompilacji
    // nccVector.push_back(ncc1); // To spowoduje błąd kompilacji
    // nccVector.push_back(ncc2); // To również spowoduje błąd kompilacji

    return 0;
}

