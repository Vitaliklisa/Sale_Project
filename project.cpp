//Dasha Podolska, Vitalii Khomenko and Antik 

#include <iostream>
#include <vector>
#include <iomanip> 

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
	cout << "     Welcome to our restaurant 'Puzata Hata'!" << endl;
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

//then we added a vector and while loop to ask the customer what dishes they want
    vector<int> order; // To store the meals ordered
    vector<int> portions_added; // To store how many portions has been ordered for each item
    float subtotal = 0.00;
    const float prices[] = {8.00, 6.50, 3.99, 4.99, 7.50};
    int choice = -1;
    int portions;
	
    while (true) {
		cout << "\nSelect a item by its number 0 to exit. ";
		cin >> choice;

        if (choice == 0){ 
            break;
        }
		
		if (choice > 0 && choice <= 5) {
			cout << "How many portions do you want to add? Choose 0 to delete this dish from your order." << endl;
			cin >> portions;
// after we made a code for choosing dishes, we add an if statement for our customers to choose how meny portions of that dish they want
// if they choose 0, they will delete this dish from the receipt and they won't get it
            if (portions > 0) {
                order.push_back(choice);
                portions_added.push_back(portions);
                subtotal += prices[choice - 1] * portions; 
				cout << "Great! " << portions << " of portions is added." << endl;
			}
			else if (portions == 0) {
				cout << "Okay, we deleted this dish from your order." << endl;
                for (int i = 0; i < order.size(); ++i) {
                    if (order[i] == choice) {
                        subtotal -= prices[choice - 1] * portions_added[i]; 
                        order.erase(order.begin() + i); // Remove the dish from order
                        portions_added.erase(portions_added.begin() + i); // Remove the corresponding portion
                        break;
                    }
                }
			}

		}
        else {

            cout << "Invalid output. Please enter the right number." << endl;
        }

        cout << "\nCurrent Order: " << endl;
        for (int i = 0; i < order.size(); ++i) {
            cout << "Meal " << order[i] << " x " << portions_added[i] << " = $" << fixed << setprecision(2) << prices[order[i] - 1] * portions_added[i] << endl; //display the items  which has been ordered 
        }

        cout << "\nWould you like to add or remove another item (1-yes, 0-exit)? ";
        int continue_choice;
        cin >> continue_choice;
        if (continue_choice == 0) {
            break;
        }


    }

    int seating_type;
    double total;

    while (true){
        cout << "Choose the way you want to eat: " << endl;
        cout << "1. Dine-in." << endl;
        cout << "2. Take-out." << endl;
        cout << "3. Delivery (order<$25 + $3.5 delivery fee)." << endl;
        cout << "4. Cancel the order." << endl;
        cout << "Enter the seating type you want: ";
        cin >> seating_type;

        if(seating_type == 1){
            total = subtotal + subtotal * .13;
            break;
        }
        else if(seating_type == 2){
            double reduced = subtotal - (subtotal * .10);
            total = subtotal + (reduced * .13);
            break;
        }
        else if(seating_type == 3){
            if (subtotal < 25) {
                subtotal += 3.5;
            }            
            total = subtotal + (subtotal * .13);
            break;
        }
        else if(seating_type == 4){
            cout << "Ordered has been cancelled. " << endl;
            return(0);
        } else {
            cout << "Invalid ";
        }
    }


    

    cout << "\nSubtotal: $"<< subtotal << fixed << setprecision(2) << endl;
    cout << "Total: $"<< total << fixed << setprecision(2) << endl;
// the we did another function for menu but we put it before main fuction for it to run properly 

}
