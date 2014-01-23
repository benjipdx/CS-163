/*
Benjamin Reichert
CS163 Assignment #1
4/18/13

Purpose: create a ticket ordering system through an Abstract Data Type, in this case,
Linear Linked Lists. This is main.cpp and provides the nice user interface for the back end ticketing system

*/

//prototypes 
void welcome();

#include "ticket.h"
using namespace std;

//main in this program controls the whole front-end functionality of the program
//this is where user input is taken and passed along to the data structure functions
//greets the user and provides a menu system as well
int main(){

welcome(); //call welcominggggggg

list nba_list; //initialize list

//add some items to the testing list of sections
for (int i = 1000000; i>0; i--){
	nba_list.add(100 + i, i*10, i, i*100);
}
for (int i = 20; i<10000000; i++){
	nba_list.add(100 + i, i*10, i, i*100);
}
//uncomment above for sample data to play with

char userinput; //make temp variable for user single char input

while(userinput != 'X'){
		cout << "\n\nThis is the Ticketing Menu Selection System.\n" 
		 << "Please enter one of the following choices: \n"
		 << "A - Add seating\n"
		 << "O - Organize all seating\n"
		 << "D - Display all seating\n"
		 << "S - Display all seating, sorted by section\n"
		 << "Y - Display all seating, sorted by best to worst seats\n"
		 << "Z - Display all seating, sorted by cost\n"
		 << "B - Display seating in a section\n"
		 << "R - Remove a section of seating\n"
		 << "H - Reserve a seat\n"
		 << "C - Check available seats in a section\n"
		 << "X - Exit the program\n"
		 << "Enter here: "; //tell the options they have
	cin >> userinput; //get their selection
	cin.ignore(100, '\n'); //ignore input buffer
	userinput = toupper(userinput); //capitalize character for matching
	
	if (userinput == 'A') //if a, add posting
	{
		int section; //temporary variables used for storing and passing along to data structure
		int seats;
		int seat_class;
		int price;
		
		cout << "Please enter a section number: " ; //ask for a section number and store it
		cin >> section;
		cin.ignore(100,'\n');
		
		cout << "Please enter the seats in this section: "; // ask for seats and store it
		cin >> seats;
		cin.ignore(100,'\n');
	
		cout << "Please enter the class of the seats: "; //ask for seat class and store it
		cin >> seat_class;
		cin.ignore(100,'\n');
	
		cout << "Please enter the price of the seats: "; //ask for price and store it
		cin >> price;
		cin.ignore(100,'\n');

		if(section > 0 && seats > 0 && seat_class > 0 && price > 0) //are valid answers, not negative numbers, then add to list with values
			nba_list.add(section, seats, seat_class, price); //add to the data structure with the given information
		else
			cout << "Please enter values that are over 0." <<endl; //if they didn't enter valid answers, tell them
	}

	else if(userinput == 'D') //if d, display all seating in the list
	{
		nba_list.display_all(); 
	}
	
	else if(userinput == 'B') //if b, display a section in the list
	{
		int section; //temp variable to pass to function
		cout << "Which section would you like to display? ";
		cin >> section;
		cin.ignore(100, '\n');
		nba_list.display_section(section); //call function
	}
	
	else if(userinput == 'R') //remove a section of seating
	{
		int section; //temp integer to store data to pass to function
		cout << "Which section would you like to remove? ";
		cin >> section;
		cin.ignore(100, '\n');
		nba_list.remove(section); //remove the section specified
	}

	else if(userinput == 'H') //want a seat, so reserve it for them 
	{
		int section; //stores which section the user wants to reserve a seat in. 
		cout << "Which section would you like to reserve a seat in? ";
		cin >> section;
		cin.ignore(100, '\n');
		int available_seats = nba_list.check_available_seats(section); //temporary integer to catch the available seats of the section provided
		if (available_seats == 0) //if there isn't any seats, tell them
			cout << "I'm sorry, but there aren't any seats left in that section." <<endl;
		else{ //if there are seats available, reserve one for the user
			nba_list.reserve_seat(section);
			cout << "Successfully reserved you a seat in " <<section <<"." <<endl; 
		}
	}
	
	else if(userinput == 'C') //want to check seats available in the section
	{
		int section; //holds temporary section to check seats in
		cout << "Which section are you wanting to see that amount of seats available? ";
		cin >> section;
		cin.ignore(100, '\n');
		int available_seats = nba_list.check_available_seats(section); //ineger holds the amount of seats in the section returned by the function
		cout << "There are " <<available_seats << " available in section " <<section << "." <<endl; //output found amount of seats
	}

	else if(userinput == 'O'){ //want to organize data
		//user should keep in mind that organizing data multiple times DOES NOT delete the organized data in the list
		//this leads to duplicated data in the organized versions of the list, so please, input all the data, and then
		//only organize the data once to prevent duplicates
		nba_list.organize_cost(); //call function to organize by cost
		nba_list.organize_section(); //call function to organize by section
		nba_list.organize_seats(); //call functino to organize by best to worst seats
		cout << "Seating sections have been organized." <<endl; //tell user that the action has been taken
	}

	else if(userinput == 'S'){ //display seating sorted previously by 'O' by section
		nba_list.display_by_section(); 
	}

	else if(userinput == 'Y'){ //display seating sorted previously by 'O' by best to worst seats
		nba_list.display_by_best_seats();
	}

	else if(userinput == 'Z'){ //display seating sorted previouslt by 'O' by cost from lowest to highest
		nba_list.display_by_cost();
	}

	else if (userinput == 'X') //if want to quit, return false and while looop in main will die and program will exit
		userinput = 'X'; //let them go, when the loop goes around again
}

//exit the program, bye bye!
	return 0;
}


//the purpose of the welcome function is purely aesthetic. It is here to greet the user, and look cool. 
void welcome(){
	cout <<endl <<endl <<"Welcome to the " <<endl <<endl 
		<<"      _______      __        __  _                                __               " <<endl
		<<"     /_  __(_)____/ /_____  / /_(_)___  ____ _   _______  _______/ /____  ____ ___ " <<endl
		<<"      / / / / ___/ //_/ _ \\/ __/ / __ \\/ __ `/  / ___/ / / / ___/ __/ _ \\/ __ `__\\" <<endl
		<<"     / / / / /__/ ,< /  __/ /_/ / / / / /_/ /  (__  ) /_/ (__  ) /_/  __/ / / / / /" <<endl
	    <<"    /_/ /_/\\___/_/|_|\\___/\\__/_/_/ /_/\\__, /  /____/\\__, /____/\\__/\\___/_/ /_/ /_/" <<endl
		<<"	                              /____/        /____/" <<endl;
}	

