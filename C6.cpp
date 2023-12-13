#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class stl{
    public:
        string name, dob;
        int tel;
        void get_data(){
            cout<<"Enter a name:";
            cin>>name;

            cout<<"Enter Date of Birth:";
            cin>>dob;

            cout<<"Enter a telephone number:";
            cin>>tel;
        }

        void display(){
            cout << name << "\t\t" << dob <<"\t\t"<< tel << endl;

        }
};


int main(){
    int n, choice;
    string key;
    cout<<"how many students:";
    cin>>n;

    vector<stl> v(n);
    vector<string>name(n);

    do{
        cout<<endl;
        cout<<"---Menu---"<<endl;
        cout<<"1. add"<<endl;
        cout<<"2. Sort"<<endl;
        cout<<"3. Search"<<endl;
        cout<<"Enter a choice:";
        cin>>choice;
        cout<<endl;

        switch(choice){
            case 1:
                for(int i = 0; i < n; i++){
                    v[i].get_data();
                }
                break;

            case 2:
                for(int i =0; i< n; i++){
                    name[i] = v[i].name;
                }

                cout<<"---Sorted list---"<<endl;
                cout << "Name\t\tDOB\t\tTel No" << endl;

                sort(name.begin(), name.end());
                for(int i = 0;i < n; i++){
                    v[i].display();
                }

                break;
            
            case 3:
                cout<<"Enter a key to search:";
                cin>>key;

                sort(name.begin(), name.end());
                if(binary_search(name.begin(), name.end(), key)){
                    cout<<"recode Found"<<endl;
                }else{
                    cout<<"Record Not found"<<endl;
                }
                break;
            
            default:
                cout<<"Invalid input"<<endl;

        }   
    }while(choice != 4);

    return 0;
}