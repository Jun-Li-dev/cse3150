#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/doctest.h"

#include "student.h"

TEST_CASE("Edge case: zero students (empty list)") {
    Student* head = nullptr;
    CHECK(head == nullptr);
}

TEST_CASE("Edge case: one student with zero homeworks") {
    Student* s = new Student("Alice", 90, 0);

    CHECK(s->name == "Alice");
    CHECK(s->final == 90);
    CHECK(s->number_of_homeworks == 0);

    delete s;
}

TEST_CASE("Edge case: one student with one homework") {
    Student* s = new Student("Bob", 85, 1);
    s->hw_grades[0] = 100;

    CHECK(s->number_of_homeworks == 1);
    CHECK(s->hw_grades[0] == 100);

    delete s;
}

TEST_CASE("Edge case: linked list with one node") {
    Student* head = new Student("Tom", 70, 2);
    head->hw_grades[0] = 80;
    head->hw_grades[1] = 90;

    CHECK(head->nextStudent == nullptr);

    delete head;
}

TEST_CASE("Edge case: linked list with multiple nodes") {
    Student* s1 = new Student("A", 60, 1);
    s1->hw_grades[0] = 50;

    Student* s2 = new Student("B", 70, 1);
    s2->hw_grades[0] = 60;

    Student* s3 = new Student("C", 80, 1);
    s3->hw_grades[0] = 70;

    s1->nextStudent = s2;
    s2->nextStudent = s3;
    s3->nextStudent = nullptr;

    CHECK(s1->nextStudent == s2);
    CHECK(s2->nextStudent == s3);
    CHECK(s3->nextStudent == nullptr);

    Student* current = s1;
    while (current != nullptr) {
        Student* temp = current;
        current = current->nextStudent;
        delete temp;
    }
}

TEST_CASE("Homework scores stored correctly") {
    Student* s = new Student("Dana", 95, 3);
    s->hw_grades[0] = 10;
    s->hw_grades[1] = 20;
    s->hw_grades[2] = 30;

    CHECK(s->hw_grades[0] == 10);
    CHECK(s->hw_grades[1] == 20);
    CHECK(s->hw_grades[2] == 30);

    delete s;
}
