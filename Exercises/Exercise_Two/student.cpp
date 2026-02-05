#include <iostream>

#include "student.h"

Student::Student() { 
    hw_grades = nullptr;
}

Student::Student(string _name, int _final, int _number_of_homeworks) {
    name = _name;
    final = _final;
    number_of_homeworks = _number_of_homeworks;
    hw_grades = new int[number_of_homeworks];
}

Student::Student(const Student & student) {
    cout << "COPY CONSTRUCTOR Student" << endl;
    name = student.name;
    final = student.final;
    number_of_homeworks = student.number_of_homeworks;
    if (nullptr != student.hw_grades) {
        hw_grades = new int[number_of_homeworks];
        for (int j = 0; j < number_of_homeworks; j++) {
            hw_grades[j] = student.hw_grades[j];
        }
    }
}

Student::~Student() {
    cout << "DESTRUCTOR Student" << endl;
    if (nullptr != hw_grades) {
        delete [] hw_grades;
    }
}

string Student::getName() const { return name; }
void Student::setName(string _name) { name = _name; }

Student get_student_struct_data(int total_homeworks) {

    string name;
    int final;

    cout << "-----------------------------" << endl;
    cout << "Enter name: " << endl;
    cin >> name;

    cout << "Enter final: " << endl;
    cin >> final ;

    Student student(name,final,total_homeworks);

    cout << "Enter a homework score: " << endl;
    int score;
    for (int i = 0; i < student.number_of_homeworks; i++) {
        cin >> score;
        student.hw_grades[i] = score;
        cout << "Enter another score: " << endl;
    }

    cout << "-----------------------------" << endl;

    return student;
}

double Student::getHomeworkAverage() const {
    if (number_of_homeworks == 0 || hw_grades == nullptr)
        return 0.0;

    int sum = 0;
    for (int i = 0; i < number_of_homeworks; i++) {
        sum += hw_grades[i];
    }

    return static_cast<double>(sum) / number_of_homeworks;
}

ostream & operator<<(ostream & os, const Student & student) {
    os << student.getName()
       << " Final: " << student.final
       << " homework scores: ";

    for (int i = 0; i < student.number_of_homeworks; i++) {
        os << student.hw_grades[i] << " ";
    }

    os << " homework average: " << student.getHomeworkAverage();

    return os;
}
