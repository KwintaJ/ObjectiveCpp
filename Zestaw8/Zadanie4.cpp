//######################################//
//                                      //
//    Jan Kwinta          07.05.2024    //
//                                      //
//    Obiektowy C++                     //
//    Zestaw 8, zadanie 4               //
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

template <typename LHS, typename RHS>
class AddExpr
{
public:
    AddExpr(const LHS &l, const RHS &r) : _lhs(l), _rhs(r)
    {
    }

    double operator()(double x)
    {
        return _lhs(x) + _rhs(x);
    }

private:
    LHS _lhs;
    RHS _rhs;
};

template <typename LHS, typename RHS>
AddExpr<LHS, RHS> operator+(const LHS &l, const RHS &r)
{
    return AddExpr<LHS, RHS> (l, r);
}

template <typename LHS>
AddExpr<LHS, Constant> operator+(const LHS &l, double r)
{
    return AddExpr<LHS, Constant> (l, Constant(r));
}

template <typename RHS>
AddExpr<Constant, RHS> operator+(double l, const RHS &r)
{
    return AddExpr<Constant, RHS> (Constant(l), r);
}


template <typename LHS, typename RHS>
class DivExpr
{
public:
    DivExpr(const LHS &l, const RHS &r) : _lhs(l), _rhs(r)
    {
    }

    double operator()(double x)
    {
        return _lhs(x) / _rhs(x);
    }

private:
    LHS _lhs;
    RHS _rhs;
};

template <typename LHS, typename RHS>
DivExpr<LHS, RHS> operator/(const LHS &l, const RHS &r)
{
    return DivExpr<LHS, RHS> (l, r);
}

template <typename LHS>
DivExpr<LHS, Constant> operator/(const LHS &l, double r)
{
    return DivExpr<LHS, Constant> (l, Constant(r));
}

template <typename RHS>
DivExpr<Constant, RHS> operator/(double l, const RHS &r)
{
    return DivExpr<Constant, RHS> (Constant(l), r);
}


template <typename Arg>
class SinExpr
{
public:
    SinExpr(const Arg &arg) : _arg(arg)
    {
    }

    double operator()(double x)
    {
        return sin(_arg(x));
    }

private:
    Arg _arg;
};

template <typename Arg>
SinExpr<Arg> sin(const Arg &a)
{
    return SinExpr<Arg>(a);
}


int main()
{
    Variable x;

    std::cout << ::integrate(1.0/sin(x + 1.0), 0, 1, 0.001) << std::endl;
}
