#include "fraction.h"
#include <iostream>

void stampaFrazione(const Fraction& f)
{
    /* if (f.getDenominatore() == 1) {
         std::cout << f.getNumeratore() << std::endl;
     }
     else {
         std::cout << f.getNumeratore() << "/" << f.getDenominatore() << std::endl;
     }
     */

    std::cout << f << std::endl;
    operator<<(std::cout,f).operator<<(std::endl);
}

int main()
{
    // Risposta a domanda in fondo alle slides cap. 4
    Fraction k = new Fraction{36,8};
    stampaFrazione(k);

    k += Fraction{5,2};
    // k.operator+=(Fraction{5,2});
    stampaFrazione(k);
    k -= 3;
    stampaFrazione(k);

    Fraction j{5,8};
    Fraction l = k + j; // k.operator+(j)
    Fraction m = k - 7; // k.operator+(7) -> k.operator+(Fraction{7})
    Fraction n = 7 + k; // operator+(7,k) -> operator+(Fraction{7},k)
    stampaFrazione(l);
    stampaFrazione(m);
    stampaFrazione(n);
    Fraction o = -j;
    stampaFrazione(j);
    stampaFrazione(o);
    ++o; // prefix
    --o; // prefix
    o++; // postfix
    o--; // postfix

    //std::cout << j << std::endl;
    Fraction p = 78; // Fraction p = Fraction{78}
    //double q = p;
}

