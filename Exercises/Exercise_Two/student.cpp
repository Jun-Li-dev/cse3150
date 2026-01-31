#include "student.h"
#include <iostream>

void Student::setName(const std::string& _name) {
    name = _name;
}

std::string Student::getName() const {
    return name;
}

Student get_data() {
    Student student;

    std::string student_name;
    std::cout << "Enter student name: " << std::endl;
    std::cin >> student_name;
    student.setName(student_name);

    std::cout << "Enter midterm grade: " << std::endl;
    std::cin >> student.midterm;

    std::cout << "Enter finals grade: " << std::endl;
    std::cin >> student.final;

    std::cout << "Enter homework grades or hit Ctrl+D for exit (no score)" << std::endl;
    int score;
    while (std::cin >> score) {
        student.hw_grades.push_back(score);
        std::cout << "Enter another grade or hit Ctrl+D for exit" << std::endl;
    }
    std::cin.clear();

    return student;
}

std::ostream & operator<<(std::ostream & os, const Student & student) {
    os << student.getName()
       << " Midterm: " << student.midterm
       << " Final: " << student.final
       << " Homework scores: ";
    for (auto score : student.hw_grades) {
        os << score << " ";
    }
    return os;
}
