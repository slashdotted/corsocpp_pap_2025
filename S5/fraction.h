#pragma once
#include <iostream>

struct Fraction {
    // Public per default (perché sono in una struct)
    // Se uso è private per default
public:
    // Implementazione inline
    int getNumeratore() const
    {
        return m_numeratore;
    }
    int getDenominatore() const
    {
        return m_denominatore;
    }
    void setNumeratore(int v);
    void setDenominatore(int v);

    // Soluzione ideale per permettere
    // l'instanziazione di Fraction con 0,1 o 2 argomenti
    // Fraction(int n = 0, int d = 1);

    Fraction(int n, int d);
    Fraction(int n); // costruttore di conversione (da int a Fraction)

    Fraction(Fraction* f)
        : m_numeratore{f->m_numeratore},
          m_denominatore{f->m_denominatore}
    {
        delete f;
    }

    Fraction& operator+=(const Fraction& f);
    Fraction& operator-=(const Fraction& f);

    Fraction& operator++(); // ++frazione (prefix)
    Fraction& operator--(); // --frazione (prefix)

    Fraction operator++(int); // frazione++ (postfix)
    Fraction operator--(int); // frazione-- (postfix)

    // Fraction operator+(const Fraction& f) const;

    // Ri-abilita il costruttore di default
    Fraction() = default;

    /*operator double() const
    {
        return (double) m_numeratore / m_denominatore;
    }*/

protected:
    void semplifica();
private:
    int m_numeratore{0}, m_denominatore{1};
};

Fraction operator+(Fraction f1, const Fraction& f2);
Fraction operator-(Fraction f1, const Fraction& f2);
Fraction operator-(Fraction f1);

std::ostream& operator<<(std::ostream& o, const Fraction& f);
