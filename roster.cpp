#include <iostream>
#include <string>
#include "roster.h"
#include "student.h"
using namespace std;

//Class constructor
Roster::Roster(int classSize){
    this -> classSize = classSize;
    this -> index = 0;
    for(int i = 0; i < classSize; i++){
        this-> classRosterArray[i] = new Student;
    }
}

//Add method
void Roster::add(int age, string studentID, string fName, string lName, string email, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degree){
    
    int courseDays[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
    
    classRosterArray[classSize] = new Student(age, studentID, fName, lName, email, courseDays, daysInCourse1, daysInCourse2, daysInCourse3, degree);
}

//Parse method
void Roster::parse(string studentData){
    int daysInCourse1, daysInCourse2, daysInCourse3;
    
    if(index < classSize){
        classRosterArray[index] = new Student();
        
        int i = studentData.find(",");
        classRosterArray[index]->setStudentID(studentData.substr(0 , i));
        
        int k = i + 1;
        i = studentData.find(",", k);
        classRosterArray[index]-> setFName(studentData.substr(k, i-k));
        
        k = i + 1;
        i = studentData.find(",", k);
        classRosterArray[index]-> setLName(studentData.substr(k, i-k));
        
        k = i + 1;
        i = studentData.find(",", k);
        classRosterArray[index]-> setEmail(studentData.substr(k, i-k));
        
        k = i + 1;
        i = studentData.find(",", k);
        classRosterArray[index]-> setAge(stoi(studentData.substr(k, i-k)));
        
        k = i + 1;
        i = studentData.find(",", k);
        daysInCourse1 = stoi(studentData.substr(k, i-k));
        
        k = i + 1;
        i = studentData.find(",", k);
        daysInCourse2 = stoi(studentData.substr(k, i-k));
        
        k = i + 1;
        i = studentData.find(",", k);
        daysInCourse3 = stoi(studentData.substr(k, i-k));
        classRosterArray[index]-> setCourseDays(daysInCourse1, daysInCourse2, daysInCourse3);
        
        k = i + 1;
        i = studentData.find(",", k);
        string major = studentData.substr(k, i-k);
        if (major == "NETWORK") {
            classRosterArray[index]->setDegree(NETWORK);
        }
        else if (major == "SECURITY") {
            classRosterArray[index]->setDegree(SECURITY);
        }
        else if (major == "SOFTWARE") {
            classRosterArray[index]->setDegree(SOFTWARE);
        }
        else {
            cout << "DEGREE PROGRAM NOT FOUND" << endl;
        }
        index++;
    }
    return;
}

//Remove method
void Roster::remove(string studentID){
    for(int i = 0; i < classSize; i++){
        if(classRosterArray[i] == nullptr){
            cout << "\nERROR! Student " << studentID << " not found. \n" << endl;
        }
        else if (studentID == classRosterArray[i]-> getStudentID()){
            classRosterArray[i] = nullptr;
            cout << "\nStudent " << studentID << " has been removed. \n" << endl;
            break;
        }
    }
}

//Print all method
void Roster::printAll(){
    cout << "Students enrolled: " << endl;
    for(int i = 0; i < classSize; i++){
        if(classRosterArray[i] == nullptr){
            continue;
        }
        else{
            classRosterArray[i]->print();
        }
    }
}

//Average days in course method
void Roster::printAverageDaysInCourse(string studentID){
    for(int i = 0; i < classSize; i++){
        
        if(studentID == classRosterArray[i] -> getStudentID()){
            cout << "Student " << studentID << ": " <<(classRosterArray[i]->getCourseDays()[0] + classRosterArray[i]->getCourseDays()[1] + classRosterArray[i]->getCourseDays()[2]) / 3 << endl;
        }
        else{
            continue;
        }
    }
    return;
}

//Invalid emails method
void Roster::printInvalidEmails(){
    for(int i = 0; i < classSize; i++){
        string email = classRosterArray[i] -> getEmail();
        if((email.find('@') == string::npos) || (email.find(' ') != string::npos) || (email.find('.') == string::npos)){
            cout<< "Student " << classRosterArray[i]->getStudentID() << ": " << email << endl;
        }
        else{
            continue;
        }
    }
    return;
}

//Print by degree program method
void Roster::printByDegreeProgram(DegreeProgram degree){
    for(int i = 0; i < classSize; i++){
        if(classRosterArray[i]->getDegree() == degree){
            classRosterArray[i]->print();
        }
        else{
            continue;
        }
    }
    return;
}


//Deconstructor
Roster::~Roster(){
    for(int i = 0; i < 5; i++){
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}
