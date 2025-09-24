#include <string>
#include <iostream>

void foo()
{
    long z{1344};
    auto e{2.62};
    {
        std::string msg{"Hello world"};
    }
}

void assegna13(int* i)
{
    *i = 13;
}

void assegna17(int& i)
{
    i = 17;
}

int somma(int& x, int& y)
{
    return x+y;
}

int moltiplica(const int& x, const int& y)
{
    return x*y;
}

void test(std::string* p)
{
    std::cout << "p=" << p << " &p=" << &p << std::endl;
    //...
}

int diciassette()
{
    return 17;
}

int& baz()
{
    int k{66};
    return k;
}

int& getmax(int& x, int& y)
{
    if (x > y) {
        return x;
    }
    return y;
}

int main()
{
    // Variabili sullo stack
    int v{42};
    std::string msg{"Ciao mondo"};
    double pi{3.14};
    foo();
    std::cout << "&v="<< &v
              << ", &pi=" << &pi
              << ", &msg=" <<  &msg << std::endl;

    // Allocazione sullo heap
    int* ptr{new int{7}}; // int* ptr = (int*) malloc(sizeof(int)); *ptr = 7;
    auto ptr2{new int{7}};
    std::string* ptr3{new std::string{"Hello world"}};
    std::cout << "ptr3=" << ptr3 << " &ptr3=" << &ptr3 << std::endl;
    test(ptr3);
    // Deallocazione
    delete ptr;
    delete ptr2;
    delete ptr3;

    // Allocazione e deallocazione di un array
    int* aptr{new int[10]};
    auto aptr2{new int[10]};
    delete[] aptr;
    delete[] aptr2;

    {
        using namespace std;
        // Errore tipico per chi arriva da Java
        // string s = new string("Ciao");
    }

    // int* x{NULL}; // In C++ funziona ma è ORRIBILE
    int* x{nullptr};
    if (!x) {
        std::cout << "il puntatore x non è inizializzato\n";
    }

    // Riferimenti
    int contatore{1000};
    int& rcontatore{contatore}; // riferimento
    int* pcontatore{&contatore};
    std::cout << "&contatore=" << &contatore << std::endl;
    std::cout << "&rcontatore=" << &rcontatore << std::endl;
    std::cout << "&pcontatore=" << &pcontatore << std::endl;
    contatore = 555;
    rcontatore = 666;

    // passaggio per puntatore
    // ==> passaggio per valore di un puntatore (copia del puntatore)
    assegna13(&contatore);
    std::cout << "contatore=" << contatore << std::endl;

    //
    assegna17(contatore);
    std::cout << "contatore=" << contatore << std::endl;

    int a{9};
    int b{17};
    std::cout << "9 + 17 = " << somma(a,b) << std::endl;
    // Non posso passare riferimenti a valori temporanei (R-Value)
    // Posso passare riferimenti a L-Value
    //std::cout << "9 + 17 = " << somma(a,diciassette()) << std::endl;
    //std::cout << "9 + 17 = " << somma(9,17) << std::endl;

    // ... tranne se i riferimenti sono a valori const
    std::cout << "9 + 17 = " << moltiplica(a,diciassette()) << std::endl;
    std::cout << "9 + 17 = " << moltiplica(9,17) << std::endl;

    //int& i{baz()};
    //std::cout << i << std::endl;
    std::cout << getmax(a,b) << std::endl;

    int valori[] {1,2,3,4,5};
    for (int v : valori) {
        std::cout << v << std::endl;
    }

    for (int& v : valori) {
        v += 1;
    }
    std::cout << "------\n";
    for (int v : valori) {
        std::cout << v << std::endl;
    }
}
