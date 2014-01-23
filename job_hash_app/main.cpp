/* Benjamin Reichert CS163 

Assignment #3

Purpose: This program is designed to store job opportunities in computer science 
implemented with a hash table and chaining. Job information included is company name,
type of position, list of skills required, programming languages used at the position, 
company description, location, salary, and desirability to work there. 


*/

#include "job.h"

//prototypes
void welcome();
void prog_manager();
void add_job(job_manager & job_manager);
void display(job_manager & job_manager);
void remove(job_manager & job_manager);
void find(job_manager & job_manager);
//the main function, work gets shipped out from here
int main(){
	
	welcome(); //welcomes the user
	prog_manager(); //manages the whole program
	

	return 0;
}
//this function is just for aesthetics and displays a sign and greets the user
void welcome(){
	cout << "Welcome to the Computer Science" <<endl;
	cout << "      #                  #     #                                   "<<endl
	     << "      #  ####  #####     #     # #    # #    # ##### ###### #####  "<<endl
		 << "      # #    # #    #    #     # #    # ##   #   #   #      #    # "<<endl
		 << "      # #    # #####     ####### #    # # #  #   #   #####  #    # "<<endl
	     << "#     # #    # #    #    #     # #    # #  # #   #   #      #####  "<<endl
		 << "#     # #    # #    #    #     # #    # #   ##   #   #      #   #  "<<endl
		 <<  " #####   ####  #####     #     #  ####  #    #   #   ###### #    # "<<endl;
}

//this function manages the program through function calls - the backbone of the program
void prog_manager(){

//declare class here
job_manager job_listings;


char userinput; //make temp variable for user single char input

while(userinput != 'X'){
		cout << "\n\nThis is the Ticketing Menu Selection System.\n" 
		 << "Please enter one of the following choices: \n"
		 << "A - Add job to listings\n"
		 << "F - Retrieve job listing\n"
		 << "R - Remove job from listings\n"
		 << "D - Display job listing\n"
		 << "X - Exit the program\n"
		 << "Enter here: "; //tell the options they have
	cin >> userinput; //get their selection
	cin.ignore(100, '\n'); //ignore input buffer
	userinput = toupper(userinput); //capitalize character for matching
	
	if (userinput == 'A' ){ //if matches call appropriate function
		add_job(job_listings);
	}
	else if (userinput == 'R'){
		remove(job_listings);
	}
	else if (userinput == 'F'){
		find(job_listings);
	}
	
	else if (userinput == 'D'){
		display(job_listings);
	}
	
	else if (userinput == 'X') //if want to quit, return false and while looop in main will die and program will exit
		userinput = 'X'; //let them go, when the loop goes around again
}

}
//this function prompts the user for what they want to add and then addds it to the database
void add_job(job_manager & job_manager){
	char temp_company_name[100]; //100 chars for temp should be reasonable to hold
	char temp_company_desc[200]; //enough to hold description before dynamically allocating real description
	char temp_location[50];
	char temp_position_type[100]; //temp holder for position type
	char temp_skill_required[200];
	char temp_programming_langs[100];
	int temp_salary = 0;
	int temp_stars = 0; //stars, 1-5 on a scale

	cout << "What is the company name for the job listing? " <<endl; //prompt, read in, wash, rinse, repeat
	cin.get(temp_company_name, 100, '\n');
	cin.ignore(100, '\n');
	
	cout << "What is a description of the company?" <<endl;
	cin.get(temp_company_desc, 200, '\n');
	cin.ignore(200, '\n');
	
	cout << "Where is the job located?" <<endl;
	cin.get(temp_location, 50, '\n');
	cin.ignore(50, '\n');

	cout << "What is the type of position at the job?" <<endl;
	cin.get(temp_position_type, 100, '\n');
	cin.ignore(100, '\n');

	cout << "What kind of skills are required for this job?" <<endl;
	cin.get(temp_skill_required, 200, '\n');
	cin.ignore(200, '\n');

	cout << "What kind of programming languages are needed for this job?" <<endl;
	cin.get(temp_programming_langs, 100, '\n');
	cin.ignore(100, '\n');

	cout << "How much is the job salary? (enter as plain number, no commas, etc.)" <<endl;
	cin >> temp_salary;
	cin.ignore(100, '\n');

	cout << "How many stars (from 1-5) does this job get for desirability? " <<endl;
	cin >> temp_stars;
	cin.ignore(100, '\n');
	/* now we need to put this all into a job struct and call the function to add it to the database */

	job * new_job; //initialize the new job struct
	
	new_job->company_name = new char[strlen(temp_company_name)+1]; //start copying into the new node we're going to pass to the insert function
	strcpy(new_job->company_name, temp_company_name);
	
	new_job->company_description = new char[strlen(temp_company_desc)+1];
	strcpy(new_job->company_description, temp_company_desc);

	new_job->location = new char[strlen(temp_location)+1];
	strcpy(new_job->location, temp_location);

	new_job->position_type = new char[strlen(temp_position_type)+1];
	strcpy(new_job->position_type, temp_position_type);

	new_job->skills_required = new char[strlen(temp_skill_required)+1];
	strcpy(new_job->skills_required, temp_skill_required);

	new_job->programming_languages = new char[strlen(temp_programming_langs)];
	strcpy(new_job->programming_languages, temp_programming_langs);

	new_job->salary = temp_salary;
	new_job->stars = temp_stars;

	new_job->next = NULL;

	//call function with needed info
	job_manager.insert(new_job); //call the insert function passing in the new_job struct we just made

}
//this function prompts the user for what they want displayed and calls the display function
void display(job_manager & job_manager){

	char temp_company_name[100]; //100 chars for temp should be reasonable to hold
	char temp_position_type[100]; //temp holder for position type

	cout << "What is the company name for the job listing? " <<endl;
	cin.get(temp_company_name, 100, '\n');
	cin.ignore(100, '\n');

	cout << "What is the type of position at the job?" <<endl;
	cin.get(temp_position_type, 100, '\n');
	cin.ignore(100, '\n');

	job * new_job; //initialize the new job struct

	new_job->company_name = new char[strlen(temp_company_name)+1];
	strcpy(new_job->company_name, temp_company_name);

	new_job->position_type = new char[strlen(temp_position_type)+1];
	strcpy(new_job->position_type, temp_position_type);
	
	//call function with needed info
	job_manager.display(new_job -> position_type, new_job -> company_name);

}
//prompts the user what they want removes and calls the remove function
void remove(job_manager & job_manager){

	char temp_company_name[100]; //100 chars for temp should be reasonable to hold
	char temp_position_type[100]; //temp holder for position type

	cout << "What is the company name for the job listing? " <<endl;
	cin.get(temp_company_name, 100, '\n'); //get input
	cin.ignore(100, '\n');
	
	cout << "What is the type of position at the job?" <<endl;
	cin.get(temp_position_type, 100, '\n');
	cin.ignore(100, '\n');

	job * new_job; //initialize the new job struct
	
	new_job->company_name = new char[strlen(temp_company_name)+1];
	strcpy(new_job->company_name, temp_company_name); //copy to new struct
	
	new_job->position_type = new char[strlen(temp_position_type)+1];
	strcpy(new_job->position_type, temp_position_type);

	job_manager.remove(new_job -> position_type, new_job -> company_name); //call the function with args


}
//prompts the user what they want to find and then stores the return in found
void find(job_manager & job_manager){

	char temp_company_name[100]; //100 chars for temp should be reasonable to hold
	char temp_position_type[100]; //temp holder for position type

	cout << "What is the company name for the job listing? " <<endl;
	cin.get(temp_company_name, 100, '\n');
	cin.ignore(100, '\n');
	
	cout << "What is the type of position at the job?" <<endl;
	cin.get(temp_position_type, 100, '\n');
	cin.ignore(100, '\n');

	job * new_job; //initialize the new job struct
	
	new_job->company_name = new char[strlen(temp_company_name)+1];
	strcpy(new_job->company_name, temp_company_name);
	
	new_job->position_type = new char[strlen(temp_position_type)+1];
	strcpy(new_job->position_type, temp_position_type);

	job * found; //where the found data will be stored

	job_manager.find(new_job -> position_type, new_job -> company_name, found);

	//the the clienct program would display the found data or pass is along to another program at this point


}


//have a nice night!
