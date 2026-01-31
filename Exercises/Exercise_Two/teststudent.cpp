#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../include/doctest.h"

#include "student.h"

#include <sstream>

TEST_CASE("Testing Student basic functionality") {

    Student s;
    s.setName("Alice");
    CHECK(s.getName() == "Alice");

    s.midterm = 90;
    s.final = 95;
    CHECK(s.midterm == 90);
    CHECK(s.final == 95);

    s.hw_grades.push_back(100);
    s.hw_grades.push_back(80);
    CHECK(s.hw_grades.size() == 2);
    CHECK(s.hw_grades[0] == 100);
    CHECK(s.hw_grades[1] == 80);

    std::ostringstream oss;
    oss << s;
    std::string output = oss.str();
    CHECK(output.find("Alice") != std::string::npos);
    CHECK(output.find("Midterm: 90") != std::string::npos);
    CHECK(output.find("Final: 95") != std::string::npos);
    CHECK(output.find("100") != std::string::npos);
    CHECK(output.find("80") != std::string::npos);
}