#include <string>
using namespace std;

class Employee {

    // Private variables
   private:
       string employeeId;
       string firstName;
       string lastName;
       string birthDate;
       char gender;
       string startDate;
       double annualSalary;

    // Public Variables
   public:

       // Constructors
       Employee();
       Employee(string);
       Employee(string, string, string, string, char, string, double);

       void setEmployeeId(string);
       void setLastName(string);
       void setFirstName(string);
       void setBirthDate(string);
       void setGender(char);
       void setStartDate(string);
       void setAnnualSalary(double);

       string getEmployeeId();
       string getLastName();
       string getFirstName();
       string getBirthDate();
       char getGender();
       string getStartDate();
       double getAnnualSalary();
};
