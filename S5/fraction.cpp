#include "fraction.h"
#include <numeric>

void Fraction::setNumeratore(int v)
{
    // Accesso ai campi dell'oggetto: varianti possibili
    m_numeratore = v;
    //this->m_numeratore = v;
    //(*this).m_numeratore = v;
    semplifica();
}

void Fraction::setDenominatore(int v)
{
    m_denominatore = v;
    semplifica();
}

void Fraction::semplifica()
{
    auto gcd = std::gcd(m_numeratore,m_denominatore);
    if (gcd > 1) {
        m_numeratore /= gcd;
        m_denominatore /= gcd;
    }
}

Fraction::Fraction(int n, int d)
    : m_numeratore{n}, m_denominatore{d} // init-list
{
    semplifica();
}

Fraction::Fraction(int n)
    : Fraction{n,1} // delega a un altro costruttore
{
}

Fraction& Fraction::operator+=(const Fraction& f)
{
    int t_num = f.m_numeratore * m_denominatore;
    m_denominatore *= f.m_denominatore;
    m_numeratore *= f.m_denominatore;
    m_numeratore += t_num;
    semplifica();
    return *this;
}

Fraction& Fraction::operator-=(const Fraction& f)
{
    int t_num = f.m_numeratore * m_denominatore;
    m_denominatore *= f.m_denominatore;
    m_numeratore *= f.m_denominatore;
    m_numeratore -= t_num;
    semplifica();
    return *this;
}


Fraction& Fraction::operator++()
{
    return this->operator+=(1);
}

Fraction& Fraction::operator--()
{
    return this->operator-=(1);
}

Fraction Fraction::operator++(int)
{
    auto f{*this};
    this->operator+=(1);
    return f;
}

Fraction Fraction::operator--(int)
{
    auto f{*this};
    this->operator-=(1);
    return f;
}


/*Fraction Fraction::operator+(const Fraction& f) const
{
    auto k{*this}; // Creo una copia dell'oggetto corrente
    k += f;
    return k;
}*/

Fraction operator+(Fraction f1, const Fraction& f2)
{
    f1 += f2;
    return f1;
}

Fraction operator-(Fraction f1, const Fraction& f2)
{
    f1 -= f2;
    return f1;
}

Fraction operator-(Fraction f1)
{
    f1.setNumeratore(-1 * f1.getNumeratore());
    return f1;
}

std::ostream& operator<<(std::ostream& o, const Fraction& f)
{
    if (f.getDenominatore() == 1) {
        o << f.getNumeratore();
    }
    else {
        o << f.getNumeratore() << "/" << f.getDenominatore();
    }
    return o;
}


