#include <iostream>
using namespace std;

class Example {
public:
    void f(double x)
    {
        cout << "f(double x)" << endl;
    }
    void f(int x)
    {
        cout << "f(int x)" << endl;
    }

    void g(int x, double y)
    {

    }

    void g(double x, int y)
    {

    }
};

int main()
{
    Example e;
    e.f(3.2);
    e.f(3);
    // senza cast esplicito ho un errore dovuto a ambiguità
    e.g(1,double(2));
    e.g(int(3.14),2.6);
}
