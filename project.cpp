//Dasha Podolska, Vitalii Khomenko and Antik 

#include <iostream>
using namespace std; 
//first, we're doing the welcome message for our customers!
int main() {
  cout << "***************************************************" << endl;
  cout << "Welcome to our restaurant 'Puzata Maty'!" << endl;
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

 if ( entry == pin )
  cout << "\nPIN is approved. Here is our menu!" << endl;
 else if ( tries <= max_tries )
  cout << "\nYou are out of attempts :( " << endl;

}

}
