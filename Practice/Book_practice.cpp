#include<iostream>
using namespace std;

class student{
    public:
        string name;
        int age;

        student(string _name, int _age) : name{_name}, age{_age} {}
};

class job: public virtual student{
    public:
        string title;

        job(string _name, int _age, string _title) : student(_name, _age), title{_title} {}
};



int main(){
    student s1("John", 20);
    cout << "Name: " << s1.name << ", Age: " << s1.age << endl;

    job j1("Alice", 30, "Engineer");
    cout << "Name: " << j1.name << ", Age: " << j1.age << ", Job Title: " << j1.title << endl;

    return 0;
}