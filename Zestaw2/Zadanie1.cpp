//######################################//
//                                      //
//    Jan Kwinta          12.03.2024    //
//                                      //
//    Obiektowy C++                     //
//    Zestaw 2, zadanie 1               //
//                                      //
//######################################//

// Polimorfizm

// W obiektowym C++ polimorfizm jest mechanizmem, który
// pozwala różnym obiektom reagować na wywołanie tej samej
// metody w sposób odpowieni dla danego obiektu.

// Jeżeli wiązanie funkcji(metody) z obiektem(klasą) 
// zachodzi na etapie kompilacji mówimy o polimorfiźmie 
// statycznym - funkcja wybierana jest na podstawie
// statycznego typu wskaźnika/referencji.

// Jeżeli natomiast wiązanie funkcja-obiekt zachodzi podczas
// pracy programu, w czasie rzeczywistym - to nazywamy
// polimorfizmem dynamicznym.


// Funkcje wirtualne i klasy abstrakcyjne

// Funkcja wirtualna to taka funkcja, której definicja
// znajduje się w klasie C, ale jej implementacja (ciało
// funkcji) nie znajduje się w klasie C tylko w klasach
// które dziedziczą po C.

// Klasa abstrakcyjna to klasa posiadająca przynajmniej 
// jedną funkcję wirtualną. Nie można tworzyć obiektów 
// klas abstrakcyjnych (ale można tworzyć wskaźniki na nie
// aby wykorzystać mechanizm polimorfizmu).

