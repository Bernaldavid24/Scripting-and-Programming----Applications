// studnet.h - student class definition
#pragma once
#include <string>
#include <iostream>
#include "degree.h"

using namespace std;

class Student {
private:
    // student fields - all the data we need to track
    string studentID; // A1, A2, etc.
    string firstName; // first names
    string lastName; // last names
    string emailAddress; // email addresses, which some contain errors
    int age; // student age in years
    int daysInCourse[3]; // days to complete 3 courses
    DegreeProgram degreeProgram; // students degree program

public:
    // constructors - one is empty and the other holds the params
    Student(); // empty/default one
    Student(string studentID, string firstName, string lastName, string emailAddress, 
            int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, 
            DegreeProgram degreeProgram); // all params
    
    // destructor
    ~Student();

    // getters - tried to keep these on single lines
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    int getAge();
    int* getDaysInCourse(); // returns point to the array
    DegreeProgram getDegreeProgram();

    // setters - also on single lines
    void setStudentID(string studentID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmailAddress(string emailAddress);
    void setAge(int age);
    void setDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3);
    void setDegreeProgram(DegreeProgram degreeProgram);

    // print - displays student info
    void print();
};