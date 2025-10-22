#include <iostream>
#include <functional>

void richiama(std::function<double(int,int)>& g)
{
    g(7,8);
}

std::function<int(int)> generaLambda()
{
    int y{7};
    return [&y](int k) {
        return y+k;
    };
}

int main()
{
    auto l0 = [](int i, int j) {
        return i+j;
    };
    auto l1 = [](int i, int j) -> double { return i+j; };
    // auto equivale a std::function<double(int,int)> come
    // nell'esempio che segue:
    std::function<double(int,int)> l2 = [](int i, int j) -> double { return i+j; };

    // capture-list
    int x{42};
    // cattura x per valore (copia)
    auto l3 = [x](int i) {
        return x + i;
    };
    // cattura x per riferimento
    auto l4 = [&x](int i) {
        return x + i;
    };
    std::cout << "l3:" << l3(5) << '\n';
    std::cout << "l4:" << l4(5) << '\n';
    x = 10;
    std::cout << "l3:" << l3(5) << '\n';
    std::cout << "l4:" << l4(5) << '\n';
    auto l5 = generaLambda();
    std::cout << "l5:" << l5(5) << '\n';
    double k{1},y{2},z{3};
    // Catturo più variabile per valore
    auto l6 = [k,y,z]() {
        return k+y+z;
    };
    // Catturo tutto per valore
    auto l7 = [=]() {
        return k+y+z;
    };
    // Catturo k e y per valore, e z per riferimento
    auto l8 = [=,&z]() {
        return k+y+z;
    };
    // Catturo k e y per riferimento, e z per valore
    auto l9 = [&,z]() {
        return k+y+z;
    };
    // Catturo tutto per riferimento
    auto l10 = [&]() {
        return k+y+z;
    };
}
