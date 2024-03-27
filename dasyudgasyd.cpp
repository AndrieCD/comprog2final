#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cctype>


using namespace std;

// STUDENT CLASS + MEMBERS AND METHODS
class Student {
	public: //public members of class Student
	
	//CLASS MEMBER DECLARATION
			string idNumber;      
			char fullName[3][20]; 
			char birthday[3][20]; 
			string address;       
			char gender;
			string degreeProgram;
			string yearLevel;
	// END OF CLASS MEMBER DECLARATION		
			
	// CLASS MEMBER FUNCTION
	void getData(){  //Member Function to get data from user
		string input = "";
			
		cout << "Enter Student ID Number: "; //for USER INPUT OF STUDENT ID NUMBER
		
		while(true){ //do this code while the bool valid value is true
			cin >> input; //extracts input from user
			
			bool valid = true;
			
			for(int i = 0; i < input.size(); ++i){ //checks if the input is digit, if not valid value becomes false
				if(!isdigit(input[i])){
					valid = false;
					break;
				}
			}
			
			if(valid && input.size() == 9){ //checks if the input is valid and the size of the input is 9 inputs long
				idNumber = input; //saves input to idNumber
				cin.clear();
				cin.ignore(123, '\n');
				break;
			} else {  //if valid or size is false show this error message
				cout << "Invalid input. Please enter a 9-digit numeric input: ";
				cin.clear();
				cin.ignore(123, '\n');
			}
		}
		
		char nPrmpt[3][20] = {"Given Name", "Middle Name", "Surname"};  //prompt for given, middle and surname
		
		for (int cntr = 0; cntr < 3; cntr++){  //cntr is used to know what part of the name it should be (given, middle, or surname)
			cout << "Enter Student's " << nPrmpt[cntr] << ": ";  //for USER INPUT OF STUDENTS FULL NAME
			while(true){ //do this code while the bool valid value is true
				cin.getline(fullName[cntr], 20);
			
				bool valid = true;
			
				for(int i = 0; i < strlen(fullName[cntr]); ++i){ //checks if the input is a letter or a space, if not valid becomes false
					if(!(isalpha(fullName[cntr][i]) || isspace(fullName[cntr][i]))){
						valid = false;
						break;
					}
				}
			
				if(valid){ //if valid clears the cin for the next input
					cin.clear();
					break;
				} else { //if not valid show this error message
					cout << "Invalid input. Please enter a valid name input: ";
					cin.clear();
				}
			}
			
		}		
				
		char bPrmpt[3][20] = {"Birth Month", "Birth Day", "Birth Year"}; //prompt for month day and year
		
		for (int cntr = 0; cntr < 3; cntr++){ //cntr is used to know which part of the date is to entered (month, day , or year)
		cout << "Enter Student's " << bPrmpt[cntr] << ": "; //for USER INPUT OF STUDENT BIRTHDAY
			while(true){ //do this code while the bool valid value is true
				cin.getline(birthday[cntr], 20);
			
				bool valid = true;
				
				if(cntr == 0){ //if cntr is 0 or the Birth Month, check if input is a letter, if not valid becomes false
					for(int i = 0; i < strlen(birthday[cntr]); ++i){
						if(!(isalpha(birthday[cntr][i]))){
							valid = false;
							break;
						}
					}
				}else { //if cntr is not 0 meaning it is either the day or year, check if input is a number, if not valid becomes false
					for(int i = 0; i < strlen(birthday[cntr]); ++i){
						if(!(isdigit(birthday[cntr][i]))){
							valid = false;
							break;
						}
					}
				}
	
			
				if(valid){ //if valid clear input for the next input
						cin.clear();
					break;
				} else { //if valid is false, show this error message
					cout << "Invalid input. Please enter a birthday input: ";
					cin.clear();
				}
			}
		}
				
	
	
		cout << "Enter Student's Address (City Name): "; //for USER INPUT OF STUDENT ADDRESS
		while(true){ //do this code while the bool valid value is true
			getline(cin, input);
			
			bool valid = true;
			
			for(int i = 0; i < input.size(); ++i){ //checks if input is either a letter or space, if not valid becomes flase
				if(!(isalpha(input[i])|| isspace(input[i]))){
					valid = false;
					break;
				}
			}
			
			if(valid){ //if valid, input is saved to address
				address = input; //saves input to address
				cin.clear(); //clears the input for next input
				break;
			} else { //if not valid, show this error message
				cout << "Invalid input. Please enter a valid city name input: ";
				cin.clear();
			}
		}
	
		cout << "Enter Student's Gender (M/F): "; //for USER INPUT OF STUDENT GENDER
		while(true){ //do this code while the bool valid value is true
			cin >> gender; //input is saved to gender
			
			bool valid = true;
			
			if(!(gender == 'M' || gender == 'F')){ //if the input is not the letter "M" or "F", valid is false
				valid = false;
			}
			
			if(valid){ //if valid, clear input for next user input
				cin.clear();
				break;
			} else { //if valid is false, show this error message. ****NOTE: ERROR MESSAGE WILL SHOW FOR EACH CHARACTER THAT IS INPUTTED BY THE USER****
				cout << "Invalid input. Please enter a gender input: ";
				cin.clear();
			}
		}
	
		cout << "Enter Student's Degree Program (BSIT/BSCE/BSCoE/BSCS/BSMMA): "; //for USER INPUT OF STUDENT PROGRAM
		while(true){//do this code while the bool valid value is true
			cin >> input;
			
			bool valid = true;
			
			for(int i = 0; i < input.size(); ++i){ //loop while i is less than the size of the input
				if(!(input == "BSIT" || input == "BSCE" || input == "BSCoE" || input == "BSCS" || input == "BSMMA")){ //checks if input is "BSIT", "BSCE", "BSCoE", "BSCS", or "BSMMA", if not, valid becomes false
					valid = false;
					break;
				}
			}
			
			if(valid){ //if valid do this code
				degreeProgram = input; //input is saved to degreeProgram
				cin.clear();
				break;
			} else { //if valid is false, show this error message
				cout << "Invalid input. Please enter a valid degree program input: ";
				cin.clear();
			}
		}
	
		cout << "Enter Student's Year Level:(1st, 2nd, 3rd, or 4th) "; //for USER INPUT OF STUDENTS YEAR LEVEL
		while(true){ //do this code while valid value is true
			cin >> input;
			
			bool valid = true;
			
			if(!(input == "1st" || input == "2nd" || input == "3rd" || input == "4th")){ //checks if input is valid, if not valid becomes false
				valid = false;
			}
			
			if(valid){ //if valid do this code
				yearLevel = input; //save input to yearLevel
				cin.clear(); //clear input for next input
				break;
			} else { //if valid is false, show this error message
				cout << "Invalid input. Please enter a year level input: ";
				cin.clear(); //clear input 
			}
		}
		
	}

	void display(){ //this code is to display the added student info or loaded from file student info
		cout << idNumber << endl << fullName[0] << fullName[1] << fullName[2] << endl << birthday[0] << birthday[1] << birthday[2] << endl << address << endl << gender << endl << degreeProgram << endl << yearLevel;
	} //shows the student info
		
		private:
		
};
//END OF CLASS STUDENT 

//NODE STRUCTURE
struct Node {
	Student student;
	Node* next;
};

//FUNCTION FOR PAUSE AND CLEAR
void pauseClear(){ //code is for pausing and clearing the screen
	system("pause");
	system("cls");
}

//core functions

//ADDS A NEW RECORD
void addNewRecord(const Student& student, Node*& head, Node*& tmp){ // ADD NEW RECORD
	ofstream outFile ("student_records.txt", ios::app); //creates the file
	
	if (head == NULL){ //if there is no head, the node made becomes the head
		Node* newNode = new Node;
		newNode->student = student;
		newNode->next = head;
		head = newNode;
		tmp = head;
		
	}else { //if head already exists, this is a part of the node or the tail.
		Node* newNode = new Node;
		newNode->student = student;
		tmp->next = newNode;
		tmp = tmp->next;
		tmp->next = NULL;
	}
	// INPUT INFO TO TXT FILE
	outFile << student.idNumber << endl
			<< student.fullName[0] << endl
			<< student.fullName[1] << endl
			<< student.fullName[2] << endl
			<< student.birthday[0] << endl
			<< student.birthday[1] << endl
			<< student.birthday[2] << endl
			<< student.address << endl
			<< student.gender << endl
			<< student.degreeProgram << endl
			<< student.yearLevel << endl;
			
	outFile.close(); //close txt file
	
	pauseClear();
};

//this function searches then matches and displays the records, that the user has inputed
void searchRecord(Node* head, string match){
	Node* current = head;
	if (current== NULL){ // it displays a message "No Records Available" if the list is empty
	   
	  	cout << "No Records Available..." << endl;
	   
	    system("pause");
		return;
	}
	     
	while (current !=NULL ){ //it displays the records
		if (current->student.fullName[2] == match || current->student.idNumber == match){
			cout << "\nStudent ID Number: " << current->student.idNumber << endl;
			cout << "Full Name: "  << current->student.fullName[0] << " " << current->student.fullName[1] << " " << current->student.fullName[2] << endl;
			cout << "Birthday: "  << current->student.birthday[0] << " " << current->student.birthday[1] << " " << current->student.birthday[2] << endl;
			cout << "Address: "  << current->student.address << endl;
			cout << "Gender: "  << current->student.gender << endl;
			cout << "Degree Program: "  << current->student.degreeProgram << endl;
			cout << "Year Level: "  << current->student.yearLevel << endl;

			cout << "---------------------------------------------" << endl;	
		}
		current = current->next;
	}
	pauseClear();
}

void deleteRecord(Node*& head, string match){ //code to delete records
	Node* current = head;
	Node* prev = NULL;
	
	if (current == NULL){ //if there is nothing on the list, show this message
		
		cout << "NO RECORDS AVAILABLE..." << endl << endl;
		system("pause");
		return;
	}
	
		 
		while (current != NULL){ //if current is not null do this code
			if (current->student.idNumber == match){ //checks if student idNumber is the same as the input
				if (current != head){ //if the chosen is not the head
					prev->next = current->next;
					delete current; //deletes the node
				} else { //if the current is the head
					head = current->next; //give head to the next node
					delete current; //delete the current node
				}
			}
			prev = current;
			current = current->next;
		}
		
		ofstream outFile("student_records.txt"); //output to file
		
		current = head;
		
		while (current != NULL){ //do this code if the current is not NULL or empty
			outFile << current->student.idNumber << endl
				<< current->student.fullName[0] << endl
				<< current->student.fullName[1] << endl
				<< current->student.fullName[2] << endl
				<< current->student.birthday[0] << endl
				<< current->student.birthday[1] << endl
				<< current->student.birthday[2] << endl
				<< current->student.address << endl
				<< current->student.gender << endl
				<< current->student.degreeProgram << endl
				<< current->student.yearLevel << endl;
			
			current = current->next;
	}
	
	outFile.close(); //close file
	
	cout << "Records Updated. " << endl //show user that the records have been updated
		 << "Record for " << match << " has been deleted." << endl; //show user deleted match
	
	pauseClear();
}

void displayRecords(Node*& head){ //code to display all records
	
	 Node* current = head;
	 
	if (current == NULL){ //show if the list is empty
		cout << "=====================================================" << endl
			 << "                   DISPLAY RECORDS                   " << endl
			 << "=====================================================" << endl << endl;
		
		cout << "NO RECORDS AVAILABLE..." << endl << endl;
		
		pauseClear();
		return;
	 }
	 	cout << "=====================================================" << endl
			 << "                   DISPLAY RECORDS                   " << endl
			 << "=====================================================" << endl << endl;
	 
	 int i = 1;
	 while(current != NULL){ //if list is not empty, show the following info
	 	cout << "Student " << i << ": " << endl;
	 	cout << "ID: " << current->student.idNumber << endl;
		cout << "Full Name: " << current->student.fullName[0] << " " << current->student.fullName[1] << " " << current->student.fullName[2] << endl;
		cout << "Birthday: " << current->student.birthday[0] << " " << current->student.birthday[1] << " " << current->student.birthday[2] << endl;
		cout << "Address: " << current->student.address << endl;
		cout << "Gender: " << current->student.gender << endl;
		cout << "Degree Program: " << current->student.degreeProgram << endl;
		cout << "Year Level: " << current->student.yearLevel << endl << endl;
		
		cout << "----------------------------------" << endl;
		
		i++;
		
		current = current->next;
	 }
	
	pauseClear();
};

void displaySpecific(Node*& head){ //code to display only specific records, only of same gender, program, or yearlevel.
	Node* current = head;
	//VARIABLE DECLARATION
	char gender;
	string program;
	string yearlvl;
	int i = 1;
	 
	if (current == NULL){ //if the list is empty, show this error message
		cout << "NO RECORDS AVAILABLE..." << endl << endl;
		
		system("pause");
		return;
	 }
	
	int option; //OPTION VARIABLE DECLARATION
	cout << "Display Specific Records By: " << endl
		 << "1. Gender" << endl
		 << "2. Degree Program" << endl
		 << "3. Year Level" << endl << endl
		 << "Enter your choice: ";
		 
	cin >> option; //user input for option
	
	switch(option){//switch case depending on user input
		case 1: //if user inputs 1 run this code
			cout << "Type the Gender of Students to View: ";
			while(true){ //do this code while bool valid value is true
				cin >> gender; //accepts user input
				
				bool valid = true;
				
				if(!(gender == 'M' || gender == 'F')){ //if the input is not "M" or "F" valid becomes false
					valid = false;
				}
				
				if(valid){ //if valid is true clear input 
					cin.clear();
					break;
				} else { //if valid is false show this error message
					cout << "Invalid input. Please enter a gender input: ";
					cin.clear(); //clear input 
				}
			}
			
			i = 1; //this is a counter
			while(current != NULL){ //do this code while current is not NULL
				if (current->student.gender == gender){ //checks if the saved student gender matches the gender being found, if true run this code
				 	cout << "\nStudent " << i << ": " << endl;
				 	cout << "ID: " << current->student.idNumber << endl;
					cout << "Full Name:" << current->student.fullName[0] << " " << current->student.fullName[1] << " " << current->student.fullName[2] << endl;
					cout << "Birthday: " << current->student.birthday[0] << " " << current->student.birthday[1] << " " << current->student.birthday[2] << endl;
					cout << "Address: " << current->student.address << endl;
					cout << "Gender: " << current->student.gender << endl;
					cout << "Degree Program: " << current->student.degreeProgram << endl;
					cout << "Year Level: " << current->student.yearLevel << endl << endl;
					
					cout << "----------------------------------" << endl;
					i++; //increment i for next student information
				}
				current = current->next;
			 }
			 
			break;
		case 2: //if user inputs 2 run this code
			cout << "Type the Degree Program of Students to View (BSIT/BSCE/BSCoE/BSCS/BSMMA)): ";
			
			while(true){ //do this code while bool valid value is true
				cin >> program; //accepts user input
				
				bool valid = true;
				
				for(int i = 0; i < program.size(); ++i){ //loop this code while i is less than the size of the input
					if(!(program == "BSIT" || program == "BSCE" || program == "BSCoe" || program == "BSCS" || program == "BSMMA")){ //checks if the input is correct, if not, valid becomes false
						valid = false;
						break;
					}
				}
				
				if(valid){ //if valid, clear input
					cin.clear();
					break;
				} else { //if valid is false, show this error message
					cout << "Invalid input. Please enter a valid degree program input: ";
					cin.clear();
				}
			}
			
			i = 1; //counter
			while(current != NULL){ //do this code while current is not NULL
				if (current->student.degreeProgram == program){ //checks if the saved degreeProgram matches the program being searched, if the same, run this code
				 	cout << "\nStudent " << i << ": " << endl;
				 	cout << "ID: " << current->student.idNumber << endl;
					cout << "Full Name:" << current->student.fullName[0] << " " << current->student.fullName[1] << " " << current->student.fullName[2] << endl;
					cout << "Birthday: " << current->student.birthday[0] << " " << current->student.birthday[1] << " " << current->student.birthday[2] << endl;
					cout << "Address: " << current->student.address << endl;
					cout << "Gender: " << current->student.gender << endl;
					cout << "Degree Program: " << current->student.degreeProgram << endl;
					cout << "Year Level: " << current->student.yearLevel << endl << endl;
					
					cout << "----------------------------------" << endl;
					i++; //increment i for next student info
				}
				current = current->next;
			 }
			 
			break;
		case 3: //if user inputs 3 run this code
			cout << "Type the Year Level of Students to View: ";
			while(true){ //do this while bool valid value is true
				cin >> yearlvl; //accepts user input
				
				bool valid = true;
				
				if(!(yearlvl == "1st" || yearlvl == "2nd" || yearlvl == "3rd" || yearlvl == "4th")){ //checks if user input is correct, if not, valid becomes false
					valid = false;
				}
				
				if(valid){ //if valid, clear input
					cin.clear();
					break;
				} else { //if valid is false, show this error message 
					cout << "Invalid input. Please enter a year level input: ";
					cin.clear(); //clear input
				}
			}
			
			i = 1; //counter
			while(current != NULL){ //do this while current is not NULL or not at the end
				if (current->student.yearLevel == yearlvl){ //checks if ssaved student yearLevel is the same as the yearlvl being searched, if same, run this code
				 	cout << "\nStudent " << i << ": " << endl;
				 	cout << "ID: " << current->student.idNumber << endl;
					cout << "Full Name:" << current->student.fullName[0] << " " << current->student.fullName[1] << " " << current->student.fullName[2] << endl;
					cout << "Birthday: " << current->student.birthday[0] << " " << current->student.birthday[1] << " " << current->student.birthday[2] << endl;
					cout << "Address: " << current->student.address << endl;
					cout << "Gender: " << current->student.gender << endl;
					cout << "Degree Program: " << current->student.degreeProgram << endl;
					cout << "Year Level: " << current->student.yearLevel << endl << endl;
					
					cout << "----------------------------------" << endl;
					i++; //increment counter for next student info
				}
				current = current->next;
			 }
			break;
	}
	
	pauseClear(); //clears screen 
}

void loadFromFile(Node*& head, Node*& tmp){
	ifstream inFile("student_records.txt");
	
	if (!inFile.is_open()) {
        cout << "Error: Unable to open file for reading. Restart the program." << endl;
        return;
    }
	
	string line;
	Node* newNode = new Node;
	int counter = 1;
	while(!inFile.eof()){
		
		getline(inFile, line);
		
		switch(counter){
			case 1:
				newNode->student.idNumber = line;
				counter++;
				break;
			case 2:
				for(int i = 0; i < line.size(); i++){
					newNode->student.fullName[0][i] = line[i];
				}
				counter++;
				break;
			case 3:
				for(int i = 0; i < line.size(); i++){
					newNode->student.fullName[1][i] = line[i];
				}
				counter++;
				break;
			case 4:
				for(int i = 0; i < line.size(); i++){
					newNode->student.fullName[2][i] = line[i];
				}
				counter++;
				break;
			case 5:
				for(int i = 0; i < line.size(); i++){
					newNode->student.birthday[0][i] = line[i];
				}
				counter++;
				break;
			case 6:
				for(int i = 0; i < line.size(); i++){
					newNode->student.birthday[1][i] = line[i];
				}
				counter++;
				break;
			case 7:
				for(int i = 0; i < line.size(); i++){
					newNode->student.birthday[2][i] = line[i];
				}
				counter++;
				break;
			case 8:
				newNode->student.address = line;
				counter++;
				break;
			case 9:
				for(int i = 0; i < line.size(); i++){
					newNode->student.gender = line[i];
				}
				counter++;
				break;
			case 10:
				newNode->student.degreeProgram = line;
				counter++;
				break;
			case 11:

				newNode->student.yearLevel = line;
				
				if (head == NULL){					// IF HEAD IS NULL OR THERE'S NO NODES YET IN THE LIST THEN...
					newNode->next = head;			// link to headd
					head = newNode;					// make head point to newNode
					tmp = head;						// make tmp point to newNode
				} else {
					tmp->next = newNode;			// connect prev node or the node tmp is pointing to toward the new one
					tmp = tmp->next;				// make tmp point to "previous" node's next link
					tmp->next = NULL;				// make the new node's next link NULL temporarily
				}
				newNode = new Node;
				counter = 1;
				break;
		}
	}
	
	inFile.close();
}

void mainMenu(int &menuChoice){
	do{
		cout << "---------------------------------------------------------------------------" << endl
			 << "             WELCOME TO Forda Grades STUDENT INFORMATION SYSTEM            " << endl
			 << "---------------------------------------------------------------------------" << endl << endl
		 
			<< "What do you want to do?" << endl
		 	<< "1. Add New Record" << endl
		 	<< "2. Search Record" << endl
		 	<< "3. Display All Records" << endl
		 	<< "4. Display Specific Record" << endl
		 	<< "5. Delete Record" << endl
		 	<< "6. Exit" << endl << endl;
    	
   		cout << "Please type your selection: ";
   		
   		// INPUT VALIDATION
		do{	
		while(!(cin>>menuChoice)){  // Repeat until a valid integer input is received.
			cout << "Enter a valid numeric input: ";
			cin.clear();
			cin.ignore(123, '\n');
		}
			
		if (menuChoice > 6 || menuChoice < 1){          //If the input does not fall inside the menu's available options...
			cout << "Enter a valid numeric input: ";    //prompt the user to enter a valid input.
		}

		}while(menuChoice > 6 || menuChoice < 1);   // Repeat the loop until a valid input is acquired.
   		
   		if (menuChoice == 6)
   			break;
   		
	}while(menuChoice < 1 || menuChoice > 6);

	system("cls");
}

int main(){
	int menuChoice;
	Student studentData;
	Node* head = NULL;
	Node* tmp = NULL;
	string match;
	
	loadFromFile(head, tmp);
	
	do{
		
	    mainMenu(menuChoice);
	    
	    switch(menuChoice){
	    	case 1:
	    		studentData.getData();
	    		addNewRecord(studentData, head, tmp);
	    		break;
	    	case 2:
	    		cout << "---------------------------------------------" << endl
					 << "                Search Record                " << endl	
				     << "---------------------------------------------" << endl << endl;
		     
	    		cout << "Search by surname or ID number: ";
	    		
	    		cin.clear();
	    		cin.ignore(123, '\n');
				getline(cin, match);
				    		
	    		searchRecord(head, match);
	    		break;
			case 3:
	    		displayRecords(head);
	    		break;
	    	case 4:
	    		cout << "=====================================================" << endl
					 << "               DISPLAY SPECIFIC RECORDS              " << endl
					 << "=====================================================" << endl << endl;
			 
	    		displaySpecific(head);
	    		break;
	    	case 5:
	    		cout << "=====================================================" << endl
					 << "                Delete Record" << endl
					 << "=====================================================" << endl << endl;
					 
	    		cout << "Enter the ID Number of the Student: ";
	    		cin >> match;
	    		deleteRecord(head, match);
	    		break;
	    	case 6:
	    		break;
		}
	}while(menuChoice!=6);
	
	cout << "Forda Grades: " << endl
		 << "Members: " << endl
		 << "        Ric Josef De Gracia" << endl 
		 << "        Andrie Detera      " << endl
		 << "        Angelito Jose Regero" << endl;
	
    return 0;
}
