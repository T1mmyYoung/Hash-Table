//Timothy Young, CS 163, Program 3:
//This is the header file for the hash table class.


#include "housing_list.h"

//Node structure to create a linear linked list at the head of each chain in the hash table.
struct node
{
	housing_list a_house;//dataType data
	node * next;//node nextPointer

};

//Hash table class as an abstract data structure.
class table
{
	public:
		//Table size must be a prime number for minimal collisions and uniform data distribution;
		table(int size = 599);//599 performs a uniform distribution, mapping each ascii character to a respective index.
		table(table & a_table);//Constructor
		int insert(char * key_value, const housing_list & to_add);//Insert data into the hash table, hashing the key value passed in.
		//Recursive function per program requirements:
		int retrieve(char* listing_to_find, housing_list & found) const;//Retrieve an item using a character passed into retrieve.
		int hash_function(char* key) const;//Cyphers the data in the hash table using the modulus operation.
		~table(void);//Destructor to deallocate dynamic memory.
		
		//Display all items in the list.
		int display_all(int flag) const;
		//Display all information for a particularly matching key.
		int display_retrieve(int flag)const;
		int delete_retrieve(int flag1) const;//Delete an item retrieved by matching key.
		//int find_first();
	private:
		node ** hash_table;//The 'head' of the hash table.Protected by the private section.
		int hash_table_size;//The hash table size set by the constructer function.
		
};
