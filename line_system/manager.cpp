/* BENJAMIN REICHERT, CS163
ASSIGNMENT: #2
PURPOSE: A program to organize lines at an amusement park or other location that uses lines.
		 It also has implementations for two lines, one with a fast pass system, where the 
		 person in line does not have to wait in the regular line, but rather they have to 
		 wait in the priority line, and from there they can bypass the regular line. The other
		 line is just a regular line system, the person gets in line, and eventually they will
		 be allowed out of the line once it is their turn. 

*/

#include "manager.h"

//default constructor
manager::manager(){
	head = NULL;
}

//default desctructor
manager::~manager(){

if(head){ //iterate through list, destroying as we go
	node * current = head;
	node * previous = head;
	while(current -> next){
		previous = current;
		current = current -> next;
		delete [] previous -> rides; //deallocate dynamic array 
		delete previous;
	}
	//on last node, deal with it
	delete [] current -> rides; //deallocate dynamic mem
	delete current;
	head = NULL; 
}

}


//allocates nodes so that people can be added to a ride without worrying about if there are nodes made yet
bool manager::add_ride(int ride_number){
	if(!head){
		head = new node;
		head -> rides = new queue[MAX]; //if we don't have a head, then make one

		int trav = ride_number / MAX;

		node * current = head;
		for(int i = 0; i < trav; i++){ //traverse until we are on the node we want
			if(current -> next == NULL){
				node * temp = new node; //if it doesn't exist, make it
				temp -> rides = new queue[MAX];
				temp -> next = NULL;
				current -> next = temp;
				current = current -> next;
			}
			else if(current -> next){
				current = current -> next;
			}

		}
		return true;
	}
	else if(head){
		int trav = ride_number / MAX;
		node * current = head;
		for(int i = 0; i < trav; i++){ //traverse until we are on the node we want
			if(current -> next == NULL){
				node * temp = new node; //if it doesn't exist, make it
				temp -> rides = new queue[MAX];
				temp -> next = NULL;
				current -> next = temp;
				current = current -> next;
			}
			else if(current -> next){ //if does exist, simply traverse to next node
				current = current -> next;
			} 
	}
	}

	else
		return false;
}

//ASSUMES THEY CALL ADD RIDE FIRST, or else it will traverse into memory that may not be the programs
void manager::display_line(int ride_number, int line_type){
	if(!head){
		//do nothing, there is nothign to display
	}
	else if(head){
		//traverse to the right node
		node * current = head;
		int trav = ride_number / MAX;
		int index = ride_number % MAX;
		for(int i = 0; i < trav; i++){
			current = current -> next;
		}
		if(line_type == 0){ //determine which functino to call based on line type
		current -> rides[index].reg_display_all();
		}
		else if(line_type == 1){
		current -> rides[index].fast_display_all();
		}
	}
}

//peek at the next person up in line
void manager::see_next(int ride_number, int line_type){
	if(!head){
	//do nothing, ther is nothign to see here, move along
	}
	else if(head){
		//traverse to the right node
		node * current = head;
		int trav = ride_number / MAX; //determine how many nodes to traverse
		int index = ride_number % MAX; //determien dhte index on that node
		for(int i = 0; i < trav; i++){
			current = current -> next; //traverse
		}
		if(line_type == 0){
		current -> rides[index].reg_peek(); //determine which functino to call based on pass type
		}
		else if(line_type == 1){
		current -> rides[index].fast_peek();
		}
	}
}

//this function adds a person and all of their contact into to a line
bool manager::add_line(int ride_number, int line_type, char new_name[], int new_age, int new_cell){
	if(!head){
	return false; //nothitng to display, consider checking if there was a ride added 
	}
	else if(head){
		//traverse to the right node
		node * current = head;
		int trav = ride_number / MAX;
		int index = ride_number % MAX;
		for(int i = 0; i < trav; i++){
			current = current -> next;
		}
		if(line_type == 0){
		current -> rides[index].reg_enqueue(new_name, new_age, new_cell); //call the right function based on line type
		}
		else if(line_type == 1){
		current -> rides[index].fast_enqueue(new_name, new_age, new_cell);
		}
	return true;
	}

}

//this functino removes the next perosn in line from the line
bool manager::remove_line(int ride_number, int line_type){
	if(!head){
	return false; //nothitng to display, consider checking if there was a ride added 
	}
	else if(head){
		//traverse to the right node
		node * current = head;
		int trav = ride_number / MAX; //determine which node the ride is on
		int index = ride_number % MAX; //determine which index on that node that is
		for(int i = 0; i < trav; i++){ //traverse
			current = current -> next; 
		}
		if(line_type == 0){
		current -> rides[index].reg_dequeue(); // call the appropriate functino based on line_type
		}
		else if(line_type == 1){
		current -> rides[index].fast_dequeue();
		}
	return true;
	}
}


