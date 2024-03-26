#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <cctype>


using namespace std;

// STUDENT CLASS + MEMBERS AND METHODS
class Student {
	public:
			string idNumber;
			char fullName[3][20];
			char birthday[3][20];
			string address;
			char gender;
			string degreeProgram;
			string yearLevel;
						
	void getData(){
		string input = "";
			
		cout << "Enter Student ID Number: ";
		
		while(true){
			cin >> input;
			
			bool valid = true;
			
			for(int i = 0; i < input.size(); ++i){
				if(!isdigit(input[i])){
					valid = false;
					break;
				}
			}
			
			if(valid && input.size() == 9){
				idNumber = input;
				cin.clear();
				cin.ignore(123, '\n');
				break;
			} else {
				cout << "Invalid input. Please enter a 9-digit numeric input: ";
				cin.clear();
				cin.ignore(123, '\n');
			}
		}
		
		char nPrmpt[3][20] = {"Given Name", "Middle Name", "Surname"};
		
		for (int cntr = 0; cntr < 3; cntr++){
			cout << "Enter Student's " << nPrmpt[cntr] << ": ";
			while(true){
				cin.getline(fullName[cntr], 20);
			
				bool valid = true;
			
				for(int i = 0; i < strlen(fullName[cntr]); ++i){
					if(!(isalpha(fullName[cntr][i]) || isspace(fullName[cntr][i]))){
						valid = false;
						break;
					}
				}
			
				if(valid){
					cin.clear();
					break;
				} else {
					cout << "Invalid input. Please enter a valid name input: ";
					cin.clear();
				}
			}
			
		}		
				
		char bPrmpt[3][20] = {"Birth Month", "Birth Day", "Birth Year"};
		
		for (int cntr = 0; cntr < 3; cntr++){
		cout << "Enter Student's " << bPrmpt[cntr] << ": ";
			while(true){
				cin.getline(birthday[cntr], 20);
			
				bool valid = true;
			
				for(int i = 0; i < strlen(birthday[cntr]); ++i){
					if(!(isalnum(birthday[cntr][i]) || isspace(birthday[cntr][i]))){
						valid = false;
						break;
					}
				}
			
				if(valid){
						cin.clear();
					break;
				} else {
					cout << "Invalid input. Please enter a birthday name input: ";
					cin.clear();
				}
			}
			
		}		
	
	
		cout << "Enter Student's Address (City Name): ";
		while(true){
			cin >> input;
			
			bool valid = true;
			
			for(int i = 0; i < input.size(); ++i){
				if(!isalpha(input[i])){
					valid = false;
					break;
				}
			}
			
			if(valid){
				address = input;
				cin.clear();
				break;
			} else {
				cout << "Invalid input. Please enter a valid city name input: ";
				cin.clear();
			}
		}
	
		cout << "Enter Student's Gender (M/F): ";
		while(true){
			cin >> gender;
			
			bool valid = true;
			
			if(!(gender == 'M' || gender == 'F')){
				valid = false;
			}
			
			if(valid){
				cin.clear();
				break;
			} else {
				cout << "Invalid input. Please enter a gender input: ";
				cin.clear();
			}
		}
	
		cout << "Enter Student's Degree Program (BSIT/BSCE/BSCoE/BSCS/BSMMA): ";
		while(true){
			cin >> input;
			
			bool valid = true;
			
			for(int i = 0; i < input.size(); ++i){
				if(!(input == "BSIT" || input == "BSCE" || input == "BSCoe" || input == "BSCS" || input == "BSMMA")){
					valid = false;
					break;
				}
			}
			
			if(valid){
				degreeProgram = input;
				cin.clear();
				break;
			} else {
				cout << "Invalid input. Please enter a valid degree program input: ";
				cin.clear();
			}
		}
	
		cout << "Enter Student's Year Level:(1st, 2nd, 3rd, or 4th) ";
		while(true){
			cin >> input;
			
			bool valid = true;
			
			if(!(input == "1st" || input == "2nd" || input == "3rd" || input == "4th")){
				valid = false;
			}
			
			if(valid){
				yearLevel = input;
				cin.clear();
				break;
			} else {
				cout << "Invalid input. Please enter a year level input: ";
				cin.clear();
			}
		}
		
	}

	void display(){
		cout << idNumber << endl << fullName[0] << fullName[1] << fullName[2] << endl << birthday[0] << birthday[1] << birthday[2] << endl << address << endl << gender << endl << degreeProgram << endl << yearLevel;
	}
		
		private:
		
};

//NODE STRUCTURE
struct Node {
	Student student;
	Node* next;
};

//FUNCTION FOR PAUSE AND CLEAR
void pauseClear(){
	system("pause");
	system("cls");
}

//core functions

//ADDS A NEW RECORD
void addNewRecord(const Student& student, Node*& head, Node*& tmp){ // ADD NEW RECORD
	ofstream outFile ("student_records.txt", ios::app); //creates the file
	
	if (head == NULL){
		Node* newNode = new Node;
		newNode->student = student;
		newNode->next = head;
		head = newNode;
		tmp = head;
		
	}else {
		Node* newNode = new Node;
		newNode->student = student;
		tmp->next = newNode;
		tmp = tmp->next;
		tmp->next = NULL;
	}
	
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
			<< student.yearLevel << endl 
			<< endl;
			
	outFile.close();
	
	pauseClear();
};

//this function searches then matches and displays the records, that the user has inputed
void searchRecord(Node* head, string match){
	Node* current = head;
	if (current== NULL){ // it displays a message "No Records Available" if the list is empty

		cout << "---------------------------------------------" << endl
			 << "                Search Record                " << endl	
		     << "---------------------------------------------" << endl
	   
	  		 << "No Records Available..." << endl;
	   
	    system("pause");
		return;
	}
	
	cout << "---------------------------------------------" << endl
		 << "                Search Record                " << endl	
	     << "---------------------------------------------" << endl << endl;
	     
	while (current !=NULL ){ //it displays the records
		if (current->student.fullName[2] == match || current->student.idNumber == match){
			cout << "Student ID Number: " << current->student.idNumber << endl;
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

void deleteRecord(Node*& head, string match){
	Node* current = head;
	Node* prev = NULL;
	
	if (current == NULL){
		cout << "=====================================================" << endl
			 << "                Delete Record" << endl
			 << "=====================================================" << endl << endl;
		
		cout << "NO RECORDS AVAILABLE..." << endl << endl;
		system("pause");
		return;
	}
	
	cout << "=====================================================" << endl
		 << "                   Delete Record                     " << endl
		 << "=====================================================" << endl << endl;
		 
		while (current != NULL){
			if (current->student.idNumber == match){
					prev->next = current->next;
					delete current;
			}
			prev = current;
			current = current->next;
		}
		
		ofstream outFile("student_records.txt");
		
		current = head;
		
		while (current != NULL){
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
				<< current->student.yearLevel << endl 
				<< endl;
			
			current = current->next;
	}
	
	outFile.close();
	
	cout << "Records Updated" << endl;
	
	pauseClear();
}

void displayRecords(Node*& head){
	
	 Node* current = head;
	 
	if (current == NULL){
		cout << "=====================================================" << endl
			 << "                   DISPLAY RECORDS                   " << endl
			 << "=====================================================" << endl << endl;
		
		cout << "NO RECORDS AVAILABLE..." << endl << endl;
		
		system("pause");
		return;
	 }
	 	cout << "=====================================================" << endl
			 << "                   DISPLAY RECORDS                   " << endl
			 << "=====================================================" << endl << endl;
	 
	 int i = 1;
	 while(current != NULL){
	 	cout << "Student " << i << ": " << endl;
	 	cout << "ID: " << current->student.idNumber << endl;
		cout << "Full Name:" << current->student.fullName[0] << " " << current->student.fullName[1] << " " << current->student.fullName[2] << endl;
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

void displaySpecific(Node*& head){
	Node* current = head;
	char gender;
	string program;
	string yearlvl;
	int i = 1;
	 
	if (current == NULL){
		cout << "=====================================================" << endl
			 << "                 DISPLAY RECORDS" << endl
			 << "=====================================================" << endl << endl;
		
		cout << "NO RECORDS AVAILABLE..." << endl << endl;
		
		system("pause");
		return;
	 }
 	cout << "=====================================================" << endl
			 << "                 DISPLAY RECORDS" << endl
			 << "=====================================================" << endl << endl;
	
	int option; 
	cout << "Display Specific Records By: " << endl
		 << "1. Gender" << endl
		 << "2. Degree Program" << endl
		 << "3. Year Level" << endl;
		 
	cin >> option;
	
	switch(option){
		case 1:
			cout << "Type the Gender of Students to View: ";
			while(true){
				cin >> gender;
				
				bool valid = true;
				
				if(!(gender == 'M' || gender == 'F')){
					valid = false;
				}
				
				if(valid){
					cin.clear();
					break;
				} else {
					cout << "Invalid input. Please enter a gender input: ";
					cin.clear();
				}
			}
			
			i = 1;
			while(current != NULL){
				if (current->student.gender == gender){
				 	cout << "Student " << i << ": " << endl;
				 	cout << "ID: " << current->student.idNumber << endl;
					cout << "Full Name:" << current->student.fullName[0] << " " << current->student.fullName[1] << " " << current->student.fullName[2] << endl;
					cout << "Birthday: " << current->student.birthday[0] << " " << current->student.birthday[1] << " " << current->student.birthday[2] << endl;
					cout << "Address: " << current->student.address << endl;
					cout << "Gender: " << current->student.gender << endl;
					cout << "Degree Program: " << current->student.degreeProgram << endl;
					cout << "Year Level: " << current->student.yearLevel << endl << endl;
					
					cout << "----------------------------------" << endl;
					i++;
				}
				current = current->next;
			 }
			 
			break;
		case 2:
			cout << "Type the Degree Program of Students to View (BSIT/BSCE/BSCoE/BSCS/BSMMA)): ";
			cin >> program;
			
			while(true){
				cin >> program;
				
				bool valid = true;
				
				for(int i = 0; i < program.size(); ++i){
					if(!(program == "BSIT" || program == "BSCE" || program == "BSCoe" || program == "BSCS" || program == "BSMMA")){
						valid = false;
						break;
					}
				}
				
				if(valid){
					cin.clear();
					break;
				} else {
					cout << "Invalid input. Please enter a valid degree program input: ";
					cin.clear();
				}
			}
			
			i = 1;
			while(current != NULL){
				if (current->student.degreeProgram == program){
				 	cout << "Student " << i << ": " << endl;
				 	cout << "ID: " << current->student.idNumber << endl;
					cout << "Full Name:" << current->student.fullName[0] << " " << current->student.fullName[1] << " " << current->student.fullName[2] << endl;
					cout << "Birthday: " << current->student.birthday[0] << " " << current->student.birthday[1] << " " << current->student.birthday[2] << endl;
					cout << "Address: " << current->student.address << endl;
					cout << "Gender: " << current->student.gender << endl;
					cout << "Degree Program: " << current->student.degreeProgram << endl;
					cout << "Year Level: " << current->student.yearLevel << endl << endl;
					
					cout << "----------------------------------" << endl;
					i++;
				}
				current = current->next;
			 }
			 
			break;
		case 3:
			cout << "Type the Year Level of Students to View: ";
			while(true){
				cin >> yearlvl;
				
				bool valid = true;
				
				if(!(yearlvl == "1st" || yearlvl == "2nd" || yearlvl == "3rd" || yearlvl == "4th")){
					valid = false;
				}
				
				if(valid){
					cin.clear();
					break;
				} else {
					cout << "Invalid input. Please enter a year level input: ";
					cin.clear();
				}
			}
			
			i = 1;
			while(current != NULL){
				if (current->student.yearLevel == yearlvl){
				 	cout << "Student " << i << ": " << endl;
				 	cout << "ID: " << current->student.idNumber << endl;
					cout << "Full Name:" << current->student.fullName[0] << " " << current->student.fullName[1] << " " << current->student.fullName[2] << endl;
					cout << "Birthday: " << current->student.birthday[0] << " " << current->student.birthday[1] << " " << current->student.birthday[2] << endl;
					cout << "Address: " << current->student.address << endl;
					cout << "Gender: " << current->student.gender << endl;
					cout << "Degree Program: " << current->student.degreeProgram << endl;
					cout << "Year Level: " << current->student.yearLevel << endl << endl;
					
					cout << "----------------------------------" << endl;
					i++;
				}
				current = current->next;
			 }
			break;
	}
	
	pauseClear();
}

void loadFromFile(Node*& head, Node*& tmp){
	ifstream inFile("student_records.txt");
	
	if (!inFile.is_open()) {
        cout << "Error: Unable to open file for reading. Restart the program." << endl;
        return;
    }
    
    string idNumber;
    
	string givenName, middleName, surName;
	string month, day, year;
	
	string address;
	char gender;
	string degreeProgram;
	string yearLevel;
	
	while(inFile >> idNumber >> givenName >> middleName >> surName >> month >> day >> year >> address >> gender >> degreeProgram >> yearLevel){
		
		Node* newNode = new Node; 		// CREATE A NEW NODE
		newNode->student.idNumber = idNumber;
		
		for(int i = 0; i < givenName.size(); i++){
			newNode->student.fullName[0][i] = givenName[i];
		}
		
		newNode->student.fullName[1] = fullName[1];
		newNode->student.fullName[2] = fullName[2];
		
		newNode->student.birthday[0] = birthday[0];
		newNode->student.birthday[1] = birthday[1];
		newNode->student.birthday[2] = birthday[2];
		
		
		newNode->student.address = address;
		newNode->student.gender = gender;
		newNode->student.degreeProgram = degreeProgram;
		newNode->student.yearLevel = yearLevel;
		
		if (head == NULL){					// IF HEAD IS NULL OR THERE'S NO NODES YET IN THE LIST THEN...
			newNode->next = head;			// link to headd
			head = newNode;					// make head point to newNode
			tmp = head;						// make tmp point to newNode
		} else {
			tmp->next = newNode;			// connect prev node or the node tmp is pointing to toward the new one
			tmp = tmp->next;				// make tmp point to "previous" node's next link
			tmp->next = NULL;				// make the new node's next link NULL temporarily
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
    		studentData.display();
    		addNewRecord(studentData, head, tmp);
    		break;
    	case 2:
    		cout << "Search by surname or ID number: ";
    		
			cin >> match;
			    		
    		searchRecord(head, match);
    		break;
		case 3:
    		displayRecords(head);
    		break;
    	case 4:
    		displaySpecific(head);
    		break;
    	case 5:
    		cout << "Enter the ID Number of the Student: ";
    		cin >> match;
    		deleteRecord(head, match);
    		break;
    	case 6:
    		break;
	}
	}while(menuChoice!=6);
	cout << "Members..." << endl;
	
    return 0;
}
