//######################################//
//                                      //
//    Jan Kwinta          12.03.2024    //
//                                      //
//    Obiektowy C++                     //
//    Zestaw 2, zadanie 4               //
//                                      //
//######################################//

#include <iostream>
#include <algorithm>
#include <vector>

template <class T>
class SeqGen
{
private:
    T seq_start;
    T seq_step;

public:
    SeqGen(T start = T(), T step = 1): seq_start{start}, seq_step{step}
    {
    }

    T operator()()
    {
        T temp = seq_start;
        seq_start += seq_step;
        return temp;
    }
};

int main(int argc, char **argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    std::vector<int> vec(20);
    std::generate_n(vec.begin(), 20, SeqGen<int>(1, 2));

    std::cout << "vec: [ ";
    for(auto x : vec)
        std::cout << x << " ";
    std::cout << "]" << std::endl;

    std::vector<int>::iterator it = std::find_if(vec.begin(), vec.end(), std::bind(std::greater<int>(), std::placeholders::_1,  4));
    std::cout << "pierwszy element vec wiekszy od 4: " << *it << std::endl;
}
