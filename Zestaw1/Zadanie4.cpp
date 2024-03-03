//######################################//
//                                      //
//    Jan Kwinta          03.03.2024    //
//                                      //
//    Obiektowy C++                     //
//    Zestaw 1, zadanie 4               //
//                                      //
//######################################//

#include <iostream>

template <int N, class T>
struct Table
{
    T arr[N];
};

template <template <int N, class T> class Container, int K, class T>
void printTable(Container<K, T> &x)
{
    for(int i = 0; i < K; i++)
        std::cout << x.arr[i] << " ";
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    Table<4, double> tblA;
    tblA.arr[0] = 0.0; tblA.arr[1] = 1.3; tblA.arr[2] = 2.4; tblA.arr[3] = 6.9;

    Table<6, char> tblB;
    tblB.arr[0] = 'c'; tblB.arr[1] = 'f'; tblB.arr[2] = 'm';
    tblB.arr[3] = 'x'; tblB.arr[4] = '?'; tblB.arr[5] = 'g';

    printTable(tblA);
    printTable(tblB);
}
