/* BENJAMIN REICHERT, CS163
ASSIGNMENT: #2
PURPOSE: A program to organize lines at an amusement park or other location that uses lines.
		 It also has implementations for two lines, one with a fast pass system, where the 
		 person in line does not have to wait in the regular line, but rather they have to 
		 wait in the priority line, and from there they can bypass the regular line. The other
		 line is just a regular line system, the person gets in line, and eventually they will
		 be allowed out of the line once it is their turn. 

*/

#include "queue.h"

const int MAX = 5; //constant size of the ride array ineach node, this can be changed to any value

struct node{
	queue * rides; //dynamically allocated array of queues
	node * next; //next pointer
};
//this class manages the queue data structure through a flexible array
class manager{

	public: 
		manager(); //default constructor
		~manager(); //default deconstructor
		//it is up to the user to know which rides are which number, this is not done in the data stucture
		//for example, if they wanted to know the lines for fiery red dragon, they would have to know that 
		//fiery red dragon is ride number 2
		bool add_ride(int ride_number);
		//displays the line of the ride that is requested and its line type
		void display_line(int ride_number, int line_type); //line_type is 0 for regular line and 1 for fast pass line system
		//displays the next person in line and their contact information
		void see_next(int ride_number, int line_type); //see who is next in line for a particular ride
		//adds a person to a line and all of their contact info
		bool add_line(int ride_number, int line_type, char new_name[], int new_age, int new_cell); //put someone in line
		//removes the next perosn in line from the line for a specific ride
		bool remove_line(int ride_number, int line_type); //remove the next person from line, like for when their turn is ready for a ride

	private:
		node * head; //pointer to the first node

};
