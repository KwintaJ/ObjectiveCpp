//######################################//
//                                      //
//    Jan Kwinta          07.05.2024    //
//                                      //
//    Obiektowy C++                     //
//    Zestaw 8, zadanie 2               //
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

class Variable
{
public:
    double operator()(double x)
    {
        return x;
    }
};

class Constant
{
public:
    Constant(double c) : _c(c)
    {
    }

    double operator()(double x)
    {
        return _c;
    }

private:
    double _c;
};

int main()
{
    Variable x;

    std::cout << ::integrate(x, 0, 1, 0.001) << std::endl;
    std::cout << ::integrate(Constant(2.0), 0, 1, 0.001) << std::endl;
}
