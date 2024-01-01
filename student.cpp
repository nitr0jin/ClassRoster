#include <iostream>
#include <string>
#include "student.h"
using namespace std;

//Default constructor
Student::Student() {
    this-> studentID = " ";
    this-> fName = " ";
    this-> lName = " ";
    this-> email = " ";
    this-> age = 0;
    this-> degree;
    for(int i : courseDays)
        this-> courseDays[i] = 0;
}

//Parameter constructor
Student::Student(int age, string studentID, string fName, string lName, string email, int courseDays[], int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degree){
    this-> studentID = studentID;
    this-> fName = fName;
    this-> lName = lName;
    this-> email = email;
    this-> age = age;
    this-> degree = degree;
    this-> courseDays[0] = daysInCourse1;
    this-> courseDays[1] = daysInCourse2;
    this-> courseDays[2] = daysInCourse3;
}

// Mutator/Setter
void Student::setStudentID(string s) {
    studentID = s;
}
void Student::setAge(int a) {
    age = a;
}
void Student::setFName(string f) {
    fName = f;
}
void Student::setLName(string l) {
    lName = l;
}
void Student::setEmail(string e) {
    email = e;
}
void Student::setDegree(DegreeProgram d){
    degree = d;
}
void Student::setCourseDays(int daysInCourse1, int daysInCourse2, int daysInCourse3){
    courseDays[0] = daysInCourse1;
    courseDays[1] = daysInCourse2;
    courseDays[2] = daysInCourse3;
}

// Accessor/Getter
int Student::getAge() {
    return age;
}
string Student::getStudentID() {
    return studentID;
}
string Student::getFName() {
    return fName;
}
string Student::getLName() {
    return lName;
}
string Student::getEmail() {
    return email;
}
DegreeProgram Student::getDegree(){
    return degree;
}
int* Student::getCourseDays(){
    return courseDays;
}

//Print method
void Student::print() {

    cout << studentID << "\t" << fName << "\t" << lName << "\t" << age << "\t";
    for(int i = 0; i < 3; i++){
        cout << courseDays[i] << " ";
    }
    cout << "\t";
    if(degree == SECURITY){
        cout << "SECURITY";
    }
    else if (degree == NETWORK){
        cout << "NETWORK";
    }
    else if (degree == SOFTWARE){
        cout << "SOFTWARE";
    }
    else{
        cout << "ERROR";
    }
    cout << endl;
    
}
