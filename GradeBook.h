#include <string>
using namespace std;

class GradeBook
{
	public: 
        //constructor
        GradeBook(string); 
        //set the course name
		void setCourseName (string);
        //retreive the course name
		string getCourseName();
        //display the message
        void displayMessage();
        //does not return anything, no input, no output, no argument
        void determineClassAverage();
    private:
        string courseName;
};