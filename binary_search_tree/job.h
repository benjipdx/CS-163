/* Benjamin Reichert CS163 

Assignment #4

Purpose: This program is designed to store job opportunities in computer science 
implemented with a binary search tree. Job information included is company name,
type of position, list of skills required, programming languages used at the position, 
company description, location, salary, and desirability to work there. 


*/

#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

struct job {

	char * company_name; //holds company name
	char * company_description; //holds company description
	char * location; //holds job location
	char * position_type; //holds type of job position
	char * skills_required; //holds types of skills required
	char * programming_languages; //holds programming languages needed to work at that job
	int salary; //holds annual salary
	int stars; //the scale on 1-5 on desireablility to work there

};

struct node {

	job job_data; //job struct that holds node data
	node * right; // pointer to the right child
	node * left; // pointer to the left child

};


class job_manager {

	public:
		job_manager(); //default constructor, intializes the databse
		~job_manager(); //default desctructor - deallocates all duynamic memory
		//wrapper functions
		int store(job * &  new_job); //stores a job in the database 
		int search(char * position_type, job returned_jobs[]); //uses an array of returned_jobs to hold the data found in the binary search tree 
		int remove(char * position_type); //returns 0 if found and deleted job listing, 1 if could not find job listing
		int display(char * position_type); //displays a single job listing from the database
		void display_all(); //displays all the items in the bst
		void test(); //test function

	private:
	//all private functions where most of th work is done
		int store(job * & new_job, node * &  root, node * & final);  //stores a job in the database
		void display_all(node * root); //display all the items in the bst, passing in root pointer
		int display(char * position_type, node * & root); // display a specific node
		int search(char * position_type, job returned_jobs[], node * & root, int & index); //return found itemsin the returned_jobs array, retrieval function 
		void destroy(node * &  root); //called for destroying the list 
		int remove(char * position_type, node * & root, node * & child); //remove a specific lisitng
		void get_right(node * root, node * & farthest_right); //returns pointer to farthest right node from root passed in
		void delete_node(node * & root); //delete a node that is passed in as root

		//pointer to the root of the bst
		node * root; 

};
