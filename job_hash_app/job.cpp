/* Benjamin Reichert CS163 

Assignment #3

Purpose: This program is designed to store job opportunities in computer science 
implemented with a hash table and chaining. Job information included is company name,
type of position, list of skills required, programming languages used at the position, 
company description, location, salary, and desirability to work there. 


*/

#include "job.h"

//this function is the default constructor and it initializes all the head node pointers null
job_manager::job_manager(){ //default constructor

	job_listings = new job * [MAX]; //create the list of head pointers dynamically
	//initialize all pointers to NULL 
	for (int i = 0; i < MAX-1; i++){
		job_listings[i] = NULL;
	}
}
//this releases all dynamic memory used in the program
job_manager::~job_manager(){ //default deconstructor

	for(int i = 0; i < MAX-1; i++){ //run through the for loop for each head pointer in the table
		
		if(job_listings[i]){ //if there is someting in the list
			job * previous;
			job * current = job_listings[i]; //create temporary pointers 
			while(current -> next){
				previous = current; //travers
				current = current -> next;
				delete [] previous -> company_description;
				delete [] previous -> company_name;
				delete [] previous -> location;
				delete [] previous -> position_type;
				delete [] previous -> skills_required;
				delete [] previous -> programming_languages;
				
				delete previous; //delete
			}
			//on last node
				previous = current;
				delete [] previous -> company_description;
				delete [] previous -> company_name;
				delete [] previous -> location;
				delete [] previous -> position_type;
				delete [] previous -> skills_required;
				delete [] previous -> programming_languages;
				delete previous;
	
		}
		
	}

}
//this function inserts a job into the table 
int job_manager::insert(job * & new_job){

//hashing function
int index = 0; //holds index for which head node to store the job listing in
int company_length = strlen(new_job->company_name); //length of company name as int
int job_length = strlen(new_job->position_type);

//create index total for company name
for(int i = 0; company_length > i; i++){
	index = index + new_job->company_name[i];	 //add up ascii values of each char for index
} 

for(int i = 0; job_length > i; i++){
	index = index + new_job->position_type[i];	 //ascii values added for position as well
}

//so now we have a big number of all the ascii values for the characters and we need a nice index

index = index % MAX; //make a reasonable index from the hashing function

//now insert into the list with the index
//end of hashing, now we will insert

if(job_listings[index] != NULL){ //there is something in that index, then traverse until next is null;
	job * current = job_listings[index];
	cout << current <<endl;
	cout <<current->next <<endl;
	while(current -> next){ //traverse until end of chain
		current = current -> next;
	}

	current -> next = new_job; //insert new job listing
}

else if(job_listings[index] == NULL){ //there are no nodes in this index, yet

	job_listings[index] = new_job;
}

}

//function finds an asked job listing and returns it through the found_job instance as an argument
int job_manager::find(char * position_type, char * company_name, job *& found_job){ //where the job_title is the job title being searched for, is NOT case sensitive
int index = 0; //hold where the data is in the table
int company_length = strlen(company_name); //length of company name as int
int job_length = strlen(position_type);
//create index total for company name
for(int i = 0; company_length > i; i++){ //calculate hash 
	index = index + company_name[i];	
}
for(int i = 0; job_length > i; i++){
	index = index + position_type[i];	
}
//so now we have a big number of all the ascii values for the characters and we need a nice index

index = index % MAX; //make a reasonable index from the hashing function

if(job_listings[index]->position_type == position_type){ //if the first node in the chain is the one we are looking for, copy that into found_job
	found_job->company_name = new char[strlen(job_listings[index] -> company_name)+1];
	strcpy(found_job -> company_name, job_listings[index] -> company_name);
	
	found_job->company_description = new char[strlen(job_listings[index] -> company_description)+1];
	strcpy(found_job->company_description, job_listings[index] -> company_description);

	found_job->location = new char[strlen(job_listings[index] -> location)+1];
	strcpy(found_job->location, job_listings[index] -> location);

	found_job->position_type = new char[strlen(job_listings[index] -> position_type)+1];
	strcpy(found_job->position_type, job_listings[index] -> position_type);

	found_job->skills_required = new char[strlen(job_listings[index] -> skills_required)+1];
	strcpy(found_job -> skills_required, job_listings[index] -> skills_required);

	found_job->programming_languages = new char[strlen(job_listings[index] -> programming_languages)];
	strcpy(found_job->programming_languages, job_listings[index] -> programming_languages);

	found_job->salary = job_listings[index] -> salary;
	found_job->stars = job_listings[index] -> stars;

	found_job->next = NULL;

}

else if(job_listings[index]->position_type != position_type ){ //there is something in that index, then traverse until next is null;
	job * current = job_listings[index];
	while(current -> next){
		if(current -> position_type == position_type){ //if we are sitting on the node we wanted to find, copy it out 
			found_job->company_name = new char[strlen(job_listings[index] -> company_name)+1];
			strcpy(found_job -> company_name, job_listings[index] -> company_name);
			
			found_job->company_description = new char[strlen(job_listings[index] -> company_description)+1];
			strcpy(found_job->company_description, job_listings[index] -> company_description);

			found_job->location = new char[strlen(job_listings[index] -> location)+1];
			strcpy(found_job->location, job_listings[index] -> location);

			found_job->position_type = new char[strlen(job_listings[index] -> position_type)+1];
			strcpy(found_job->position_type, job_listings[index] -> position_type);

			found_job->skills_required = new char[strlen(job_listings[index] -> skills_required)+1];
			strcpy(found_job -> skills_required, job_listings[index] -> skills_required);

			found_job->programming_languages = new char[strlen(job_listings[index] -> programming_languages)];
			strcpy(found_job->programming_languages, job_listings[index] -> programming_languages);

			found_job->salary = job_listings[index] -> salary;
			found_job->stars = job_listings[index] -> stars;

			found_job->next = NULL;
		}
		current = current -> next; //traverse down the chain
	}

}
}
//this function removes a job listing from the table
int job_manager::remove(char * position_type, char * company_name){ //returns 0 if found and deleted job listing, 1 if could not find job listing

int index = 0;
int company_length = strlen(company_name); //length of company name as int
int job_length = strlen(position_type);
//create index total for company name
for(int i = 0; company_length > i; i++){
	index = index + company_name[i];	
}
for(int i = 0; job_length > i; i++){
	index = index + position_type[i];	
}
//so now we have a big number of all the ascii values for the characters and we need a nice index

index = index % MAX; //make a reasonable index from the hashing function

//if it is the first node
if(job_listings[index] -> position_type == position_type){ //if it is the first node in the hash table
	delete [] job_listings[index] -> company_description;
	delete [] job_listings[index] -> company_name;
	delete [] job_listings[index] -> location;
	delete [] job_listings[index] -> position_type; //deallocate memory
	delete [] job_listings[index]-> skills_required;
	delete []job_listings[index] -> programming_languages;;
	delete [] job_listings[index];  //delete node
	job_listings[index] = NULL;
}
else{
	job * current = job_listings[index]; //set temp pointers
	job * previous;
	
	while (current -> next){ //traverse
		previous = current;
		current = current -> next;
		if(current -> position_type = position_type){ //if we find what we are looking for
				delete [] previous -> company_description;
				delete [] previous -> company_name;
				delete [] previous -> location; 
				delete [] previous -> position_type;
				delete [] previous -> skills_required;
				delete [] previous -> programming_languages;
				delete previous;
			}
		}
		if(current -> position_type = position_type){
				delete [] previous -> company_description;
				delete [] previous -> company_name;
				delete [] previous -> location;
				delete [] previous -> position_type;
				delete [] previous -> skills_required;
				delete [] previous -> programming_languages;
				delete previous;
		}
		
	}

}

//this function displays a single job position
int job_manager::display(char * position_type, char * company_name){
int index = 0;
int company_length = strlen(company_name); //length of company name as int
int job_length = strlen(position_type);
//create index total for company name
for(int i = 0; company_length > i; i++){
	index = index + company_name[i];	
}
for(int i = 0; job_length > i; i++){
	index = index + position_type[i];	
}

//so now we have a big number of all the ascii values for the characters and we need a nice index

index = index % MAX; //make a reasonable index from the hashing function
//now insert into the list with the index
//end of hashing, now we will insert
if(job_listings[index]->position_type == position_type){ //if it is the first node in the chain
	//output the first node then
			cout << "Company: " <<job_listings[index] -> company_name <<endl; 
			cout << "Company description: " <<job_listings[index] -> company_description <<endl;
			cout << "Job Location: " <<job_listings[index] -> location <<endl;
			cout << "Position type: " <<job_listings[index] -> position_type <<endl;
			cout << "Skills required: " <<job_listings[index] -> skills_required <<endl;
			cout << "Programming languages used: " <<job_listings[index] -> programming_languages <<endl;
			cout << "Salary: " <<job_listings[index] -> salary <<endl;
			cout << "Rating: " <<job_listings[index] -> stars <<endl;
}

else if(job_listings[index] != NULL){ //there is something in that index, then traverse until next is null;
	job * current = job_listings[index];
	cout << current <<endl;
	cout <<current->next <<endl;
	while(current -> next){
		if(current -> position_type == position_type){
			cout << "Company: " <<job_listings[index] -> company_name <<endl; 
			cout << "Company description: " <<job_listings[index] -> company_description <<endl;
			cout << "Job Location: " <<job_listings[index] -> location <<endl;
			cout << "Position type: " <<job_listings[index] -> position_type <<endl;
			cout << "Skills required: " <<job_listings[index] -> skills_required <<endl;
			cout << "Programming languages used: " <<job_listings[index] -> programming_languages <<endl;
			cout << "Salary: " <<job_listings[index] -> salary <<endl;
			cout << "Rating: " <<job_listings[index] -> stars <<endl;
		}
		current = current -> next;
	}

	return 0; //success
}
else
	return 1; //failed to find
}

