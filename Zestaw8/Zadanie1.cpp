//######################################//
//                                      //
//    Jan Kwinta          07.05.2024    //
//                                      //
//    Obiektowy C++                     //
//    Zestaw 8, zadanie  1              //
//                                      //
//######################################//

#include <iostream>
#include <cmath>

template <typename F>
double integrate(F f, double min, double max, double ds)
{
    double integral = 0.0;
    for(double x = min; x < max; x += ds)
        integral += f(x);

    return integral * ds;
}

class SinA
{
public:
    SinA(double a) : _a(a)
    {
    }

    double operator()(double x)
    {
        return sin(_a * x);
    }
private:
    double _a;
};

int main()
{
    std::cout << ::integrate(sin, 0, 3.141926, 0.01) << std::endl;
    std::cout << ::integrate(SinA(0), 0, 3.141926, 0.01) << std::endl;
    std::cout << ::integrate(SinA(1), 0, 3.141926, 0.01) << std::endl;
    std::cout << ::integrate(SinA(2), 0, 3.141926, 0.01) << std::endl;
}
