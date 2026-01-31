#ifndef _SIMPLE_STUDENT_H
#define _SIMPLE_STUDENT_H

#include <vector>
#include <string>

using namespace std;

struct Student {
 
    public: 
        int final;
        int midterm;
        vector<int> hw_grades;

    private: 
        string name;

    public:
        void setName(const std::string& _name); 
        std::string getName() const;
};

ostream & operator<<(ostream & os, const Student & student);

Student get_data();

#endif