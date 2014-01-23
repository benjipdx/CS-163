/* Benjamin Reichert
CS163 Assignment #1
4/18/13

Purpose: create a ticket ordering system through an Abstract Data Type, in this case,
Linear Linked Lists. this is ticket.h and it is the header file for the implementation.cpp file

*/


#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;


struct section
{
	int section_number; //stores a unique number for the section
	int total_seats; //holds the total number of seats in a section
	int seats_available; //holds the seats that have not been reserved (total - reserved = available)
	//levels of seat class (best and worst) are on an integer basis set by the creator
	//of the sections, 1 being the best (and most expensive) seats and higher numbers
	//are cheaper, but not so great seats
	int seat_class; //^
	int price; //holds the cost per seat as an integer
	section * next; //the pointer to the next item in the LLL

};

class list
{
	public:
		list(void); //default constructor, sets head pointers to NULL
		~list(void); //default deconstructor, iterates through each LLL, (there are 4, as shown by the private data pointers) and 
		//destroys all of the dynamic memory and sets the pointers to NULL
		int add(int section_num, int seats, int seat_class, int price); //adds a new section to the list of sections
		//does NOT keep the user from entering many seating sections with the same section number, since it is easy to delete
		//them with the remove() function. takes in all data necessary to build a struct and attach it to the dynamic list
		//returns 0 if error occured, and 1 if the item was successfully added
		int remove(int section_num); //this functions iterates through the list and upon a match specified through section_num, 
		//it removes the item from the list and correctly reattacheds the list togther for seamless integration
		//returns 0 if error occured, and 1 if the item was successfully removed
		int reserve_seat(int section_num); //this function allows the user to reserve a seat through general admission, it simply finds
		//the correct seating area and deducts one seat from the seats available total. 
		//returns 0 if error occured, and 1 if the seat was successfully reserved
		int check_available_seats(int section_num); //returns seats available in section as integer
		//takes as an argument a desired section and goes through the data and returns the amount of available seats in the 
		//section as an integer
		void display_all(void);
		//display_all iterates through the data and ouputs is as it goes, this is for the master list, the one things get added to
		//and is designated by the pointer head. does not return any values since it provides standard out feedback
		void display_section(int section_num);
		//displays the information about a specific section passed in as an argument. does not provide return values as it outputs
		//data to standar out
		void display_by_cost(void); 
		//diplays the data from the order_cost list. This requires that data be put in this list, using the appropriate organize function
		//first, or else it will not have any data in it from the original master head list.
		void display_by_section(void); 
		//diplays the data from the order_section list. This requires that data be put in this list, using the appropriate organize function
		//first, or else it will not have any data in it from the original master head list.
		void display_by_best_seats(void); 
		//diplays the data from the order_best_seats list. This requires that data be put in this list, using the appropriate organize function
		//first, or else it will not have any data in it from the original master head list.
		int organize_cost(void);
		//the organize functions should only be called once after all the data from the sections has been added with the add function. 
		//if this is not followed, there will be duplicate entries of the data from the master head since this function reads it and stores
		//it and does not delete its own data after it has been initialized. DO NOT CALL THIS FUNCTION MORE THAN ONCE unless you would like
		//all the data from head to also be duplicated twice in the organized lists.
		//these functions do not take in any arguments since they work with the private data structures directly
		//returns 0 if the list could not be organized and 1 if it was successful
		//organizes seating sections by cheapest to most expensive
		int organize_section(void);
		//the organize functions should only be called once after all the data from the sections has been added with the add function. 
		//if this is not followed, there will be duplicate entries of the data from the master head since this function reads it and stores
		//it and does not delete its own data after it has been initialized. DO NOT CALL THIS FUNCTION MORE THAN ONCE unless you would like
		//all the data from head to also be duplicated twice in the organized lists.
		//these functions do not take in any arguments since they work with the private data structures directly
		//returns 0 if the list could not be organized and 1 if it was successful
		//organizes seating sections section numbers from lowest to highest 
		int organize_seats(void); //organize by best seats
		//the organize functions should only be called once after all the data from the sections has been added with the add function. 
		//if this is not followed, there will be duplicate entries of the data from the master head since this function reads it and stores
		//it and does not delete its own data after it has been initialized. DO NOT CALL THIS FUNCTION MORE THAN ONCE unless you would like
		//all the data from head to also be duplicated twice in the organized lists.
		//these functions do not take in any arguments since they work with the private data structures directly
		//returns 0 if the list could not be organized and 1 if it was successful
		//organizes seating sections by best seats, this is on an integer scale
		//1 is the best type of seat, and as the number increases, the worse the seating is
		//this organizes data from the best (lowest number) seating to the worse (highest number)
		
	private:

		section * head; //the original, or master listing of seating, this is only organized in the order the data was entered. 
		section * order_cost; //seats ordered by cost from low to high in a separate list
		section * order_section; //pointer to the LLL for ordered seats from the lowest to highest section
		section * order_best_seats; //pointer to LLL section for the best to the worst seats in order

};
