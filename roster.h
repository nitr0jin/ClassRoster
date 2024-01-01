#ifndef roster_h
#define roster_h
#include <iostream>
#include <string>
#include <array>
#include "student.h"
using namespace std;

class Roster{
public:
    
    //Array of pointers for the data in studentData
    Student* classRosterArray[5];
    
    int classSize;
    int index;
    Roster(int classSize);
    
    //Defining the methods
    void add(int age, string studentID, string fName, string lName, string email, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degree);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void parse(string studentData);
    void printByDegreeProgram(DegreeProgram degree);
    
    
    //Deconstructor
    ~Roster();
};


#endif
