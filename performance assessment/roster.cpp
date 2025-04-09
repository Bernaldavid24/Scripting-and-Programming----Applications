#include "roster.h"
#include <iostream>
#include <string>

// constructor, creates an empty roster
Roster::Roster() {
    // set all array elements to nullptr
    for (int i = 0; i < 5; i++) {
        classRosterArray[i] = nullptr;
    }
    // start with no students, so the lastIndex is -1
    lastIndex = -1;
}

// this function splits the comma separated student data
void Roster::parse(string studentData) {
    // find where each comma is located
    int pos = studentData.find(",");
    string studentID = studentData.substr(0, pos);
    
    // get first name between the 1st and 2nd commas
    int start = pos + 1; // start after the comma
    pos = studentData.find(",", start); // find the next comma
    string firstName = studentData.substr(start, pos - start);
    
    // get last name between the 2nd and 3rd commas
    start = pos + 1;
    pos = studentData.find(",", start);
    string lastName = studentData.substr(start, pos - start);
    
    // get email between the 3rd and 4th commas
    start = pos + 1;
    pos = studentData.find(",", start);
    string emailAddress = studentData.substr(start, pos - start);
    
    // get age between the 4th and 5th commas
    start = pos + 1;
    pos = studentData.find(",", start);
    int age = stoi(studentData.substr(start, pos - start));
    
    // get days for the first course between the 5th and 6th commas
    start = pos + 1;
    pos = studentData.find(",", start);
    int days1 = stoi(studentData.substr(start, pos - start));
    
    // get days for the second course between the 6th and 7th commas
    start = pos + 1;
    pos = studentData.find(",", start);
    int days2 = stoi(studentData.substr(start, pos - start));
    
    // get days for the third course between the 7th and 8th commas
    start = pos + 1;
    pos = studentData.find(",", start);
    int days3 = stoi(studentData.substr(start, pos - start));
    
    // the last part is the degree program, which is everything after the last comma
    start = pos + 1;
    string degreeStr = studentData.substr(start);
    
    // convert the degree string to the enum value
    DegreeProgram degreeProgram;
    if (degreeStr == "SECURITY") {
        degreeProgram = SECURITY;
    }
    else if (degreeStr == "NETWORK") {
        degreeProgram = NETWORK;
    }
    else if (degreeStr == "SOFTWARE") {
        degreeProgram = SOFTWARE;
    }
    
    // finally add the student to the roster
    add(studentID, firstName, lastName, emailAddress, age,
        days1, days2, days3, degreeProgram);
}

// add a student to the roster
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, 
                 int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, 
                 DegreeProgram degreeProgram) {
    
    // increment lastIndex, this is where the new student goes
    lastIndex++;
    
    // create a new student with the given info
    classRosterArray[lastIndex] = new Student(studentID, firstName, lastName, emailAddress,
                                             age, daysInCourse1, daysInCourse2, daysInCourse3,
                                             degreeProgram);
}

// remove a student from the roster
void Roster::remove(string studentID) {
    // flag to check if the student was found
    bool found = false;
    
    // loop through all the students in the array
    for (int i = 0; i <= lastIndex; i++) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID) {
            // found the student, now delete them
            delete classRosterArray[i];
            classRosterArray[i] = nullptr;
            
            // need to shift the other students up
            for (int j = i; j < lastIndex; j++) {
                classRosterArray[j] = classRosterArray[j + 1];
            }
            classRosterArray[lastIndex] = nullptr;
            
            // there is one less student now
            lastIndex--;
            found = true;
            cout << "Student " << studentID << " was removed." << endl;
            break; // exit the loop
        }
    }
    
    // if the student wasn't found
    if (!found) {
        cout << "Error: Student with ID " << studentID << " was not found." << endl;
    }
}

// print all students in the roster
void Roster::printAll() {
    cout << "All students:" << endl;
    
    // loop through and print each student
    for (int i = 0; i <= lastIndex; i++) {
        if (classRosterArray[i] != nullptr) {
            classRosterArray[i]->print();
        }
    }
    cout << endl;
}

// calculate and print the average days in course
void Roster::printAverageDaysInCourse(string studentID) {
    // loop to find the student
    bool found = false;
    
    for (int i = 0; i <= lastIndex; i++) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == studentID) {
            found = true;
            
            // get the array of days
            int* days = classRosterArray[i]->getDaysInCourse();
            
            // calculate the average
            float average = (days[0] + days[1] + days[2]) / 3.0;
            
            cout << "Student ID: " << studentID;
            cout << ", average days in course: " << average << endl;
            break;
        }
    }
    
    if (!found) {
        cout << "Student with ID " << studentID << " not found." << endl;
    }
}

// check to see if the emails are valid
void Roster::printInvalidEmails() {
    cout << "Invalid emails:" << endl;
    bool foundInvalid = false;
    
    // check each student's email
    for (int i = 0; i <= lastIndex; i++) {
        if (classRosterArray[i] != nullptr) {
            string email = classRosterArray[i]->getEmailAddress();
            
            // check for a space
            bool hasSpace = (email.find(' ') != string::npos);
            
            // check for the @ symbol
            bool hasAtSign = (email.find('@') != string::npos);
            
            // check for a . after the @ symbol
            bool hasPeriod = false;
            if (hasAtSign) {
                int atPos = email.find('@');
                hasPeriod = (email.find('.', atPos) != string::npos);
            }
            
            // if any check fails, the email is invalid
            if (hasSpace || !hasAtSign || !hasPeriod) {
                cout << email << " - " << classRosterArray[i]->getStudentID() << endl;
                foundInvalid = true;
            }
        }
    }
    
    if (!foundInvalid) {
        cout << "No invalid emails found." << endl;
    }
    cout << endl;
}

// print the students in a specific degree program
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    cout << "Students in degree program: " << degreeProgramStrings[degreeProgram] << endl;
    bool found = false;
    
    // check each student
    for (int i = 0; i <= lastIndex; i++) {
        if (classRosterArray[i] != nullptr && classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
            found = true;
        }
    }
    
    if (!found) {
        cout << "No students found in this program." << endl;
    }
    cout << endl;
}

// destructor - need to delete all the students
Roster::~Roster() {
    cout << "Freeing memory..." << endl;
    
    // delete each student we created
    for (int i = 0; i < 5; i++) {
        if (classRosterArray[i] != nullptr) {
            delete classRosterArray[i];
            classRosterArray[i] = nullptr;
        }
    }
    
    cout << "Memory freed. Roster destroyed." << endl;
}