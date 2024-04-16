
#include <iostream>
#include <stdexcept>

// Klasa wytycznych dla braku sprawdzania
class No_checking_policy {
public:
    static void check_push(size_t, size_t) {}
    static void check_pop(size_t) {}
    static void check_top(size_t) {}
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
    // Testowanie stosu z domyślnym alokatorem (Static_table_allocator)
    Stack<int, 5> stack_static;

    // Testowanie stosu z dynamicznym alokatorem (Dynamic_table_allocator)
    Stack<int, 0, No_checking_policy, Dynamic_table_allocator> stack_dynamic;

    return 0;
}