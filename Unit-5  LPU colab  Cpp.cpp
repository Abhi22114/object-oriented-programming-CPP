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
//}
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

