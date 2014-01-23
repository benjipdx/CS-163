/*
Benjamin Reichert

Assignment #5, the 5 installment in the data structures class of programs
6/13/13

PURPOSE: This program uses a graph ADT to organize a zoo and its animals. 
Each animal is positionally related to other animals in the zoo, through 
an adjacency edge list

*/

#include "animal.h"


//prototypes
void welcome();
void prog_manager();
int add_animal_wrapper(zoo & zoo_listings);
void display_all_wrapper(zoo & zoo_listings);
int create_link_wrapper(zoo & zoo_listings);
int retrieve_adjacent_animals(zoo & zoo_listings);

int main(){
	
	welcome(); //welcomes the user
	prog_manager(); //manages the whole program
	

	return 0;
}
//this function is just for aesthetics and displays a sign and greets the user
void welcome(){
	cout << "\n\n\n\n\nWelcome to the Z-O-O manager, Version 1.0\n\n" <<endl;
	cout <<endl <<endl <<"/* Fancy ASCII Art of Cute Panda inserted here */" <<endl;

}

//this function manages the program through function calls - the backbone of the program
void prog_manager(){

//declare class here
zoo MyZoo;

char userinput; //make temp variable for user single char input

while(userinput != 'X'){
		cout << "\n\nZ-O-O Management Menu Selection System.\n" 
		 << "Please enter one of the following choices: \n"
		 << "A - Add animal\n"
		 << "D - Display all animals\n"
		 << "L - Link two animals together\n"
		 << "X - Exit the program\n"
		 << "Enter here: "; //tell the options they have
	cin >> userinput; //get their selection
	cin.ignore(100, '\n'); //ignore input buffer
	userinput = toupper(userinput); //capitalize character for matching
	
	if (userinput == 'A' ){ //if matches call appropriate function
		add_animal_wrapper(MyZoo);
	}
	else if (userinput == 'D'){
		display_all_wrapper(MyZoo);
	}
	else if (userinput == 'L'){
		create_link_wrapper(MyZoo);
	}
	
	else if (userinput == 'X') //if want to quit, return false and while looop in main will die and program will exit
		userinput = 'X'; //let them go, when the loop goes around again
}

}

int add_animal_wrapper(zoo & zoo_listings){
	zoo_listings.add_animal();
}

void display_all_wrapper(zoo & zoo_listings){
	zoo_listings.display_all();
}

int create_link_wrapper(zoo & zoo_listings){
//	zoo_listings.create_link();
}

int retrieve_adjacent_animals(zoo & zoo_listings){
	char temp_name[100];
	char * new_name;
	vertex * retrieved_animals;
	cout << "What is the name of the animal you want the adjacent animals to? " <<endl;
	cin.get(temp_name, 100, '\n');
	cin.ignore(100, '\n');

	new_name = new char[strlen(temp_name)+1]; //start copying into the new node we're going to pass to the insert function
	strcpy(new_name, temp_name);

//	zoo_listings.retrieve_adjacent(new_name, retrieved_animals);
	
}


