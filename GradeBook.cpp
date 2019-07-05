#include <iostream>
#include <iomanip> //input output manipulation
#include "GradeBook.h"
using namespace std;

//constructor
GradeBook::GradeBook(string name) 
{
    setCourseName(name); //validate and store courseName
}

void GradeBook::setCourseName(string name) 
{
    if (name.length() <= 25) //if the name has 25 or fewer chars
        courseName = name; //store the course name in the object
    else //if name is longer than 25 chars
    {
        courseName = name.substr(0,25); //select first 25 chars
        cout << "Name \"" << name << "\"exceeds the maximum length(25).\n" << endl;
    }
}

//function to retreive the course name
string GradeBook::getCourseName()  
{
    return courseName;
}

void GradeBook::displayMessage()
{
    cout << "Welcome to the grade book for\n" << courseName << "!\n" << endl;
}

//determine the class average based on 10 grades entered by the user
void GradeBook::determineClassAverage()
{
    int total; //sum of grades entered by user
    int gradeCounter; //number of the grade to be entered next
    int grade; //grade value entered by user
    double average; //average of grades

    //initialization phase
    total = 0; //initialize total
    gradeCounter = 1; //initialize loop counter

    //processing phase
    cout << "Enter a grade or '-1' to quit: ";
    cin >> grade; //input grade or sentinel value
    while (grade != -1)
    {
        total = total + grade; //add grade to total
        gradeCounter = gradeCounter + 1; //increment counter

        //prompt for input and read next grade from user
        cout << "Enter a grade or '-1' to quit: ";
        cin >> grade; //input grade or sentinel value
    }
    
    //termination phase
    if (gradeCounter != 0) //if user entered at least one grade...
    {
        //calculate average of all grades entered
        average = static_cast<double>(total) / (gradeCounter - 1) ; //temporary float by static_cast

        //display total and average (with 2 digits precision)
        cout << "\nTotal of all " << gradeCounter - 1 << " grades entered is " << total << endl;
        cout << "Class average is " << setprecision(2) << fixed << average << endl;
    }
    else
    {
        cout << "No grades were entered" << endl;
    }
}

int main()
{
    //create GradeBook object myGradeBook and pass course name to constructor
    GradeBook myGradeBook("CS101 C++ Programming");
    myGradeBook.displayMessage(); //display welcome message
    myGradeBook.determineClassAverage();
}