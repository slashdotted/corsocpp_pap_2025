#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <memory>

void esempi_exception3() /* noexcept */
{
    std::cout<< "Inizio esempi_exception3\n";
    std::vector<int> v;
    try {
        std::cout << v.at(0) << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Eccezione: " << e.what() << '\n';
    }

    try {
        throw "Aiuto!";
    }
    catch(int e) {
        std::cerr << "Eccezione di tipo int: " << e << '\n';
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Eccezione: " << e.what() << '\n';
    }
    catch(...) {
        std::cerr << "Eccezione generica" << '\n';
        throw; // Rilancio l'eccezione
    }
    std::cout<< "Inizio esempi_exception3\n";
}

void esempi_exception2()
{
    std::cout<< "Inizio esempi_exception2\n";
    //int* k{new int{8}};
    int k{8};
    std::unique_ptr<int> o{new int{8}};
    // smart pointers
    esempi_exception3();
    //delete k;
    std::cout<< "Fine esempi_exception2\n";
}

void esempi_exception()
{
    std::cout<< "Inizio esempi_exception\n";
    esempi_exception2();
    std::cout<< "Fine esempi_exception\n";
}

void esempi_vector()
{
    std::vector<int> v1{1,2,3,4,5};
    std::vector<int> v2;
    std::vector<int> v3;

    // size e capacity
    std::cout << "v1.size()=" << v1.size() << std::endl;
    std::cout << "v1.capacity()=" << v1.capacity() << std::endl;

    std::cout << "v2.size()=" << v2.size() << std::endl;
    std::cout << "v2.capacity()=" << v2.capacity() << std::endl;

    v3.reserve(50); // preallocazione
    std::cout << "v3.size()=" << v3.size() << std::endl;
    std::cout << "v3.capacity()=" << v3.capacity() << std::endl;

    // inserimento
    v2.push_back(42);
    std::cout << "v2.size()=" << v2.size() << std::endl;
    std::cout << "v2.capacity()=" << v2.capacity() << std::endl;
    v2.push_back(13);
    std::cout << "v2.size()=" << v2.size() << std::endl;
    std::cout << "v2.capacity()=" << v2.capacity() << std::endl;
    v2.push_back(17);
    std::cout << "v2.size()=" << v2.size() << std::endl;
    std::cout << "v2.capacity()=" << v2.capacity() << std::endl;
    v2.push_back(46);
    std::cout << "v2.size()=" << v2.size() << std::endl;
    std::cout << "v2.capacity()=" << v2.capacity() << std::endl;

    int primo = v2.at(0);
    int primo_op = v2[0]; // nessun bound-checking
    std::cout << "Primo: " << primo << std::endl;
    int& primo_ref = v2.at(0); // riferimento a elemento
    std::cout << "Primo_ref: " << primo_ref << std::endl;

    v2.push_back(77);
    std::cout << "v2.size()=" << v2.size() << std::endl;
    std::cout << "v2.capacity()=" << v2.capacity() << std::endl;
    std::cout << "Primo: " << primo << std::endl;
    std::cout << "Primo_ref: " << primo_ref << std::endl; // attenzione, riferimento non più valido

    for(int& c : v2) {
        std::cout << "Elemento prima: " << c << std::endl;
        ++c;
        std::cout << "Elemento dopo: " << c << std::endl;
    }
    std::cout << "====================================\n";
    for(int c : v2) {
        std::cout << "Elemento: " << c << std::endl;
    }

    v2.pop_back();

    std::cout << "====================================\n";
    for(int i{0}; i<v2.size(); ++i) {
        std::cout << "Elemento: " << v2.at(i) << std::endl;
    }

    // Rimozione di un elemento
    std::cout << "====================================\n";
    for(const auto& v : v1) {
        std::cout << "Elemento: " << v << std::endl;
    }
    std::cout << "====================================\n";
    v1.erase(v1.begin()+2);
    for(const auto& v : v1) {
        std::cout << "Elemento: " << v << std::endl;
    }

    // Rimozione di tutti gli elementi
    v1.clear();
    std::cout << "v1.size()=" << v1.size() << " v1.capacity()=" << v1.capacity() << std::endl;

    // Attenzione (vector gestisce in automatico la memoria occupata
    // dai valori in esso contenuti). Se ho della memoria allocata altrove
    // devo liberarla prima di "perdere" il puntatore.
    std::vector<int*> v4;
    v4.push_back(new int{78});
    v4.push_back(new int{767});
    //delete v4.at(0);
    //delete v4.at(1);
    for(const auto& p : v4) {
        delete p;
    }
    v4.clear();
}

void esempi_map()
{
    std::map<std::string,double> valori1;
    std::map<std::string,double> valori2{{"pi",3.14},{"e",2.62}};

    std::cout << "valori1.size()=" << valori1.size() << '\n';
    valori1["pi"] = 3.14;
    std::cout << "valori1.size()=" << valori1.size() << '\n';
    valori1["e"] = 2.62;
    std::cout << "valori1.size()=" << valori1.size() << '\n';

    // Come NON verificare se la chiave "g" esiste nella map
    if (valori1["g"]) { // Crea un'associazione tra "g" e 0 (default per double)
        std::cout << "g esiste in valori1\n";
    }
    std::cout << "valori1.size()=" << valori1.size() << '\n';
    std::cout << "valori1[\"g\"]=" << valori1["g"] << '\n';

    if (valori1.count("s") == 1) {
        std::cout << "s esiste in valori1\n";
    }
    else {
        std::cout << "s non esiste in valori1\n";
    }

    // da C++ 20
    if (valori1.contains("s")) {
        std::cout << "s esiste in valori1\n";
    }
    else {
        std::cout << "s non esiste in valori1\n";
    }
}

int main()
{
    //esempi_vector();
    //esempi_map();
    try {
        esempi_exception();
    }
    catch(...) {
        std::cout << "Yuppi, ho catturato l'eccezione\n";
    }

}
