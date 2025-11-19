#include <iostream>
#include "lecturer.h"

using std::cout;

void foo(Employee e)
{
    cout << "Name:" << e.name() << " Istitute:" << e.institute()
         << " Nr:" << e.employeenr() << " Classname:" << e.classname() << '\n';
}

int main()
{
    Lecturer l1{"Franco","ISIN", 42, "CS", "C++"};
    // Upcasting
    Employee* ep{&l1};
    Employee& er{l1};
    Employee ev{l1}; // copia dell'Employee in l1
    foo(l1); // copia dell'Employee in l1

    cout << "Employee* ep=" << ep << '\n';
    cout << "Employee& er=" << &er << '\n';
    cout << "Employee  ev=" << &ev << '\n';

    cout << "=== l1 ===\n";
    cout << "Name:" << l1.name() << " Istitute:" << l1.institute()
         << " Nr:" << l1.employeenr() << " Studies:" << l1.studies()
         << " Course:" << l1.course()
         << " Classname:" << l1.classname() << '\n';

    cout << "=== ep (Employee*) ===\n";
    cout << "Name:" << ep->name() << " Istitute:" << ep->institute()
         << " Nr:" << ep->employeenr() << " Classname:" << ep->classname() << '\n';

    cout << "=== er (Employee&) ===\n";
    cout << "Name:" << er.name() << " Istitute:" << er.institute()
         << " Nr:" << er.employeenr() << " Classname:" << er.classname() << '\n';

    //AbstractEmployee ae;
    AbstractEmployee& ael{l1};
    cout << ael.employeenr() << '\n';

}
