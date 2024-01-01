#ifndef student_h
#define student_h
#include "degree.h"
#include <iostream>
#include <string>
#include <array>
using namespace std;

class Student{
    
private:
    int age;
    string studentID;
    string fName;
    string lName;
    string email;
    int courseDays[3];
    DegreeProgram degree;
    
public:
    //constructors
    Student();
    Student(int age, string studentID, string fName, string lName, string email, int courseDays[], int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degree);
    
    // Mutator/Setter
    void setAge(int a);
    void setStudentID(string s);
    void setFName(string f);
    void setLName(string l);
    void setEmail(string e);
    void setCourseDays(int daysInCourse1, int daysInCourse2, int daysInCourse3);
    void setDegree(DegreeProgram d);
    
    // Accessor/Getter
    int getAge();
    string getStudentID();
    string getFName();
    string getLName();
    string getEmail();
    int* getCourseDays();
    DegreeProgram getDegree();
    
    void print();
};

#endif
