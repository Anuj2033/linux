
#include <iostream>
#include <fstream>
using namespace std;


class Student{
    public:
        char name[30], division;
        int id;

        void get_info(){
            cout<<"Enter a name:";
            cin>>name;

            cout<<"Enter a id:";
            cin>>id;

            cout<<"Enter a division:";
            cin>>division;
        }

        void display_info(){
            cout<<"---------Display-------"<<endl;
            cout<<"name:"<<name<<endl;
            cout<<"Id:"<<id<<endl;
            cout<<"Division:"<<division<<endl;
        }

};


int main(){
    Student stud[5];
    int no_of_student, choice;

    string filename;
    cout<<"Enter a filename:";
    cin>>filename;


    do{
        fstream file(filename, ios::out | ios::app);

        cout<<"----------Menu-----------"<<endl;
        cout<<"1.Add information:"<<endl;
        cout<<"2.Display information:"<<endl;
        cout<<"3.Exit"<<endl;
        cout<<"Enter a choice:";
        cin>>choice;



        switch(choice){
            case 1:
                cout<<"How many student do you want to add:";
                cin>>no_of_student;
                for(int i = 0; i < no_of_student; i++){
                    stud[i].get_info();
                    file << stud[i].name << ' ' << stud[i].id << ' ' << stud[i].division << '\n';

                }
		        break;
	    
	            case 2:
		            for(int i = 0; i < no_of_student; i++){
			            stud[i].display_info();
                        file >> stud[i].name >> stud[i].id >> stud[i].division;
		
        	        }

		            break;
	    
                default:
		            cout<<"Invalid input please enter a valid information"<<endl;
        }
        file.close();

    }while(choice != 3);
    return 0;
}
