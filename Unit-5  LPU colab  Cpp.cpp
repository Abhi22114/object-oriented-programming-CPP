//-->unit - 5 lecture 34 COD questions


//-->>sawapping in c++ code 

//#include<iostream>
//using namespace std;
//
///*void swap(int a, int b){
//
//int c;
//c=a;
//a=b;
//b=c;
//cout<<"After swap: "<<a<<" "<<b<<endl;
//} */
//
//void swap(int &a, int &b){   //we can change actual parameters, this method is called passing by reference
//int c;
//c=a;
//a=b;
//b=c;
//cout<<"After swap: "<<a<<" "<<b<<endl;
//}
//
//void func(int &a, int b){
//a=9999;
//b=9999;
//cout<<"values of a & b in func: "<<a<<" "<<b<<endl;
//}
//
//int main(){
//int a,b;
//a=4;
//b=6;
//
//cout<<"Before swap: "<<a<<" "<<b<<endl;
//swap(a,b);
//cout<<"after swap in main func: "<<a<<" "<<b<<endl;
//
//
//func(a,b);
//cout<<"values of a & b in main: "<<a<<" "<<b<<endl; //a is changed to 9999, b doesn't change
//return 0;
//} 

//Create a class named Line is derived from the Point class and represents a line segment connecting two points. It has two additional private data members, x2 and y2, representing the x-coordinate and y-coordinate of the end point of the line segment, respectively. The class has a constructor to initialize the line segment and setX2() and setY2() functions to update the coordinates of the end point. The display() function is overridden to display the start and end points of the line.
//In the main function, the program should prompt the user to enter the coordinates of two points (x1, y1) and (x2, y2) to represent the line segment. The program should then create a Line object with the given coordinates and display the line segment by calling the display() function.
//Input format :
//The first two integer inputs denote the x and y coordinates of the start point.
//The next two integer inputs denote the x and y coordinates of the end point.
//Output format :
//The output prints the start point and end point of the line as per the sample output format.
//Refer to the sample output for format specifications.
//Code constraints
//The coordinates x1, y1, x2, and y2 are integers.
//1 <= x1, y1, x2, y2 <= 6000 (The coordinates are within this range.)
//Sample test cases :
//Input 1 :
//1 2
//3 4
//Output 1 :
//The line is:
//Start point: (1,2)
//End point: (3,4)
//

#include <iostream>
using namespace std;

class Point {
protected:
    int x, y;

public:
    Point(int x_val, int y_val) : x(x_val), y(y_val) {}

    void setX(int x_val) {
        x = x_val;
    }

    void setY(int y_val) {
        y = y_val;
    }

    virtual void display() = 0;
};

class Line : public Point {
private:
    int x2, y2;

public:
    Line(int x1, int y1, int x2_val, int y2_val) : Point(x1, y1), x2(x2_val), y2(y2_val) {}

    void setX2(int x_val) {
        x2 = x_val;
    }

    void setY2(int y_val) {
        y2 = y_val;
    }

    void display() override {
        cout << "The line is:" << endl;
        cout << "Start point: (" << x << "," << y << ")" << endl;
        cout << "End point: (" << x2 << "," << y2 << ")" << endl;
    }
};

int main() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    Line line(x1, y1, x2, y2);
    line.display();

    return 0;
}

////q-:---Write a program to implement runtime polymorphism.ase. Whitelist
//Set 1: Color,RedPaint,BluePaint,virtual,paint() The program should define a base class "Color" with a virtual function "paint" and two derived classes "RedPaint" and "BluePaint" that override the "paint()" function to paint with the respective colors.
//The program should use runtime polymorphism to create either a "RedPaint" or "BluePaint" object based on user input and call the "paint()" function to paint with the chosen color.
//Note: This kind of question will help in clearing Cocubes recruitment
//Input format :
//The input consists of a single character representing the color to paint, where "R" or "r" represents the red color and "B" or "b" represents a blue color.
//Output format :
//The program should output the message "I'm Painting with Red Color." if the user inputs 'R' or 'r', or "I'm Painting with Blue Color."
//If the user inputs "B" or "b". If the user inputs any other character, the program should output "Invalid choice!" and terminate.
//Refer to the sample output for the formatting specifications.
//Code constraints :
//The user's input must be a single character.
//The user can only enter 'R', 'r', 'B', or 'b' to select a color. Any other character will be considered an invalid choice.
//Sample test cases :
//Input 1 :
//R
//Output 1 :
//I'm Painting with Red color.
//Input 2 :
//B
//Output 2 :
//I'm Painting with Blue color.

#include <iostream>
using namespace std;

class Color {
public:
    virtual void paint() {
        // Base class function is defined as virtual and overridden in derived classes.
    }
};

class RedPaint : public Color {
public:
    void paint() override {
        cout << "I'm Painting with Red color." << endl;
    }
};

class BluePaint : public Color {
public:
    void paint() override {
        cout << "I'm Painting with Blue color." << endl;
    }
};

int main() {
    char choice;
    cin >> choice;

    Color *paintObject = nullptr;

    if (choice == 'R' || choice == 'r') {
        paintObject = new RedPaint();
    } else if (choice == 'B' || choice == 'b') {
        paintObject = new BluePaint();
    } else {
        cout << "Invalid choice!" << endl;
        return 0;
    }

    paintObject->paint(); // Calls the appropriate paint function based on the user's choice

    delete paintObject; // Deallocate memory to prevent memory leaks

    return 0;
}

////question-3---> (whitelist syntax-operator--)Karthick is developing a search engine system that allows users to find a substring in a given text document. Users will input the main text and the substring they want to search for.
//His task is to implement a program that uses operator overloading (/) to find if the provided substring is present in the given text. Write a program to accomplish this task.
//Input format :
//The first line of the input represents a string.
//The second line represents a substring.
//Output format :
//The output displays whether the substring is present in the given string or not.
//Refer to the sample output for formatting specifications.
//Code constraints :
//The length of each string should not exceed 30 characters.
//Sample test cases :
//Input 1 :
//Programming
//gram
//Output 1 :
//Substring is present
//Input 2 :
//Television
//live
//Output 2 :
//substring is not present
#include <iostream>
#include <string>
class SearchEngine {
public:
    SearchEngine(const std::string& text) : text_(text) {}
    bool operator/(const std::string& substring) {
        // Perform a case-insensitive search
        size_t found = text_.find(substring);
        // Check if the substring was found
        return found != std::string::npos;
    }
private:
    std::string text_;
};
int main() {
    std::string mainText, substring;
    std::getline(std::cin, mainText);
    std::getline(std::cin, substring);
    SearchEngine engine(mainText);
    if (engine / substring) {
        std::cout << "Substring is present" << std::endl;
    } else {
        std::cout << "substring is not present" << std::endl;
    }
    return 0;
}
//question-4--:Akshitha is tasked with developing a program to determine the day of the week based on a given integer input representing a day number (1 to 7). In this scenario, each integer from 1 to 7 corresponds to a specific day of the week, as follows:
//1: Sunday
//2: Monday
//3: Tuesday
//4: Wednesda
//5: Thursday
//6: Friday
//7: Saturday
//The program should take an integer input from the user representing the day number and output the corresponding day of the week. If the input is not within the range of 1 to 7, the program should print "Invalid.
//You need to create a class named Main that handles this functionality. The constructor of the class Main takes an integer argument representing the day number. The class should then determine the day of the week based on the input and print the result to the console.
//You should also ensure that the class Main has a virtual destructor to allow for proper cleanup when deleting objects through a base-class pointer.
//Input format :The input is a single integer d, representing the day number.
//Output format :The output displays a string representing the corresponding day of the week. If the input d is within the range of 1 to 7, the program should output the day of the week.
//If the input d is outside this range, the program should output "Invalid".
//Refer to the sample output for the formatting specification.
//Code constraints :
//1 <= d <= 7
//Sample test cases :
//Input 1 :
//7
//Output 1 :
//Saturday
//Input 2 :
//0
//Output 2 :
//Invalid
//Input 3 :
//9
//Output 3 :
//Invalid
#include <iostream>
#include <string>
class Main {
public:
    Main(int dayNumber) : dayNumber(dayNumber) {}
    virtual ~Main() {}
    std::string getDayOfTheWeek() {
        switch (dayNumber) {
            case 1:
                return "Sunday";
            case 2:
                return "Monday";
            case 3:
                return "Tuesday";
            case 4:
                return "Wednesday";
            case 5:
                return "Thursday";
            case 6:
                return "Friday";
            case 7:
                return "Saturday";
            default:
                return "Invalid";
        }
    }
private:
    int dayNumber;
};
int main() {
    int dayNumber;
    std::cin >> dayNumber;
    Main dayOfWeek(dayNumber);
    std::string result = dayOfWeek.getDayOfTheWeek();
    std::cout << result << std::endl;
    return 0;
}

//question-5---(case: whitelist syntax virtual)Marc is working as a software developer for a scientific research institute, and his team is currently investigating various types of interesting numbers. One such type is the "Neon Number." A neon number is a special type of positive integer where the sum of the digits of its square is equal to the original number.
//Your task is to develop a program that can efficiently determine whether a given positive integer is a neon number or not,  while also implementing a virtual destructor for appropriate memory management.
//For Example,
//N = 9
//Then, 9^2=81 =>8+1=9
//So, 9 is a neon number.
//Input format :
//The first line of the input represents the neon number.
//Output format :
//The output displays whether the number is a neon number or not.
//Refer to the sample output for formatting specifications.
//Code constraints :
//N < 20
//Sample test cases :
//Input 1 :
//8
//Output 1 :
//8 it's Not a Neon Number.
//Input 2 :
//1
//Output 2 :
//1  it's a Neon Number.
//Input 3 :
//6543
//Output 3 :
//Enter a valid number.
#include <iostream>
class Number {
public:
    Number(int n) : num(n) {}
    virtual ~Number() {}
    bool isNeon() {
        int square = num * num;
        int sum = 0;
        while (square > 0) {
            sum += square % 10;
            square /= 10;
        }
        return sum == num;
    }
    void displayResult() {
        if (num >= 1 && num < 20) {
            if (isNeon()) {
                std::cout << num << " it's a Neon Number." << std::endl;
            } else {
                std::cout << num << " it's Not a Neon Number." << std::endl;
            }
        } else {
            std::cout << "Enter a valid number." << std::endl;
        }
    }
private:
    int num;
};
int main() {
    int n;
    std::cin >> n;
    Number number(n);
    number.displayResult();
    return 0;
}

// #--->>>CPP_Unit 5_Lecture 34_RB_CY
//question-1      case. CPP_Unit 5_Lecture 34_RB_CY 

//Whitelist
//Set 1:
//class
//virtual int min(int x, int y, int z) = 0;

//Kamalesh is building a spell-checking system for a word-processing application. He needs to write a program that calculates the minimum number of operations required to transform one word into another.
//Specifically, the program takes two strings as input and computes their edit distance. The program defines a base class "EditDistanceCalculator" with a pure virtual function "min" and a derived class "MinEditDistanceCalculator" override the "min" function to calculate the minimum edit distance. Write a program to accomplish this task.
//Example
//
//Input:
//
//kitten
//
//sitting
//
//Output:
//The edit distance between kitten and sitting is 3
//
//Explanation:
//To transform "kitten" into "sitting", we can perform the following operations:
//Substitute "s" for "k": sitten
//Substitute "i" for "e": sittin
//Insert "g" at the end: sitting
//Thus, the minimum number of operations required to transform "kitten" into "sitting" is 3.
//Input format :
//The input consists of two strings on separate lines.
//Output format :
//The output displays the edit distance between the strings.
//Refer to the sample output for formatting specifications.
//Code constraints :
//Length of string1<=100
//Length of string2<=100
//Sample test cases :
//Input 1 :
//kitten
//sitting
//Output 1 :
//Edit distance between kitten and sitting is 3
//Input 2 :
//intention
//execution
//Output 2 :
//Edit distance between intention and execution is 5


#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class EditDistanceCalculator {
public:
    virtual int min(int x, int y, int z) = 0;
};

class MinEditDistanceCalculator : public EditDistanceCalculator {
public:
    int min(int x, int y, int z) override {
        return std::min(std::min(x, y), z);
    }

    int minEditDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();

        int dp[m + 1][n + 1];
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0)
                    dp[i][j] = j;
                else if (j == 0)
                    dp[i][j] = i;
                else if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]);
            }
        }

        return dp[m][n];
    }
};

int main() {
    string str1, str2;
    cin >> str1 >> str2;

    MinEditDistanceCalculator calculator;
    int distance = calculator.minEditDistance(str1, str2);

    cout << "Edit distance between " << str1 << " and " << str2 << " is " << distance << endl;

    return 0;
}
//question -2 (  Problem Statement

//A car rental company wants to calculate the total cost of a rental based on the number of days and the type of car rented. The company has set rental rates for different car types, which are stored in the following constants:
//ECONOMY_RATE: $40.00 per day
//
//COMPACT_RATE: $50.00 per day
//
//STANDARD_RATE: $60.00 per day
//The program should take as input the number of days and the type of car. The type of car is an optional parameter with a default value of "Economy". The program defines a base class "car" with the virtual function "calculateRentalCost" and three derived classes "EconomyCar", "CompactCar" and "StandardCar" override "calculateRentalCost" to calculate the total cost of the rental.
//
//Function signature:
//double calculateRentalCost(int numDays, string carType = "Economy")
//
//Note: This kind of question will help in clearing Wipro recruitment.
//
//Input format :
//
//An integer numDays (1 <= numDays <= 365), the number of days of the rental.
//A string carType, the type of car (either "Economy", "Compact", or "Standard").
//
//Output format :
//
//If the carType is one of the valid types, output double, the total cost of the rental, rounded to 2 decimal places.
//If the carType is not valid, output "Invalid car type."
//
//Code constraints :
//
//The rental rates for different car types are stored in constants and cannot be changed.
//If carType is not specified, the default value is "Economy".
//
//The number of days is an integer between 1 and 365, inclusive.
//The output should be rounded to two decimal places.
//The program should use the calculateRentalCost function to calculate the rental cost.
//
//Sample test cases :
//Input 1 :
//3 Compact
//Output 1 :
//The total cost of the rental is $150
//
//Input 2 :
//5 Economy
//Output 2 :
//The total cost of the rental is $200
//
//Input 3 :
//5 SUV
//
//Output 3 :
//Invalid car type.
//
//Input 4 :
//2 Standard
//Output 4 :
//The total cost of the rental is $120

// solution--->>

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Car {
public:
    virtual double calculateRentalCost(int numDays, string carType = "Economy") = 0;
};

class EconomyCar : public Car {
public:
    double calculateRentalCost(int numDays, string carType = "Economy") override {
        if (carType == "Economy") {
            return 40.00 * numDays;
        } else {
            cout << "Invalid car type." << endl;
            return 0.0;
        }
    }
};

class CompactCar : public Car {
public:
    double calculateRentalCost(int numDays, string carType = "Economy") override {
        if (carType == "Compact") {
            return 50.00 * numDays;
        } else {
            cout << "Invalid car type." << endl;
            return 0.0;
        }
    }
};

class StandardCar : public Car {
public:
    double calculateRentalCost(int numDays, string carType = "Economy") override {
        if (carType == "Standard") {
            return 60.00 * numDays;
        } else {
            cout << "Invalid car type." << endl;
            return 0.0;
        }
    }
};

int main() {
    int numDays;
    string carType;
    cin >> numDays >> carType;

    Car *car;
    EconomyCar eCar;
    CompactCar cCar;
    StandardCar sCar;

    if (carType == "Economy") {
        car = &eCar;
    } else if (carType == "Compact") {
        car = &cCar;
    } else if (carType == "Standard") {
        car = &sCar;
    } else {
        cout << "Invalid car type." << endl;
        return 0;
    }

    double totalCost = car->calculateRentalCost(numDays, carType);
    if (totalCost != 0.0) {
        cout << fixed << setprecision(0);
        cout << "The total cost of the rental is $" << totalCost << endl;
    }

    return 0;
}

//---->>>CPP_Unit 5_Lecture 35_RB_COD-->>

// question-->>>Single File Programming Question

// Problem Statement
// Design a program to calculate the total price of products in an online store based on their specific pricing rules. The program should utilize an abstract class called "Product" to represent a generic product and provide a framework for calculating the total price. Implement two derived classes, "Electronics" and "Apparel," which inherit from the abstract class and provide their own implementations for calculating the total price based on their specific pricing rules.


// Note: The abstract class "Product" serves as a blueprint for the derived classes "Electronics" and "Apparel." It enforces the implementation of a "calculateTotalPrice" method in the derived classes to calculate the total price based on their specific pricing rules. This approach ensures code reusability and flexibility to accommodate various types of products with their unique pricing calculations.

// Note: This kind of question will help in clearing mPhasis recruitment.

// Input format :

// The first line of the input represents the price of the electronics product.

// The second line of the input represents the discount percentage for the electronics product.

// The third line of the input represents the price of the apparel product.

// The fourth line of the input represents the tax percentage for the apparel product.

// Output format :

// The total price of the electronics product after applying the discount.

// The total price of the apparel product after applying the tax.

// Code constraints :

// The price, discount, and tax values are non-negative.

// Sample test cases :
// Input 1 :
// 500.00
// 15.00
// 250.00
// 8.5
// Output 1 :
// 425.00
// 271.25
// Input 2 :
// 2000.00
// 15.5
// 300.00
// 12.00
// Output 2 :
// 1690.00
// 336.00
// Note :
// The program will be evaluated only after the “Submit Code” is clicked.
// Extra spaces and new line characters in the program output will result in the failure of the test case.

// ans

#include <iostream>
#include <iomanip>
using namespace std;

class Product {
public:
    virtual double calculateTotalPrice() = 0;
};

class Electronics : public Product {
private:
    double price;
    double discount;

public:
    Electronics(double p, double d) : price(p), discount(d) {}

    double calculateTotalPrice() override {
        return price - (price * (discount / 100.0));
    }
};

class Apparel : public Product {
private:
    double price;
    double tax;

public:
    Apparel(double p, double t) : price(p), tax(t) {}

    double calculateTotalPrice() override {
        return price + (price * (tax / 100.0));
    }
};

int main() {
    double electronicsPrice, electronicsDiscount, apparelPrice, apparelTax;
    cin >> electronicsPrice >> electronicsDiscount >> apparelPrice >> apparelTax;

    Electronics electronics(electronicsPrice, electronicsDiscount);
    Apparel apparel(apparelPrice, apparelTax);

    cout << fixed << setprecision(2) << electronics.calculateTotalPrice() << endl;
    cout << fixed << setprecision(2) << apparel.calculateTotalPrice() << endl;

    return 0;
}

// question--2.
// The Human Resources Department at ABC Corporation needs a program to manage employee information and find the highest-paid employee. They require a concrete class named "Employee" to represent individual employee details. The "Employee" class should be a concrete implementation with private attributes to store the employee name, employee ID, and monthly salary. The class should provide methods to update the salary and display the employee's information.

// Once the user provides the employee details, the program should create an array of "Employee" objects and store each employee's information in the array.

// Next, the program should find the highest-paid employee among the entered employees and display their details, including their name, employee ID, and monthly salary.

// To achieve this, the program should define the "Employee" class as a concrete class with appropriate member functions to manage the employee information. The class should include a constructor to initialize the employee details, a function to update the salary, and a function to display the employee's information.

// Finally, after displaying the highest-paid employee's details, the program should deallocate the memory used for the array of employees before terminating.

// Input format :

// The first line of input contains an integer, which represents the total number of employees in the company.

// For each employee, there will be three lines of input:

// The employee's name (a string containing alphabets and spaces).
// The employee's ID (an integer)
// The employee's salary (an integer)
// Output format :

// The output will display the details of the highest-paid employee.

// Refer to the sample output for formatting specifications.

// Code constraints :

// The number of employees will be a positive integer (1 <= numEmployees <= 1000).

// Each employee's name will be a string containing alphabets and spaces only. The length of the name will not exceed 100 characters.

// Employee ID will be a positive integer (1 <= employeeID <= 10000).

// Salary will be a floating-point number, representing the employee's monthly salary. Salary will be in the range of 1000 to 100000.

// Sample test cases :
// Input 1 :
// 5
// Alice Anderson
// 201
// 42000
// Bob Brown
// 202
// 48000
// Claire Carter
// 203
// 51000
// David Davis
// 204
// 44000
// Eva Evans
// 205
// 49000
// Output 1 :
// Employee Name: Claire Carter
// Employee ID: 203
// Salary: 51000

// Input 2 :
// 3
// John Doe
// 101
// 50000
// Jane Smith
// 102
// 55000
// Michael Johnson
// 103
// 48000
// Output 2 :
// Employee Name: Jane Smith
// Employee ID: 102
// Salary: 55000

#include <iostream>
#include <string>
#include <vector>

class Employee {
private:
    std::string name;
    int employeeID;
    int salary;

public:
    Employee(const std::string& empName, int ID, int empSalary) {
        name = empName;
        employeeID = ID;
        salary = empSalary;
    }

    void updateSalary(int newSalary) {
        salary = newSalary;
    }

    void displayInfo() const {
        std::cout << "Employee Name: " << name << std::endl;
        std::cout << "Employee ID: " << employeeID << std::endl;
        std::cout << "Salary: " << salary << std::endl;
    }

    int getSalary() const {
        return salary;
    }
};

int main() {
    int numEmployees;
    std::cin >> numEmployees;

    std::vector<Employee> employees;

    for (int i = 0; i < numEmployees; ++i) {
        std::string empName;
        int ID, empSalary;
        std::cin.ignore(); // Ignore the newline after the number
        std::getline(std::cin, empName);
        std::cin >> ID >> empSalary;

        Employee newEmployee(empName, ID, empSalary);
        employees.push_back(newEmployee);
    }

    int highestSalary = 0;
    int highestSalaryIndex = 0;

    for (int i = 0; i < numEmployees; ++i) {
        if (employees[i].getSalary() > highestSalary) {
            highestSalary = employees[i].getSalary();
            highestSalaryIndex = i;
        }
    }

    employees[highestSalaryIndex].displayInfo();

    return 0;
}
