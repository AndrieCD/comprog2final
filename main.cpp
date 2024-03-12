
/*
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

Avoid using \n or new line control character, instead use endl for visibility.

	cout << "Hello World" << endl;
	cout << "Two new lines!" << endl << endl;
	
-------------------------//////////-------------------------

*/



#include <iostream>


using namespace std;

void addNewRecord();
void validateMenuChoice(int *input);

int main(){
	
	int menuChoice = 0;
    
   	cout << "---------------------------------------------------------------------------" << endl;
   	cout << "\t\t\t Welcome to <GROUP NAME HERE> STUDENT INFORMATION SYSTEM" << endl;
   	cout << "---------------------------------------------------------------------------" << endl << endl;
    	
   	cout << "What do you want to do?" << endl;
   	cout << "1. Add New Record" << endl;
   	cout << "2. Search Record" << endl;
   	cout << "3. Display All Records" << endl;
   	cout << "4. Display Specific Record" << endl;
   	cout << "5. Delete Record" << endl;
   	cout << "6. Exit" << endl << endl;
    	
   	cout << "Please type your selection: ";
   	validateMenuChoice(&menuChoice);
    	
    cout << menuChoice << endl;
    	
    switch(menuChoice){
    	case 1:
    		addNewRecord();
    		break;
    	case 2:
    	case 3:
    	case 4:
    	case 5:
    	case 6:
    		break;
	}
	
	cout << "Members..." << endl;
	
    return 0;
}


void addNewRecord(){
	cout << "Adding new record..." << endl;
}

void validateMenuChoice(int *input){
	
	do {
 	   while (!(cin >> *input)) {
  	      cout << "Error! Invalid input, try again: ";
  	      cin.clear();
   	     cin.ignore(123, '\n');
  	  }

 	   if (*input > 6 || *input < 1) {
  	      cout << "Error! Input out of range, try again." << endl;
  	  }
	} while (*input > 6 || *input < 1);

}
