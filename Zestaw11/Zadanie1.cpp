//######################################//
//                                      //
//    Jan Kwinta          28.05.2024    //
//                                      //
//    Obiektowy C++                     //
//    Zestaw 11, zadanie 1              //
//                                      //
//######################################//

#include <concepts>
#include <iostream>

// Funkcja szablonowa gcd, która działa tylko dla typów całkowitoliczbowych
template<std::integral T>
T gcd(T a, T b) {
    while (b != 0) {
        T temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int a = 56;
    int b = 98;
    std::cout << "GCD of " << a << " and " << b << " is " << gcd(a, b) << std::endl;

    long c = 56L;
    long d = 98L;
    std::cout << "GCD of " << c << " and " << d << " is " << gcd(c, d) << std::endl;

    // Kompilator zwróci błąd, jeśli użyjemy typów niecałkowitoliczbowych:
    // double e = 56.0;
    // double f = 98.0;
    // std::cout << "GCD of " << e << " and " << f << " is " << gcd(e, f) << std::endl;

    return 0;
}