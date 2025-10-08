#include "fraction.h"

void Fraction::setNumeratore(int v)
{
    // Accesso ai campi dell'oggetto: varianti possibili
    m_numeratore = v;
    this->m_numeratore = v;
    (*this).m_numeratore = v;
}

void Fraction::setDenominatore(int v)
{
    m_denominatore = v;
}

Fraction::Fraction(int n, int d)
    : m_numeratore{n}, m_denominatore{d} // init-list
{
}

Fraction::Fraction(int n)
    : Fraction{n,1} // delega a un altro costruttore
{
}

