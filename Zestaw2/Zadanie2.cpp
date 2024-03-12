//######################################//
//                                      //
//    Jan Kwinta          12.03.2024    //
//                                      //
//    Obiektowy C++                     //
//    Zestaw 2, zadanie 2               //
//                                      //
//######################################//

#include <iostream>

class Shape
{
public:
    // virtual function
    virtual void draw() = 0;
    
    virtual ~Shape() 
    {
    }
};

class Point : public Shape
{
private:
    double _x;
    double _y;

public:
    Point(double x = 0.0, double y = 0.0): _x{x}, _y{y}
    {
    }

    void draw() override
    {
        std::cerr << "(" << _x << ", " << _y << ")";
    }
};

class Line : public Shape
{
private:
    Point _K;
    Point _L;

public:
    Line(Point k, Point l): _K{k}, _L{l}
    {
    }

    void draw() override
    {
        _K.draw();
        std::cerr << "--";
        _L.draw();
        std::cerr << std::endl;
    }
};

class Triangle : public Shape
{
private:
    Point _A;
    Point _B;
    Point _C;
    
public:
    Triangle(Point a, Point b, Point c): _A{a}, _B{b}, _C{c}
    {
    }
    
    void draw() override
    {
        _A.draw(); 
        std::cerr << "--"; 
        _B.draw();
        std::cerr << "--";
        _C.draw();
        std::cerr << std::endl;
    }
};

int main(int argc, char **argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
    
    Point A(0.0, 0.0);
    Point B(1.0, 0.5);
    Point C(-4.2, 1.5);
    Point D(-8.0, 5.0);

    // Uzycie mechanizmu polimorfizmu statycznego

    // Wiazanie metody draw() z obiektami klas Line i Triangle
    // w czasie kompilacji.
    Line L1(C, D);
    Triangle T1(A, B, C);

    L1.draw();
    T1.draw();
    std::cerr << std::endl;

    // Uzycie mechanizmu polimorfizmu dynamicznego

    // Wiazanie metody draw() z obiektami klas Point, Line i Triangle
    // w czasie wykonania programu.

    Shape* listOfShapes[3];
    listOfShapes[0] = new Line(A, B);
    listOfShapes[1] = new Triangle(D, C, B);
    listOfShapes[2] = new Point(0.1, 0.1);

    for(int i = 0; i < 3; i++)
        listOfShapes[i]->draw();

    std::cerr << std::endl;
}
