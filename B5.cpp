#include <iostream>
using namespace std;

const int MAX_SIZE = 15;
int n;

template <typename T> T selection_sort(T arr[MAX_SIZE]){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n - 1; j++){
			T temp;
			if(arr[i] <= arr[j]){
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
		
	for(int i = 0; i < n; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;

}

int main(){
	
	cout<<"How many intergers:";
	cin>>n;
	
	int array[n];
	
	for(int i = 0; i < n; i++){
		cout<<"Enter a number:";
		cin>>array[i];
	}
	cout<<"Sorted integers are"<<endl;
	selection_sort<int>(array);
	
	cout<<"How many floats:";
	cin>>n;
	
	float farray[n];
	
	for(int i= 0; i < n; i++){
		cout<<"Enter a number:";
		cin>>farray[i];
	}
	
	selection_sort<float>(farray);
	
	
	return 0;
}
