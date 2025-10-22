#include <iostream>

using namespace std;

struct Foo {
    Foo& operator() (const string& msg)
    {
        cout << msg << ++c << "\n";
        return *this;
    }
private:
    int c{0};
};

struct Comparatore {
    Comparatore(int i) : m_i{i} {}

    bool operator() (int k)
    {
        return k == m_i;
    }

private:
    int m_i;
};

int main()
{
    Foo f;
    f("Ciao")("mondo")("!");
    f("Hello world: ");

    Comparatore quarantadue{42};
    cout << quarantadue(8) << '\n';
    cout << quarantadue(42) << '\n';
}
