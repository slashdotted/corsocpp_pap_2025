#include "libreria.h"
#include <iostream>
namespace pdp {
namespace toolbox {

void funzione()
{
    std::cout << "corsocpp::funzione\n";
}

int moltiplica(int a, int b, int c, int d)
{
    return a*b*c*d;
}

}

namespace testing {
int moltiplica(int a, int b, int c, int d)
{
    return a*b*c*d;
}
}
}
