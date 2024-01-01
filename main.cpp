#include <iostream>
#include <string>
#include <array>
#include "roster.h"
#include "student.h"
#include "degree.h"

using namespace std;

int main(){
    
    cout << "C867 Scripting & Programming: Applications" << endl;
    cout << "Language: C++" << endl;
    cout << "Student ID: 011249069" << endl;
    cout << "Name: Jin Hee Choe\n"<< endl;
    
    const string studentData[] = 
    {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Choe,Jin Hee,jchoe10@wgu.edu,19,14,21,16,SOFTWARE"
    };
    
    //Instance of the Roster class.
    Roster* classRoster = new Roster(5);
    
    //Parsing the information in studentData and adding it to the classRosterArray.
    for(int i = 0; i < 5; i++){
        classRoster->parse(studentData[i]);
    }
    
    //Printing all the students.
    classRoster->printAll();
    
    //Displaying invalid emails.
    cout << "\nInvalid Emails: " << endl;
    classRoster->printInvalidEmails();
    
    //Displaying the average days.
    cout << "\nStudent's average days to complete a course: " << endl;
    for(int i = 0; i < 5; i++){
        classRoster->printAverageDaysInCourse(classRoster->classRosterArray[i]->getStudentID());
    }
    //Displaying the software students enrolled.
    cout << "\nSoftware Students: " << endl;
    classRoster->printByDegreeProgram(SOFTWARE);
    
    //Removing student A3.
    classRoster-> remove("A3");
    
    //Printing the students to show A3 has been successfully removed.
    classRoster->printAll();
    
    //Trying to remove student A3 again.
    classRoster-> remove("A3");
    
}
