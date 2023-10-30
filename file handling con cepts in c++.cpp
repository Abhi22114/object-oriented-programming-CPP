//Thsi programme will print the dceatils of n numbers student
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define a structure to represent student details
struct Student {
    string name;
    int rollNumber;
};

int main() {
    int n; 
    cout << "Enter the number of students: ";
    cin >> n;

    vector<Student> students; 
   
    for (int i = 0; i < n; ++i) {
        Student student;
        cout << "Enter details for Student " << i + 1 << ":" << endl;
        cout << "Name: ";
        cin.ignore(); 
        getline(cin, student.name);
        cout << "Roll Number: ";
        cin >> student.rollNumber;
        // Add more fields as needed

        students.push_back(student); 
    }

    // Print student details
    cout << "Student Details:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Student " << i + 1 << " Details:" << endl;
        cout << "Name: " << students[i].name << endl;
        cout << "Roll Number: " << students[i].rollNumber << endl;
        
        cout << endl;
    }

    return 0;
}


