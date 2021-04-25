//Timothy Young, CS 163, Program 3:
//This main function drives the client application for adding, retrieving, and deleting housing entries that exist within the hash table.
//Objects defined for the table and housing list class allow us to access data members and functions for the classes within main. Static
//arrays hold user input, when they are passed in, a dynamic array is created in its place within housing list data collection. This dynamic 
//array is then passed to the hash table and placed at the head of a chain for its respective index.

#include "table_ADT.h"
using namespace std;


bool again();//Prototype for the again function. Allows the user to add another housing entry.
bool display_again();//Prototype to display all housing entries again.

//This function allows the while loop to continue runnning until the user decides to stop adding housing entries.
bool again()
{
	char response;//Holds a character to denote if the user would like to add another activity.
	cout << "Would you like to add another housing listing? Input 'y' or 'Y' to continue: " << endl;
	cin >> response;
	cin.ignore(100,'\n');//Ignore the garbage
	if(response == 'y' || response == 'Y')
		return true;//Adds another listing.
	else
		return false;//Goes to display function.
}

//This function allows the while loop to continue runnning until the user decides to stop removing housing entries.
bool display_again()
{
	char response1;//Holds a character to denote if the user would like to add another activity.
	cout << "Would you like to retrieve/remove another housing listing? Input 'y' or 'Y' to continue: " << endl;
	cin >> response1;
	cin.ignore(100,'\n');//Ignore the garbage
	if(response1 == 'y' || response1 == 'Y')
		return true;//Adds another activity.
	else

		return false;//Goes to display function.
}

int main()
{

	table a_listing;//Object of the table class.
	housing_list to_add, an_entry;//Object of the housing list class.
	//Static arrays store input from user to add,retrieve, and delete entries from the hash table.
	char name[100];
	char location[100];
	char size[100];
	char numBeds[100];
	char distance[100];
	char match[100];	
	//Used for verification and error checking.
	int start = 0;//Insert Success. This is called start because this will always be the beginning of the application 
	char input = 'z';
	int success;//Retrieve success
	//Perform the do statement first, repeat if the while statement is true.
	do{
		cout << "Please enter the name of the house/apartment: ";
		cin.get(name,100);//Read in name.
		cin.ignore(100,'\n');
		cout << "Please enter the location: ";
		cin.get(location,100);//Read in location.
		cin.ignore(100,'\n');
		cout << "Please enter the size(in sqft): ";
		cin.get(size,100);//Read in size.
		cin.ignore(100,'\n');
		cout << "Please enter the number of beds available: ";
		cin.get(numBeds,100);//Read in number of beds.
		cin.ignore(100,'\n');
		cout << "Please enter the distance from school(in miles): ";
		cin.get(distance,100);//Read in distance from school.
		cin.ignore(100,'\n');
		//Creates a new housing listing
		start = to_add.create_entry(name,location,size,numBeds,distance);//Call create entry with an object of the housing class.
		//Inserts this new listing into the hashtable
		a_listing.insert(name, to_add);//Call insert function with an object of the table class.
	}while(again());//Keep running until user does not enter Y.

	cout<<"__________________________________________________________\n"<<endl;
	cout<<"Would you like to display all housing entries?:\n"<<endl;
	cout<<"Enter a 'Y' or 'y' to display all entries:\n"<<endl;
	cin >>input;
	cin.ignore();

	//Display all housing entries if the user enters a Y character.
	if(input == 'y' || input == 'Y')
	{
		cout<< "\n\nThe housing entries you have gathered so far:\n"<<endl;
		a_listing.display_all(start);//Calling display all with an object of the table class.
	}

	//Retrieve a matching data collection from the hash table and display the data:
	do{
		cout <<"Which listing would you like to retrieve and display information about? Please provide the name:\n" << endl;
		cin.get(match,100);//Read in matching key to be retrieved.
		cin.ignore(100,'\n');
		success = a_listing.retrieve(match, an_entry);//Calling retrieve with an object of the table class.

		if(a_listing.retrieve(match, an_entry))
		{
			cout<<"We retrieved this listing:\n ";
			a_listing.display_retrieve(success);//Calling display with an object of the table class.
		}
		cout<<"__________________________________________________________\n"<<endl;

		//Delete the retrieved housing entry if the user enters a Y:
		cout <<"Would you like to delete this listing?\n" << endl;
		cout<<"Enter a 'Y' or 'y' to delete this key and display all entries:\n"<<endl;
		cin >>input;
		cin.ignore();
		if(input == 'y' || input == 'Y')
		{
			a_listing.delete_retrieve(success);//Calling display all with an object of the table class.
		}
		cout<<'\n'<<endl;	
		cout<< "\n\nThe housing entries after deletion is performed:\n"<<endl;
		cout << '\n'<< endl;
		a_listing.display_all(start);//Calling display all with an object of the table class.
	}while(display_again());
		return 0;
	}
