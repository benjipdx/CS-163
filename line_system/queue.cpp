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

queue::queue(){
	
	regular_line = NULL; //this is a pointer for the regular line
	fastpass_line = NULL; //pointer for the fast pass line

}
//default constructor
queue::~queue(){
	if(regular_line){
		rider * temp = regular_line -> next; //create a temp pointer
		while(temp != regular_line){
			regular_line -> next = temp -> next;
			delete [] temp -> name; //iterate through and delete the list
			delete temp;
			//since temp is still a pointer
			temp = regular_line -> next;
		}
		//on the last and final node
		delete [] regular_line -> name;
		delete regular_line;
		regular_line = NULL;

	}
	if(fastpass_line){
		rider * temp = fastpass_line -> next;
		while(temp != fastpass_line){
			fastpass_line -> next = temp -> next; //iterate through and delete the list
			delete [] temp -> name;
			delete temp;
			temp = fastpass_line -> next;
		}
		//on the last node of fastpass line
		delete [] fastpass_line -> name;
		delete fastpass_line;
		fastpass_line = NULL;
	}
}

//this function adds a node to the end of the queue with person contact information for the regular list`
bool queue::reg_enqueue(char new_name[], int new_age, int new_cell){

	//if there isn't anything in the queue yet
	if(!regular_line){
		regular_line = new rider;
		int temp_name_size = strlen(new_name);
		regular_line -> name = new char[temp_name_size];
		regular_line -> name = new_name;
		regular_line -> age = new_age;
		regular_line -> cell = new_cell;
		regular_line -> next = regular_line;

		return true;
	}	
	//if there already is items in the queue
	else if(regular_line){
		rider * temp = new rider;
		//populate the new node
		int temp_name_size = strlen(new_name);
		temp -> name = new char[temp_name_size];
		temp -> name = new_name;
		temp -> age = new_age;
		temp -> cell = new_cell;
		//now link up
		temp -> next = regular_line -> next;
		regular_line -> next = temp;
		regular_line = regular_line -> next;
		
		return true;
		}	
	else 
		return false;
}



//this function displays all the people in line for th regular list
void queue::reg_display_all(void){
	
	if(regular_line){
	
	//case for if there is only one node in the list
		if(regular_line -> next == regular_line){
			cout << "Rider's name: " <<regular_line -> name <<endl;
			cout << "Rider's age: " <<regular_line -> age <<endl;
			cout << "Rider's cell: " <<regular_line -> cell <<endl;
		
	//case if there are more than one nodes in the list
		}
		else if(regular_line -> next != regular_line){
			rider * current = regular_line -> next;
			//output the rest of the list
			while(current != regular_line){
				cout << "Rider's name: " <<current -> name <<endl;
				cout << "Rider's age: " <<current -> age <<endl;
				cout << "Rider's cell: " <<current -> cell <<endl <<endl;
				current = current -> next;
			}

			//output the regular_line node
			cout << "Rider's name: " <<regular_line -> name <<endl;
			cout << "Rider's age: " <<regular_line -> age <<endl;
			cout << "Rider's cell: " <<regular_line -> cell <<endl <<endl;


		}
	}

}
//function that removes the first person from the regular list
bool queue::reg_dequeue(){
	
	if(!regular_line)
		return false; //nothing in queue to remove
	else if(regular_line){
		if(regular_line -> next == regular_line){ //only one node in list
			delete [] regular_line -> name;
			delete regular_line;
			regular_line = NULL;
		}
		else if(regular_line -> next != regular_line){
			rider * to_remove = regular_line -> next;
			//remove it from the list, and then delete it
			regular_line -> next = to_remove -> next;
			delete [] to_remove -> name;
			delete to_remove;
	

		}

	return true;
	}



}
//peeks at the next person in the regular list
void queue::reg_peek(){
	if(regular_line){ //if head is not null
	cout << "Rider's name: " <<regular_line -> next -> name <<endl;
	cout << "Rider's age: " <<regular_line -> next -> age <<endl;
	cout << "Rider's cell: " <<regular_line -> next -> cell <<endl;
	}
}
//displays all people in the fast pass line
void queue::fast_display_all(void){
	if(fastpass_line){
		
		if(fastpass_line -> next == fastpass_line){ //if ther is only one node
			cout << "Rider's name: " <<fastpass_line -> name <<endl;
			cout << "Riders's age: " <<fastpass_line -> age <<endl;
			cout << "Rider's cell: " <<fastpass_line -> cell <<endl <<endl;
		}

		else if(fastpass_line -> next != fastpass_line){ //if there are many nodes
			rider * current = fastpass_line -> next;
			while(current != fastpass_line){
				cout << "Rider's name: " <<current -> name <<endl;
				cout << "Rider's age: " <<current -> age <<endl;
				cout << "Rider's cell: " <<fastpass_line -> cell <<endl <<endl;
				current = current -> next;
			} // to display in order, do tail pointer last
			cout << "Rider's name: " <<fastpass_line -> name <<endl;
			cout << "Riders's age: " <<fastpass_line -> age <<endl;
			cout << "Rider's cell: " <<fastpass_line -> cell <<endl <<endl;
		}

	}

}

//peeks at the next person in the fast pass list
void queue::fast_peek(){
	if(fastpass_line){
	cout << "Rider's name: " <<fastpass_line -> next -> name <<endl;
	cout << "Rider's age: " <<fastpass_line -> next -> age <<endl;
	cout << "Rider's cell: " <<fastpass_line -> next -> cell <<endl;
	}
}

//adds a person the the fast pass queue
bool queue::fast_enqueue(char new_name[], int new_age, int new_cell){
	if(!fastpass_line){ //if they are the fist person and only in line
		fastpass_line = new rider; 
		int temp_name_length = strlen(new_name);
		fastpass_line -> name = new char[temp_name_length];
		fastpass_line -> name = new_name;
		fastpass_line -> age = new_age;
		fastpass_line -> cell = new_cell;
		fastpass_line -> next = fastpass_line;

		return true;
	}

	else if(fastpass_line){ ///otherwise link them into a new node and link it into the cLL
		rider * temp = new rider;
		
		int temp_name_length = strlen(new_name);
		temp -> name = new char[temp_name_length];
		temp -> name = new_name;
		temp -> age = new_age;
		temp -> cell = new_cell;
		temp -> next = fastpass_line -> next;
		fastpass_line -> next = temp;
		fastpass_line = fastpass_line -> next;

		return true;

	}

	else 
		return false;

}

//removes the first person in line for the fast pass line
bool queue::fast_dequeue(){
	
	if(!fastpass_line)
		return false; //nothing in queue to remove
	else if(fastpass_line){
		if(fastpass_line -> next == fastpass_line){ //only one node in list
			delete [] fastpass_line -> name;
			delete fastpass_line;
			fastpass_line = NULL;
		}
		else if(fastpass_line -> next != fastpass_line){
			rider * to_remove = fastpass_line -> next;
			//remove it from the list, and then delete it
			fastpass_line -> next = to_remove -> next;
			delete [] to_remove -> name;
			delete to_remove;
		}

	return true;
	}


}


