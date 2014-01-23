/* Benjamin Reichert CS163 

Assignment #4

Purpose: This program is designed to store job opportunities in computer science 
implemented with a binary search tree. Job information included is company name,
type of position, list of skills required, programming languages used at the position, 
company description, location, salary, and desirability to work there. 


*/

#include "job.h"

//this function is the default constructor and it initializes all pointers to null
job_manager::job_manager(){ //default constructor
	//initializing everything to null to start out with
	root = NULL;
}

job_manager::~job_manager(){ //default deconstructor

	destroy(root); //just calls the destroy function

}

//this function recursively destroys the bst that is passed in as root
void job_manager::destroy(node * & root){
	
	if(!root){
		return; //if land at end of leafs, start unwinding stack
	}

	if(root){

		destroy(root -> left); //call function to traverse left node
		destroy(root -> right); //call function to traverse right node

		//on the way back up from returns, delete everything that is dynamic
		delete [] root -> job_data.company_description;
		delete [] root -> job_data.company_name;
		delete [] root -> job_data.location;
		delete [] root -> job_data.position_type;
		delete [] root -> job_data.skills_required;
		delete [] root -> job_data.programming_languages;

		return; //done
	}


}

//this function deletes the node passed in as root
void job_manager::delete_node(node * & root){

	//delete dynamic data
	delete [] root -> job_data.company_description;
	delete [] root -> job_data.company_name;
	delete [] root -> job_data.location;
	delete [] root -> job_data.position_type;
	delete [] root -> job_data.skills_required;
	delete [] root -> job_data.programming_languages;
	root -> right = NULL; //set children to null
	root -> left = NULL;
	root = NULL; //set itself to null

}

//this function adds a job to the bst list by calling a worker function
//this is the wrapper function
int job_manager::store(job * & new_job){
	
	node * final = NULL;
	return store(new_job, root, final);

}


//this function inserts a job into the table 
int job_manager::store(job * & new_job, node * & root, node * & final){

final = NULL; //set final to null, if not already

//final is the pointer once the insert algorithm has reached a leaf

if(root == NULL){

	root = new node; //create a new node to hold the root of the data
	//now we populate the node
	//copy in node data	
	root -> job_data.company_name = new char[strlen(new_job->company_name)+1];
	strcpy(root -> job_data.company_name, new_job->company_name);

	root -> job_data.company_description = new char[strlen(new_job->company_description)+1];
	strcpy(root -> job_data.company_description, new_job->company_description);

	root -> job_data.location = new char[strlen(new_job->location)+1];
	strcpy(root -> job_data.location, new_job->location);

	root -> job_data.position_type = new char[strlen(new_job->position_type)+1];
	strcpy(root -> job_data.position_type, new_job->position_type);

	root -> job_data.skills_required = new char[strlen(new_job->skills_required)+1];
	strcpy(root -> job_data.skills_required, new_job->skills_required);

	root -> job_data.programming_languages = new char[strlen(new_job->programming_languages)+1];
	strcpy(root -> job_data.programming_languages, new_job->programming_languages);

	root -> job_data.salary = new_job -> salary; //copy in salary
	root -> job_data.stars = new_job -> stars; //copy in salary

	root -> right = NULL;
	root -> left = NULL;
	//set left and right pointers to null

	final = root; //for linking up later

	return 10; //for successful insertion
}

else if(root){

//determine if we go right or left first

		//if the added item should go to the right, recursive call right
		if((strcmp(new_job -> position_type, root -> job_data.position_type)) > 0){
			int returned = 0;
			returned = store(new_job, root->right, final);
			if(returned == 10){ //listen for return value, if 10, node was added and now we need to link up
				root -> right = final; //link up the new nodes
			}
			return 1; //now we have succeded
		}
		//if need to traverse left, the same as above, just left
		else if((strcmp(new_job -> position_type, root -> job_data.position_type)) < 0){
			int returned = 0;
			returned = store(new_job, root->left, final);
			if(returned == 10){
				root -> left = final; //link up new node
			}
			return 1; //for success
		}
		//if the added job is the same as root, we put it to the right
		else if((strcmp(new_job -> position_type, root -> job_data.position_type)) == 0){
			int returned = 0;
			returned = store(new_job, root -> right, final);	
			//if the word is the same as the one on the 
			//node we are on, recursive return and move to the right node
			if(returned == 10){
				root -> right = final;
			}
			return 1; //for success
		}

		}

else
	return 0; //for failure

}

//function finds an asked job listing and returns it through the found_job instance as an argument
//wrapper function
int job_manager::search(char * position_type, job returned_jobs[]){ 
	int index = 0;
	return search(position_type, returned_jobs, root, index);

}

//workhorse that takes in returned_jobs array as argument with found jovs
int job_manager::search(char * position_type, job returned_jobs[], node * & root, int & index){ 

	if(!root){ //if there isn't anythign to search through, return
		return 0;
	}
//if there is something, look through bst
	if(root){

		if(strcmp(root -> job_data.position_type, position_type) == 0){ //if they match, copy the data			
		//copy the data
			
			returned_jobs[index].company_name = new char[strlen(root -> job_data.company_name)+1];
			strcpy(returned_jobs[index].company_name, root -> job_data.company_name);

			returned_jobs[index].company_description = new char[strlen(root -> job_data.company_description)+1];
			strcpy(returned_jobs[index].company_description, root -> job_data.company_description);

			returned_jobs[index].location = new char[strlen(root -> job_data.location)+1];
			strcpy(returned_jobs[index].location, root -> job_data.location);

			returned_jobs[index].position_type = new char[strlen(root -> job_data.position_type)+1];
			strcpy(returned_jobs[index].position_type, root -> job_data.position_type);

			returned_jobs[index].skills_required = new char[strlen(root -> job_data.skills_required)+1];
			strcpy(returned_jobs[index].skills_required, root -> job_data.skills_required);

			returned_jobs[index].programming_languages = new char[strlen(root -> job_data.programming_languages)+1];
			strcpy(returned_jobs[index].programming_languages, root -> job_data.programming_languages);

			returned_jobs[index].salary = root -> job_data.salary; //copy in salary
			returned_jobs[index].stars = root -> job_data.stars; //copy in salary

			++index;

			root -> right = NULL;
			root -> left = NULL;
			//set left and right pointers to null
			}
		}
		//if need to traverse right
		else if((strcmp(position_type, root -> job_data.position_type)) > 0){
			return search(position_type, returned_jobs, root->right, index); //traverse right
		}
		//if ned to traverse left
		else if((strcmp(position_type, root -> job_data.position_type)) < 0){
			return search(position_type, returned_jobs, root->left, index); //traverse left
		}
		//if need to traverse right since item is same as node
		else if((strcmp(position_type, root -> job_data.position_type)) == 0){
			return search(position_type, returned_jobs, root->right, index); //traverse right
		}

}

//this function removes a job listing from the table
//wrapper function
int job_manager::remove(char * position_type){ //returns 0 if found and deleted job listing, 1 if could not find job listing

	node * child;

	remove(position_type, root, child);

}

//this function is the removal function, the workhorse
int job_manager::remove(char * position_type, node * & root, node * & child){ //returns 0 if found and deleted job listing, 1 if could not find job listing

	if(!root) //empty tree case
		return 0;
	if(root){
		
		if(strcmp(root -> job_data.position_type, position_type) >  0){ //the node we're on is not what we're looking for	
			int returned;
			returned = remove(position_type, root->right, child);
			if(returned == 10){ //case for if the deleted node has no children
				root -> right = NULL; //remove pointer to the node we just deleted
				return 1; //succeeded
			}
			else if(returned == 20){ //if node only had one child
				root -> right = child;	
				return 1;
			}
			else if(returned == 30){ //if node had more than one child
				root -> right = child;
				return 1;
			}

			return returned; //else, pass on the returned value if doesnt match those cases
		}
		else if(strcmp(root -> job_data.position_type, position_type) < 0){
			
			int returned;
			returned = remove(position_type, root -> left, child);
			if(returned == 10){ //case for if the deleted node has no children
				root -> left = NULL; //remove pointer to the node we just deleted
				return 1; //succeeded
			}
			else if(returned == 20){ //if node only had one child
				root -> right = child;	
				return 1;
			}
			else if(returned == 30){ //if node had more than one child
				root -> right = child;
				return 1;
			}

			return returned; //else, pass on the returned value if doesnt match those cases
		}

		else if(strcmp(root -> job_data.position_type, position_type) == 0){ //we found the node we're looking for

			//now cases for removal

			if((root -> left == NULL) && (root -> right == NULL)){ //if the item is a node with no children
			 	
				delete_node(root);
				return 10;
				
			}

			if((root -> left) && (root -> right == NULL)){ //if the node had a left child, but no right
				
				child = root -> left; //set child to be returned to calling for linking back up
				delete_node(root); //delete the node
				return 20; //return value 

			}

			if((root -> right) && (root -> left == NULL)){ //same as case direclty above, but with child on right, and none on left
				child = root -> right;
				delete_node(root);
				return 20;

			}

			if((root -> right) && (root -> left)){ //if it has two children
				child = root -> left; // set child 
				node * farthest_right; //get the farthest right node of the left child
				get_right(root -> left, farthest_right); //now we have farthest right node
				farthest_right -> right = root -> right; //its right should now point to the right node of root
				delete_node(root); //delete root, return child, link up
				return 30;

			}


		}

	}
	

}

//this function displays a single job position
//wrapper function
int job_manager::display(char * position_type){

	return display(position_type, root);

}

//this function is the display item function, takes in position type as char array and if matches something
//in the bst, it outputs it
int job_manager::display(char * position_type, node * & root){

	if(!root){ //if nothign to search return not found
		return 0;
	}

	if(root){ //if something to search through

		if(strcmp(root -> job_data.position_type, position_type) == 0){ //if they match, output the data
			
			cout << "Company name: " <<root->job_data.company_name <<endl;
			cout << "Company Description: " <<root->job_data.company_description <<endl;
			cout << "Job Location: " <<root->job_data.location <<endl;
			cout << "Job Position: " <<root->job_data.position_type <<endl;
			cout << "Required Skills: " <<root->job_data.skills_required <<endl;
			cout << "Programming Languages: " <<root->job_data.programming_languages <<endl;
			cout << "Salary: " <<root->job_data.salary <<endl;
			cout << "Stars (1-5): " <<root->job_data.stars <<endl;

			return 1; //for success

		}
		//if it should be right, traverse right
		else if((strcmp(position_type, root -> job_data.position_type)) > 0){
			return display(position_type, root -> right);
		}
		//if should be left, go left
		else if((strcmp(position_type, root -> job_data.position_type)) < 0){
			return display(position_type, root -> left);
		}
		//if is the same, go right
		else if((strcmp(position_type, root -> job_data.position_type)) == 0){
			return display(position_type, root -> right);
		}
	}

}

//wrapper for display all jobs in bst
void job_manager::display_all(){

	display_all(root); //call real function

}
//workhorse function to display all things given root pointer
void job_manager::display_all(node * root){

	if(!root){
		return; //if land at end of leafs, start unwinding stack
	}

	if(root){

		display_all(root -> left); //call function to traverse left node
		display_all(root -> right); //call function to traverse right node

		//then output on the way back
		cout << "\n\nCompany name: " <<root->job_data.company_name <<endl;
		cout << "Company Description: " <<root->job_data.company_description <<endl;
		cout << "Job Location: " <<root->job_data.location <<endl;
		cout << "Job Position: " <<root->job_data.position_type <<endl;
		cout << "Required Skills: " <<root->job_data.skills_required <<endl;
		cout << "Programming Languages: " <<root->job_data.programming_languages <<endl;
		cout << "Salary: " <<root->job_data.salary <<endl;
		cout << "Stars (1-5): " <<root->job_data.stars <<endl <<endl <<endl;

		return;
	}


}

//function that takes in farthest_right pointer, and returns it pointing to the farthest right node from root passed in
void job_manager::get_right(node * root, node * & farthest_right){
	
	if(root -> right){ //if can go right
		get_right(root -> right, farthest_right); //go right, recursively
	}
	else{
		//were on the farthest right node	
		farthest_right = root; //if we cant go right, on farthest right node
		return; //return

	}

}
//test function, move along, there is nothing to see here
void job_manager::test(){

	cout << "root is: " <<root <<endl;
	cout << "root->right: " <<root->right <<endl;
	cout << "root->left: " <<root->left <<endl;

	node * far_right;
	get_right(root, far_right);
	node * new_node = new node;
	new_node -> job_data.position_type = new char [100];
	char thing[100] = "hello";
	strcpy(new_node -> job_data.position_type, thing);
	far_right -> right = new_node;
	node * fart;
	get_right(root, fart);
	cout << "tjinggngggg " << fart->job_data.position_type;

}


