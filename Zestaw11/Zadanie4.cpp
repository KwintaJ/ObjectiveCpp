//######################################//
//                                      //
//    Jan Kwinta          28.05.2024    //
//                                      //
//    Obiektowy C++                     //
//    Zestaw 11, zadanie 4              //
//                                      //
//######################################//

#include <iostream>
#include <vector>
#include <list>
#include <concepts>
#include <type_traits>

// Koncept sprawdzający, czy typ jest arytmetyczny
template<typename T>
concept Arithmetic = std::is_arithmetic_v<T>;

// Koncept sprawdzający, czy typ jest iterowalny
template<typename T>
concept Iterable = requires(T t) {
    { t.begin() } -> std::same_as<decltype(t.begin())>;
    { t.end() } -> std::same_as<decltype(t.end())>;
};

// Funkcja dla typów arytmetycznych
template <Arithmetic T>
void process(const T& value) {
    std::cout << "Processing arithmetic value: " << value << "\n";
}

// Funkcja dla typów iterowalnych
template <Iterable T>
void process(const T& container) {
    std::cout << "Processing iterable container: ";
    for (const auto& element : container) {
        std::cout << element << " ";
    }
    std::cout << "\n";
}

int main() {
    int num = 42;
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::list<double> lst = {1.1, 2.2, 3.3};

    process(num);    // Wywoła wersję dla typów arytmetycznych
    process(vec);    // Wywoła wersję dla typów iterowalnych
    process(lst);    // Wywoła wersję dla typów iterowalnych

    return 0;
}