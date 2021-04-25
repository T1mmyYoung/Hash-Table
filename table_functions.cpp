//Timothy Young, CS 163, Program 3:
//This file contains the function definitions for the member functions of the
//hash table class used for this program.

#include "table_ADT.h"
using namespace std;
//Constructor
table::table(int size)
{
	hash_table_size = size;	
	hash_table = new node*[size];//Creating a chain of new head nodes.

	for(int i = 0;i<size;i++)
		hash_table[i]=NULL;//Initializing the head of each chain that was just allocated to NULL.
}

//Copy Constructor
table::table(table & a_listing)
{
	hash_table = new node*[hash_table_size];//Allocate dynamic memory for a chain of new head nodes.

	for(int i = 0;i<hash_table_size;i++)
	{
		node* source = a_listing.hash_table[i];//Setting the head of the hash table to a node pointer.
		node* destination;//Declaring a node pointer named destination.
		if(source == NULL)
		{
			hash_table[i] = NULL;//Set these elements to NULL.
			continue;//No data to copy, continue to next row.
		}

		destination = new node;//Allocate dynamic memory the node pointer destination.
		destination->a_house = source->a_house;//set the data member of destination to the data member of source.

		hash_table[i] = destination;//Set the head of the chain to the data held by destination.
		source = source->next;//Traverse to the next node.

		while(source!=NULL)
		{
			node* temp = new node;//Allocating dynamic memory for a temporary node.
			destination->next = temp;//Set the next pointer of destination to this newly allocated dynamic memory.
			destination = temp;//Set destination to temp.

			destination->a_house = source->a_house;//Set the data member of destination to the data member of source.
			source = source->next;//Traverse to the next node.
		}
		destination->next = NULL;//Set the last pointer to null, which will be the end of the list.
	}
}


//Destructor using pointer arithmetic.
table::~table(void)
{
	node* p = *hash_table;
	node* q;
	for(int i = 0;i<hash_table_size;i++)	
	{
		//p = *hash_table;//Pointer p holds the first index of the hash table.
		while(NULL!=p)
		{	
			q = ++p;//Q is set to the next index in the hash table.
			delete[] p;//Delete the memory p is pointing too.
			p = NULL;
			p = q;//Set P to the value of q(the next index).
		}
		//*hash_table = NULL;
	}

}

//Hash function definition:
int table::hash_function(char* key) const
{
	int size = hash_table_size;//Accessing the private data member hash_table_size.
	int hash = *key%size;//Mod the character passed in. Set this to variable hash.

	return hash;//Return this hash index.
}


//Using the hash function, inserting at the head of the chain.
int table::insert(char* key_value, const housing_list & to_add)
{
	node* temp = new node;//Allocate dynamic memory for a temporary node.
	if(!temp->a_house.copy_entry(to_add))
	{
		delete temp;//Delete the dynamic memory allocated for temp.
		temp = NULL;//Set to NULL to avoid dangling pointers.
		return 0;
	}


	int index = hash_function(key_value);//Set the index to a value calculated and returned by the hash function.
	temp->next = hash_table[index];//Set temp's next pointer to a index in the chain of head pointers.
	hash_table[index] = temp;//Set an index in the chain of head pointers to temp. Allocates a new node for the chain.
	return index;//Return the index for error checking and display function.
}

//Retrieve function to retrieve a collection of data within a particular key formed by a chain of head nodes.
//Each head node has it's own key respectivley.
int table::retrieve(char* listing_to_find, housing_list & found) const
{
	char* argument = listing_to_find;//Key being passed in to retrieve.
	bool success = false;//Initialize success to false for while loop.

	int index = hash_function(argument);//Set index to value returned by hash function.

	node * current = hash_table[index];//Set a current pointer to a particular index in the chain of head pointers.
	if(current==NULL)
		return 0;

	while(current && !success)
	{
		success = current->a_house.retrieve(listing_to_find, found);//Access the table object recursivley with member access(.), using the indirect member access operator with node and object.
		current = current->next;//Traverse to the next node in the linear linked list in that chain.
	}

	return index;//Return the index that was set by the hash function.
}


//Display all hash table entries in the chain of head pointers.
int table::display_all(int flag)const//Flag must be passed in so that the display function has the first index to start displaying from.
{
	int size = hash_table_size;//Size of the hash table.
	int i = flag;//Setting i to first index passed in.

	while(i<size)//While the index is less than the table size.
	{	
		node*current = hash_table[i];//Declare a node pointer set to the head element at that index in the chain.
		while(current)//While current is not NULL.
		{
			cout<< "Index: " << i <<endl;//Provides the index of a particular chain to the client.
			current->a_house.display();//Calling the display function. Display is a housing list function for display a single housing entry collection.
			current = current->next;//Travers to the next node.
		}
		++i;//Increment i(pre-fix).
	}
	return 1;
}


//Display the collection of data retrieved at that index of the hash table.
int table::display_retrieve(int flag)const
{
	int i = flag;//Set i to the index variable passed in.
	node* current = hash_table[i];//Declare a current pointer initialized to a hash table head pointer at index i.
	if(current == NULL)
		return 0;
	
	current->a_house.display();//Call the display functin for a single collection of data for a housing entry.
	return 1;
}


int table::delete_retrieve(int flag1) const//Delete an item retrieved by matching key.
{
	int i = flag1;
	node* previous;
	node* current = hash_table[i];

	if(current==NULL)
		return 0;

	while(current->next!=NULL)
	{
		previous = current;
		current = current->next;
	}
	
	if(current->next != NULL)
	{
		previous->next = current->next;
	}
	
	delete current;
	current = NULL;
	hash_table[i]=NULL;
	return 1;

}

