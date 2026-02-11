#include <iostream>
#include <string>
#include "student.h"

using namespace std;

Student::Student() { 
    hw_grades = nullptr;
    nextStudent = nullptr;  
}

Student::Student(string _name, int _final, int _number_of_homeworks) {
    name = _name;
    final = _final;
    number_of_homeworks = _number_of_homeworks;
    hw_grades = new int[number_of_homeworks];
    nextStudent = nullptr;   
}

Student::Student(const Student & student) {
    name = student.name;
    final = student.final;
    number_of_homeworks = student.number_of_homeworks;
    nextStudent = nullptr; 

    if (student.hw_grades != nullptr) {
        hw_grades = new int[number_of_homeworks];
        for (int j = 0; j < number_of_homeworks; j++) {
            hw_grades[j] = student.hw_grades[j];
        }
    }
    else {
        hw_grades = nullptr;
    }
}

Student::~Student() {
    if (hw_grades != nullptr) {
        delete [] hw_grades;
    }
}

string Student::getName() const {
    return name;
}

void Student::setName(string _name) {
    name = _name;
}

Student get_student_struct_data(int total_homeworks) {

    string name;
    int final;

    cout << "-----------------------------" << endl;
    cout << "Enter name: ";
    cin >> name;

    cout << "Enter final: ";
    cin >> final;

    Student student(name, final, total_homeworks);

    for (int i = 0; i < student.number_of_homeworks; i++) {
        cout << "Enter homework score: ";
        cin >> student.hw_grades[i];
    }

    cout << "-----------------------------" << endl;

    return student;
}

ostream & operator<<(ostream & os, const Student & student) {
    os << student.name
       << " Final: "
       << student.final
       << " homework scores: ";

    for (int i = 0; i < student.number_of_homeworks; i++) {
        os << student.hw_grades[i] << " ";
    }

    return os;
}
