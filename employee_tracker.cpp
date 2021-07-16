#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <fstream>
#include "Employee.h"

using namespace std;

// Prints menu options and prompts user for input
void printMenu() {
    
    cout << endl;
    cout << "Employee Tracking System" << endl;
    cout << endl;
    cout << "1. Enter new employee information" << endl;
    cout << "2. Print employee information alphabetically" << endl;
    cout << "3. Search for employee by ID" << endl;
    cout << "4. Delete employee information" << endl;
    cout << "5. Save information to 'Employee.txt' and exit program" << endl;
    cout << endl;
    cout << "Choose a menu item: ";
}

// Adds new employee information
void createNewEmployee(int &employeeCount, Employee *arr[]) {
    
    // Boolean to check if the user ID has already been assigned
    bool used = false;
    string employeeIdentification;
    
    // Checks if number of employees exceeds maximum amount
    if (employeeCount < 100) {
        
        cout << "Enter new employee ID: ";
        getline(cin, employeeIdentification);

        if (employeeCount > 0) {

           for (int i = 0; i < employeeCount; i++ ) {

               if (employeeIdentification.compare(arr[i] -> getEmployeeId()) == 0) {

                   cout << "The ID you entered is already in use for another employee" << endl;
                   cout << endl;
                   used = true;
               }
           }
       }

        // Prompt user for more information if the ID doesn't exist yet
       if (used == false) {

           string firstName;
           string lastName;
           string birthDate;
           char gender;
           string startDate;
           double salary;

            // Prompts user for all other information
           cout << "Enter employee's last name: ";
           getline(cin, lastName);

           cout << "Enter employee's first name: ";
           getline(cin, firstName);

           cout << "Enter employee's birth date (MM/DD/YYYY): ";
           getline(cin, birthDate);

           cout << "Enter employee's gender (M or F): ";
           cin.get(gender);

           cin.clear();
           cin.ignore(INT_MAX, '\n');

           cout << "Enter employee's start date: ";
           getline(cin, startDate);

           cout << "Enter employee's salary per year: ";
           cin >> salary;

           Employee *ptr;
           ptr = new Employee(employeeIdentification, lastName, firstName, birthDate, gender, startDate, salary);

           arr[employeeCount]= ptr;
           ++employeeCount;
       }
   }

   else {

       cout << "Cannot store more than 100 employees" << endl;
       cout << endl;
   }
}

// Sorts employees alphabetically
void sortAlphabetically(int count, Employee *sortedArr[]) {

   bool swap;

   // Number of items being swapped
   int swapNumber = 2;

   // Array temporarily holds information
   Employee *temp[swapNumber];

   do {

       swap = false;

       for (int i = 0; i < count - 1; i++) {

            // If the array is not in alphabetical order
           if (sortedArr[i] -> getLastName().compare(sortedArr[i + 1] -> getLastName()) > 0) {

               // Stores objects in temporary array
               int iteration = 0;
               temp[iteration] = sortedArr[i];
               ++iteration;
               temp[iteration] = sortedArr[i + 1];

                // Swaps the objects
               sortedArr[i] = temp[iteration];
               --iteration;
               sortedArr[i + 1] = temp[iteration];
               swap = true;

           }
       }
   } 
   
   while(swap);
}

// Sorts and prints employee information
void printInformation(int count, Employee *arr []) {

    // Formats information neatly
   cout << setw(20) << left << "Employee ID" << "|";
   cout << setw(20) << left << "Last Name" << "|";
   cout << setw(20) << left << "First Name" << "|";
   cout << setw(15) << left << "Birth Date" << "|";
   cout << setw(11) << left << "Gender" << "|";
   cout << setw(15) << left << "Start Date" << "|" ;
   cout << setw(20) << left << "Salary" << endl;
   cout << "----------------------------------------------------------------------------------------------------------------" << endl;

   sortAlphabetically(count, arr);

    // Fills table with information
   for (int i = 0; i < count; i++) {

       cout << setw(20) << arr[i] -> getEmployeeId() << "|";
       cout << setw(20) << arr[i] -> getLastName() << "|";
       cout << setw(20) << arr[i] -> getFirstName() << "|";
       cout << setw(15) << arr[i] -> getBirthDate() << "|";
       cout << setw(11) << arr[i] -> getGender()<< "|";
       cout << setw(15) << arr[i] -> getStartDate() << "|";

       cout << setprecision(0) << fixed;
       cout << setw(20) << arr[i] -> getAnnualSalary();
       cout << endl;
   }

   cout << endl;
}

// Search for employee by ID
void searchById(int employeeCount, Employee *arr[]) {

   string employeeIdentification;
   bool exist = false;

   cout << "Enter Employee ID: "<< endl;
   getline(cin, employeeIdentification);

   for (int i = 0; i < employeeCount; i++ ) {

       if (employeeIdentification.compare(arr[i] -> getEmployeeId()) == 0) {

           // Print employee information if the ID is found
           cout << "Employee ID: " << arr[i] -> getEmployeeId() << endl;
           cout << "Last Name: " << arr[i] -> getLastName()<< endl ;
           cout << "First Name: " << arr[i] -> getFirstName() << endl;
           cout << "Birth Date: " << arr[i] -> getBirthDate() << endl;
           cout << "Gender: " << arr[i] -> getGender()<< endl;
           cout << "Start Date: " << arr[i] -> getStartDate() << endl;
           cout << "Salary: " << arr[i] -> getAnnualSalary() << endl;
           cout << endl;
           exist = true;

           break;
       }
   }

    // Print error if the ID doesn't exist
   if (!exist) {

       cout << "Employee with the ID you entered doesn't exist" << endl;
       cout << endl;
   }
}


// Saves information to 'Employee.txt' and exits the program
void saveAndExit(int count , Employee *arr[]) {

   ofstream outputFile;
   outputFile.open("Employee.txt");

    // Writes one employee per line
   for (int i = 0; i < count ; i++) {

       outputFile << arr[i] -> getEmployeeId() << '\t';
       outputFile << arr[i] -> getLastName() << '\t';
       outputFile << arr[i] -> getFirstName() << '\t';
       outputFile << arr[i] -> getBirthDate() << '\t';
       outputFile << arr[i] -> getGender() << '\t';
       outputFile << arr[i] -> getStartDate() << '\t';
       outputFile << arr[i] -> getAnnualSalary();
       outputFile << endl;
   }

   outputFile.close();
}


// Deletes employee from array
void deleteEmployee(int& count, Employee * arr[]) {

   string employeeIdentification;
   bool exist = false;

   cout << "Enter Employee ID: "<< endl;
   getline(cin, employeeIdentification);

    // Compare ID to existing IDs
   for (int j = 0; j < count; j++ ) {

       // Delete employee if the ID exists
       if (employeeIdentification.compare(arr[j] -> getEmployeeId()) == 0) {

           delete arr[j] ;

           for (int i = j; i < count; i++) {

               arr[i] = arr[i + 1];
           }

           --count;

            // Print success message
           cout << "Employee has been deleted" << endl;
           cout << endl;
           exist = true;
           break;
       }
   }

    // Print error message if the ID doesn't exist
   if (exist == false) {

       cout << "Employee with that ID doesn't exist" << endl;
       cout << endl;
   }
}

// Chekcs if 'Employee.txt' exists and reads from it
void fileReadIn(int& count, Employee *arr[]) {
   bool noSpace = false;

    // Empty variables for employee information
   string employeeId = "";
   string firstName= "";
   string lastName = "";
   string birthDate = "";
   char gender = '\0';
   string startDate = "";
   double salary = 0;

    // Variable for file input
   ifstream inputFile;
   inputFile.open("Employee.txt");

   if (inputFile) {

          while (inputFile >> employeeId >> lastName >> firstName >> birthDate >> gender >> startDate >> salary ) {

            // Print error message if there are more than 100 employees
              if (count >= 100) {

                  cout << "Company can't have more than 100 employees" << endl;
                  cout << endl;
                  noSpace = true;

                  break;
              }

              if (noSpace == false) {

                  Employee *ptr;
                  ptr = new Employee(employeeId, lastName, firstName, birthDate, gender, startDate, salary);

                  arr[count]= ptr;
                  ++count;
              }
          }
   }

   inputFile.close();
}

int main() {
    
    // Maximum number of employees allowed
    int MAX = 100;
    Employee *array[MAX];

    // User input
    int userChoice;

    // Tracks number of employees
    int numberOfEmployees = 0;
    
    // Reads information from 'Employee.txt'
    fileReadIn(numberOfEmployees, array);
    
    do {
       
       // Prints menu and prompts user for input
       printMenu();
       cin >> userChoice;

       // Clears user input
       cin.clear();
       cin.ignore(INT_MAX, '\n');
       
       switch(userChoice) {
           
           // Creates new employee if user selects option 1
           case 1:
           createNewEmployee(numberOfEmployees, array);
           break;
           
           // Prints all employee information if user selects option 2
           case 2:
           // Prints error if there is no employee information
           if(numberOfEmployees == 0) {
               
               cout << "No employee information available" << endl;
               cout << endl;
            }
            
            else {
                
                printInformation(numberOfEmployees , array);
            }

            break;

            // Searches for employee by ID if user selects option 3
            case 3:
            if(numberOfEmployees == 0) {
                
                cout << "No employee information available" << endl;
                cout << endl;
            }
            
            else {
                
                searchById(numberOfEmployees, array);
            }

            break;

            // Removes an employee if user selects option 4
            case 4:
            if(numberOfEmployees == 0) {

                cout << "No employee information available" << endl;
                cout << endl;
            }
            
            else {
                
                deleteEmployee(numberOfEmployees, array);
            }

            break;

            // Saves all information and exits the progra if user selects option 5
            case 5:
            saveAndExit(numberOfEmployees, array);
            break;
        }
    }

    while(userChoice != 5);

    return 0;
}
