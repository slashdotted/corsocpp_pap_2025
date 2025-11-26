#include <iostream>
#include "lecturerresearcher.h"

using std::cout;


int main()
{
    LecturerResearcher lr{"Tiziano","ISIN",493,"CS",
                          "Parallel Programming", "Audio",0.5};


    Lecturer& llr{lr}; // upcast
    Researcher& rlr{lr}; // upcast
    auto& lr2{static_cast<LecturerResearcher&>(llr)}; // downcast
    auto& lr3{static_cast<LecturerResearcher&>(rlr)}; // downcast

    Lecturer* pllr{&lr}; // upcast
    Researcher* prlr{&lr}; // upcast
    auto lr2p{static_cast<LecturerResearcher*>(pllr)}; // downcast
    auto lr3p{static_cast<LecturerResearcher*>(prlr)}; // downcast

    cout << lr.researchPercentage() << '\n';
    cout << lr.course() << '\n';
    //cout << lr.Lecturer::classname() << '\n';
    //cout << lr.Researcher::classname() << '\n';
    cout << lr.Lecturer::classname() << '\n';
    cout << lr.Lecturer::name() << '\n';
    cout << lr.Researcher::name() << '\n';
}
