/* Benjamin Reichert
CS163 Assignment #1
4/18/13

Purpose: create a ticket ordering system through an Abstract Data Type, in this case,
Linear Linked Lists.

*/

#include "ticket.h" //include the header file so we can implement the functions stated there


//default constructor, initilizes dynamic memory from the private data section of the list class
list::list(){
//set the pointers to null so that are not GARBAGE
	head = NULL;
	order_cost = NULL;
	order_section = NULL;
	order_best_seats = NULL;
}

//default deconstructor, iterates through each linear linked list (all four) and deallocates dynamic memory and 
//also keeps memory leaks from happening during deletion dynamic memory
list::~list(){
	
	if(head){ //check to see if there is anything in the list
		section * current = head; //create two temp pointers to assist in deletion
		section * previous = head;
		
		if(head && !current -> next){ //if head is pointing to something and there isn't a next node
			delete current; //delete the only node that head is pointing to
		}

		else{
			while(current->next){ //while there are nodes in the list
				current = current->next; //traverse to the next node
				delete previous; //delete the previous node
				previous = current; //place them back on the same node
			}
			//at this point we are on the last node
			if(current->next == NULL) 
				delete current; //delete last node
		}

		//set head to null since there are no items in the list at this point
	  head = NULL;
	}

//delete the order_cost LLL	
	if(order_cost){ //check to make sure the head of the list is not null already
		section * current = order_cost; //temp pointers to assist in deletion
		section * previous = order_cost;
		
		if(order_cost && !current -> next){ //if head is pointing to something and there isnt a next node
			delete current; //delete the only node that head is pointing to
		}

		else{
			while(current->next){//while there are nodes in the list
				current = current->next; //traverse to the next node 
				delete previous; //get rid of the prevoous one
				previous = current; //sync them back on the same node
			}
			//at this point we are on the last node
			if(current->next == NULL)
				delete current; //delete the last node
		}

	//set head to null since there are no items in the list at this point
	  order_cost = NULL; 
	}

//delete the order_section LLL	
	if(order_section){ // check to make sure head of the list is not null already
		section * current = order_section; //temps to assist in deletion
		section * previous = order_section;
		
		if(order_section && !current -> next){ //if head is pointing to something and there isn't a next node
			delete current; //delete the only node that head is pointing to
		}

		else{
			while(current->next){ //while there are items in the list
				current = current->next; //traverse to the next node
				delete previous; //delete the previous one
				previous = current; //sync them back up on the same node
			}
			//at this point we are on the last node
			if(current->next == NULL) 
				delete current; //delete the last node
		}

	//set head to null since there are no items in the list at this point
	  order_section = NULL;
	}

//delete the order_cost LLL	
	if(order_best_seats){ //check to make sure head is not null already
		section * current = order_best_seats; //temps to assist in traversal and deletion
		section * previous = order_best_seats;
		
		if(order_best_seats && !current -> next){ //if there is only one node
			delete current; //delete the only node that head is pointing to
		}

		else{
			while(current->next){ //while there are nodes in the list
				current = current->next; //traverse to them
				delete previous; //delete the previous node
				previous = current; //sync them back on the same node
			}
			//at this point we are on the last node
			if(current->next == NULL)
				delete current; //delete the last node
		}

	//set head to null since there are no items in the list at this point
	  order_best_seats = NULL;
	}
//END OF DECONSTRUCTOR

}


//this function adds items to the *master* linked list, designated by the pointer head. This function takes in 
//arguments needed to populate the new seating section and returns a sucess or failure integer
int list::add(int section_num, int seats, int seat_class, int price){
	
//status codes for return values = 0 for success, 1 for failure;

	if(head == NULL){ //if there isn't anything in the list already
		head = new section; //make a new section from head
		//populate head with the incoming data
		head -> section_number = section_num;
		head -> total_seats = seats;
		head -> seats_available = seats; //since this is just being created, assume all seats are empty
		head -> seat_class = seat_class;
		head -> price = price;
		return 0; //return good
	}

	else if(head){ //if head already exists and is pointing to somethign
		section * current = head; //create a current pointer to head
		section * new_node; //aand a pointer for a temporary new node
		while(current -> next){ //while there are nodes in the list
			current = current -> next; //travers
		}
		//now current points to the last node;
		
		new_node = new section; //create a new temp node
		current -> next = new_node; //have the last node in the list now point to the new node

		//populate the newly added section with data passed in as args
		new_node -> next = NULL;
		new_node -> section_number = section_num;
		new_node -> total_seats = seats;
		new_node -> seats_available = seats; //since this is just being created, assume all seats are empty
		new_node -> seat_class = seat_class;
		new_node -> price = price;
		new_node -> next = NULL;
		return 0;
	}
	//if something went wrong, and didn't fit the two above specifications, return failure
	return 1;
}

//this function takes in a section number as an argument and removes if from the master list
//does not remove items from the sorted lists. Sorry.
int list::remove(int section_num){
	
	//returns 0 for successful removal, 1 for no removal or error

	if(head == NULL) //if there are no items in the list, there is nothing to delete
		return 1; //since there were no items, there is nothing to remove
	else if(head){
		section * current = head; //temp pointers to assist in traveral an deletion
		section * previous = head;
		section * next = head;
		
		if(section_num = head -> section_number){ //if the section number asked for is the first node
			if(head -> next == NULL){ //if there isn't anything past the first node, its the only one
				delete head; //delete it
				head = NULL; //set head to null
			}
			else{
				current = head; //set current to point to head
				head = head->next; //let head point to the second node (now the first after deletion)
				delete current; //delete the old first node
			}

		}
		
		while(current -> section_number != section_num){ //while the current node does not have the right section number
			previous = current; //set previous to current
			current = current -> next; //traverse to the next node
		}
		//now current is pointing to the node we want to remove;
		if(current -> next){ //if there is anohter node to the right
			next = current -> next; //set next to point to the next section
			delete current; //delte current 
			previous -> next = next; //link previous and next nodes together

		}
		else if(current -> next == NULL){ //if there isn't a next node
			delete current; //delete current
			previous -> next = NULL; //and set the new end node to the previous one
		}
		return 0;
	}

}


//this function allows the user to reserve a seat in general admission style
//error checks to makes sure there is an open seat before reserving one
//returns 0 if seat was reservec, 1 if can't be reserved
int list::reserve_seat(int section_num){
	//returns 0 for successful seat reservation, 1 for no seat reservation

	if(check_available_seats(section_num) == 0)
		return 1; //no seats to reserve

	//there are seats available, so reserve one
	else{
		section * current = head; //current pointer 
		while(current -> section_number != section_num){ //while current isn't the section we're looking for
			current = current -> next; //traverse
		}
		current -> seats_available = current -> seats_available - 1; //on the right section, decrement the seats available by 1
		return 0; //seat was reserved
	}
}


//thic function traverses and checks to see if there are available seats in a passed in section number
int list::check_available_seats(int section_num){ //returns seats available in section as integer

	if(head == NULL) //if there are no itesm in the list, there are no seats.
		return 0; //no seats available, since there aren't any sections!
	
	else if(head){ //if there are sections 
		section * current = head; //create a current pointer

		while(current -> section_number != section_num){ //while not on the section we're looking for
			current = current -> next; //travers
		}
		//on the desired seating section -- return how many seats available
		return current -> seats_available;
	}
}


//this function uses cout statements while iterating through the list to display the seating sections
//does not take any arguments or return values since it displays the values
void list::display_all(void){
	if(!head){ //if there isn't anything in the list
		cout << "There are no seat sections to display." <<endl;
	}

	else if(head){ //if there are items in the list 
		section * current = head; //make a current pointer
		while(current){ 
			//display section information
			
			cout << endl;
			cout << "The seating section is " <<current -> section_number <<endl;
			cout << "The amount of seats in this section are " <<current -> total_seats <<endl;
			cout << "There amount of available seats in this section are " <<current -> seats_available <<endl;
			cout << "The class of the seats in this section are " <<current -> seat_class <<endl;
			cout << "The price of the seats in this section are " <<current -> price <<endl;

			current = current -> next; //then traverse to the next node
		}

	}
}


//this function uses cout statements while iterating through the list to display once seating section asked for through an integer arg
void list::display_section(int section_num){	

	if(head == NULL) //there isn't anyting in the list
		cout << "There is no section to display, since there is no data stored for this event." <<endl;

	else if(head){ //if there are items in hte list
		section * current = head; //create a current pointer

		while(current -> section_number != section_num){//iterate through the list to find the desired section
			current = current -> next;
		}
		//now go and display the section's information
		
		cout << endl;
		cout << "The seating section is " <<current -> section_number <<endl;
		cout << "The amount of seats in this section are " <<current -> total_seats <<endl;
		cout << "There amount of available seats in this section are " <<current -> seats_available <<endl;
		cout << "The class of the seats in this section are " <<current -> seat_class <<endl;
		cout << "The price of the seats in this section are " <<current -> price <<endl;

}
}

//this function uses cout statements while iterating through the list to display the seating sections organized by cost
//does not take any arguments or return values since it displays the values
void list::display_by_cost(void){
	if(!order_cost){ //if there isn't anything in the ordered list
		cout << "There are no seat sections to display." <<endl;
	}

	else if(order_cost){ //if there is things in the list
		section * current = order_cost; //current pointer
		while(current){
			//display section information
			
			cout << endl;
			cout << "The seating section is " <<current -> section_number <<endl;
			cout << "The amount of seats in this section are " <<current -> total_seats <<endl;
			cout << "There amount of available seats in this section are " <<current -> seats_available <<endl;
			cout << "The class of the seats in this section are " <<current -> seat_class <<endl;
			cout << "The price of the seats in this section are " <<current -> price <<endl;

			current = current -> next; //traverse to next node
		}

	}
}

//this function uses cout statements while iterating through the list to display the seating sections organized by section number
//does not take any arguments or return values since it displays the values
void list::display_by_section(void){

	if(!order_section){ //if there isn't anything in the list
		cout << "There are no seat sections to display." <<endl;
	}

	else if(order_section){ //if there is something in the list
		section * current = order_section; //current pointer
		while(current){
			//display section information
			
			cout << endl;
			cout << "The seating section is " <<current -> section_number <<endl;
			cout << "The amount of seats in this section are " <<current -> total_seats <<endl;
			cout << "There amount of available seats in this section are " <<current -> seats_available <<endl;
			cout << "The class of the seats in this section are " <<current -> seat_class <<endl;
			cout << "The price of the seats in this section are " <<current -> price <<endl;

			current = current -> next; //traverse to next section
		}

	}
}
//this function uses cout statements while iterating through the list to display the seating sections organized by best to worst seats
//does not take any arguments or return values since it displays the values
void list::display_by_best_seats(void){
	if(!order_best_seats){ //if there isnt anything in the list
		cout << "There are no seat sections to display." <<endl;
	}

	else if(order_best_seats){ //if there is
		section * current = order_best_seats;//current pointer
		while(current){
			//display section information
			
			cout << endl;
			cout << "The seating section is " <<current -> section_number <<endl;
			cout << "The amount of seats in this section are " <<current -> total_seats <<endl;
			cout << "There amount of available seats in this section are " <<current -> seats_available <<endl;
			cout << "The class of the seats in this section are " <<current -> seat_class <<endl;
			cout << "The price of the seats in this section are " <<current -> price <<endl;

			current = current -> next; //travers to next section
		}

	}
}

//assumes there is at LEAST 2 sections of seating ro organize, otherwise it will fail
//do not try to organize less that two seating sections, but really what would be the point since 
//there is not much data to organize 
//these organizing functions look through the master "head" node and build a new organized section list, in this case organized by cost
int list::organize_cost(void){
	
	if(head){ //if there is a head, there is something to organize
			section * current = head; //temp pointers to help with traversal and moving thinds
			section * current_ordered;
			section * temp_section;
			section * next; //to assist in placing the right

			current_ordered = order_cost; //set the current_ordered pointer to the cost main pointer
			while(current){
				bool success = false; //controls when the inner while loop is done placing the assigned node from the master list
					while(success != true){ //while the current node has not been organized
							if(order_cost == NULL){ //if the head is null, nonexistant, populate with the first item in the master list
								temp_section = new section;
								temp_section -> section_number = current -> section_number;
								temp_section -> total_seats = current -> total_seats;
								temp_section -> seats_available = current -> seats_available;
								temp_section -> seat_class = current -> seat_class;
								temp_section -> price = current -> price;
								order_cost = temp_section;
								temp_section -> next = NULL; //set the next pointer 
								current_ordered = order_cost; //set the current for the ordered list to point to head
								success = true; //successfully placed the first item in the list
							}
							
							else if((current -> price) < (order_cost -> price)){ //if the item fits between the first node and head
								if(order_cost != NULL) //and head is not null
									next = order_cost; //set next to head
								current_ordered = order_cost; //hold the value of the current first node
								temp_section = new section; //create a temporary node to fill with data

								temp_section -> section_number = current -> section_number;
								temp_section -> total_seats = current -> total_seats;
								temp_section -> seats_available = current -> seats_available;
								temp_section -> seat_class = current -> seat_class;
								temp_section -> price = current -> price;

								order_cost = temp_section; //link head to the new node
								order_cost -> next = next; //set the original first node to be the second
								success = true; //did it! 
							}
							
							else if(current -> price >= current_ordered->price && current_ordered -> next == NULL || current->price >= current_ordered->price && current->price <= current_ordered -> next -> price){ //if the new section fits between existing nodes, or is at the end of the list
								next = current_ordered -> next; //get the next node, if null, that is fine
								temp_section = new section; //create new section and populate it
								temp_section -> section_number = current -> section_number;
								temp_section -> total_seats = current -> total_seats;
								temp_section -> seats_available = current -> seats_available;
								temp_section -> seat_class = current -> seat_class;
								temp_section -> price = current -> price;
								
								current_ordered -> next = temp_section; //change current to point the the new temp
								temp_section -> next = next; //set the temp next pointer to next, and null is ok
								success = true; //successssss!

							}

							else{
								//if it doesn't happen on this round through the list, traverse!
								if(current_ordered -> next){
									current_ordered = current_ordered -> next;
								}
								success = false; //didn't make it this time around :(
							}

					}//when done placing one item in the ordered list, advance the master list and go through it all again
				current = current -> next;
			
			}
		}

}

//assumes there is at LEAST 2 sections of seating ro organize, otherwise it will fail
//do not try to organize less that two seating sections, but really what would be the point since 
//there is not much data to organize 
//these organizing functions look through the master "head" node and build a new organized section list, in this case organized by section number
int list::organize_section(void){
	if(head){ //if there is a head, there is something to sort

		section * current = head; //temp pointers to help out
		section * current_ordered; 
		section * temp_section;
		section * next; //to assist in placing the right

			//organize by section
		current_ordered = order_section; //set pointer to head main
					while(current){ //while there are items in the main list to sort, sort them
						bool success = false; //initial success flag
							while(success != true){
									if(order_section == NULL){ //if the head is null, nonexistant, populate with the first item in the master list
										temp_section = new section;
										temp_section -> section_number = current -> section_number;
										temp_section -> total_seats = current -> total_seats;
										temp_section -> seats_available = current -> seats_available;
										temp_section -> seat_class = current -> seat_class;
										temp_section -> price = current -> price;
										order_section = temp_section;
										temp_section -> next = NULL; //set the next pointer
										current_ordered = order_section; //set the current for the ordered list to point to head
										success = true; //successfully placed the first item in the list

									}
									
									else if((current -> section_number) < (order_section -> section_number)){ //if the item fits between the first node and head
										if(order_section != NULL) //and head is not null
											next = order_section; //set next to the head of organized list
										current_ordered = order_section; //hold the value of the current first node
										temp_section = new section; //create a temporary node to fill with data

										temp_section -> section_number = current -> section_number;
										temp_section -> total_seats = current -> total_seats;
										temp_section -> seats_available = current -> seats_available;
										temp_section -> seat_class = current -> seat_class;
										temp_section -> price = current -> price;

										order_section = temp_section; //link head to the new node
										order_section -> next = next; //set the original first node to the second
										success = true; 
									}
									
									else if(current -> section_number >= current_ordered->section_number && current_ordered -> next == NULL || current->section_number >= current_ordered->section_number && current->section_number <= current_ordered -> next -> section_number){ 
										//if the new section fits between existing nodes, or it is at the end of the list
										next = current_ordered -> next; //get the next node
										temp_section = new section;
										temp_section -> section_number = current -> section_number;
										temp_section -> total_seats = current -> total_seats;
										temp_section -> seats_available = current -> seats_available;
										temp_section -> seat_class = current -> seat_class;
										temp_section -> price = current -> price;
										
										current_ordered -> next = temp_section; //change current to point to the new temp
										temp_section -> next = next; //set the temp pointer to next, and null is ok, since it's at the end of the list
										success = true;

									}

									else{
										if(current_ordered -> next){ //if it doesn't happen through this round, traverse
											current_ordered = current_ordered -> next;
										}
										success = false;
									}

							}
							//when done placing one item organized, advance to the next item in the master list
						current = current -> next;
					
					}
			
		}
}



//assumes there is at LEAST 2 sections of seating ro organize, otherwise it will fail
//do not try to organize less that two seating sections, but really what would be the point since 
//there is not much data to organize 
//these organizing functions look through the master "head" node and build a new organized section list, in this case organized by best to worst seats
int list::organize_seats(void){
	if(head){ //if there is a head, there is something to organize

		section * current = head; //temporary pointers to assists
		section * current_ordered;
		section * temp_section;
		section * next; //to assist in placing the right


			//organize by section
		current_ordered = order_best_seats; //set pointer to head main
					while(current){
						bool success = false;
							while(success != true){
									if(order_best_seats == NULL){ //if the head is null, populate with the first item in the master list
										temp_section = new section;
										temp_section -> section_number = current -> section_number;
										temp_section -> total_seats = current -> total_seats;
										temp_section -> seats_available = current -> seats_available;
										temp_section -> seat_class = current -> seat_class;
										temp_section -> price = current -> price;
										order_best_seats = temp_section;
										temp_section -> next = NULL; //set the next pointer
										current_ordered = order_best_seats; //set the current for the ordered list to point to head
										success = true;
									}
									
									else if((current -> seat_class) < (order_best_seats -> seat_class)){ //if the items fits between the first node and head
										if(order_best_seats != NULL)//and head it not null
											next = order_best_seats; //set next to head of organized list
										current_ordered = order_best_seats; //hold the value of the current first node
										temp_section = new section; //create a temporary node to fill with data

										temp_section -> section_number = current -> section_number;
										temp_section -> total_seats = current -> total_seats;
										temp_section -> seats_available = current -> seats_available;
										temp_section -> seat_class = current -> seat_class;
										temp_section -> price = current -> price;

										order_best_seats = temp_section; //link head to the new node
										order_best_seats -> next = next; //set the original first node to the second
										success = true;
									}
									
									else if(current -> seat_class >= current_ordered->seat_class && current_ordered -> next == NULL || current->seat_class >= current_ordered->seat_class && current->seat_class <= current_ordered -> next -> seat_class){ 
										//if the new seating section fits between existing nodes, or it is at the end of the list
										next = current_ordered -> next; //get the next node
										temp_section = new section;
										temp_section -> section_number = current -> section_number;
										temp_section -> total_seats = current -> total_seats;
										temp_section -> seats_available = current -> seats_available;
										temp_section -> seat_class = current -> seat_class;
										temp_section -> price = current -> price;
										
										current_ordered -> next = temp_section; //change current to point to the new temp
										temp_section -> next = next; //set temp to point to next
										success = true;

									}

									else{
										if(current_ordered -> next){ //if it diddn't happend on that round, go around the loop again
											current_ordered = current_ordered -> next; 
										}
										success = false;
									}

							}
							//when done placing one item organized, advance to the next item in the master list
						current = current -> next;
					
					}
			
		}
}






