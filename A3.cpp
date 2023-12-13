#include <iostream>
#include <string.h>
using namespace std;

class Publication{

    public:
        string title;
        float price;
        void get_data(){
            cout<<"Enter a book name:";
            cin>>title;

            cout<<"Enter a book price:";
            cin>>price;
        }

        void display(){
            cout<<"Book name:"<< " "<< title<<endl;
            cout<<"Book Price:"<<" "<< price<<endl;
        }

};

class Book: public Publication{
    private:
        float pagecount;
        int b;
    
    public:
        void page_count(){
            cout<<"Enter a pagecount:";
            cin>>pagecount;
            b = int(pagecount);
            
        }

        void get_data(){
            try{
                cout<<"----Enter a information----"<<endl;
                Publication::get_data();
                page_count();
                if(b != pagecount){
                    throw pagecount;
                }else{
                    display();
                }
            }catch(float){
                cout << "\nInvalid Page Count!!!"<<endl;
			    pagecount = 0;
			    Publication::price = 0;
			    Publication::title = "-";
			    display();	
            }
        }

        void display(){
            cout<<"-----BOOK INFO-----"<<endl;
            Publication::display();
            cout<<"pages of the book are:"<<pagecount<<endl;
        }

};

class Tape: public Publication{
    private:
        float playtime;
        int x;
    
    public:
        void play_time(){
            cout<<"Enter a book playtime:";
            cin>>playtime;
            x = int(playtime);
            
        }

        void get_data(){
            try{
                cout<<"----Enter a information----"<<endl;
                Publication::get_data();
                play_time();
                if(playtime - x> 0.6){
                    throw playtime;
                }else{
                    display();
                }
            }catch(float){
                cout << "\nInvalid Page Count!!!"<<endl;
			    playtime = 0;
			    Publication::price = 0;
			    Publication::title = "-";
			    display();	
            }
        }

        void display(){
            cout<<"-----BOOK INFO-----"<<endl;
            Publication::display();
            cout<<"play time of the book are:"<<playtime<<endl;
        }

};


void menu()
	{
		cout<<endl<<"------------------MENU------------------"<<endl;
		cout<<"1. BOOK"<<endl<<"2. TAPE"<<endl<<"3. EXIT"<<endl;
	}

int main()
{	
	int choice;
	Book b1;
	Tape t1;

	do
	{
		menu();
		cout<<"Enter your choice: "<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				b1.get_data();
				break;
			case 2:
				t1.get_data();
				break;
			case 3:
				cout<<endl<<"You have terminated the program."<<endl;
				break;
			default:cout<<endl<<"Good Bye!!!";	
		}
	}while(choice!=3);
	return 0;


}

