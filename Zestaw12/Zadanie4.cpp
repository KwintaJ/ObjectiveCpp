//######################################//
//                                      //
//    Jan Kwinta          04.06.2024    //
//                                      //
//    Obiektowy C++                     //
//    Zestaw 12, zadanie 4              //
//                                      //
//######################################//

// Wzorzec adapter stosujemy, aby umozliwic interakcje
// miedzy obiektami o niewspolpracujacych interfejsach.
// Zazwyczaj stosujemy, gdy laczymy w dzialaniu obiekty
// zaprojektowane osobno, np w duzej odleglosci czasowej
// lub pochodzace od innych producentow.

#include <iostream>
#include <string>

class Client
{
public:
    virtual std::string Request() const
    {
        return "Generic thing";
    }
};

class Tool
{
public:
    std::string SomeMethod()
    {
        return "Special thing";
    }
};

class Adapter : public Client
{
public:
    Adapter(Tool* t) : T_{t}
    {
    }

    std::string Request() const override
    {
        return T_->SomeMethod();
    }

private:
    Tool* T_;
};

void DoThings(const Client* c)
{
    std::cout << c->Request() << std::endl;
}

int main()
{
    Client* c = new Client;
    Tool* t = new Tool;
    Adapter* a = new Adapter(t);

    DoThings(c);
    //DoThings(t);
    DoThings(a);
}
