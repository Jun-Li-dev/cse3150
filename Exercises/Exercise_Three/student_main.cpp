#include <iostream>
#include "student.h"

using namespace std;

int main() {

    Student* head = nullptr;   
    Student* tail = nullptr;   

    int numberOfStudents, numberOfHws;
    cout << "Enter the number of students: " << endl;
    cin >>  numberOfStudents;

    cout << "Enter the number of homeworks: " << endl;
    cin >> numberOfHws;

    for (int i = 0; i < numberOfStudents; i++) {

        Student student = get_student_struct_data(numberOfHws);

        Student* newStudent = new Student(student);  

        if (head == nullptr) {
            head = newStudent;
            tail = newStudent;
        }
        else {
            tail->nextStudent = newStudent;
            tail = newStudent;
        }
    }

    Student* current = head;
    while (current != nullptr) {
        cout << endl << *current << endl;
        current = current->nextStudent;
    }

    current = head;
    while (current != nullptr) {
        Student* temp = current;
        current = current->nextStudent;
        delete temp;
    }

    return 0;
}
