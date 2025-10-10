#include <format>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>

void addStudent(std::vector<std::string> &students,
                std::map<std::string, int> &grades,
                const std::string &name)
{
    // TODO: add a student's name to the vector and initialize the grade in the map to -1
    if (grades.count(name) == 0) {
        students.push_back(name);
        grades[name] = -1;
    }
}
void updateGrade(std::map<std::string, int> &grades, const std::string &name, int grade)
{
    // TODO: update the grade of a student in the map
    // Generate exceptions if something is not as expected. More specifically when a student is not found while an
    // operation is attempted on a student who does not exist in the map, and when an invalid grade (less
    // than 1 or greater than 6) is entered.
    if (grade < 1 || grade > 6) {
        throw std::out_of_range("Grade not in range [1,6]");
    }
    // Variante A
    if (grades.find(name) == grades.end()) {
        throw std::runtime_error("Name not found");
    }
    grades[name] = grade;
    // Variante B
    // grades.at(name)= grade;
}

int showGrade(const std::map<std::string, int> &grades, const std::string &name)
{
    // TODO: returns the grade of a specific student
    // Generate exceptions if something is not as expected. More specifically when a student is not found while an
    // operation is attempted on a student who does not exist in the map
    if (grades.find(name) == grades.end()) {
        throw std::runtime_error(std::format("Name {0} not found", name));
    }
    return grades.at(name);
}

void displayGrades(const std::vector<std::string> &students,
                   const std::map<std::string, int> &grades)
{
    // TODO: Print the names of all students and their corresponding grade,
    for (const auto &s : grades) {
        std::cout << "Nome: " << s.first << " Valutazione: " << s.second << '\n';
    }
}

void removeStudent(std::vector<std::string> &students,
                   std::map<std::string, int> &grades,
                   const std::string &name)
{
    // TODO: remove a student from both the vector and the map
    // Generate exceptions if something is not as expected. More specifically when a student is not found while an
    // operation is attempted on a student who does not exist in the map
    if (grades.find(name) == grades.end()) {
        throw std::runtime_error(std::format("Name {0} not found", name));
    }
    size_t posizione{0};
    for (const auto &s : students) {
        if (s == name) {
            break;
        }
        ++posizione;
    }
    students.erase(students.begin() + posizione);
    grades.erase(name);
}

int main()
{
    std::vector<std::string> students;
    std::map<std::string, int> grades;
    try {
        addStudent(students, grades, "Andrea");
        addStudent(students, grades, "Amos");
        updateGrade(grades, "Andrea", 5);
        updateGrade(grades, "Amos", 4);
        displayGrades(students, grades);
        std::cout << "Andrea: " << showGrade(grades, "Andrea") << std::endl;
        removeStudent(students, grades, "Luca"); // Luca does not exist! Throws!
        displayGrades(students, grades);
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
