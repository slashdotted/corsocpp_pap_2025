#include "fraction.h"
#include <iostream>

class Foo {
public:
    explicit Foo(int i=8) {}

};

void usaFoo(const Foo& f) {}

void stampaFrazione(const Fraction& f)
{
    std::cout << f.getNumeratore() << "/" << f.getDenominatore() << std::endl;
}

Fraction getFrazione()
{
    return Fraction{8,9};
}

int main()
{
    // Sullo stack
    Fraction f1{5,6};
    //f1.setNumeratore(5);
    //f1.setDenominatore(6);

    // Sullo heap
    Fraction* f2{new Fraction{7,9}};
    //f2->setNumeratore(7);
    //f2->setDenominatore(9);
    delete f2;

    Fraction f3; // 0/1

    Fraction f4{17}; // 17/1
    stampaFrazione(f4);

    stampaFrazione(getFrazione());
    stampaFrazione(Fraction{3,2});

    Fraction f5;
    f5 = 9; // conversione implicita da int a Fraction -> f5 = Fraction{9};
    f5 = Fraction{9}; // conversione esplicita
    stampaFrazione(67); // conversione implicita da int a Fraction -> stampaFrazione(Fraction{67});
    stampaFrazione(Fraction{67}); // conversione esplicita

    stampaFrazione(f5);

    usaFoo(Foo{});
    //usaFoo(42); // conversione implicita da
    // int a Foo non è più possibile
    // perché in costruttore di
    // conversione è dichiarato come
    // explicit
}
