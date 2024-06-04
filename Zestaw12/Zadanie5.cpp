//######################################//
//                                      //
//    Jan Kwinta          04.06.2024    //
//                                      //
//    Obiektowy C++                     //
//    Zestaw 12, zadanie 5              //
//                                      //
//######################################//

// Wzorzec odwiedzajacy stosujemy, aby oddzielic obiekty
// od algorytmow, ktore operuja na tych obiektach.
// Mamy zbior obiektow, kazdy obiekt z wlasnymi metodami.
// Rozni odwiedzajacy moga po kolei odwiedzac obiekty i 
// roznie operowac na ich eksluzywnych metodach.

#include <iostream>
#include <string>
#include <vector>

class ComponentA;
class ComponentB;

class Visitor
{
public:
    virtual void VisitA(const ComponentA* c) const = 0;
    virtual void VisitB(const ComponentB* c) const = 0;
};

class VirtualComponent
{
public:
    virtual void Accept(Visitor* v) const = 0;
};

class ComponentA : public VirtualComponent
{
public:
    void Accept(Visitor* v) const override
    {
        v->VisitA(this);
    }

    void MethodA() const
    {
        std::cout << "A" << std::endl;
    }
};

class ComponentB : public VirtualComponent
{
public:
    void Accept(Visitor* v) const override
    {
        v->VisitB(this);
    }

    void MethodB() const
    {
        std::cout << "B" << std::endl;
    }
};

class Visitor1 : public Visitor
{
public: 
    void VisitA(const ComponentA* c) const override
    {
        std::cout << "1: ";
        c->MethodA();
    }
    void VisitB(const ComponentB* c) const override
    {
        std::cout << "1: ";
        c->MethodB();
    }
};

class Visitor2 : public Visitor
{
public: 
    void VisitA(const ComponentA* c) const override
    {
        std::cout << "2: ";
        c->MethodA();
    }
    void VisitB(const ComponentB* c) const override
    {
        std::cout << "2: ";
        c->MethodB();
    }
};

void DoThingsToComponents(std::vector<const VirtualComponent*> &c, Visitor* v)
{
    for(auto x : c)
        x->Accept(v);
}

int main()
{
    std::vector<const VirtualComponent*> components;
    components.push_back(new ComponentA);
    components.push_back(new ComponentB);

    Visitor1* v1 = new Visitor1;
    Visitor2* v2 = new Visitor2;

    DoThingsToComponents(components, v1);
    DoThingsToComponents(components, v2);
}
