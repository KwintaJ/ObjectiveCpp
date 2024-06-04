//######################################//
//                                      //
//    Jan Kwinta          04.06.2024    //
//                                      //
//    Obiektowy C++                     //
//    Zestaw 12, zadanie 2              //
//                                      //
//######################################//

// Wzorzec obserwator stosowany jest wtedy, kiedy chcemy aby dwie niesprzegniete ze
// soba klasy mogly porozumiewac sie o stanie jednej z nich. Obserwator unika
// a) spamu b) niepotrzebnego sprawdzania stanu obiektu

#include <iostream>
#include <list>
#include <string>

class IObserver
{
public:
    virtual void Update(const std::string &m) = 0;
};

class ISubject
{
public:
    virtual void Attach(IObserver *o) = 0;
    virtual void Detach(IObserver *o) = 0;
    virtual void Notify(const std::string &m) = 0;
};

class Subject : public ISubject
{
public:
    void Attach(IObserver* o) override
    {
        subscribers.push_back(o);
    }

    void Detach(IObserver* o) override
    {
        subscribers.remove(o);
    }

    void Notify(const std::string &message_) override
    {
        for(auto x : subscribers)
            x->Update(message_);
    }

private:
    std::list<IObserver*> subscribers;
};

class Observer : public IObserver
{
public:
    Observer(Subject &s) : s__{s}
    {
        s.Attach(this);
        ++Observer::static_id;
        this->id__ = Observer::static_id;
    }

    void Update(const std::string &m_) override
    {
        message = m_;
        std::cerr << id__ << ": " << message << std::endl;
    }

    void Unsubscribe()
    {
        s__.Detach(this);
    }

private:
    std::string message;
    Subject &s__;
    static int static_id;
    int  id__;
};

int Observer::static_id = 0;

int main()
{
    Subject *s1 = new Subject; 

    Observer *o1 = new Observer(*s1);
    Observer *o2 = new Observer(*s1);

    s1->Notify("wiadomosc 1");

    o1->Unsubscribe();

    s1->Notify("wiadomosc 2");

}
