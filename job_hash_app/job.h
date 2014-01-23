/* Benjamin Reichert CS163 

Assignment #3

Purpose: This program is designed to store job opportunities in computer science 
implemented with a hash table and chaining. Job information included is company name,
type of position, list of skills required, programming languages used at the position, 
company description, location, salary, and desirability to work there. 


*/

#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

const int MAX = 5; //array size for data;

struct job {

	char * company_name; //holds company name
	char * company_description; //holds company description
	char * location; //holds job location
	char * position_type; //holds type of job position
	char * skills_required; //holds types of skills required
	char * programming_languages; //holds programming languages needed to work at that job
	int salary; //holds annual salary
	int stars; //the scale on 1-5 on desireablility to work there

	job * next; //next pointer for chains
};

class job_manager{

	public:
		job_manager(); //default constructor, intializes the databse
		~job_manager(); //default desctructor - deallocates all duynamic memory
		int insert(job * & new_job); //where new_job is the job struct to be added to the database, adds it to the database
		int find(char * position_type, char * company_name, job * & found_job); //return the found_job struct filled with data about the job that is asked thrugh
		//position tupe and company name
		//removes a job listing from the database
		int remove(char * position_type, char * company_name); //returns 0 if found and deleted job listing, 1 if could not find job listing
		int display(char * position_type, char * company_name); //displays a single job listing from the database

	private:
		job ** job_listings; //dynamically allocated pointer to an array of head pointers


};
