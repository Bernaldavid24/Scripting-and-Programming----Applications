#include <iostream>
#include <string>
#include "roster.h"

using namespace std;

int main() {
    // print my info
    cout << "Course Title: Scripting and Programming - Applications" << endl;
    cout << "Programming Language: C++" << endl;
    cout << "WGU Student ID: ******" << endl;  // my ID placed here
    cout << "Name: David Bernal" << endl << endl;  // my info placed here
    
    // student data from the table with my info in the last entry
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,David,Bernal,dbern96@wgu.edu,27,25,30,35,SOFTWARE"  // my student email here
    };
    
    // create the roster
    Roster classRoster;
    
    // add each student to the roster
    for (int i = 0; i < 5; i++) {
        classRoster.parse(studentData[i]);
    }
    
    // do all the required function calls
    classRoster.printAll();
    
    classRoster.printInvalidEmails();
    
    // loop through each student ID
    for (int i = 0; i < 5; i++) {
        string studentID = "A" + to_string(i + 1);
        classRoster.printAverageDaysInCourse(studentID);
    }
    cout << endl;
    
    // print students in SOFTWARE program
    classRoster.printByDegreeProgram(SOFTWARE);
    
    // remove student A3
    classRoster.remove("A3");
    
    // print all students again
    classRoster.printAll();
    
    // try to remove A3 again - should show error
    classRoster.remove("A3");
    
    // destructor will be called automatically
    
    return 0;
}
