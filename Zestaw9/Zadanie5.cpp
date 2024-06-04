//######################################//
//                                      //
//    Jan Kwinta          14.05.2024    //
//                                      //
//    Obiektowy C++                     //
//    Zestaw 9, zadanie 5               //
//                                      //
//######################################//

#include <iostream>
#include <memory>

class aClass
{
public:
    aClass() {}
    ~aClass() { std::cerr << "obiekt zniszczony\n"; }
    void sayHello() const { std::cout << "Hello\n"; }
};

int main()
{
    std::cerr << "Przed ifem" << std::endl;
    if(true)
    {
        std::shared_ptr<aClass> ptr0 = std::make_shared<aClass>();
        std::cerr << "Przed petla" << std::endl;
        for(int i = 1; i <= 4; i++)
        {  
            std::shared_ptr<aClass> ptr1 = ptr0;
            ptr0->sayHello();
        }
        std::cerr << "Po petli" << std::endl;
        ptr0->sayHello();
    }
    std::cerr << "Po ifie" << std::endl;

}
