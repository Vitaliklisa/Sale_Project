//Dasha Podolska, Vitalii Khomenko and Antik 

#include <iostream>
using namespace std; 

void menu() {
  cout << "~~~~~~~~~~~~~~~~~~ MENU ~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
  cout << "1. Pierogi with potato and cheese        $8.00" << endl;
  cout << "2. Borscht                               $6.50" << endl;
  cout << "3. Compot (beverage with berries)        $3.99" << endl;
  cout << "4. The Monastic Hut                      $4.99" << endl;
  cout << "5. Poppyseed Roll                        $7.50" << endl;
}

//first, we did the welcome message for our customers!

int main() {
  cout << "***************************************************" << endl;
  cout << "Welcome to our restaurant 'Puzata Hata'!" << endl;
  cout << "***************************************************" << endl;

  //then, we created code to ask the customer for PIN to access the menu of our restaurant:

string pin = "ICS4U1";
int tries = 3;
int max_tries = 0;
string entry;

 
 cout << "Enter PIN code to access the menu: ";
 cin >> entry;
 tries--;

 while ( entry != pin && tries > max_tries )
 {
  cout << "\nWrong PIN. Try again. Remaining attempts: " << tries  << endl;
  cout << "Enter PIN code to access the menu: " << endl;
  cin >> entry;
  tries--;
 }

 if ( entry == pin ) {
  cout << "\nPIN is approved. Here is our menu!" << endl;
  menu();
 }
   
 else if ( tries <= max_tries ) {
  cout << "\nYou are out of attempts :( " << endl;
 }
  
  vector<int> order; // To store the meals ordered
	float subtotal = 0.0;
	const float prices[] = {8.00, 6.50, 3.99, 4.99, 7.50};
	int choice = -1;

	while (choice != 0) {
		cout << "\nSelect a item by its number 0 to exit. ";
		cin >> choice;

		if (choice > 0 && choice <= 5) {
			order.push_back(choice);
			cout << "Added to your order!" << endl;
		} else if (choice != 0) {
			cout << "Invalid choice, please select a valid menu item." << endl;

		}
	}
// the we did another function for menu but we put it before main fuction for it to run properly 
//and then add a vector and while loop to ask the customer what dishes they want and the number of the dishes they expect
}


