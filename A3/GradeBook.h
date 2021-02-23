#ifndef GRADEBOOK_H
#define GRADEBOOK_H
//  GradeBook.h
// GradeBook class definition that counts letter grades.
// Member functions are defined in GradeBook.cpp
#include <string> // program uses C++ standard string class

// GradeBook class definition
class GradeBook
{
public:
   explicit GradeBook( std::string ); // initialize course name
   ~GradeBook();
   void setCourseName( std::string ); // set the course name
   std::string getCourseName() const; // retrieve the course name
   void displayMessage() const; // display a welcome message
   void displayGradeReport();  // display report based on user input
   void inputGrades(); // input arbitrary number of grades from user
   void displayInputs();  
   void initializeData();
   double calculateGrade();

private:
   std::string courseName; // course name for this GradeBook
   char letterGrades[100];
   int countGrades[6];
}; // end class GradeBook  

#endif // !GRADEBOOK_H