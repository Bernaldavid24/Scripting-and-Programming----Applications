#pragma once
#include "student.h"

// this class manages all the students
class Roster {
private:
    // array of pointers to hold 5 students
    Student* classRosterArray[5]; 

    // keep track of how many students we have, starts at -1 when empty
    int lastIndex;
    
public:
    // constructor and destructor
    Roster(); // creates and empty roster
    ~Roster(); // this one prevents memory leaks
    
    // functions needed to implement
    void add(string studentID, string firstName, string lastName, string emailAddress, 
             int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, 
             DegreeProgram degreeProgram);
    void remove(string studentID); //removes a student if they exist
    void printAll(); // shows all students
    void printAverageDaysInCourse(string studentID); // calculates average days
    void printInvalidEmails(); // checks for email formatting problems
    void printByDegreeProgram(DegreeProgram degreeProgram); // filters by program
    
    // function to split the student data string into parts
    void parse(string studentData);
};