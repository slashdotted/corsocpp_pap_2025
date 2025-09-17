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
}
