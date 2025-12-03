#include <iostream>

struct Base {
    int i{42};
    virtual ~Base() = default; // metodo polimorfico che mi permette di usare dynamic_cast
};
struct DerivedA : virtual Base {
    double j{3.14};
};
struct DerivedB : virtual Base {
    std::string k{"Ciao"};
};
struct MultiDerived : DerivedA, DerivedB {
    std::string msg{"Hello world"};
};

bool instanceOfDerivedA(Base * p)
{
    return dynamic_cast<DerivedA*>(p) != nullptr;
}

int main()
{
    Base b;
    DerivedA da;
    DerivedB db;
    MultiDerived md;

    // La conversione di valori con dynamic_cast NON è possibile
    //Base da_da_a_base = dynamic_cast<Base>(da);

    // Conversione di puntatori e riferimenti
    Base* da_b_ptr = &da;
    Base* md_b_ptr = &md;
    Base& da_b_ref = da;
    Base& md_b_ref = md;

    Base* da_b_ptr2 = dynamic_cast<Base*>(&da);
    Base* md_b_ptr2 = dynamic_cast<Base*>(&md);
    Base& da_b_ref2 = dynamic_cast<Base&>(da);
    Base& md_b_ref2 = dynamic_cast<Base&>(md);

    // Downcast con dynamic_cast PUÒ attraversare una derivazione virtual
    // Per dynamic_cast è NECESSARIO che il tipo sorgente sia polimorfico
    // ovvero che ci sia almeno un metodo virtual
    DerivedA* da_from_b_ptr = dynamic_cast<DerivedA*>(da_b_ptr);
    MultiDerived* md_from_b_ptr = dynamic_cast<MultiDerived*>(da_b_ptr);

    DerivedA& da_from_b_ref = dynamic_cast<DerivedA&>(da_b_ref);

    // Cast non validi
    // con puntatori il risultato è nullptr
    DerivedB* db_da = dynamic_cast<DerivedB*>(&da);
    if (db_da == nullptr) {
        std::cout << "Cast fallito\n";
    }
    DerivedB* db_from_b_ptr = dynamic_cast<DerivedB*>(da_b_ptr);
    if (db_from_b_ptr == nullptr) {
        std::cout << "Cast fallito\n";
    }
    // con riferimenti ottengo un'eccezione
    try {
        MultiDerived& md_from_b_ref = dynamic_cast<MultiDerived&>(da_b_ref);
    }
    catch (const std::bad_cast& e) {
        std::cout << "Cast fallito\n";
    }
}

