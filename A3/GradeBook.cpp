// GradeBook.cpp
// Member-function definitions for class GradeBook that
// uses a switch statement to count A, B, C, D and F grades.
#include <iostream>
#include <iomanip>
#include "GradeBook.h" // include definition of class GradeBook
using namespace std;

// constructor initializes courseName with string supplied as argument;
// initializes counter data members to 0
GradeBook::GradeBook( string name )
{
    cout << "The Grade Book Constructor is called\n";
    initializeData();
    setCourseName( name );
    displayMessage();
    cout << "The Grade Book, " << getCourseName() << ", contains\n" << endl;
    displayGradeReport();
    cout << "\n*****The end of Grade Book Constructor.*****\n\n" << endl;;

} // end GradeBook constructor

// function to set the course name; limits name to 25 or fewer characters
void GradeBook::setCourseName( string name )
{
   if ( name.size() <= 30 ) // if name has 30 or fewer characters
      courseName = name; // store the course name in the object
   else // if name is longer than 30 characters
   { // set courseName to first 30 characters of parameter name
      courseName = name.substr( 0, 30 ); // select first 30 characters
      cerr << "        Name: \"" << name << "\"\n        exceeds maximum length (30).\n"
         << "\n        Limiting courseName to first 30 characters.\n" << endl;
   } // end if...else
} // end function setCourseName

// function to retrieve the course name
string GradeBook::getCourseName() const
{
   return courseName;
} // end function getCourseName

// display a welcome message to the GradeBook user
void GradeBook::displayMessage() const
{
   // this statement calls getCourseName to get the 
   // name of the course this GradeBook represents
   cout << "        Welcome to the grade book for\n        " 
       << getCourseName() << "!\n" << endl;
} // end function displayMessage

void GradeBook::initializeData()
{
    courseName = "";

    for (int i = 0; i < 100; i++)
        letterGrades[i] = '\0';

    for (int i = 0; i < 6; i++)
        countGrades[i] = 0;
}




// display a report based on the grades entered by user
void GradeBook::displayGradeReport()
{
    int data = 0;
    int grades = 0;
    for (int i = 0; i < 5; i++)
        grades += countGrades[i];
    data = grades + countGrades[5];

    cout << "\nThe total number of data entered is " << data;
    cout << "\nThe total number of students receive grades is " << grades;
    cout << "\nNumber of students who received reach letter grade:";
    cout << "\nA:       " << countGrades[0];
    cout << "\nB:       " << countGrades[1];
    cout << "\nC:       " << countGrades[2];
    cout << "\nD:       " << countGrades[3];
    cout << "\nF:       " << countGrades[4];
    cout << "\nError:   " << countGrades[5];

    cout << setprecision(1) << fixed;
    cout << "\n\nThe class average is: " << calculateGrade() << endl;
} // end function displayGradeReport


double GradeBook::calculateGrade()
{
    
    
    int grades = (countGrades[0] * 4) + (countGrades[1] * 3) + (countGrades[2] * 2) + (countGrades[3] * 1);
    
    int data = countGrades[0] + countGrades[1] + countGrades[2] + countGrades[3] + countGrades[4];

    if (grades == 0)
        return 0;
    else
        return grades / static_cast<double>(data);

}

  
 // input arbitrary number of grades from user; update grade counter
void GradeBook::inputGrades() 
{   
    cout << "        Enter the letter grades." << endl
       << "        Enter the EOF character to end input." << endl
       << "        (Use Ctl + D, or Ctl + Z)" << endl;
   
   int i = 0;
   
   // loop until user types end-of-file key sequence
   while(((letterGrades[i] = cin.get()) != EOF) && (i < 100))
   {   
       // determine which grade was entered
      switch (letterGrades[i]) // switch statement nested in while
      {      
         case 'A': // grade was uppercase A
         case 'a': // or lowercase a
            ++countGrades[0]; // increment aCount
            letterGrades[i] = 'A';
            i++;
            break; // necessary to exit switch

         case 'B': // grade was uppercase B
         case 'b': // or lowercase b
             ++countGrades[1]; // increment bCount 
             letterGrades[i] = 'B';
             i++;
            break; // exit switch

         case 'C': // grade was uppercase C
         case 'c': // or lowercase c
             ++countGrades[2]; // increment cCount
             letterGrades[i] = 'C'; 
             i++;
            break; // exit switch

         case 'D': // grade was uppercase D
         case 'd': // or lowercase d
             ++countGrades[3]; // increment dCount 
             letterGrades[i] = 'D';
             i++;
            break; // exit switch

         case 'F': // grade was uppercase F
         case 'f': // or lowercase f
             ++countGrades[4]; // increment fCount   
             letterGrades[i] = 'F';
             break; // exit switch

         case '\n': // ignore newlines,  
         case '\t': // tabs, 
         case ' ': // and spaces in input
             continue;

         default: // catch all other characters 
            ++countGrades[5];   
            cout << "        XXXX An incorrect letter grade entered.  XXXX" << endl
                << "        \"" << letterGrades[i] << "\" is not a proper letter grade.\n";
            i++;
            break; // optional; will exit switch anyway

      } // end switch

      cout << "\n        Enter the letter grades." << endl
          << "        -->     Or Enter the EOF character to end input." << endl
          << "        (Use Ctl + D, or Ctl + Z)" << endl;
      
   } // end while
} // end function inputGrades


void GradeBook::displayInputs()
{
    cout << "The data entered is listed at the following:\n";
    for (int i = 0; (letterGrades[i] != EOF) && (i < 100); i++)
    {
        cout << "[" << i << "] -> " << letterGrades[i] << "\t";
        if ((i + 1) % 4 == 0)
            cout << endl;
    }
    cout << endl;
}

GradeBook::~GradeBook()
{
    cout << "\n\nDestructor is called\n\n";
}
