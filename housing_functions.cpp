//Timothy Young, CS163, Program 3:
//This file contains the function definitions for the member functions of the housing class.


#include "housing_list.h"
using namespace std;
//Constructor
housing_list::housing_list(void)
{
	this->name = NULL;
	this->location = NULL;
	this->size = NULL;
	this->numBeds = NULL;
	this->distance = NULL;
}

//Destructor for a collection of data for a single housing entry(housing list class).
housing_list::~housing_list(void)
{
	if(this->name != NULL)//Checking to see if the name in the housing class has data already.
	{
		delete[] this->name;//Deallocating the data used up by name so it may be replaced with a new entry.
		this->name = NULL;//Set member variable to NULL to avoid dangling.
	}

	if(this->location != NULL)
	{
		delete[] this->location;//Deallocating the data used up by location so it may be replaced with a new entry.
		this->location = NULL;//Set member variable to NULL to avoid dangling.
	}

	if(this->size != NULL )//Is size empty?
	{
		delete[] this->size;//Deallocate the data.
		this->size = NULL;//Set to NULL.
	}

	if(this->numBeds != NULL)//Is numBeds empty?
	{
		delete[] this->numBeds;//Deallocate the data.
		this->numBeds = NULL;//Set to NULL.
	}

	if(this->distance != NULL)//Is distance empty?
	{
		delete[] this->distance;//Deallocate the data.
		this->distance = NULL;//Set to NULL.
	}
}


int housing_list::create_entry(char* name, char* location, char* size, char* numBeds, char* distance)//Create a new entry from main.
{

	if(name == NULL)
		return 0;
	if(location == NULL)
		return 0;
	if(size == NULL)
		return 0;
	if(numBeds == NULL)
		return 0;
	if(distance == NULL)
		return 0;


	if(this->name != NULL)//Checking to see if the name in the housing class has data already.
	{
		delete[] this->name;//Deallocating the data used up by name so it may be replaced with a new entry.
		this->name = NULL;//Set member variable to NULL to avoid dangling.
	}

	if(this->location != NULL)
	{
		delete[] this->location;//Deallocating the data used up by location so it may be replaced with a new entry.
		this->location = NULL;//Set member variable to NULL to avoid dangling.
	}

	if(this->size != NULL )//Is size empty?
	{
		delete[] this->size;//Deallocate the data.
		this->size = NULL;//Set to NULL.
	}

	if(this->numBeds != NULL)//Is numBeds empty?
	{
		delete[] this->numBeds;//Deallocate the data.
		this->numBeds = NULL;//Set to NULL.
	}

	if(this->distance != NULL)//Is distance empty?
	{
		delete[] this->distance;//Deallocate the data.
		this->distance = NULL;//Set to NULL.
	}


	this->name = new char[strlen(name)+1];//Allocate a dynamic array sized just right, set equal to name.
	strcpy(this->name,name);//Use string copy to copy the copy_from item to the name private data member of the housing_list class.


	this->location = new char[strlen(location)+1];
	strcpy(this->location,location);


	this->size = new char[strlen(size)+1];
	strcpy(this->size,size);

	this->numBeds = new char[strlen(numBeds)+1];
	strcpy(this->numBeds,numBeds);


	this->distance = new char[strlen(distance)+1];
	strcpy(this->distance,distance);

	return 1;
}


int housing_list::copy_entry(const housing_list & copy_from)
{
	if(name != NULL)//Checking to see if the name in the housing class has data already.
	{
		delete[] name;//Deallocating the data used up by name so it may be replaced with a new entry.
		name = NULL;//Set member variable to NULL to avoid dangling.
	}

	if(location != NULL)
	{
		delete[] location;//Deallocating the data used up by location so it may be replaced with a new entry.
		location = NULL;//Set member variable to NULL to avoid dangling.
	}

	if(size != NULL )//Is size empty?
	{
		delete[] size;//Deallocate the data.
		size = NULL;//Set to NULL.
	}

	if(numBeds != NULL)//Is numBeds empty?
	{
		delete[] numBeds;//Deallocate the data.
		numBeds = NULL;//Set to NULL.
	}

	if(distance != NULL)//Is distance empty?
	{
		delete[] distance;//Deallocate the data.
		distance = NULL;//Set to NULL.
	}

	if(copy_from.name)//Does the item we are coping from(by reference) contain something?
	{
		name = new char[strlen(copy_from.name)+1];//Allocate a dynamic array sized just right, set equal to name.
		strcpy(name,copy_from.name);//Use string copy to copy the copy_from item to the name private data member of the housing_list class.
	}

	if(copy_from.location)
	{
		location = new char[strlen(copy_from.location)+1];
		strcpy(location,copy_from.location);
	}

	if(copy_from.size)
	{
		size = new char[strlen(copy_from.size)+1];
		strcpy(size,copy_from.size);
	}

	if(copy_from.numBeds)
	{
		numBeds = new char[strlen(copy_from.numBeds)+1];
		strcpy(numBeds,copy_from.numBeds);
	}

	if(copy_from.distance)
	{
		distance = new char[strlen(copy_from.distance)+1];
		strcpy(distance,copy_from.distance);
	}
	return 1;
}


int housing_list::retrieve(char * name, housing_list & found) const
{
	return 1;
}


int housing_list::display(void) const
{
	cout << "Name: " << name << '\n';
	cout << "Location: "<< location << '\n';
	cout << "Size: " << size << '\n';
	cout << "Number of Beds: " << numBeds << '\n';
	cout << "Distance: " << distance << '\n';
	cout << '\n';
	return 1;
}



