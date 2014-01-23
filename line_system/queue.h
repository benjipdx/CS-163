/* BENJAMIN REICHERT, CS163
ASSIGNMENT: #2
PURPOSE: A program to organize lines at an amusement park or other location that uses lines.
		 It also has implementations for two lines, one with a fast pass system, where the 
		 person in line does not have to wait in the regular line, but rather they have to 
		 wait in the priority line, and from there they can bypass the regular line. The other
		 line is just a regular line system, the person gets in line, and eventually they will
		 be allowed out of the line once it is their turn. 

*/
#include <cstring>
#include <cctype>
#include <iostream> 
using namespace std;

struct rider{

	char * name; //dynamically allocated array of chars for person name
	int age; //age of the person in line
	int cell; //cell phone number of person in line
	rider * next; ////pointer to next node in cll

};

class queue{

	public:
		//these are for the regular list
		queue(); //default constructor
		~queue(); //default deconstructor
		void reg_display_all(void); //displays all poeople in line for the regular line
		void reg_peek(); //peeks at the first person in line for the regular list
		bool reg_enqueue(char new_name[], int new_age, int new_cell); //places a new person in the regular list and their contact info
		bool reg_dequeue(); //remove someone from the regular list that is next in line
		//for fast line queue
		void fast_display_all(void); //displays all of the people in the fast pass line
		void fast_peek(); //displays the next perosn in line in the fast pass list
		bool fast_enqueue(char new_name[], int new_age, int new_cell); //adds a person to the fast pass line and their contact info
		bool fast_dequeue(); //removes someone from the fast pass list that is next in line

	private:
		rider * regular_line; //head pointer for regular line
		rider * fastpass_line; //head pointer for fast pass line

};
