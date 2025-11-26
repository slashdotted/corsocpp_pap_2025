#include "lecturerresearcher.h"

LecturerResearcher::LecturerResearcher(std::string name,
                                       std::string institute,
                                       int nr,
                                       std::string studies,
                                       std::string course,
                                       std::string researcharea,
                                       double researchPercentage)
    : Employee{name,institute,nr}, Lecturer{name,institute,nr,studies,course},
      Researcher{name,institute,nr,researcharea},
      m_researchPercentage{researchPercentage}
{

}

double LecturerResearcher::researchPercentage() const
{
    return m_researchPercentage;
}

std::string LecturerResearcher::classname() const
{
    return "LecturerResearcher";
}
