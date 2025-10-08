#pragma once

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

    // Ri-abilita il costruttore di default
    Fraction() = default;


protected:

private:
    int m_numeratore{0}, m_denominatore{1};
};
