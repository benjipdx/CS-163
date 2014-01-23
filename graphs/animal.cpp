/*
Benjamin Reichert

Assignment #5, the 5 installment in the data structures class of programs
6/13/13

PURPOSE: This program uses a graph ADT to organize a zoo and its animals. 
Each animal is positionally related to other animals in the zoo, through 
an adjacency edge list

*/

#include "animal.h"

//default constructor
zoo::zoo(){

adjacency_list = new list_item[MAX_ARRAY_SIZE];

for(int i = 0; i < MAX_ARRAY_SIZE; i++){

	adjacency_list[i].visit = false;
	adjacency_list[i].head = NULL;
	adjacency_list[i].animal_vertex = NULL;

}

}

zoo::~zoo(){
//this loop destroys the adjacency list
for(int i = 0; i < MAX_ARRAY_SIZE; i++){

	if(adjacency_list[i].head){ //if there is a head

		//dealocate all the data about the animal
		node * current = adjacency_list[i].head;
		node * previous = current;

		while(current){
			previous = current;
			current = current -> next;

			//now get rid of dynamic data of previous
			delete [] previous -> animal_info -> name;
			delete [] previous -> animal_info -> species;
			delete [] previous -> animal_info -> location;
			delete [] previous -> animal_info -> add_info;
			delete [] previous -> animal_info -> date;
			delete previous;

		}
		adjacency_list[i].head = NULL;
		
	}
}
//destroy the intial vertex of each adjacnecy list item
for(int i = 0; i < MAX_ARRAY_SIZE; i++){
	delete [] adjacency_list[i].animal_vertex -> name;
	delete [] adjacency_list[i].animal_vertex -> species;
	delete [] adjacency_list[i].animal_vertex -> location;
	delete [] adjacency_list[i].animal_vertex -> add_info;
	delete [] adjacency_list[i].animal_vertex -> date;
}

}

int zoo::add_animal(){
	char temp_name[100]; //100 chars for temp should be reasonable to hold
	char temp_species[50]; //enough to hold description before dynamically allocating real description
	char temp_location[50];
	char temp_add_info[200]; //temp holder for position type
	char temp_date[50];
	int temp_health = 0;

	vertex * new_animal = new vertex;
	//vertex -> animal_info -> name

	cout << "What is the name of the animal? " <<endl; //prompt, read in, wash, rinse, repeat
	cin.get(temp_name, 100, '\n');
	cin.ignore(100, '\n');
	
	cout << "What is the species of " <<temp_name << " ?" <<endl;
	cin.get(temp_species, 50, '\n');
	cin.ignore(50, '\n');
	
	cout << "Where is " <<temp_name << " located?" <<endl;
	cin.get(temp_location, 50, '\n');
	cin.ignore(50, '\n');

	cout << "Any additional info about " <<temp_name << " ?" <<endl;
	cin.get(temp_add_info, 200, '\n');
	cin.ignore(200, '\n');

	cout << "When was " <<temp_name <<" brought to the zoo (DD/MM/YYYY)?" <<endl;
	cin.get(temp_date, 50, '\n');
	cin.ignore(200, '\n');

	cout << "How healthy is " <<temp_name << ", on a scale of 1-10?" <<endl;
	cin >> temp_health;
	cin.ignore(100, '\n');

	new_animal->name = new char[strlen(temp_name)+1];
	strcpy(new_animal->name, temp_name);

	new_animal->species = new char[strlen(temp_species)+1];
	strcpy(new_animal->species, temp_species);

	new_animal->location = new char[strlen(temp_location)+1];
	strcpy(new_animal->location, temp_location);

	new_animal->add_info = new char[strlen(temp_add_info)+1];
	strcpy(new_animal->add_info, temp_add_info);

	new_animal->date = new char[strlen(temp_date)+1];
	strcpy(new_animal->date, temp_date);

	new_animal -> health = temp_health;

	//determine where to insert the new animal
	for(int i = 0; i < MAX_ARRAY_SIZE; i++){
		if(adjacency_list[i].animal_vertex != NULL){
			//found the first one that can hold the data, insert there

			adjacency_list[i].animal_vertex = new_animal;
			return 1; //for success
		}

	}

}

void zoo::display_all(){

	for(int i = 0; i < MAX_ARRAY_SIZE; i++){
	
		if(adjacency_list[i].animal_vertex){
		
			cout << "Name: " <<adjacency_list[i].animal_vertex -> name <<endl;
			cout << "Species: " <<adjacency_list[i].animal_vertex -> species <<endl;
			cout << "Location: " <<adjacency_list[i].animal_vertex -> location <<endl;
			cout << "Additional Info: " <<adjacency_list[i].animal_vertex -> date <<endl;
			cout << "Health: " <<adjacency_list[i].animal_vertex -> health <<endl;

			if(adjacency_list[i].head){
				node * current = adjacency_list[i].head;
				//recursive function call to output the linear linked list implementation
				
				display_recursive_LLL(adjacency_list[i].head);

				}
			
			}

		}


}

void zoo::display_recursive_LLL(node * head){
	
	cout << "Name: " <<head -> animal_info -> name <<endl;
	cout << "Species: " <<head -> animal_info -> species <<endl;
	cout << "Location: " <<head -> animal_info -> location <<endl;
	cout << "Additional Info: " <<head -> animal_info -> add_info <<endl;
	cout << "Health: " <<head -> animal_info -> health <<endl;

	display_recursive_LLL(head -> next);

}

int zoo::create_link(){

}
int zoo::retrieve_adjacent(char * name, vertex * & retrieved_animals){

}


//I'm sorry it's not finished, I didn't have as much time as i'd hoped due to finals week being hectic. 
