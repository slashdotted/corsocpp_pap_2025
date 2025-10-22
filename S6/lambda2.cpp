#include <iostream>

double f(int k)
{
}

auto g(int k) -> double
{
}

struct Foo {
    int operator() ()
    {
        return ++c;
    }
private:
    int c{0};
};

int main()
{
    // dichiarazione di variabili locali al body
    auto l0 = [](int i, int j) {
        int v{42};
        ++v;
        ++i;
        return v+i+j;
    };

    int x{7};
    // Per valore, non mi è permesso cambiare x
    auto l1 = [x](int i, int j) {
        int v{42};
        ++i; /*++x;*/ return v+i+j+x;
    };
    // Per riferimento mi è permesso cambiare x
    auto l2 = [&x](int i, int j) {
        int v{42};
        ++x;
        ++i;
        return v+i+j;
    };
    // Per valore, non mi è permesso cambiare x a meno che la lambda non sia mutable
    auto l3 = [x](int i, int j) mutable -> double { int v{42}; ++i; ++x; return v+i+j+x; };

    Foo f;
    std::cout << f() << '\n';
    std::cout << f() << '\n';
    std::cout << f() << '\n';

    int c{0};
    auto g = [c]() mutable { return ++c;};
    std::cout << g() << '\n';
    std::cout << g() << '\n';
    std::cout << g() << '\n';

    // dichiarazione di variabili "interne alla lambda" nella capture list
    // d è una variabile interna alla lambda
    // il tipo di d è dedotto automaticamente dal valore assegnato
    auto h = [d=0]() mutable { return ++d;};
    std::cout << h() << '\n';
    std::cout << h() << '\n';
    std::cout << h() << '\n';
}
