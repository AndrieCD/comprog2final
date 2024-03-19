#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>

#include <fstream>

using namespace std;

struct Player { 			// PLAYER DATA STRUCTURE DECLARATION
	string nickname;  	    // STRING NICKNAME MEMBER DECLARATION
	int age;  	    		// INT AGE MEMBER DECLARATION
	double score1;  	    // DOUBLE SCORE1 MEMBER DECLARATION
	double score2; 			// DOUBLE SCORE2 MEMBER DECLARATION
}; 

struct Node { 				// NODE STRUCTURE DECLARATION
    Player player;  		// NODE DATA ITEM DECLARATION (PLAYER STRUCTURE VARIABLE)
    Node* next; 			// NODE LINK || POINTER || NEXT
}; 

// ADD RECORD FUNCTION WITH THE PLAYER STRUCTURE VARIABLE, HEAD POINTER (NODE), AND TMP POINTER (NODE) AS PARAMETERS PASSED FROM MAIN().
void addRecord(const Player& player, Node*& head, Node*& tmp) {	
	ofstream outFile("player_records.txt", ios::app); // create the file	
	
	if (head == NULL){					// IF HEAD IS NULL OR THERE'S NO NODES YET IN THE LIST THEN...
		Node* newNode = new Node; 		// CREATE A NEW NODE
		newNode->player = player;		// data assignment
		newNode->next = head;			// link to headd
		head = newNode;					// make head point to newNode
		tmp = head;						// make tmp point to newNode
		
//		cout << "first node created";	//DEBUGGING
		
	} else {
//		cout << "there's already a first node...";	//DEBUGGING
		
		Node* newNode = new Node;		// new node
		newNode->player = player;		// data assignmetn
		tmp->next = newNode;			// connect prev node or the node tmp is pointing to toward the new one
		tmp = tmp->next;				// make tmp point to "previous" node's next link
		tmp->next = NULL;				// make the new node's next link NULL temporarily
		
//		cout << "new node created after first";	//DEBUGGING
	}
	
//	cout << "will now save to file...";
	
	outFile << player.nickname << endl; // save the nickname to file
	outFile << player.age << endl; // save the age to file
	outFile << player.score1 << " " << player.score2; //save the recorded scores in a single line 
 
	outFile << endl << endl; 
	
	outFile.close(); // close the file
	
//	cout << "\nsaved to file?";

//	cout << tmp -> player.nickname;  ///DEBUGGING
	
	system("pause");	// PAUSE FOR VIEWING
	system("cls");		// BEFORE CLEARING THE SCREEN
}

//This function shows every record that is kept in the list.
void viewRecords(Node*& head) {			// KAY RIC JOSEF ITO
	Node* current = head;   //Initialize a pointer to the head of the list.
	
	if (current == NULL){   //Display a message stating that no records are available if the list is empty.
 		cout << "=====================================================" << endl;
		cout << "\t\t    VIEW RECORDS" << endl;
		cout << "=====================================================" << endl << endl;
		
		cout << "NO RECORDS AVAILABLE..." << endl << endl;
	 }
	//Print the details of each entry after going through the list.
	while (current != NULL) {
		cout << "Nickname: " << current->player.nickname << endl;
		cout << "Age: " << current->player.age << endl;
		cout << "Score 1: " << current->player.score1 << endl;
		cout << "Score 2: " << current->player.score2 << endl << endl;
		cout << "----------------------------------" << endl << endl;
		current = current->next;
 	}
 	
 	system("pause");
	system("cls");
}

// THIS FUNCTION COMPUTES FOR THE AVERAGE OF THE TWO SCORES FOR EACH PLAYER.
void computeAverage(Node*& head) {	// KAY ANGIE ITO
	Node* current = head;		//NODE DECLARATION
	
	if (current == NULL){		//THIS RUNS IF THE CURRENT NODE IS EMPTY
	 	cout << "=====================================================" << endl;
		cout << "\t\t   COMPUTE AVERAGE" << endl;
		cout << "=====================================================" << endl << endl;
		
		cout << "NO RECORDS AVAILABLE..." << endl << endl;
	}
	 
	while (current != NULL) {		//THIS CODE RUN IF THE CURRENT NODE IS NOT EMPTY .
		double average = (current->player.score1 + current->player.score2) / 2.0;		//THIS CODE COMPUTES FOR THE AVERAGE OF THE TWO SCORES
		cout << "Nickname: " << current->player.nickname << endl;
		cout << "Average Score: " << average << endl;
		cout << "----------------------------------" << endl << endl;
		current = current->next;		//MOVES THE CURRENT POINTER TO THE NEXT NODE.
	 }
	system("pause");
	system("cls");	 
}

//This function displays the player(s) with the maximum average score.
void showMaxAverage(Node*& head) {	// KAY RIC ITO
	Node* current = head;   // Initialize a pointer to the head of the list.
	
	if (current == NULL){   //Display a message stating that no records are available if the list is empty.
 		cout << "=====================================================" << endl;
		cout << "\t\t   SHOW MAX AVERAGE" << endl;
		cout << "=====================================================" << endl << endl;
		
		cout << "NO RECORDS AVAILABLE..." << endl << endl;
	}
	
	double maxAverage = -1; // DECLARATIONialize to a non-valid value
	while (current != NULL) {   // Find the maximum average score in the list.
		double average = (current->player.score1 + current->player.score2) / 2.0;
		if (average > maxAverage) {
			maxAverage = average;
		}
	current = current->next;
	}

// Now, iterate again to display players with the max average
	current = head;
	while (current != NULL) {
		double average = (current->player.score1 + current->player.score2) / 2.0;
		if (average == maxAverage) {			// displays the name of the player who got the highest avg score
			cout << "Nickname: " << current->player.nickname << endl;
			cout << "Average Score: " << average << endl;
			cout << "----------------------------------" << endl << endl;
		}	
	current = current->next;
	}
	
	system("pause");
	system("cls");	 
}

//THIS FUNCTION IS TO SHOW THE PLAYER WITH THE LOWEST AVERAGE SCORE.
void showMinAverage(Node*& head) {	// KAY ANGIE ITO
	Node* current = head;		//NODE DECLARATION
	
	if (current == NULL){		//THIS RUNS IF THE CURRENT POINTER POINTS TO NOTHING OR NULL THUS SHOWING NOTHING OR NO RECORD.
 		cout << "=====================================================" << endl;
		cout << "\t\t   SHOW MIN AVERAGE" << endl;
		cout << "=====================================================" << endl << endl;
		
		cout << "NO RECORDS AVAILABLE..." << endl << endl;
	}
	
	double minAverage = 999999; // DECLARATIONialize to a large value
		while (current != NULL) {		//THIS RUNS WHEN THE POINTER POINTS TO SOMETHING OR HAS VALUE.
			double average = (current->player.score1 + current->player.score2) / 2.0;		//THIS CODE COMPUTES THE AVERAGE OF THE PLAYER'S TWO SCORES
		if (average < minAverage) {		//IF THE AVERAGE IS LESS THAN THE MINAVERAGE, IT WILL REPLACE THE MINAVERAGE VALUE
			minAverage = average;		//THIS CODE MAKES THE MINAVERAGE TAKE THE AVERAGE VALUE THAT WAS CALCULATED
		}
	current = current->next;
}
// Now, iterate again to display players with the min average
	current = head;		//THIS MAKES THE POINTER POINT TO THE HEAD
		while (current != NULL) {		//THIS CODE RUNS IF THE CURRENT POINTER POINTS TO SOMETHING WITH VALUE OR NOT NULL
			double average = (current->player.score1 + current->player.score2) / 2.0;		//THIS CODE CALCULATES THE AVERAGE OF THE PLAYER'S TWO SCORES
		if (average == minAverage) {		//IF THE AVERAGE IS EQUAL TO THE MINAVERAGE IT WILL OUTPUT THE PLAYER INFORMATION
			cout << "Nickname: " << current->player.nickname << endl;
			cout << "Average Score: " << average << endl;
			cout << "----------------------------------" << endl << endl;
		}
	current = current->next;		//THIS CODE MAKES THE CURRENT POINTER MOVE TO THE NEXT NODE
	}
	
	system("pause");
	system("cls");	 
}

//void saveToFile(Node*& head) { // save the records to a file
//	ofstream outFile("player_records.txt", ios::app); // create the file
//	Node* current = head; 
//	
//	while (current != NULL) { // if the list is not empty then...
//		outFile << current->player.nickname << endl; // save the nickname to file
//		outFile << current->player.age << endl; // save the age to file
//		outFile << current->player.score1 << " " << current->player.score2; //save the recorded scores in a single line 
// 
//		outFile << endl; 
// 		current = current->next; 
//	} 
//	outFile.close(); // close the file
//	cout << "Records saved to 'player_records.txt'." << endl; 
//}

void loadFromFile(Node*& head, Node*& tmp) {
    ifstream inFile("player_records.txt");
    if (!inFile.is_open()) {
        cout << "Error: Unable to open file for reading." << endl;
        return;
    }

    string nickname;
    int age, score1, score2;
    while (inFile >> nickname >> age >> score1 >> score2) {
   		Node* newNode = new Node; 		// CREATE A NEW NODE
		newNode->player.nickname = nickname;
    	newNode->player.age = age;
   		newNode->player.score1 = score1;
   		newNode->player.score2 = score2;
    
	   	if (head == NULL){					// IF HEAD IS NULL OR THERE'S NO NODES YET IN THE LIST THEN...

			newNode->next = head;			// link to headd
			head = newNode;					// make head point to newNode
			tmp = head;						// make tmp point to newNode
//			cout << "first node created";	//DEBUGGING	
		} else {
//			cout << "there's already a first node...";	//DEBUGGING
			tmp->next = newNode;			// connect prev node or the node tmp is pointing to toward the new one
			tmp = tmp->next;				// make tmp point to "previous" node's next link
			tmp->next = NULL;				// make the new node's next link NULL temporarily
		
//		cout << "new node created after first";	//DEBUGGING
		}
	}

    inFile.close();
    cout << "Linked list recreated from file." << endl;
}

void Search(Node*& head, string match){
	Node* current = head;   //Initialize a pointer to the head of the list.
	
	if (current == NULL){   //Display a message stating that no records are available if the list is empty.
 		cout << "=====================================================" << endl;
		cout << "\t\t    Search RECORDS" << endl;
		cout << "=====================================================" << endl << endl;
		
		cout << "NO RECORDS AVAILABLE..." << endl << endl;
	 }

	while (current != NULL) {
		if (current->player.nickname == match){
		cout << "Nickname: " << current->player.nickname << endl;
		cout << "Age: " << current->player.age << endl;
		cout << "Score 1: " << current->player.score1 << endl;
		cout << "Score 2: " << current->player.score2 << endl << endl;
		cout << "----------------------------------" << endl << endl;
		}
		current = current->next;
 	}
 	
 	system("pause");
	system("cls");
}

void deleteRecord(Node*& head, string match){
	Node* current = head;   //Initialize a pointer to the head of the list.
	Node* prev = NULL;
	
	if (current == NULL){   //Display a message stating that no records are available if the list is empty.
 		cout << "=====================================================" << endl;
		cout << "\t\t    Delete RECORD" << endl;
		cout << "=====================================================" << endl << endl;
		
		cout << "NO RECORDS AVAILABLE..." << endl << endl;
	 }
	 

	while (current != NULL) {
		if (current->player.nickname == match){
			prev->next = current->next;
			delete current;
		}
		prev = current;
		current = current->next;
 	}
 	
 	ofstream outFile("player_records.txt"); // create the file
 	
	current = head; 
	
	while (current != NULL) { // if the list is not empty then...
		outFile << current->player.nickname << endl; // save the nickname to file
		outFile << current->player.age << endl; // save the age to file
		outFile << current->player.score1 << " " << current->player.score2; //save the recorded scores in a single line 

		outFile << endl << endl; 
 		current = current->next; 
	} 
	outFile.close(); // close the file
	cout << "Records Updated" << endl; 
 	
 	system("pause");
	system("cls");
}

int main(){
	Node* tmp = NULL;		//NODE TMP DECLARATION
	Node* head = NULL;		//NODE HEAD DECLARATION
	int choice; 			//INT CHOICE DECLARATION
	Player p1;				//PLAYER P1 DECLARATION
	string match;

	
	loadFromFile(head, tmp);
	
	do{		//THIS DO WHILE MAKES THE CODE LOOP AS LONG AS THE CONDITION IS SATISFIED WHICH IS CHOICE !=6
		cout << "=====================================================" << endl;
		cout << "\t\t\tMENU" << endl;		//MENU OUTPUT SCREEN
		cout << "=====================================================" << endl << endl;
		cout << "1) Add a Record" << endl;
		cout << "2) View Record" << endl;
		cout << "3) Compute Average" << endl;
		cout << "4) Show Max Average" << endl;
		cout << "5) Show Min Average" << endl;
		cout << "6) Search" << endl;
		cout << "7) Delete Record" << endl;
		cout << "8) Exit" << endl << endl;
		
		cout << "Choose an option: ";
		
		// INPUT VALIDATION
		do{	
		while(!(cin>>choice)){  // Repeat until a valid integer input is received.
			cout << "Enter a valid numeric input: ";
			cin.clear();
			cin.ignore(123, '\n');
		}
			
		if (choice > 8 || choice < 1){          //If the input does not fall inside the menu's available options...
			cout << "Enter a valid numeric input: ";    //prompt the user to enter a valid input.
		}

	}while(choice > 8 || choice < 1);   // Repeat the loop until a valid input is acquired.
			
			switch(choice){			//Depending on the user's menu selection, this switch statement controls the program's flow.

				case 1:
					system("cls");	 
					cout << "=====================================================" << endl;
					cout << "\t\t    ADD RECORDS" << endl;
					cout << "=====================================================" << endl << endl;
					
					cin.clear();
					cin.ignore(123, '\n');
					
					cout << "Enter Player Name: ";
					cin >> p1.nickname;
					
					for (int i = 0; i < p1.nickname.size(); i++){   // Ensure the input for the player's name contains alphabetic characters only.
						if (!(isalpha(p1.nickname[i]))){
							cout << "Invalid string input, try again: ";
							cin >> p1.nickname;		
						}
					}
					
					cin.clear();
					cin.ignore(123, '\n');
					
					cout << endl << "Enter Player Age: ";
					while(!(cin >> p1.age)){    // Ensure the input for the player's age is a valid integer.
						cout << "Enter a valid numeric input: ";
						cin.clear();
						cin.ignore(123, '\n');
					}
					
					cin.clear();
					cin.ignore(123, '\n');
					
					cout << endl << "Enter Player First Score: ";
					while(!(cin >> p1.score1)){    // Ensure the input for the player's first score is a valid double.
						cout << "Enter a valid numeric input: ";
						cin.clear();
						cin.ignore(123, '\n');
					}
					
					cin.clear();
					cin.ignore(123, '\n');
					
					cout << endl <<"Enter Player Second Score: ";
					while(!(cin >> p1.score2)){    // Emsure the input for the player's second score is a valid double.
						cout << "Enter a valid numeric input: ";
						cin.clear();
						cin.ignore(123, '\n');
					}
					
					cin.clear();
					cin.ignore(123, '\n');
										
					addRecord(p1, head, tmp);   // Add the player record to the list.
					
					break;
				case 2: // If the user chooses option 2...
						system("cls");	 

					viewRecords(head);  // View all records stored in the list.
					break;
				case 3: // If the user chooses option 3...
						system("cls");	 

					computeAverage(head);   // Computes the average scores of all players.
					break;
				case 4: // If the user chooses option 4...
						system("cls");	 

					showMaxAverage(head);   // it Shows player(s) with the maximum average score.
					break;
				case 5: // If the user chooses option 5...
						system("cls");	 

					showMinAverage(head);   // it Shows player(s) with the minimum average score.
					break;
				case 6: // If the user chooses option 5...
						system("cls");	 
												
						cout << "Search for? ";
						cin >> match;

					Search(head, match);   // it Shows player(s) with the minimum average score.
					break;
				case 7: // If the user chooses option 5...
						system("cls");	 
						
						cout << "Delete whose record? ";
						cin >> match;

					deleteRecord(head, match);   // it Shows player(s) with the minimum average score.
					break;
			}
	}while(choice!=8);
	system("cls");
	
	cout << "COMPUTER PROGRAMMING 2 || LABORATORY EXERCISE 6 BY \"FORDA GRADES\"." << endl << endl << "RIC DE GRACIA\nANDRIE DETERA\nANGELITO REGERO" << endl;
	
	return 0;
}


