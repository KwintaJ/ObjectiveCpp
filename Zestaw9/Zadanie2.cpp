//######################################//
//                                      //
//    Jan Kwinta          14.05.2024    //
//                                      //
//    Obiektowy C++                     //
//    Zestaw 9, zadanie 2               //
//                                      //
//######################################//

#include <iostream>
#include <memory>

class aClass {
public:
    aClass() {}
};

int main()
{
    aClass* rawPtr = nullptr;
    std::unique_ptr<aClass> uniquePtr;
    std::shared_ptr<aClass> sharedPtr;
    std::cout << "Rozmiar zwyklego wskaznika: " << sizeof(rawPtr) << std::endl;
    std::cout << "Rozmiar unique_ptr: " << sizeof(uniquePtr) << std::endl;
    std::cout << "Rozmiar shared_ptr: " << sizeof(sharedPtr) << std::endl;
}
