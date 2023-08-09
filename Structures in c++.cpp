
          //--->>>> Stuctures In C++  -------->>>>>>>>>//
          
//Structures (also called structs) are a way to group several related variables into one place. Each variable in the structure is known as a member of the structure.


//To create a structure, use the struct keyword and declare each of its members inside curly braces.


//NOTE___  :- To access members of a structure, use the dot syntax (.):
//NOTE___ :- You can use a comma (,) to use one structure in many variables: examples

//struct {
//  int myNum;
//  string myString;
//} myStruct1, myStruct2, myStruct3; 



//-->>  Simple structure progran

//#include <>iostream
//#include <string>
//using namespace std;
//
//int main() {
//  struct {
//    int myNum;
//    string myString;
//  } myStructure;
//
//  myStructure.myNum = 1;
//  myStructure.myString = "Hello World!";
//
//  cout << myStructure.myNum << "\n";
//  cout << myStructure.myString << "\n";
//  return 0;
//}


//#include <iostream>
//#include <string>
//using namespace std;
//int main (){
//	struct{
//		int myNum;
//		string myString ;
//		
//		
//		
//	} myStructure;
//	myStructure.myNum=2;
//	myStructure.myString ="Abhijeeet kumar Singh";
//	cout<<myStructure.myNum<<"\n";
//	cout<<myStructure.myString<<"\n";
//	return 0;
//}



//Program  To use one structure in multiple varriables


//#include <iostream>
//#include <string>
//using namespace std;
//int main(){
//	struct{
//		int registration_number;
//		int age ;
//		string Full_name ;	
//	}Student_1,Student_2;
//	
//	Student_1.registration_number= 12216848;
//	Student_1.age=19;
//	Student_1.Full_name="Abhijeet kumar Singh";
//	
//	Student_2.registration_number= 12221345;
//	Student_2.age=20;
//	Student_2.Full_name="Monal Aditya (chutiya)";
//	
//	cout<<Student_1.registration_number<<"  "<<Student_1.age<<" "<<Student_1.Full_name<<" \n ";
//	cout<<Student_2.registration_number<<"  "<<Student_2.age<<" "<<Student_2.Full_name<<"  \n ";
//	return 0;
//	
//}

#include <iostream>
#include <string>
using namespace std;
int main(){
	

struct{
	int uid;
	int salary;
	string name;
	int mob ;
	
	
}e_1,e_2,e_3;

e_1.uid= 12134;
e_1.salary=100000 ;
e_1.name="Abhijeet kumar";
e_1.mob=8797059472;

e_2.uid=23232;
e_2.salary=120000;
e_2.name="Abhinav kumar";
e_2.mob= 8568575857;

e_3.uid=3214;
e_3.salary=75000;
e_3.name="Akash chaurasiya";
e_3.mob=8845677823;

cout<<e_1.uid<<"  "<<e_1.salary<<"  "<<e_1.name<<" "<<e_1.mob<<" \n\n";
cout<<e_2.uid<<"  "<<e_2.salary<<"  "<<e_2.name<<" "<<e_2.mob<<" \n\n";
cout<<e_3.uid<<"  "<<e_3.salary<<"  "<<e_3.name<<" "<<e_3.mob<<" \n\n";
return 0;
}


//----->>Program to print the deatils of students --->>>>>>>>>





//#include <iostream>
//#include <cstring>
//using namespace std;
//class Student {
//    private:
//        char name[30];
//    long marks;
//    char subject[30];
//    public:
//        Student(const char * name, long marks,
//            const char * subject) 
//    {
//        strcpy(this -> name, name);
//        this -> marks= marks;
//        strcpy(this->subject,subject);
//    }
//    void show() {
//        cout << "Student Details are" << endl;
//        cout << "Name " << name << endl;
//        cout << "Marks" << marks<< endl;
//        cout << "Subject " << subject<< endl;
//    }
//};
//int main() {
//    Student student[3] = {
//        Student("Ram", 57, "DSA"),
//        Student("Mohan", 82, "DSA"),
//        Student("Sohan", 93, "DSA")
//    };
////    for (int i = 0;/ i <= 2; i++) {
//        student[i].show();
//    }
//}
