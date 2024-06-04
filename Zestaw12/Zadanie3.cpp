//######################################//
//                                      //
//    Jan Kwinta          04.06.2024    //
//                                      //
//    Obiektowy C++                     //
//    Zestaw 12, zadanie 3              //
//                                      //
//######################################//

// Wzorzec dekorator używamy, gdy chcemy rozszerzyc obowiazki
// jakiegos obiektu bez stosowania dziedziczenia. W trakcie
// dzialania programu mozna dodawac lub usuwac te obowiazki,
// mozna tez laczyc zachowania klas nakladajac wiele 
// dekoratorow na obiekt - specjalizacja

#include <iostream>
#include <string>

class VirtualComponent
{
public:
    virtual std::string Operation() const = 0;
};

class Component : public VirtualComponent
{
public:
    std::string Operation() const override
    {
        return "Basic component";
    }
};

class Decorator : public VirtualComponent
{
protected:
    VirtualComponent* C_;

public:
    Decorator(VirtualComponent* c) : C_{c}
    {
    }

    std::string Operation() const override
    {
        return this->C_->Operation();
    }
};

class DecoratorA : public Decorator
{
public:
    DecoratorA(VirtualComponent* c) : Decorator(c)
    {
    }

    std::string Operation() const override
    {
        return "A(" + Decorator::Operation() + ")";
    }
};

class DecoratorB : public Decorator
{
public:
    DecoratorB(VirtualComponent* c) : Decorator(c)
    {
    }

    std::string Operation() const override
    {
        return "B(" + Decorator::Operation() + ")";
    }
};

void doTheOperation(VirtualComponent* c)
{
    std::cerr << c->Operation() << std::endl;
}

int main()
{
    VirtualComponent* simple = new Component;
    VirtualComponent* A = new DecoratorA(simple);
    VirtualComponent* B = new DecoratorB(A);

    doTheOperation(simple);
    doTheOperation(A);
    doTheOperation(B);
}
