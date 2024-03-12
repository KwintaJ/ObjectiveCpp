//######################################//
//                                      //
//    Jan Kwinta          12.03.2024    //
//                                      //
//    Obiektowy C++                     //
//    Zestaw 2, zadanie 3               //
//                                      //
//######################################//

#include <iostream>
#include <vector>
#include <set>

template <class Iter, class T>
T accumulate(Iter left, Iter right, T init)
{
    T sum = init;

    for( ; left != right; left++) 
        sum += *left;

    return sum;
}

int main(int argc, char **argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    std::vector<float> vec1;
    vec1.push_back(4.2);
    vec1.push_back(5.1);
    vec1.push_back(6.9);
    vec1.push_back(0.0);
    vec1.push_back(10.3);
    vec1.push_back(7.3);

    std::cout << "vec1: [ ";
    for(auto x : vec1)
        std::cout << x << " ";
    std::cout << "]" << std::endl;
    std::cout << "sum1(2, 5) = " << accumulate(vec1.begin() + 2, vec1.end(), 0.0) << std::endl;
    std::cout << std::endl;

    std::vector<int> vec2;
    vec2.push_back(0);
    vec2.push_back(1);
    vec2.push_back(9);
    vec2.push_back(3);
    vec2.push_back(10);
    vec2.push_back(7);

    std::cout << "vec2: [ ";
    for(auto x : vec2)
        std::cout << x << " ";
    std::cout << "]" << std::endl;
    std::cout << "sum2(0, 4) = " << accumulate(vec2.begin(), vec2.end() - 1, 0) << std::endl;
    std::cout << std::endl;
    
    std::set<int> set3;
    set3.insert(3);
    set3.insert(1);
    set3.insert(9);
    set3.insert(3);
    set3.insert(7);
    set3.insert(4);
    set3.insert(11);
    set3.insert(-2);

    std::cout << "set3: { ";
    for(auto x : set3)
        std::cout << x << " ";
    std::cout << "}" << std::endl;
    std::cout << "sum3(find(3), end) + 8 = " << accumulate(set3.find(3), set3.end(), 8) << std::endl;
    std::cout << std::endl;
}
