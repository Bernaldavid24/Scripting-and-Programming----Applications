#include "student.h"

// default constructor - sets everything to empty or zero
Student::Student() {
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = 0;
    
    // initialize days array
    for (int i = 0; i < 3; i++) {
        this->daysInCourse[i] = 0;
    }
    
    // default to SOFTWARE program
    this->degreeProgram = SOFTWARE;
}

// constructor with parameters
Student::Student(string studentID, string firstName, string lastName, string emailAddress, 
                int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, 
                DegreeProgram degreeProgram) {
    
    // set all the values
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    
    // put the course days into the array one by one
    this->daysInCourse[0] = daysInCourse1;
    this->daysInCourse[1] = daysInCourse2;
    this->daysInCourse[2] = daysInCourse3;
    
    this->degreeProgram = degreeProgram;
}

// destructor - doesn't need to do anything
Student::~Student() { // nothing to destroy since we don't use new in this class
}

// getter implementations
// just return the value of each variable

string Student::getStudentID() { 
    return this->studentID; 
}

string Student::getFirstName() { 
    return this->firstName; 
}

string Student::getLastName() { 
    return this->lastName; 
}

string Student::getEmailAddress() { 
    return this->emailAddress; 
}

int Student::getAge() { 
    return this->age; 
}

//this one returns a pointer and lets us access the whole array
int* Student::getDaysInCourse() { 
    return this->daysInCourse; 
}

DegreeProgram Student::getDegreeProgram() { 
    return this->degreeProgram; 
}

// setter, just set each variable to what was passed in
void Student::setStudentID(string studentID) { 
    this->studentID = studentID; 
}

void Student::setFirstName(string firstName) { 
    this->firstName = firstName; 
}

void Student::setLastName(string lastName) { 
    this->lastName = lastName; 
}

void Student::setEmailAddress(string emailAddress) { 
    this->emailAddress = emailAddress; 
}

void Student::setAge(int age) { 
    // check if age is valid
    this->age = age; 
}

void Student::setDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3) {
    // set all three courses at once
    this->daysInCourse[0] = daysInCourse1;
    this->daysInCourse[1] = daysInCourse2;
    this->daysInCourse[2] = daysInCourse3;
}

void Student::setDegreeProgram(DegreeProgram degreeProgram) { 
    this->degreeProgram = degreeProgram; 
}

// print student info according to required format
void Student::print() {
    cout << this->studentID << "\t";
    cout << "First Name: " << this->firstName << "\t";
    cout << "Last Name: " << this->lastName << "\t";
    cout << "Email: " << this->emailAddress << "\t";
    cout << "Age: " << this->age << "\t";
    cout << "daysInCourse: {" << this->daysInCourse[0] << ", " 
         << this->daysInCourse[1] << ", " 
         << this->daysInCourse[2] << "} ";
    cout << "Degree Program: " << degreeProgramStrings[this->degreeProgram] << endl;
}