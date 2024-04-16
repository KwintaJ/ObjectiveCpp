//######################################//
//                                      //
//    Jan Kwinta          16.04.2024    //
//                                      //
//    Obiektowy C++                     //
//    Zestaw 6, zadanie 3               //
//                                      //
//######################################//

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

// Szablon ze statyczną tablicą w pamięci
template<typename T, size_t N = 0>
struct Static_table_allocator {
    typedef T rep_type[N];

    void init(rep_type&, size_t) {}
    void expand_if_needed(rep_type&, size_t) {}
    void shrink_if_needed(rep_type&, size_t) {}
    void deallocate(rep_type&) {}
    static size_t size() { return N; }
};

// Przykład klasy Dynamic_table_allocator
template<typename T>
struct Dynamic_table_allocator {
    typedef T* rep_type;

    void init(rep_type&, size_t) {}
    void expand_if_needed(rep_type&, size_t) {}
    void shrink_if_needed(rep_type&, size_t) {}
    void deallocate(rep_type&) {}
    static size_t size() { return 0; }
};

template<typename T = int, size_t N = 100,
         typename Checking_policy = No_checking_policy,
         template<typename U, size_t M> class Allocator_policy = Static_table_allocator>
class Stack {
private:
    typename Allocator_policy<T, N>::rep_type _rep;
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
    // Stos statyczny 5-elementowy
    Stack<int, 5, Abort_on_error_policy> stack_static;

    // Stos dynamiczny
    Stack<int, 0, No_checking_policy, Dynamic_table_allocator> stack_dynamic;

    stack_dynamic.push(1);
    stack_dynamic.push(2);

    stack_static.push(1);
    stack_static.push(1);
    stack_static.push(1);
    stack_static.push(1);
    stack_static.push(1);
    stack_static.push(1);

    return 0;
}