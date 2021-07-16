#include "Employee.h"

Employee::Employee() {

   employeeId = "";
   firstName = "";
   lastName = "";
   birthDate= "";
   gender = '\0';
   startDate = "";
   annualSalary = 0;
}

Employee::Employee(string id) {
   employeeId = id;
   firstName = "";
   lastName = "";
   birthDate= "";
   gender = '\0';
   startDate = "";
   annualSalary = 0;

}

Employee::Employee(string id, string lName, string fName, string bDate, char gen, string sDate, double salary) {

   employeeId = id;
   lastName = lName;
   firstName = fName;
   birthDate= bDate;
   gender = gen;
   startDate = sDate;
   annualSalary = salary;
}

// Mutator functions
void Employee::setEmployeeId(string id) {

   employeeId = id;
}

void Employee::setFirstName(string fName) {

   firstName = fName;
}

void Employee::setLastName(string lName) {

   lastName = lName;
}

void Employee::setBirthDate(string bDate) {

   birthDate = bDate;
}

void Employee::setGender(char gen) {

   gender = gen;
}

void Employee::setStartDate(string sDate) {

   startDate = sDate;
}


void Employee::setAnnualSalary(double salary) {

   annualSalary = salary;
}

// Accessor functions
string Employee::getEmployeeId() {

   return employeeId;
}

string Employee::getFirstName() {

   return firstName;
}

string Employee::getLastName() {

   return lastName;
}

string Employee::getBirthDate() {

   return birthDate;
}

char Employee::getGender() {

   return gender;
}

string Employee::getStartDate() {

   return startDate;
}

double Employee::getAnnualSalary() {

   return annualSalary;
}
