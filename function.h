#include<iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int NUM_CHARITIES = 3;

struct Charity {
    string name;
    double totalDonation;
};

vector<Charity> charities;

void setupDonationSystem() {
    charities.resize(NUM_CHARITIES);

    for (int i = 0; i < NUM_CHARITIES; ++i) {
        cout << "Enter the name of Charity " << i + 1 << ": ";
        cin >> charities[i].name;
        charities[i].totalDonation = 0.0;
    }
}

int getCharityChoice() {
    int choice;

    cout << "Choose a charity (1, 2, or 3): ";
    cin >> choice;

    if (choice < 1 || choice > NUM_CHARITIES) {
        cout << "Invalid choice. Please choose 1, 2, or 3." << endl;
        return -1;
    }

    return choice;
}

double getShoppingBill() {
    double bill;

    cout << "Enter the customer's shopping bill: $";
    cin >> bill;

    return bill;
}

void recordAndTotalDonation() {
    int choice = getCharityChoice();

    if (choice == -1) {
        return;  // Exit early if choice is -1
    }

    double bill = getShoppingBill();
    double donation = bill * 0.01;

    charities[choice - 1].totalDonation += donation;

    cout << fixed << setprecision(2);
    cout << "Donation of $" << donation << " recorded for " << charities[choice - 1].name << "." << endl;
}

void showTotalsSoFar() {
    // Sort charities by total donation in descending order
    sort(charities.begin(), charities.end(), [](const Charity& a, const Charity& b) {
        return a.totalDonation > b.totalDonation;
        });

    // Display totals and calculate grand total
    double grandTotal = 0.0;

    cout << "Charities' names and totals in descending order:\n";
    for (const Charity& charity : charities) {
        cout << charity.name << ": $" << charity.totalDonation << endl;
        grandTotal += charity.totalDonation;
    }

    cout << "GRAND TOTAL DONATED TO CHARITY: $" << grandTotal << endl;
}
