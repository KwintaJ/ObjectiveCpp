//######################################//
//                                      //
//    Jan Kwinta          04.06.2024    //
//                                      //
//    Obiektowy C++                     //
//    Zestaw 12, zadanie 1              //
//                                      //
//######################################//

// Singleton to wzorzec projektowy, ktory zapewnia istnienie
// tylko jednego obiektu danej klasy. Wykorzystuje sie go
// kiedy chcemy miec kontrole nad dostepem do wspoldzielonego
// zasobu. Obiekt inicjalizowany jest dopiero, kiedy jest
// potrzebny po raz pierwszy. Istnieje globalny "punkt
// dostepu" do obiektu


#include <iostream>
#include <thread>
#include <mutex>

class Singleton
{
private:
    static Singleton* instance__;
    static std::mutex m__;

protected:
    Singleton(const int v): value__{v}
    {
    }

    ~Singleton()
    {
    }

    int value__;

public:
    Singleton(Singleton &other) = delete;
    void operator=(const Singleton &) = delete;

    static Singleton *getInstance(const int &v);

    int value() const
    {
        return value__;
    }
};

Singleton* Singleton::instance__{nullptr};
std::mutex Singleton::m__;

Singleton* Singleton::getInstance(const int &v)
{
    std::lock_guard<std::mutex> lock(m__);
    if(instance__ == nullptr)
        instance__ = new Singleton(v);
    
    return instance__;
}

void Thread1()
{
    Singleton* s = Singleton::getInstance(1);
    std::cerr << s->value() << std::endl;
}

void Thread2()
{
    Singleton* s = Singleton::getInstance(2);
    std::cerr << s->value() << std::endl;
}

int main()
{
    std::thread t1(Thread1);
    std::thread t2(Thread2);
    t1.join();
    t2.join();
}
