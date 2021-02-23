// GradeBook.h
// GradeBook class definition. This file presents GradeBook's public 
// interface without revealing the implementations of GradeBook's member
// functions, which are defined in GradeBook.cpp.
#include <string> // class GradeBook uses C++ standard string class

// GradeBook class definition
class GradeBook
{
public:
	// constructor initialize courseName and instructorName
	explicit GradeBook(std::string, std::string ); 
   void setCourseName( std::string ); // sets the course name
   std::string getCourseName() const; // gets the course name
   void setInstructorName(std::string); // sets the instructor name
   std::string getInstructorName() const;// gets the instructor name
   void displayMessage() const; // displays a welcome message
private:
   std::string courseName; // course name for this GradeBook
   std::string instructorName;
}; // end class GradeBook  


