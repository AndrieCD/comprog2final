
/*
REQUIREMENTS
   The program must use the following programming concepts:
a. Functions
b. Arrays
c. Structures
d. Pointers and/or Linked List
e. File Manipulation

   The program must have a Main Menu wherein the user can select the operation
he wants. Operations must be:
a. Add new record
b. Search record
c. Delete record
d. Display records

The program must store the following:
a. Student ID Number
b. Full Name
c. Birthday
d. Address
e. Gender
f. Degree Program
g. Year Level

----SAMPLE----
Welcome to Group Pr0gr@mm@z Student Information System
What do you want to do?
1. Add New Record
2. Search Record
3. Display All Records
4. Display Specific Record
5. Delete Record
6. Exit
Please type your selection: __


----additional functions---
-save data to file on exit
-load data from file on start
-(sorting for all records display???)


---FORMAT---

Code blocks should have the open curly braces in the same line as the control line, for example:

    if (!n){            <--- open curly brace on the same line as control

    }

    while (true){       <--- open curly brace on the same line as control

    }
-------------------------//////////-------------------------

Code blocks should have indentations for the lines within the block, for example:

    if (x==y){
        y++;
        x++;
        
        if (x>10){
            x--;
            y++;
        }
    }
-------------------------//////////-------------------------

Use camel case when initializing variables or functions, for example:

    int myNumber;						// lowerCase then upperCase for first letters
    char myCharacterHere;				//		helloWorld  

    void thisIsMyFunction();
-------------------------//////////-------------------------

Utilize spaces for readability and visibility as much as possible, for exampe:

	while (true)
         ^ space
	     
	if (x == y)
	     ^  ^ space
	     
	for (int hi = 0; hi < hello; hi++)
                    ^ space     ^ space
-------------------------//////////-------------------------

Avoid using \n or new line control character, instead use endl for visibility and consistency.

	cout << "Hello World" << endl;
	cout << "Two new lines!" << endl << endl;
	
-------------------------//////////-------------------------

// SAVE TO FILE EVERY RECORD ADDED (???)
// LOAD FROM FILE ON PROGRAM START

*/



#include <iostream>

#include "Node.h"
#include "Student.h"

using namespace std;

class Student {
	public:
		Student();
		virtual ~Student();
		void getData();
		void display();
		
	private:
		string idNumber;
		string fullName;
		string birthday;
		string address;
		string gender;
		string degreeProgram;
		int yearLevel;
};

struct Node {
	Student student;
	Node* next;
};


//core functions
void addNewRecord();
void searchRecord();
void deleteRecord();
void displayRecords();

void mainMenu(int &menuChoice){
	do{
		cout << "---------------------------------------------------------------------------" << endl
			 << "           Welcome to <GROUP NAME HERE> STUDENT INFORMATION SYSTEM         " << endl
			 << "---------------------------------------------------------------------------" << endl << endl
		 
			 << "What do you want to do?" << endl
		 	<< "1. Add New Record" << endl
		 	<< "2. Search Record" << endl
		 	<< "3. Display All Records" << endl
		 	<< "4. Display Specific Record" << endl
		 	<< "5. Delete Record" << endl
		 	<< "6. Exit" << endl << endl;
    	
   		cout << "Please type your selection: ";
   		cin >> menuChoice;
	}while(menuChoice < 0 || menuChoice > 6);
}


int main(){
	int menuChoice;
	Student studentData;
	
	do{
	    	
    mainMenu(menuChoice);
    
    switch(menuChoice){
    	case 1:
    		studentData.getData();
    		studentData.display();
    		addNewRecord();
    		break;
    	case 2:
    	case 3:
    	case 4:
    	case 5:
    	case 6:
    		break;
	}
	}while(true);
	cout << "Members..." << endl;
	
    return 0;
}


void addNewRecord(){
	cout << "Adding new record..." << endl;
}
