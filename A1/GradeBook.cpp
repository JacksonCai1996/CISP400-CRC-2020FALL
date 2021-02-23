// GradeBook.cpp
// GradeBook member-function definitions. This file contains
// implementations of the member functions prototyped in GradeBook.h.
#include <iostream>
#include "GradeBook.h" // include definition of class GradeBook
using namespace std;

// constructor initializes courseName with string supplied as argument
GradeBook::GradeBook( string course, string instructor )
{                                                                      
    courseName = course;  // member initializer to initialize courseName 
    instructorName = instructor; // member initializer to initialize instructorName
    cout << "\n\n *Create a GradeBook Object*\n\n"; // display a message
} // end GradeBook constructor

// function to set the course name
void GradeBook::setCourseName( string course)
{
   courseName = course; // store the course name in the object
} // end function setCourseName

// function to get the course name
string GradeBook::getCourseName() const
{
   return courseName; // return object's courseName
} // end function getCourseName

// function to set the instructor name
void GradeBook::setInstructorName(string instructor)
{
    instructorName = instructor; // store the instructor name in the object
} // end function setInstructorName

// function to get the instructor name
string GradeBook::getInstructorName() const
{
    return instructorName; // return object's instructorName
} // end function getInstructorName


// display a welcome message to the GradeBook user
void GradeBook::displayMessage() const
{
   // call getCourseName and getInstructorName to get the courseName and instructorName
   cout << "  Welcome to the grade book for\n   " << getCourseName() 
      << "!" << endl;
   cout << "  This course is presented by: " << getInstructorName() << endl << endl;
} // end function displayMessage
