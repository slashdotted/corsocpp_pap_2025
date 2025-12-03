#include <map>

struct Foo {

    // memoization
    int bar(int z) const
    {
        // Se avevo già calcolato in precedenza il risultato
        // utilizzo in valore in cache
        if (cache.contains(z)) {
            return cache.at(z);
        }
        auto r = z*2; // immaginiamo che richieda mooooolto tempo
        // this è const Foo*
        // cache[z] = r;
        // this->cache[z] = r;
        auto nc_this = const_cast<Foo*>(this);
        nc_this->cache[z] = r; // nc_this non ha il vincolo const
        return r;
    }
private:
    double pi{3.14};
    unsigned int counter{0};
    std::map<int,int> cache;
};

void dosomething(const Foo& r)
{
    r.bar(7);
}

int main()
{
    const int z{6};
    //auto z2 = static_cast<int&>(z);
    //auto z3 = static_cast<int*>(&z);
    auto cz2 = const_cast<int&>(z);
    auto cz3 = const_cast<int*>(&z);

    Foo f;
    f.bar(5);
}
