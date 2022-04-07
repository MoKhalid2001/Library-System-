//Simple library system


#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include <iterator>


using namespace std;

//Common Variables
int select;
string book_to_search; string category_to_print; string book_user;
char y_or_n;

//Struct for Books
struct book {

	int book_id; int book_quantity;
	string book_name; string book_category;

	void read_book() {
		cout << "Enter Book_ID , Book_name , Book_Category " << endl;
		cin >> book_id;
		cin.ignore();
		getline(cin, book_name);
		getline(cin, book_category);
	}
};

//Struct for Users 
struct user {
	int user_id;
	string user_name;

	void read_user() {
		cout << "Enter User_ID , User_Name " << endl;
		cin >> user_id;
		cin.ignore();
		getline(cin, user_name);

	}

};
//Struct for Borrowed books
struct borrowd {
	string borrow_book;
	string borrow_user;
};

//Vectors based on structs 
vector <book> Books_vector;
book new_book;

vector <user> User_vector;
user new_user;

vector <borrowd> Borrow_vector;
borrowd b_book;

//Function to print users
void print_users(vector <user>& User_vector) {
	cout << " Users of library : " << endl;
	for (int i = 0; i < User_vector.size(); i++) {
		cout << " User ID : " << User_vector[i].user_id << ",";
		cout << " User Name : " << User_vector[i].user_name << endl;
	}
}

//Function to search for book
void search_for_book(string book_to_search) {
	cout << "Enter Book's Name : " << endl;
	cin.ignore();
	getline(cin, book_to_search);
	for (int i = 0; i < Books_vector.size(); i++) {
		if (Books_vector[i].book_name == book_to_search) {
			cout << " Book Found : " << book_to_search << endl;
			cout << " It's ID : " << Books_vector[i].book_id << ",";
			cout << " It's Category : " << Books_vector[i].book_category << endl;
		}
		else if (i == Books_vector.size())
			cout << " Book isn't found ! " << endl;
	}
}
//Founction to print by category
void print_by_category(string category_to_print) {
	cout << "Enter Category : " << endl;
	cin.ignore();
	getline(cin, category_to_print);
	for (int i = 0; i < Books_vector.size(); i++) {
		if (Books_vector[i].book_category == category_to_print) {
			cout << " Book Name : " << Books_vector[i].book_name << ",";
			cout << " Book ID : " << Books_vector[i].book_id << endl;
		}
	}
}

int main()
{
	//Show library operations
	cout << "[1] Add a Book." << endl;
	cout << "[2] Add User." << endl;
	cout << "[3] Search for Book." << endl;
	cout << "[4] Show Books by Category." << endl;
	cout << "[5] Borrow a Book." << endl;
	cout << "[6] return a Book." << endl;
	cout << "[7] Show who borrowed a specific Book." << endl;
	cout << "[8] print Users" << endl;
	cout << "[9] Exit" << endl;
jump:
	cout << endl << "Enter number of operation :  " << endl;
	cin >> select;

	//Main operations 
	switch (select)
	{
	case 1:
	add_book:
		new_book.read_book();
		Books_vector.push_back(new_book);
		break;

	case 2:
	add_user:
		new_user.read_user();
		User_vector.push_back(new_user);
		break;
	case 3:
		search_for_book(book_to_search);
		break;
	case 4:
		print_by_category(category_to_print);
		break;
	case 5:
		cout << "Enter Book's name , User's name : " << endl;
		cin.ignore();
		getline(cin, b_book.borrow_book);
		cin.ignore();
		getline(cin, b_book.borrow_user);
		//Borrow progress
		for (int i = 0; i <= Books_vector.size(); i++) {
			if (Books_vector[i].book_name == b_book.borrow_book) {
				Borrow_vector.push_back(b_book);
				Books_vector.erase(Books_vector.begin() + i);
				cout << " Book has been borrowd ! " << endl;
			}
		}
		break;
	case 6:
		cout << "Enter Book's name , User's name : " << endl;
		cin.ignore();
		getline(cin, b_book.borrow_book);
		cin.ignore();
		getline(cin, b_book.borrow_user);
		//Remove from Borrow
		for (int i = 0; i <= Books_vector.size(); i++) {
			if (Borrow_vector[i].borrow_book == b_book.borrow_book) {
				Borrow_vector.erase(Borrow_vector.begin() + i);
				cout << " Now, please add the Book again ! " << endl;
				goto add_book;
			}
		}
		break;
	case 7:
		cout << "Enter Book name : " << endl;
		cin.ignore();
		getline(cin, book_user);
		for (int i = 0; i <= Books_vector.size(); i++) {
			if (Borrow_vector[i].borrow_book == book_user) {
				cout << "The User is : " << Borrow_vector[i].borrow_user << endl;
			}
		}
		break;
	case 8:
		print_users(User_vector);
		break;
	case 9:
	break_code:
		return 0;
	}

	//Function to do another operation
	cout << "Do you want to perform another operation ? [Y] - [N] " << endl;
	y_or_n = _getche();
	if (y_or_n == 'y' || y_or_n == 'Y')
		goto jump;
	else if (y_or_n == 'n' || y_or_n == 'N')
		return 0;


	system("Pause");
	return 0;
}