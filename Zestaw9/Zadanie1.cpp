//######################################//
//                                      //
//    Jan Kwinta          14.05.2024    //
//                                      //
//    Obiektowy C++                     //
//    Zestaw 9, zadanie 1               //
//                                      //
//######################################//

#include <iostream>
#include <memory>

class Class1
{
public:
    Class1() {}
    void sayHello() const { std::cout << "Hello1\n"; }
};

class Class2
{
public:
    Class2() {}
    ~Class2() { std::cerr << "2 zniszczony\n"; }
    void sayHello() const { std::cout << "Hello2\n"; }
};

int main()
{
// unique_ptr to inteligentny wskaźnik, który zapewnia unikalne posiadanie obiektu. Oznacza to, że w danym momencie może istnieć tylko jeden unique_ptr wskazujący na dany obiekt. Przekazanie własności obiektu można zrealizować tylko poprzez przeniesienie (std::move).

    std::unique_ptr<Class1> up1 = std::make_unique<Class1>();
    up1->sayHello();

    // std::unique_ptr<Class1> up2 = up1;
    std::unique_ptr<Class1> up2 = std::move(up1);
    if(!up1)
        std::cerr << "up1  pusty\n";
    up2->sayHello();


// shared_ptr to inteligentny wskaźnik, który umożliwia współdzielone posiadanie obiektu. Wiele shared_ptr może wskazywać na ten sam obiekt, a obiekt zostanie zniszczony, gdy ostatni shared_ptr przestanie na niego wskazywać.

    std::shared_ptr<Class2> sp1 = std::make_shared<Class2>();
    sp1->sayHello();

    if(true)
    {
        std::shared_ptr<Class2> sp2 = sp1;
        sp2->sayHello();
    } // sp2 wychodzi z zakresu, ale obiekt nie jest niszczony, bo ptr1 nadal istnieje
    sp1->sayHello();
    // ptr1 zostanie automatycznie zniszczony po wyjściu z main()
}
