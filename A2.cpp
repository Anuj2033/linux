#include <iostream>
#include <string.h>
using namespace std;

class Student{
    private:
        int number = 20;
    public:
        string name, dob, division;
        int roll_number;
    
        void get_info(){
            cout<<"Enter a name:";
            cin>>name;
            
            cout<<"Enter a date of birth:";
            cin>>dob;

            cout<<"Enter a division:";
            cin>>division;

            cout<<"Enter a roll Number:";
            cin>>roll_number;
        }

        void display(){
            cout<<endl;
            cout<<"Name:"<<name<<endl;
            cout<<"Roll No:"<<roll_number<<endl;
            cout<<"Division:"<<division<<endl;
            cout<<"Date of birth:"<<dob<<endl;
            cout<<endl;
        }

        // Friend class // which access the private and protected data of the Student class
        friend class Friend;

        // Static member function // Without creating objection we can call this
        static void get_display(){
            cout<<"Static member function get's call"<<endl;
            cout<<endl;
        }

        // inline function
        inline int add(int num1, int num2){cout<<num1 + num2<<endl;}

        // Default Construtors
        Student(){
            cout<<"Constructor get called..."<<endl;
        }

        // copy constructor
        Student(Student& s){
            name = s.name;
            roll_number = s.roll_number;
            division = s.division;
            dob = s.dob;
        }

        // This pointer
        Student(string name, int roll_number, string division, string dob){
            this->name = name;
            this->roll_number = roll_number;
            this->division = division;
            this->dob = dob;
        }

        // Destructor
        ~Student(){
            cout<<"Destructor get called..."<<endl;
        }
};

class Friend{
    public:
        void display(Student& s){
            cout<<"friend class number"<<s.number<<endl;
            cout<<endl;
        }
};


int main(){
    int choice, stud;
    Student s1("Anuj", 19, "A", "20/12/2003");
    Student s2(s1);

    // Dynamic allocation
    Student* student = new Student[2];

    cout<<"---Copy Constructor----"<<endl;
    s2.display();

    cout<<"---This Pointer----"<<endl;
    s1.display();

    cout<<"----Friend class----"<<endl;
    Friend f1;
    f1.display(s1);

    cout<<"---Inline Function----"<<endl;
    s1.add(2, 5);

    cout<<"----Static Member----"<<endl;
    Student::get_display();

    cout<<"----Dynamic allocation----"<<endl;
    do{
        cout<<endl;
        cout<<"----MENU----"<<endl;
        cout<<"1. Add data"<<endl;
        cout<<"2. Display data"<<endl;
        cout<<"3. Delete data"<<endl;
        cout<<"Enter a choice:";
        cin>>choice;
        cout<<endl;
        switch(choice)
        {
            case 1:
                cout<<"How many student do you want to add:";
                cin>>stud;
                for(int i = 0; i < stud; i++){
                    student[i].get_info();
                }
                break;
            
            case 2:
                for(int i = 0; i < stud; i++){
                    student[i].display();
                }
                break;
            
            case 3:
                delete[] student;
                break;

            default:
                cout<<"Invalid input"<<endl;
                break;
        }
    }while(choice != 4);

    return 0;

}