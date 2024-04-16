


#include <iostream>
#include <stdexcept>

// Klasa wytycznych dla braku sprawdzania
class No_checking_policy {
public:
    static void check_push(size_t, size_t) {}
    static void check_pop(size_t) {}
    static void check_top(size_t) {}
};

// Klasa wytycznych dla przerywania działania
class Abort_on_error_policy {
public:
    static void check_push(size_t top, size_t N) {
        if (top >= N) {
            std::cerr << "Stack overflow! Aborting." << std::endl;
            std::abort();
        }
    }

    static void check_pop(size_t top) {
        if (top == 0) {
            std::cerr << "Stack underflow! Aborting." << std::endl;
            std::abort();
        }
    }

    static void check_top(size_t top) {
        if (top == 0) {
            std::cerr << "Stack is empty! Aborting." << std::endl;
            std::abort();
        }
    }
};

template<typename T = int, size_t N = 100, typename Checking_policy = No_checking_policy>
class Stack {
private:
    T _rep[N];
    size_t _top;

public:
    Stack() : _top(0) {}

    void push(const T& value) {
        Checking_policy::check_push(_top, N);
        _rep[_top++] = value;
    }

    T pop() {
        Checking_policy::check_pop(_top);
        return _rep[--_top];
    }

    T top() const {
        Checking_policy::check_top(_top);
        return _rep[_top - 1];
    }

    bool empty() const {
        return _top == 0;
    }

    bool full() const {
        return _top == N;
    }
};

int main() {
    // Testowanie stosu bez sprawdzania zakresu pamięci
    Stack<int, 5, No_checking_policy> stack_no_checking;
    stack_no_checking.push(1);
    stack_no_checking.push(2);
    stack_no_checking.push(3);
    stack_no_checking.push(4);
    stack_no_checking.push(5);

    std::cout << "Top element: " << stack_no_checking.top() << std::endl;

    // Testowanie stosu z polityką przerywania działania
    Stack<int, 3, Abort_on_error_policy> stack_abort;
    stack_abort.push(1);
    stack_abort.push(2);
    stack_abort.push(3);

    // Próba przekroczenia limitu stosu
    stack_abort.push(4); // Spowoduje przerwanie działania

    return 0;
}