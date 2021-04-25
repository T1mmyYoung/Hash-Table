//Timothy Young, CS 163, Program 3:
//This file contains a class managing a single housing listing.

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

//Housing list class manages a collection of data for a single housing entry. Implemented as an abstract data structure.
class housing_list
{
	public:
		housing_list(void);//Constructor
		~housing_list(void);//Destructor
		int create_entry(char* name, char* location, char* size, char* numBeds, char* distance);//Create a single housing entry collection.
		int copy_entry(const housing_list & a_new_entry);//Copy an existing housing entry collection to the hash table.
		int retrieve(char * name, housing_list & found) const;//Retrieve a housing entry using a character key passed in.
		int display(void) const;//Display a collection of data for a single housing entry.
	//Accessible via scope resolution operator.
	private:
		char* name;//Name of the housing entry.
		char* location;//Location of the housing entry.
		char* size;//Size of the housing entry in sqft.
		char* numBeds;//Number of beds available in the housing entry.
		char* distance;//Distance of the housing entry from school.


};








