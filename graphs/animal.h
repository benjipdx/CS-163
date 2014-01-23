/*
Benjamin Reichert

Assignment #5, the 5 installment in the data structures class of programs
6/13/13

PURPOSE: This program uses a graph ADT to organize a zoo and its animals. 
Each animal is positionally related to other animals in the zoo, through 
an adjacency edge list

*/

#include <cstring>
#include <iostream>
#include <cctype>
using namespace std;

const int MAX_ARRAY_SIZE = 10;

struct vertex
{
 	char * name;
	char * species;
	char * location;
	int health; //1-10 on a scale of how healthy the animal is
	char * add_info;
	char * date;

};

struct node
{
	vertex * animal_info;
	node * next;

};

struct list_item
{
	bool visit;
	vertex * animal_vertex;
	node * head;

};


class zoo {

	public:
		zoo();
		~zoo();
		//wrapper functions
		int add_animal(); //prompts user to add an animal, and the stores the animal in the graph data structure
		void display_all(); //displays all animals in the data structure
		int create_link(); // link to animals together (adds to the adjacency list of the first animal entered); assumes the user has already added an animal 
		//that they are requesting to be linked to another, do not call without creating animals first
		int retrieve_adjacent(char * name, vertex * & retrieved_animals); //where retrieved animals is a vertex pointer that will be turned into an array and passed back
		//name is the animal name we are looking for to retrieve all of its adjacent animals

	private:
		list_item * adjacency_list;
		void display_recursive_LLL(node * head);

		//int add_animal(vertex * new_animal);



};
