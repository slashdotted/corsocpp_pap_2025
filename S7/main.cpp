#include <iostream>



struct Fish {
    Fish(const std::string& name)
        : m_name{name}
    {
        std::cout << "Creating a fish named " << m_name << '\n';
        ++ fishCount;
    }

    Fish(const Fish& o) : m_name{o.m_name}
    {
        ++ fishCount;
    }

    // Distruttore
    ~Fish()
    {
        std::cout << "Destroying a fish named " << m_name << '\n';
        -- fishCount;
    }

    static unsigned int getFishCount()
    {
        return fishCount;
    }

    std::string m_name;

private:
    // dichiara che fishCount è nel contesto di Fish
    static unsigned int fishCount;
};

// crea lo spazio in memoria per il campo static
unsigned int Fish::fishCount{0};

struct Tank {
    Tank()
        : fish1{new Fish{"Aldo"}}, fish2{new Fish{"Giovanni"}}
    {
        std::cout<< "Creating a tank\n";
    }

    // Impedisco la copia
    //Tank(const Tank& o) = delete;
    //Tank& operator=(const Tank& o) = delete;

    // Costruttore di copia
    Tank(const Tank& o)
    // Istanzio due nuovi pesci sullo heap che sono copie dei pesci
    // "originali" (quelli puntati da o)
        : fish1{new Fish{*o.fish1}}, fish2{new Fish{*o.fish2}} {}

    // Operatore di assegnamento di copia
    Tank& operator=(const Tank& o)
    {
        *fish1 = *o.fish1;
        *fish2 = *o.fish2;
        return *this;
    }

    // Distruttore
    ~Tank()
    {
        delete fish2;
        delete fish1;
        std::cout<< "Destroying a tank\n";
    }

    // Fish fish1{"Aldo"};
    // Fish fish2{"Giovanni"};
    Fish *fish1;
    Fish *fish2;
};

void foo()
{
    std::cout << "Fish count: " << Fish::getFishCount() << '\n';
    Fish puntino{"Puntino"};
    std::cout << "Fish count: " << Fish::getFishCount() << '\n';
    // viene richiamato il distruttore di puntino
}

void bar(Tank s)
{
    // ...
}

int main()
{
    std::cout << "Fish count: " << Fish::getFishCount() << '\n';
    Fish nemo{"Nemo"};
    std::cout << "Fish count: " << Fish::getFishCount() << '\n';
    foo();
    std::cout << "Fish count: " << Fish::getFishCount() << '\n';
    {
        Fish bruto{"Bruto"};
        std::cout << "Fish count: " << Fish::getFishCount() << '\n';
        // viene richiamato il distruttore di bruto
    }
    std::cout << "Fish count: " << Fish::getFishCount() << '\n';
    Fish *franco{new Fish{"Franco"}};
    std::cout << "Fish count: " << Fish::getFishCount() << '\n';
    delete franco; // viene richiamato il distruttore di franco
    std::cout << "Fish count: " << Fish::getFishCount() << '\n';
    {
        std::cout << "---------------- Creating a fishtank ------------\n";
        Tank t;
        std::cout << "Fish count: " << Fish::getFishCount() << '\n';
        bar(t); // passaggio per valore -> copia -> costruttore di copia
        std::cout << "Fish count: " << Fish::getFishCount() << '\n';
        Tank k;
        k = t;
        std::cout << "Fish count: " << Fish::getFishCount() << '\n';
    }
    std::cout << "Fish count: " << Fish::getFishCount() << '\n';
}
