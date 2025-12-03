#include <iostream>

struct Base {
    int i{42};
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

struct Base2 {
    int i{42};
};
struct DerivedA2 : Base2 {
    double j{3.14};
};
struct DerivedB2 : Base2 {
    std::string k{"Ciao"};
};

void foo(Base2* b)
{
    auto a2_3 = static_cast<DerivedA2*>(b); // Downcast (valido?)
    auto b2_3 = static_cast<DerivedB2*>(b); // Downcast (valido?)
}

int main()
{
    Base b;
    DerivedA da;
    DerivedB db;
    MultiDerived md;

    // Conversione di valori
    da.j = 77;
    Base da_da_a_base = static_cast<Base>(da); // Upcast (con slicing)
    Base da_da_a_base2 = da;  // Upcast (con slicing)
    // Downcast non propriamente valido, perché l'oggetto di origine
    // deve essere completato con dei valori di default
    /*DerivedA da_base_a_da = static_cast<DerivedA>(da_da_a_base);
    std::cout << "i=" << da_base_a_da.i << '\n'
              << "j=" << da_base_a_da.j << '\n';*/

    // Conversione da enum class a valore numerico
    enum class Colori { Rosso = 0, Giallo, Verde, Blu };
    int v = static_cast<int>(Colori::Giallo);
    Colori r = static_cast<Colori>(0);

    // Conversione di puntatori e riferimenti
    Base* da_b_ptr = &da;
    Base* md_b_ptr = &md;
    Base& da_b_ref = da;
    Base& md_b_ref = md;

    Base* da_b_ptr2 = static_cast<Base*>(&da);
    Base* md_b_ptr2 = static_cast<Base*>(&md);
    Base& da_b_ref2 = static_cast<Base&>(da);
    Base& md_b_ref2 = static_cast<Base&>(md);

    // Downcast con static_cast NON può attraversare una derivazione virtual
    //DerivedA* da_from_b_ptr = static_cast<DerivedA*>(da_b_ptr);
    //MultiDerived* md_from_b_ptr = static_cast<MultiDerived*>(da_b_ptr);

    DerivedB* md_db_ptr = static_cast<DerivedB*>(&md);
    MultiDerived* md_db_ptr2 = static_cast<MultiDerived*>(md_db_ptr);

    // Limiti di static_cast
    DerivedA2 a2;
    DerivedB2 b2;
    Base2* b_a2 = &a2; // Upcast (valido)
    Base2* b_b2 = &b2; // Upcast (valido)
    auto a2_2 = static_cast<DerivedA2*>(b_a2); // Downcast (valido)
    auto b2_2 = static_cast<DerivedB2*>(b_b2); // Downcast (valido)

    auto a2_3 = static_cast<DerivedA2*>(b_b2); // Downcast (NON valido!)
    auto b2_3 = static_cast<DerivedB2*>(b_a2); // Downcast (NON valido!)

    std::cout << "j=" << a2_3->j << '\n';
    std::cout << "k=" << b2_3->k << '\n';

    // auto a2_4 = static_cast<DerivedA2*>(b2_2);

}
