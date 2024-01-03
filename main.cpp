#include "function.h"

int main()
{
    setupDonationSystem();
    int choice;
    do {
        cout << "1. Record and total each donation" << endl;
        cout << "2. Show the totals so far" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter:";
        cin >> choice;
        switch (choice) 
        {
        case 1:
            recordAndTotalDonation();
            break;
        case 2:
            showTotalsSoFar();
            break;
        case 3:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter 1, 2, or 3." << endl;
        }
    } while (choice != 3);

	return 0;
}
