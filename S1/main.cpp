#include <iostream>
#include "libreria.h"

void funzione()
{
}

// C++ supporta l'overloading
void funzione(int i)
{
}

// Non posso fare l'overloading cambiando il tipo di ritorno
//int funzione(int k) {
//
//}

template<typename T>
T getmax2(T x, T y)
{
    return (x > y) ? x : y;
}

auto getmax(auto x, auto y)
{
    if (x > y) {
        return x;
    }
    return y;
}

double getPi()
{
    return 3.14;
}

int main()
{
    std::cout << "Hello world\n";
    funzione();
    // Richiamo la funzione in un namespace diverso
    pdp::toolbox::funzione();
    {
        // Importa tutti i simboli del namespace std
        // using namespace std;
        using std::cout; // importa solo cout
        using namespace pdp::toolbox;

        cout << "Ciao mondo\n";
        moltiplica(7,4);
        //funzione();
    }
    {
        namespace lib = pdp::testing;
        lib::moltiplica();
        lib::moltiplica(3);
        lib::moltiplica(3,4);
        lib::moltiplica(3,4,5);
        lib::moltiplica(3,4,5,6);
        lib::moltiplica(3,4,5,6);
        lib::moltiplica(3,4,5,6);
    }

    funzione(3);
    funzione(3.14);
    int k = 3;
    // Inizializzazione C++
    int z(8);
    // Inizializzazione C++ (2)
    int p = {42};
    // Inizializzazione C++ (3), da preferire
    int f{5};

    int r = 4.56; // Warning: narrowing conversion
    int t(4.56);  // Warning: narrowing conversion
    //int h{4.56};  // Error: narrowing conversion (il codice non compila)

    //int pi{getPi()};
    auto pi_v2{getPi()};
    auto c = 2 * r * pi_v2;
}
