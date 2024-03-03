//######################################//
//                                      //
//    Jan Kwinta          03.03.2024    //
//                                      //
//    Obiektowy C++                     //
//    Zestaw 1, zadanie 5               //
//                                      //
//######################################//

#include <iostream>

template <size_t N, class T> 
class Stack {
private:    
    T rep[N];
    size_t top;

public:
    typedef T val;
                
    Stack(): top(0) 
    {
    }

    void push(T val)
    {
        rep[top++]=val;
    }
    
    T pop()
    {
        return rep[--top];
    }
    
    bool empty()
    {
        return top == 0;
    }
};

template <class S>
typename S::val sumStack(S &stack)
{
    typename S::val sum = 0;
    while(!stack.empty())
    {
        sum += stack.pop();
    }
    return sum;
}

int main(int argc, char **argv)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);

    Stack<5, int> stk;
    stk.push(3); stk.push(7); stk.push(5); stk.push(1);

    std::cout << "suma: " << sumStack(stk) << std::endl;
}
