#pragma once
#include <string>

// "Interfaccia" (alla Java)
// TUTTI i metodi sono "pure virtual"
class INameable {
public:
    virtual std::string name() const = 0;
};

// Classe astratta (alla Java)
// ALCUNI metodi sono "pure virtual"
class AbstractEmployee : public INameable {
public:
    // Metodo pure virtual (perché = 0)
    // non c'è un'implementazione in questa classe
    virtual int employeenr() const = 0;

    void foo()
    {
        // ...
    }
};

// Classe concreta
// NESSUN metodo è pure virtual
class Employee : public AbstractEmployee {
public:
    Employee(std::string name, std::string
             institute, int nr);
    ~Employee();
    std::string name() const override;
    std::string institute() const;
    int employeenr() const override;
    // virtual rende il metodo polimorfico
    virtual std::string classname() const;
protected:
    std::string m_name;
    std::string m_institute;
    int m_employeenr;
};
