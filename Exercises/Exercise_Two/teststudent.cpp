#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/doctest.h"

#include "student.h"
#include <sstream>

TEST_CASE("Testing Student basic functionality") {


    Student s;
    s.setName("Alice");
    CHECK(s.getName() == "Alice");


    s.final = 95;
    CHECK(s.final == 95);


    s.number_of_homeworks = 2;
    s.hw_grades = new int[s.number_of_homeworks];
    s.hw_grades[0] = 100;
    s.hw_grades[1] = 80;

    // Check homework grades
    CHECK(s.hw_grades[0] == 100);
    CHECK(s.hw_grades[1] == 80);
    CHECK(s.number_of_homeworks == 2);


    CHECK(s.getHomeworkAverage() == 90);


    std::ostringstream oss;
    oss << s;
    std::string output = oss.str();
    CHECK(output.find("Alice") != std::string::npos);
    CHECK(output.find("Final: 95") != std::string::npos);
    CHECK(output.find("100") != std::string::npos);
    CHECK(output.find("80") != std::string::npos);


    delete[] s.hw_grades;
    s.hw_grades = nullptr;
}
