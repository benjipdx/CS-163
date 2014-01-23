/* BENJAMIN REICHERT, CS163
ASSIGNMENT: #2
PURPOSE: A program to organize lines at an amusement park or other location that uses lines.
		 It also has implementations for two lines, one with a fast pass system, where the 
		 person in line does not have to wait in the regular line, but rather they have to 
		 wait in the priority line, and from there they can bypass the regular line. The other
		 line is just a regular line system, the person gets in line, and eventually they will
		 be allowed out of the line once it is their turn. 

while(userinput != 'X'){
		cout << "\n\nThis is the Ticketing Menu Selection System.\n" 
		 << "Please enter one of the following choices: \n"
		 << "A - Add person to line\n"
		 << "R - Release next person in line\n"
		 << "I - Add ride (must be called for each ride, before other functions)\n"
		 << "S - See first person in line\n"
		 << "D - Display people in line\n"
		 << "X - Exit the program\n"
	
*/
#include "manager.h"

//prototypes 
void welcome();
void prog_manager();
//these functions are called from the manager function and 
//promp the user for input and call the appropriate functions
//all take manager as arg
void add_to_line(manager & my_rides);
void release_from_line(manager & my_rides);
void add_ride(manager & my_rides);
void peek(manager & my_rides);
void display_ride_line(manager & my_rides);


//main in this program controls the whole front-end functionality of the program
//this is where user input is taken and passed along to the data structure functions
//greets the user and provides a menu system as well
int main(){


welcome(); //call welcominggggggg
prog_manager();
//exit the program, bye bye!
	return 0;
}


//the purpose of the welcome function is purely aesthetic. It is here to greet the user, and look cool. 
void welcome(){
	cout <<endl <<endl <<"Welcome to the " <<endl <<endl 
		<<"	_    _ _  _ ____    ____ _  _ ____ _  _ _ _  _ ____  " <<endl
		<<"	|    | |\\ | |___    |  | |  | |___ |  | | |\\ | | __  " <<endl
		<<"	|___ | | \\| |___    |_\\| |__| |___ |__| | | \\| |__|  " <<endl
		<<"                                                   		 " <<endl
		<<"			____ _   _ ____ ___ ____ _  _ 				 " <<endl
		<<"			[__   \\_/  [__   |  |___ |\\/| 				 " <<endl
		<<"			___]   |   ___]  |  |___ |  |				 " <<endl;
}	

//this function manages the program through function calls - the backbone of the program
void prog_manager(){

//declare the manager class instance
manager my_rides;

char userinput; //make temp variable for user single char input

while(userinput != 'X'){
		cout << "\n\nThis is the Ticketing Menu Selection System.\n" 
		 << "Please enter one of the following choices: \n"
		 << "A - Add person to line\n"
		 << "R - Release next person in line\n"
		 << "I - Add ride (must be called for each ride, before other functions)\n"
		 << "S - See first person in line\n"
		 << "D - Display people in line\n"
		 << "X - Exit the program\n"
		 << "Enter here: "; //tell the options they have
	cin >> userinput; //get their selection
	cin.ignore(100, '\n'); //ignore input buffer
	userinput = toupper(userinput); //capitalize character for matching
	
	if (userinput == 'A' ){ //if matches call appropriate function
		add_to_line(my_rides);	
	}
	else if (userinput == 'R')
		release_from_line(my_rides);
	else if (userinput == 'I')
		add_ride(my_rides);
	else if (userinput == 'S')
		peek(my_rides);
	else if (userinput == 'D')
		display_ride_line(my_rides);
	else if (userinput == 'X') //if want to quit, return false and while looop in main will die and program will exit
		userinput = 'X'; //let them go, when the loop goes around again
}

}



void add_to_line(manager & my_rides){

	char temp_name[100]; //placeholder for name of queueueeeeee
		bool success;
		int temp_age = 0; //placeholders for data about to get
		int temp_cell = 0;
		int ride = 0;
		int line_type = 0;
		cout << "Adding a person to the line. What is their name?" <<endl;
		cin.get(temp_name, 100, '\n');
		cin.ignore(200, '\n');
		cout << "How old are they?" <<endl;
		cin >> temp_age;
		cin.ignore(100, '\n');
		cout << "What is their phone number?" <<endl;
		cin >> temp_cell;
		cin.ignore(100, '\n');
		cout << "What ride are they in line for?" <<endl;
		cin >> ride;
		cin.ignore(100, '\n');
		cout << "Please enter 0 if they would like to be put in the regular line \n" 
			<< "or enter 1 of they would like to be put in the fast pass line. " <<endl;
		cin >> line_type;
		cin.ignore(100, '\n');
		success = my_rides.add_line(ride, line_type, temp_name, temp_age, temp_cell); //call function with known info
		if(success == true)
			cout << "Successfully added " <<temp_name << " to line " <<ride << "." <<endl; //determine what return value was
		else 
			cout << "An error occured." <<endl;

}

//function that removes the next person in line from the queue
void release_from_line(manager & my_rides){
	int temp_ride_num; //placeholder datas
	int temp_line_type;
	bool success;
	
	cout << "What ride number do you want to remove a person from? " <<endl;
	cin >> temp_line_type;
	cin.ignore(100, '\n');

	cout << "Please enter 0 if the line was a regular line \n" 
			<< "or enter 1 if it was the fast pass line. " <<endl;
	cin >> temp_line_type;
	cin.ignore(100, '\n');
	success = my_rides.remove_line(temp_ride_num, temp_line_type); //function call, with known info
	if (success == true)
		cout << "Successfully removed the first person in line." <<endl; //determine what return value was
	else 
		cout << "An error has occured." <<endl;

}
//functino that adds a ride to the ADT
void add_ride(manager & my_rides){
	int temp_ride_num; //data placeholders
	bool success;
	cout << "What number is the ride you would like to add?" <<endl;
	cin >> temp_ride_num;
	cin.ignore(100, '\n');
	success = my_rides.add_ride(temp_ride_num); //functin call with known info
	if(success == true)
		cout << "Successfully added ride " <<temp_ride_num << "." <<endl; //determine what return meant
	else
		cout << "An error has occured." <<endl;

}
//functino that peeks and seems who is next in line 
void peek(manager & my_rides){
	int temp_ride_num; //placeholders
	int line_type;
	cout << "What ride would you like to see the next person in line?" <<endl;
	cin >> temp_ride_num;
	cin.ignore(100, '\n');
	cout << "Please enter 0 if the line was a regular line \n"
		<< "or enter 1 if it was the fast pass line. " <<endl;
	cin >> line_type;
	cin.ignore(100, '\n');
	my_rides.see_next(temp_ride_num, line_type); //call functino in manager classs

}
//this functino displays the people in lines of a certain ride
void display_ride_line(manager & my_rides){
	int temp_ride_num; //placeholders
	int line_type;
	cout << "What ride's line would you like to display? " <<endl;
	cin >> temp_ride_num;
	cin.ignore(100, '\n');
	cout << "Please enter 0 if the line was a regular line \n"
		<< "or enter 1 if it was a fast pass line. " <<endl;
	cin >> line_type;
	cin.ignore(100, '\n');
	my_rides.display_line(temp_ride_num, line_type); //function call;
}
