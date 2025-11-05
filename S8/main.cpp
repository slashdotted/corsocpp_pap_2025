#include <iostream>
#include <vector>

static bool showOutput = true;

struct Oggetto {
    Oggetto()
    {
        if (showOutput)
            std::cout << "Oggetto::Oggetto()\n";
    }

    ~Oggetto() noexcept
    {
        if (showOutput)
            std::cout << "Oggetto::~Oggetto()\n";
    }

    Oggetto(const Oggetto&)
    {
        if (showOutput)
            std::cout << "Oggetto::Oggetto(const Oggetto&)\n";
    }

    Oggetto(Oggetto&&) noexcept
    {
        if (showOutput)
            std::cout << "Oggetto::Oggetto(Oggetto&&)\n";
    }

    Oggetto& operator=(const Oggetto&)
    {
        if (showOutput)
            std::cout << "Oggetto& Oggetto::operator=(const Oggetto&)\n";
        return *this;
    }

    Oggetto& operator=(Oggetto&&)
    {
        if (showOutput)
            std::cout << "Oggetto& Oggetto::operator=(Oggetto&&)\n";
        return *this;
    }
};

// Composizione con oggetto sullo heap
struct Contenitore {
    Contenitore() : m_oggetti{new Oggetto} {}
    ~Contenitore()
    {
        delete m_oggetti;
    }

    // Construttore di copia
    Contenitore(const Contenitore& o) : m_oggetti{new Oggetto{*o.m_oggetti}}
    {
    }

    // Costruttore di spostamento
    // (utilizzato quando o è una R-Value (valore temporaneo)
    Contenitore(Contenitore&& o)
        : m_oggetti{o.m_oggetti}   // "Rubo" l'allocazione
    {
        o.m_oggetti = nullptr; // "Resetto" il puntatore gestito da o
    }

    // Operatore di assegnamento di copia
    Contenitore& operator=(const Contenitore& o)
    {
        *m_oggetti = *o.m_oggetti;
        return *this;
    }

    // Operatore di assegnamento di spostamento
    Contenitore& operator=(Contenitore&& o)
    {
        delete m_oggetti; // Libero la memoria del "mio" oggetto
        m_oggetti = o.m_oggetti; // Rubo l'oggetto da o
        o.m_oggetti = nullptr; // "Resetto" il puntatore gestito da o
        return *this;
    }

private:
    Oggetto* m_oggetti;
};

// Composizione con oggetto "interno"
struct Contenitore2 {
    Contenitore2() {}
    ~Contenitore2() {}

    Contenitore2(const Contenitore2& o) : m_oggetti{o.m_oggetti}
    {}

    // Costruttore di spostamento
    Contenitore2(Contenitore2&& o) : m_oggetti{std::move(o.m_oggetti)}
    {}


    // Operatore di assegnamento di copia
    Contenitore2& operator=(const Contenitore2& o)
    {
        m_oggetti = o.m_oggetti;
        return *this;
    }

    // Operatore di assegnamento di spostamento
    Contenitore2& operator=(Contenitore2&& o)
    {
        m_oggetti = std::move(o.m_oggetti);
        return *this;
    }

private:
    Oggetto m_oggetti;
};

Contenitore creaContenitore()
{
    return Contenitore{};
}

Contenitore2 creaContenitore2()
{
    return Contenitore2{};
}


int main()
{
    std::cout << "===============A===============\n";
    Contenitore c;
    std::cout << "===============B===============\n";
    Contenitore d;
    std::cout << "===============C===============\n";
    c = d;
    std::cout << "===============D===============\n";
    d = creaContenitore();
    std::cout << "===============E===============\n";
    Contenitore2 e;
    std::cout << "===============F===============\n";
    e = creaContenitore2();
    std::cout << "===============G===============\n";
    std::vector<Oggetto> v;
    for(int i{0}; i<20; ++i) {
        v.push_back(Oggetto{});
    }
    std::cout << "===============H===============\n";
}
