#include <iostream>
using namespace std;

class Base {
public:
    virtual ~Base()
    {
        cout << "Destroying Base" << endl;
    }
};


class Derived : public Base {
public:
    Derived() : m_intptr { new int } {};
    ~Derived()
    {
        cout << "Destroying Derived" << endl;
        delete m_intptr;
    }
    Derived(const Derived&)  = delete;
    Derived& operator=(const Derived&) = delete;
private:
    int* m_intptr;
};

class Manager {
public:
    Manager() : m_resource{nullptr} {};
    ~Manager()
    {
        delete m_resource;
    }
    void resource(Base* r)
    {
        delete m_resource;
        m_resource = r;
    }
    Manager(const Manager&) = delete;
    Manager& operator=(const Manager&) = delete;
private:
    Base* m_resource;
};

int main()
{
    Manager g;
    Derived* pd = new Derived();
    g.resource(pd);
}
