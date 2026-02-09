#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    string fileName;
    ifstream inputFile;

    // asks user for input file
    cout << "Enter the name of the input file: ";
    cin >> fileName;

    inputFile.open(fileName);

    if (!inputFile)
    {
        cout << "Error opening file." << endl;
        return 1;
    }

    // variables
    string firstName, lastName;
    double baseSalary, commissionPercent;
    double totalSales, expenses;

    // extract data from files
    inputFile >> firstName >> lastName;
    inputFile >> baseSalary >> commissionPercent;
    inputFile >> totalSales;
    inputFile >> expenses;

    inputFile.close();

    // calculations
    double commission = (commissionPercent / 100.0) * totalSales;
    double totalPay = baseSalary + commission + expenses;

    // output
    cout << fixed << setprecision(2);

    cout << "\nPayroll data for " << firstName << " " << lastName << endl << endl;

    cout << left << setw(16) << "Base Salary:"
         << right << setw(10) << baseSalary << endl;

    cout << left << setw(16) << "Commission:"
         << right << setw(10) << commission
         << " (" << commissionPercent << "% of " << totalSales << ")" << endl;

    cout << left << setw(16) << "Expenses:"
         << right << setw(10) << expenses << endl;

    cout << right << setw(26) << "--------" << endl;

    cout << left << setw(16) << "Total:"
         << right << setw(10) << totalPay << endl;

    return 0;
}